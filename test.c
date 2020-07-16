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
	int input_dataINT;
	char input_string[S_SIZE];
	L = createLinkedList_h();
	while (1)
	{
		printf("1 : ���� �պκп� ������ �߰�\n2 : ���� �޺κп� ������ �߰�\n3 : pre �޺κп� ������ �߰�\n4 : ������ Ž��\n5 : ��� p ����\n6 : ������ �������� �ٲٱ�\n7 : ������ ��ü ���\n8 : ���α׷� ����\n");
		printf("select menu :");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("������ ���ڿ��� �Է��ϼ���\n");
			scanf("%s", input_string);
			printf("������ �������� �Է��ϼ���\n");
			scanf("%d", &input_dataINT);
			insert_FirstNODE(L, input_string, &input_dataINT);
			printf("���������� ����Ǿ����ϴ�.\n");
			break;
		case 2:
			printf("������ ���ڿ��� �Է��ϼ���\n");
			scanf("%s", input_string);
			printf("������ �������� �Է��ϼ���\n");
			scanf("%d", &input_dataINT);
			insert_LastNODE(L, input_string, &input_dataINT);
			printf("���������� ����Ǿ����ϴ�.\n");
			break;
		case 3:
			printf("1 : ���ڿ� ����\n2 : ���� ����\n");
			scanf("%d", &menu);
			if (menu == 1) {
				printf("ã�� ���ڿ��� �Է����ּ���\n");
				scanf("%s", input_string);
				p = search_str_NODE(L, input_string);
				if (p == NULL) {
					printf("���� �������� �ʽ��ϴ�.\n");
					break;
				}
				printf("������ ���ڿ��� �Է��ϼ���\n");
				scanf("%s", input_string);
				printf("������ �������� �Է��ϼ���\n");
				scanf("%d", &input_dataINT);
				insert_MiddleNODE(L, p, input_string, &input_dataINT);
				printf("���������� ����Ǿ����ϴ�.\n");
			}
			else if (menu == 2) {
				printf("ã�� �������� �Է����ּ���\n");
				scanf("%d",&input_dataINT);
				p = search_int_NODE(L,&input_dataINT);
				if (p == NULL) {
					printf("���� �������� �ʽ��ϴ�.\n");
					break;
				}
				printf("������ ���ڿ��� �Է��ϼ���\n");
				scanf("%s", input_string);
				printf("������ �������� �Է��ϼ���\n");
				scanf("%d", &input_dataINT);
				insert_MiddleNODE(L, p, input_string, &input_dataINT);
				printf("���������� ����Ǿ����ϴ�.\n");
			break;
		case 4:
			printf("1 : ���ڿ� ����\n2 : ���� ����\n");
			scanf("%d", &menu);
			if (menu == 1) {
				printf("ã�� ���ڿ��� �Է����ּ���\n");
				scanf("%s", input_string);
				p = search_str_NODE(L, input_string);
				if (p == NULL) {
					printf("���� �������� �ʽ��ϴ�.\n");
					break;
				}
				printf("%d %s �� ã�ҽ��ϴ�.\n", p->data, p->string);
			}
			else if (menu == 2) {
				printf("ã�� �������� �Է����ּ���\n");
				scanf("%d", &input_dataINT);
				p = search_int_NODE(L, &input_dataINT);
				if (p == NULL) {
					printf("���� �������� �ʽ��ϴ�.\n");
					break;
				}
				printf("%d %s �� ã�ҽ��ϴ�.\n", p->data, p->string);
			}
			break;
		case 5:
			printf("1 : ���ڿ� ����\n2 : ���� ����\n");
			scanf("%d", &menu);
			if (menu == 1) {
				printf("������ ���ڿ��� �Է����ּ���\n");
				scanf("%s", input_string);
				p = search_str_NODE(L, input_string);
				if (p == NULL) {
					printf("�ش��ϴ� �����Ͱ� �������� �ʽ��ϴ�.\n");
					break;
				}
				printf("%d %s �� �����մϴ�.\n",p->data,p->string);
				delete_NODE_p(L, p);
				printf("�����Ǿ����ϴ�.\n");
			}
			else if (menu == 2) {
				printf("ã�� �������� �Է����ּ���\n");
				scanf("%d", &input_dataINT);
				p = search_int_NODE(L, &input_dataINT);
				if (p == NULL) {
					printf("�ش��ϴ� �����Ͱ� �������� �ʽ��ϴ�.\n");
					break;
				}
				printf("%d %s �� �����մϴ�.\n", p->data, p->string);
				delete_NODE_p(L, p);
				printf("�����Ǿ����ϴ�.\n");
			}
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