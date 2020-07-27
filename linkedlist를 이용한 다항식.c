#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	float coef;
	int expo;
	struct Node* link;
}NODE;

typedef struct {
	NODE* head;
}NODE_h;

NODE_h* createLinkedlist(){
	NODE_h* L;
	L = (NODE_h*)malloc(sizeof(NODE_h));
	L->head = NULL;
	return L;
}

void appendTerm(NODE_h* L, float coef, int expo) {
	NODE* newNODE;
	NODE* p;
	newNODE = (NODE*)malloc(sizeof(NODE));
	newNODE->coef = coef;
	newNODE->expo = expo;
	newNODE->link = NULL;
	if (L->head == NULL) {
		L->head = newNODE;
		return;
	}
	else {
		p = L->head;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = newNODE;
	}
}

void addPoly(NODE_h* A, NODE_h* B, NODE_h* C) {
	NODE* pA = A->head;
	NODE* pB = B->head;
	float sum;

	while (pA && pB) {
		if (pA->expo == pB->expo) {
			sum = pA->coef + pB->coef;
			appendTerm(C, sum, pA->expo);
			pA = pA->link;
			pB = pB->link;
		}
		else if (pA->expo > pB->expo) {
			appendTerm(C, pA->coef, pA->expo);
			pA = pA->link;
		}
		else {
			appendTerm(C, pB->coef, pB->expo);
			pB = pB->link;
		}
	}

	for (; pA != NULL; pA = pA->link) {
		appendTerm(C, pA->coef, pA->expo);
	}

	for (; pB != NULL; pB = pB->link) {
		appendTerm(C, pB->coef, pB->expo);
	}
}

void printPoly(NODE_h* L) {
	NODE* p = L->head;
	for (; p; p = p->link) {
		printf("%3.0fx^%d", p->coef, p->expo);
		if (p->link != NULL)printf(" +");
	}
}

void main() {
	NODE_h* A, * B, * C;
	A = createLinkedlist();
	B = createLinkedlist();
	C = createLinkedlist();

	appendTerm(A, 4, 3);
	appendTerm(A, 3, 2);
	appendTerm(A, 5, 1);
	printf("\n A(x) =");
	printPoly(A);

	appendTerm(B, 3, 4);
	appendTerm(B, 1, 3);
	appendTerm(B, 2, 1);
	appendTerm(B, 1, 0);
	printf("\n B(x) =");
	printPoly(B);

	addPoly(A, B, C);
	printf("\n C(x) =");
	printPoly(C);
	getchar();
}
