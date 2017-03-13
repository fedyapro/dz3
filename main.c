#include "sort.h"
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>


int main (int argc, char *argv[]) {

	FILE *f = fopen(argv[1], "r");
	if (f == NULL){
		printf ("cant open file\n");
		return 1;
	} 
	node* list = read_f(f);
	if(list == NULL)
        return -1; 
	node* sort_list = sort(list);
	if(sort_list == NULL)
        return -1; 
	show_list(sort_list);
	return 0;
		
}
