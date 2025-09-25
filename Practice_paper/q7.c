#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct Node{
	char val;
	struct Node* next;	
}Node;


Node* builder(char c,Node* head){
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = c;
	node->next = NULL;
	if(!head) return node;
	Node *temp = head;	
	while(temp->next) temp = temp->next;
	temp->next = node;
	return head;
}

typedef struct Stack{
	int top;
	int cap;
	char*arr;
}Stack;

Stack* createStack(int capacity){
	Stack * st = (Stack*)malloc(sizeof(Stack));
	st->top = -1;
	st->cap = capacity;
	st->arr = (char*)malloc(capacity*sizeof(char));
	return st;
}

int isEmpty(Stack *s){return s->top<0;}
char peek(Stack*s) {return s->arr[s->top];}
char pop(Stack*s) {return s->arr[s->top--];}
void push(Stack *s, char v) {s->arr[++s->top] = v;}

int prec(char x){
	if(x == '*'|| x == '/') return 2;
	if(x == '+' || x == '-') return 1;
	return 0;
}

void infixToPost(Node* head, char*out){
	Stack *s = createStack(100);
	Node * temp = head;
	int k = 0;
	while(temp){
		char c = temp->val;
		if(isdigit(c)){
			out[k++] = c;
		} else {
			while(!isEmpty(s) && prec(peek(s)) > prec(c)){
				out[k++] = pop(s);
			}
			push(s,c);
		}
		temp = temp->next;
	}
	while(!isEmpty(s)){
		out[k++] = pop(s);
	}
	out[k] = '\0';
}


int evaluate(char*post){
	int fin = 0;
	Stack *s = createStack(strlen(post));
	for(int i = 0;i<strlen(post);i++){
		if(isdigit(post[i])){
			push(s,post[i] - '0');
		}else {
			int a = pop(s);
			int b = pop(s);
			switch (post[i]){
				case '+': fin = a + b; break;
				case '-': fin = b-a; break;
				case '*': fin = b*a;break;
				case '/': fin = b/a;break;
			}
			push(s,fin);
		}
	}
	return fin;
}


void infixx(char*post,char*inf){
	int n = strlen(post);
	int k = strlen(post)-1;
	Stack* s = createStack(strlen(post)+1);
	for(int i = n-1;i>=0;i--){
		if(!isdigit(post[i])){
			push(s,post[i]);
		} else {
			inf[k--] = post[i];
			inf[k--] = pop(s);
		}
	}
}


int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Usage : %s <infix-expression> \n",argv[0]);
		return 1;
	}
	Node* infix = NULL;
	for(int i = 0;i<strlen(argv[1]);i++){
		infix = builder(argv[1][i],infix);
	}
	char postfix[100];
	infixToPost(infix, postfix);

	printf("%s\n",postfix);
	char infixxx[100];	
	printf("%d\n",evaluate(postfix));
	infixx(postfix,infixxx);
	printf("%s\n",infixxx);
	return 0;
}
