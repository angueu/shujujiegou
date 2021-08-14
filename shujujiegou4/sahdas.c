//void Delete(List& A, ListB);
//{
//	int i, k; ElemType x;
//	for (i = 0; i <= Getlength(B); i++) {
//		x = GetElem(B, i);
//		k = Locate(A, x);
//		if (k > 0)DelElem(A, k);
//	}
//}

//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	l.data = (int*)malloc(sizeof(int));
//	int* p1 = new int; 
//}

#include "stdio.h"
#include "stdlib.h"

#define MAX_INIT_SIZE  100
#define LISTINCREMENT  10

typedef struct
{
	int* elem;
	int length;
	int listsize;
}SqList;

void InitList(SqList* L)
{
	L->elem = (int*)malloc(MAX_INIT_SIZE* sizeof(int));//�������ֽ�Ϊ��λ�Ŀռ䡣
	if (!L)
	{
		printf("error");
	}
	else
	{
		L->length = 0;
		L->listsize = MAX_INIT_SIZE;
	}
}

void ListInsert(SqList* L, int i, int e)
{
	int* p;
	int* q;
	int* newbase;
	if (i<1 || i>L->length + 1) //i == length + 1 �ú����
	{
		printf("error");
	}
	else
	{
		if (L->length >= L->listsize)
		{
			newbase = (int*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));
			if (!newbase)
			{
				printf("newbase error");
			}
			else
			{
				L->elem = newbase;
				L->listsize += LISTINCREMENT;
			}
		}

		q = &(L->elem[i - 1]);

		for (p = &(L->elem[L->length - 1]); p >= q; p--)
		{
			*(p + 1) = *p;
		}

		*(p + 1) = e;
		L->length++;


	}
}

void ListDelete(SqList* L, int i, int* e)
{
	int* p;
	int* q;
	if (i<1 || i>L->length)
	{
		printf("index error");
	}
	else
	{
		q = &(L->elem[L->length - 1]); //���һ�����ĵ�ַ
		p = &(L->elem[i - 1]);
		*e = *p;

		for (p++; p <= q; p++)
		{
			*(p - 1) = *(p);
		}

		L->length--;
	}
}

void printList(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
	{
		printf("\n˳����%d���� �� %d\n", i + 1, L.elem[i]);
	}
}


void main()
{
	SqList L;//����һ�����Ա�
	int e;
	InitList(&L);
	ListInsert(&L, 1, 10);
	ListInsert(&L, 2, 20);
	printList(L);
	ListDelete(&L, 2, &e);
	printList(L);
	printf("e = %d", e);

}