#include "sort.h"
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>


void show_list(node *head){	
	if(head == NULL)
		printf("HEAD IS NULL");
	printf("\nLIST:\n");
		while(head != NULL){
		printf("%s: %d\n", head -> word, head -> count);
		head = head -> next;		
	}
	printf("\n\n");
};

void push (node **head, char *word) {
	node *tmp = (node*) malloc(sizeof(node));
	strcpy(tmp->word, word);
	tmp -> count = 1; 
	tmp->next = (*head);
	(*head) = tmp;
};

node* contain (char *word, node *head) {
	while (head != NULL) {
		if (!strcmp(word, head->word))
			return head;
		head = head -> next;	
	}
	return NULL;
};



node* search(node *head, node *curr){
	node *prev = NULL;
	while (head != NULL) {
		if(curr->count >= head->count)
			return prev;
		prev = head;
		head = head->next;
	}
	return prev;
};

void insert(node *curr, node *prev){
	node *temp = NULL;
	if(prev != NULL){
		temp = prev->next;
		prev->next = curr;	
	}
	curr->next = temp;
	show_list(curr);
};
node* sort(node *head){
	node *headsec = head;
	if(head == NULL)
		return NULL;	
	head = head -> next;
	headsec -> next = NULL;	
	while (head != NULL){
		printf ("\n-\n");
		show_list(headsec);
		node *tmp = head->next;		
		node *search_ = search(headsec, head);
		if(search_ == NULL){
			head->next = headsec;
			headsec = head;
		}else 
			insert(head, search_);
		head = tmp;
		
	}
	return headsec;
};

node* read_f(FILE *f) {
	node *head = NULL;
	char word[20];
	char ch;
	int col = 0;
	int i = 0;
	while((ch = getc(f)) != EOF){
		if(isspace(ch) || ispunct(ch)){
			if(!i)
				continue;
			word[i] = '\0';
			i = 0;
			node *tmp = contain(word, head);		
			if (tmp == NULL){
				col++;
				push (&head, word);
			}else{
				(tmp -> count)++;	
			}
		}else{
			word[i] = ch;
			i++;
		}
		
	}
	
	printf ("%d\n", col);
	return head;
};
