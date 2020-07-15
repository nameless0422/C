#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define S_SIZE 50

typedef struct NODE {
	int data;
	char string[S_SIZE];
	NODE* link;
}NODE;

typedef struct {
	NODE* head;
}NODE_h;

NODE_h* createLinkedList_h();
void free_LinkedList(NODE_h* L);
void print_LinkedList(NODE_h* L);
void insert_FirstNODE(NODE_h* L, char* x, int* i);
void insert_MiddleNODE(NODE_h* L, NODE* pre, char* x, int* i);
void insert_LastNODE(NODE_h* L, char* x, int* i);
void delete_NODE_p(NODE_h* L, NODE* p);
NODE* search_int_NODE(NODE_h* L, int* i);
NODE* search_str_NODE(NODE_h* L, char* x);
void reverse(NODE_h* L);

int main() {
	NODE_h* L;
	NODE* p;
	int menu;
	L = createLinkedList_h();
	while (1)
	{
		printf("1 : 가장 앞부분에 데이터 추가\n2 : 가장 뒷부분에 데이터 추가\n3 : pre 뒷부분에 데이터 추가\n4 : 데이터 탐색\n5 : 노드 p 삭제\n6 : 노드순서 역순으로 바꾸기\n7 : 데이터 전체 출력\n8 : 프로그램 종료\n");
		printf("select menu :");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			scanf("%d", &menu);
			if (menu == 1) {

			}
			else if (menu == 2) {

			}
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		default:
			break;
		}
	}

}

NODE_h* createLinkedList_h() {
	NODE_h* L;
	L = (NODE_h*)mallloc(sizeof(NODE_h));
	L->head = NULL;
	return L;
}

void free_LinkedList(NODE_h* L) {
	NODE* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}

}

void print_LinkedList(NODE_h* L) {
	NODE* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%d %s", p->data, p->string);
		p = p->link;
		if (p != NULL) {
			printf(", ");
		}
	}
	printf(")\n");
}

void insert_FirstNODE(NODE_h* L, char* x, int* i) {
	NODE* newNODE;
	newNODE = (NODE*)malloc(sizeof(NODE));
	strcpy(newNODE->string, x);
	newNODE->data = *i;
	newNODE->link = L->head;
	L->head = newNODE;
}

void insert_MiddleNODE(NODE_h* L, NODE* pre, char* x, int* i) {
	NODE* newNODE;
	newNODE = (NODE*)malloc(sizeof(NODE));
	strcpy(newNODE->string, x);
	newNODE->data = *i;
	if (L == NULL) {
		newNODE->link = L->head;
		L->head = newNODE;
	}
	else if (pre == NULL) {
		L->head = newNODE;
	}
	else {
		newNODE->link = pre->link;
		pre->link = newNODE;
	}

}

void insert_LastNODE(NODE_h* L, char* x, int* i) {
	NODE* newNODE;
	NODE* tmp;
	newNODE = (NODE*)malloc(sizeof(NODE));
	strcpy(newNODE->string, x);
	newNODE->data = *i;
	newNODE->link = NULL;
	if (L->head == NULL) {
		L->head = newNODE;
		return;
	}
	tmp = L->head;
	if (tmp->link != NULL) { tmp = tmp->link; }
	tmp->link = newNODE;
}

void delete_NODE_p(NODE_h* L, NODE* p) {
	NODE* pre;
	if (L->head == NULL)return;
	if (L->head->link == NULL) {
		free(L->head);
		L->head = NULL;
		return;
	}
	else if (p == NULL) return;
	else {
		pre = L->head;
		while (pre->link != p)
		{
			pre = pre->link;
		}
		pre->link = p->link;
		free(p);
	}
}

NODE* search_int_NODE(NODE_h* L, int* i) {
	NODE* tmp;
	tmp = L->head;
	while (tmp != NULL) {
		if (*i == tmp->data)return tmp;
		else tmp = tmp->link;
	}
	return tmp;
}

NODE* search_str_NODE(NODE_h* L, char* x) {
	NODE* tmp;
	tmp = L->head;
	while (tmp != NULL) {
		if (strcmp(tmp->data, x) == 0)return tmp;
		else tmp = tmp->link;
	}
	return tmp;
}

void reverse(NODE_h* L) {
	NODE* p;
	NODE* q;
	NODE* r;

	p = L->head;
	q = NULL;
	r = NULL;

	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}