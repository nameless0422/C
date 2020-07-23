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

void insertFirstNODE_d(D_NODE_h* DL, int* i, char* s) {
	D_NODE* newNODE;
	newNODE = (D_NODE*)malloc(sizeof(D_NODE));
	newNODE->int_data = *i;
	strcpy(newNODE->string, s);
	newNODE->link = DL->head;
	DL->head = newNODE;
	newNODE->pre = NULL;
}

void insertMiddleNODE_d(D_NODE_h* DL, D_NODE* pre, int* i, char* s) {
	D_NODE* newNODE;
	newNODE = (D_NODE*)malloc(sizeof(D_NODE));
	strcpy(newNODE->string, s);
	newNODE->int_data = *i;
	if (DL == NULL) {
		newNODE->link = NULL;
		DL->head = newNODE;
	}
	else if (pre==NULL) {
		DL->head = newNODE;
	}
	else{
		newNODE->link = pre->link;
		pre->link = newNODE;
		newNODE->pre = pre;
	}
}

void insertLastNODE_d(D_NODE_h* DL,int*i,char*s) {
	D_NODE* newNODE, * temp;
	newNODE = (D_NODE*)malloc(sizeof(D_NODE));
	newNODE->int_data = *i;
	strcpy(newNODE->string, s);
	newNODE->link = NULL;
	if (DL->head == NULL) {
		DL->head = newNODE;
		return;
	}
	temp = DL->head;
	while (temp->link != NULL) { temp = temp->link; }
	temp->link = newNODE;
	newNODE->pre = temp;
}