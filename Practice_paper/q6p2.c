#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	char ch;
	struct Node *next,*prev;
}Node;

typedef struct Stack{
	char*arr;
	int top;
}Stack;

Stack *newStack(int n){
	Stack *s = malloc(sizeof(Stack));
	s->arr = malloc(n);
	s->top = -1;
	return s;
}

void push(Stack *s, char x){s->arr[++s->top]=x;}
char pop(Stack*s){return s->arr[s->top--];}
int empty(Stack *s){return s->top < 0;}

Node* buildList(char *s){
	Node *head = NULL, *tail = NULL;
	for(int i =0;s[i];i++){
		Node *node = malloc(sizeof(Node));
		node->ch = s[i];
		node->next = NULL;
		node->prev = tail;
		if(tail)tail->next = node;
		else head = node;
		tail = node;
	}
	return head;
}

int isPalindrome(char *s){
	Node *head = buildList(s), *curr= head;
	Stack *side = newStack(strlen(s));

	while(curr && curr->ch!='c'){
		push(side,curr->ch);
		curr = curr->next;
	}
	if(!curr) return 0;
	curr = curr->next;
	while(curr && !empty(side)){
		if(pop(side) != curr->ch){
			return 0;
		}
		curr = curr->next;
	}
	return(empty(side) && !curr);
}

int main(int argc, char*argv[]){
	if(argc<2) return 1;
	
	if(isPalindrome(argv[1])){
		printf("Yes Palindrome\n");
	} else {
		printf("No Palindrome\n");
	}

}
