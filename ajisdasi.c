#include <stdio.h>
int main() {
	int arr[] = { 1,1,2,3,4,4,5,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int j = 0;
	for (i = 0; i < sz-1; i++)
	{
		 
		int b = arr[i] ^ arr[i + 1];
		if (b==0)
		{
			printf("%d,%d ", arr[i], arr[i + 1]);
			printf("\n");
		}
	}
	for (j = 0; j <= sz - 1; j=j+2) 
	{
		int a = arr[j] ^ arr[j + 1];
		if (a != 0)
		{
			printf("%d,%d\n",arr[j],arr[j+1]);

		}
	}
	return 0;
}