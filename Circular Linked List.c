#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define S_SIZE 50

typedef struct node {
	int int_data;
	char string[S_SIZE];
	struct node* link;
}NODE;

typedef struct {
	NODE* head;
}NODE_h;

NODE_h* create_CircleLinkedlist_h() {
	NODE_h* CL;
	CL = (NODE_h*)malloc(sizeof(NODE_h));
	CL->head = NULL;
	return CL;
}

void free_CircleLinkedlist(NODE_h* CL) {
	NODE* p, * pre;
	p = CL->head;
	do {
		pre = p;
		p = p->link;
		free(pre);
	} while (p != CL->head);
}

void print_CircleLinkedlist(NODE_h* CL) {
	NODE* p;
	printf(" CL = (");
	p = CL->head;
	do {
		printf("%d %s", p->int_data, p->string);
		p = p->link;
		if (p != CL->head)printf(", ");
	} while (p != CL->head);
	printf(") \n");
}

void insertFirstNode_c(NODE_h* CL, int* i, char* s) {
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

void insertMiddleNode_c(NODE_h* CL, NODE* pre, int* i, char* s) {
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

void deleteNode_c(NODE_h* CL, NODE* old) {
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

NODE* search_int_NODE_c(NODE_h* CL, int* i) {
	NODE* temp;
	temp = CL->head;
	if (temp == NULL)return NULL;
	do {
		if (temp->int_data == *i) return temp;
		else temp = temp->link;
	} while (temp!=CL->head);
	return NULL;
}

NODE* search_str_NODE_c(NODE_h* CL, char* s) {
	NODE* temp;
	temp = CL->head;
	if (temp==NULL) return NULL;
	do {
		if (strcmp(temp->string, s) == 0) return temp;
		else temp = temp->link;
	} while (temp!=CL->head);
	return NULL;
}

int main() {
	NODE_h* CL;
	NODE* p;
	int menu;
	int input_int;
	char input_str[S_SIZE];
	CL = create_CircleLinkedlist_h();
	while (1) {
		printf("1 : insert data on first\n2 : insert data on middle\n3 : search data\n4 : delete data\n5 : print all data\n6 : shutdown\n");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("please Enter int data\n");
			scanf("%d", &input_int);
			printf("please Enter string data\n");
			scanf("%s", input_str);
			insertFirstNode_c(CL,&input_int,input_str);
			printf("data adding complete\n\n");
			break;
		case 2:
			printf("1 : int\n2 : string\n");
			scanf("%d", &menu);
			if (menu == 1) {
				printf("please Enter int data to find\n");
				scanf("%d", &input_int);
				p = search_int_NODE_c(CL, &input_int);
				printf("please Enter int data\n");
				scanf("%d", &input_int);
				printf("please Enter string data\n");
				scanf("%s", input_str);
			}
			else if (menu == 2) {
				printf("please Enter string data to find\n");
				scanf("%s", input_str);
				p = search_str_NODE_c(CL, input_str);
				printf("please Enter int data\n");
				scanf("%d", &input_int);
				printf("please Enter string data\n");
				scanf("%s", input_str);
			}
			else {
				printf("please select available menu.\n\n");
				break;
			}
			insertMiddleNode_c(CL, p, &input_int, input_str);
			printf("data adding complete\n\n");
			break;
		case 3:
			printf("1 : int\n2 : string\n");
			scanf("%d", &menu);
			if (menu == 1) {
				printf("please Enter int data to find\n");
				scanf("%d", &input_int);
				p = search_int_NODE_c(CL, &input_int);
			}
			else if(menu == 2){
				printf("please Enter string data to find\n");
				scanf("%s", input_str);
				p = search_str_NODE_c(CL, input_str);
			}
			else {
				printf("please select available menu.\n\n");
				break;
			}
			printf("Data found : %d %s\n\n", p->int_data, p->string);
			break;
		case 4:
			printf("1 : int\n2 : string\n");
			scanf("%d", &menu);
			if (menu == 1) {
				printf("please Enter int data to delete\n");
				scanf("%d", &input_int);
				p = search_int_NODE_c(CL, &input_int);
			}
			else if (menu == 2) {
				printf("please Enter str data to delete\n");
				scanf("%s", input_str);
				p = search_str_NODE_c(CL, input_str);
			}
			else {
				printf("please select available menu.\n\n");
				break;
			}
			deleteNode_c(CL, p);
			printf("Delete complete\n\n");
			break;
		case 5:
			print_CircleLinkedlist(CL);
		case 6:
			goto EXIT;
		default:
			printf("please select available menu.\n\n");
			break;
		}
	}
EXIT:
	free_CircleLinkedlist(CL);
}