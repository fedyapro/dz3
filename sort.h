#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>

typedef struct node {
	struct node *next;
	int count;
	char word[20];
} node;

void show_list(node *head);
void push (node **head, char *word);
node* contain (char *word, node *head);
node* search(node *head, node *curr);
void insert(node *curr, node *prev;
node* sort(node *head);
node* read_f(FILE *f);

#endif
