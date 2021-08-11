#include<stdio.h>

//int main() {
//	int i = 0;
//	int arr[101] = { 0};
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	
//	for (i = 0; i < 10; i++) {
//		//arr[i] = i;
//		//printf("%d ", arr[i]);
//		//printf("%d ", arr1[i]); 
//		//printf("%d ", arr2[i]);
//	}
//	return 0;
////}////Õ»Ëğº¦ÁË£¬
#define n 100000
long Sum1(long i) 
{
	long s = 0;
	for (long i = 1; i <= n; i++)
		s += i;
	return s;

}
long Sum2(long i) {
	long s = n * (n + 1) / 2;
	return s;
}
int main() {
	int e = clock(Sum1);
	int m = clock(Sum2);
	int a = Sum1(e);
	int b = Sum2(m);
	printf("%d ", a);
	printf("%d ", b);
	printf("%d ", e);
	printf("%d ", m);
	return 0;
}
InitList(l);