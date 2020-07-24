#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define S_SIZE 50

typedef struct d_node {
	int int_data;
	char string[S_SIZE];
	struct d_node* pre;
	struct d_node* link;
}D_NODE;

typedef struct {
	D_NODE* head;
}D_NODE_h;

D_NODE_h* create_D_NODE() {
	D_NODE_h* DL;
	DL = (D_NODE_h*)malloc(sizeof(D_NODE_h));
	DL->head = NULL;
	return DL;
}

void insertNODE(D_NODE_h* DL, D_NODE* p, int* i, char* s) {
	D_NODE* newNODE;
	newNODE = (D_NODE*)malloc(sizeof(D_NODE));
	newNODE->int_data = *i;
	strcpy(newNODE->string, s);
	if (DL->head == NULL) {
		newNODE->pre = NULL;
		newNODE->link = NULL;
		DL->head = newNODE;
	}
	else {
		newNODE->link = p->link;
		p->link = newNODE;
		newNODE->pre = p;
		if (newNODE->link != NULL) {
			newNODE->link->pre = newNODE;
		}
	}
}

void printD_NODE(D_NODE_h* DL) {
	D_NODE* p;
	printf("DL = (");
	p = DL->head;
	while (p != NULL) {
		printf("%d %s", p->int_data, p->string);
		p = p->link;
		if (p != NULL)printf(", ");
	}
	printf(")\n");
}

void DeleteNODE(D_NODE_h* DL, D_NODE* p) {
	if (DL->head == NULL) return;
	else if (p == NULL)return;
	else {
		p->pre->link = p->link;
		p->link->pre = p->pre;
		free(p);
	}
}

D_NODE* search_int_NODE(D_NODE_h* DL, int* i) {
	D_NODE* p;
	p = DL->head;
	while (p != NULL) {
		if (p->int_data == *i) {
			return p;
		}
		else {
			p = p->link;
		}
	}
	return p;
}

D_NODE* search_str_NODE(D_NODE_h* DL, char* s) {
	D_NODE* p;
	p = DL->head;
	while (p!=NULL) {
		if (strcmp(p->string, s) == 0) {
			return p;
		}
		else {
			p = p->link;
		}
	}
	return p;
}
