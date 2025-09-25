#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	char ch;
	struct Node *next,*prev;
}Node;

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
	Node *head = buildList(s), *cnode = head;
	while(cnode && cnode->ch != 'c') cnode = cnode->next;

	if(!cnode) return 0;

	Node *left = cnode->prev, *right = cnode->next;
	while(left && right){
		if(left->ch != right->ch) return 0;
		left = left->prev;
		right = right->next;
	}
	return(!left && !right);
}

int main(int argc, char*argv[]){
	if(argc<2) return 1;
	
	if(isPalindrome(argv[1])){
		printf("Yes Palindrome\n");
	} else {
		printf("No Palindrome\n");
	}

}
