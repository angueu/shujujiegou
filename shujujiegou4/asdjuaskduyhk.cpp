//#include<iostream>
//using namespace std;
//int main() {
//	char a;
//	int b;
//	float c;
//	string;
//		cin >> a /*>> b >> c*/;
//	cout << a << " " /*<< b << " " << c << " "*/ << endl;}
//void inorder(Bptr p) // p指向当前子树的根结点
//{
//    if (p == NULL)return;
//    inorder(p->Lson);
//    visit(p);
//    inorder(p->rson);
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
	L->elem = (int*)malloc(MAX_INIT_SIZE * sizeof(int));
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
	if (i<1 || i>L->length + 1) //i == length + 1 好好体会
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
		q = &(L->elem[L->length - 1]); //最后一个数的地址
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
		printf("\n顺序表第%d个数 ： %d\n", i + 1, L.elem[i]);
	}
}


void main()
{
	SqList L;
	int e;
	InitList(&L);
	ListInsert(&L, 1, 10);
	ListInsert(&L, 2, 20);
	printList(L);
	ListDelete(&L, 2, &e);
	printList(L);
	printf("e = %d", e);

}