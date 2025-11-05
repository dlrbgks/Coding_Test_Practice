#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	printf("Enter n >> ");
	int n;
	scanf("%d", &n);

	int* list = (int*)malloc(sizeof(int) * n);
	list[0] = 1;
	list[1] = 2;

	for (int i = 2; i < n;i++) {
		list[i] = list[i - 1] + list[i - 2];
	}

	printf("%d", list[n - 1]);

	free(list);

}