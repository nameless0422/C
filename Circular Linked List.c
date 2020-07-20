#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S_SIZE 50

typedef struct node {
	int int_data;
	char string[S_SIZE];
	struct node* link;
}NODE;

typedef struct {
	NODE* head;
}NODE_h;

NODE* createLinkedlist_h() {
	NODE_h* CL;
	CL = (NODE_h*)malloc(sizeof(NODE_h));
	CL->head = NULL;
	return CL;
}

void printlist(NODE_h* CL) {
	NODE* p;
	printf(" CL = (");
	p = CL->head;
	do {
		printf("%d %s", p->int_data, p->string);
		p = p->link;
		if (p != CL->head)printf(", ");
	}while(p!= CL->head);
	printf(") \n");
}

void insertFirstNode(NODE_h* CL, int* i, char* s) {
	NODE* newNODE, * temp;
	newNODE = (NODE*)malloc(sizeof(NODE));
	newNODE->int_data = *i;
	strcpy(newNODE->string,s);
	if (CL->head == NULL) {
		CL->head = newNODE;
		newNODE->link = newNODE;
	}
	else {
		temp = CL->head;
		while (temp->link!=CL->head) {
			temp = temp->link;
		}
		newNODE->link = temp->link;
		temp->link = newNODE;
		CL->head = newNODE;
	}
}

void insertMiddleNode(NODE_h* CL, NODE* pre, int* i, char* s) {
	NODE* newNODE;
	newNODE = (NODE*)malloc(sizeof(NODE));
	newNODE->int_data = *i;
	strcpy(newNODE->string, s);
	if (CL->head == NULL) {
		CL->head = newNODE;
		newNODE->link = newNODE;
	}
	else {
		newNODE->link = pre->link;
		pre->link = newNODE;
	}
}

void deleteNode(NODE_h* CL, NODE* old) {
	NODE* pre;
	if (CL->head == NULL) return;
	if (CL->head->link == CL->head) {
		free(CL->head);
		CL->head = NULL;
		return;
	}
	else if (old == NULL)return;
	else {
		pre = CL->head;
		while (pre->link != old) {
			pre = pre->link;
		}
		pre->link = old->link;
		if (old == CL->head) CL->head = old->link;
		free(old);
	}
}

NODE* search_int_Node(NODE_h* CL, int* i) {
	NODE* temp;
	temp = CL->head;
	if (temp == NULL)return NULL;
	do {
		if (temp->int_data == *i) return temp;
		else temp = temp->link;
	} while (temp!=CL->head);

}