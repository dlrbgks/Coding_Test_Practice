#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int main() {

	printf("Enter Card's count (1 ~ 500,000)>> ");
	int n;
	scanf("%d", &n);
	if (n > 500000 || n < 1) {
		printf("Wrong input.\n");
		return;
	}
	int* num = (int*)malloc(sizeof(int) * n);
	int count = 0;
	int temp;
	for (int i = 0; i < n; i++) {
		printf("Enter number(%d) (-10,000,000 ~ 10,000,000) >> ", i + 1);
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		temp = num[i];
		for (int j = i + 1; j < n; j++) {
			if (temp == num[j]) {
				printf("Overwrite number(%d) (-10,000,000 ~ 10,000,000) >> ", j + 1);
				scanf("%d", &num[j]);
			}
		}
	}
	printf("Enter Compare Card's count (1 ~ 500,000)>> ");
	int m;
	scanf("%d", &m);
	if (m > 500000 || m < 1) {
		printf("Wrong input.\n");
		return;
	}
	int* c_num = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		printf("Enter number(%d) (-10,000,000 ~ 10,000,000) >> ", i + 1);
		scanf("%d", &c_num[i]);
	}
	for (int i = 0; i < m; i++) {
		count = 0;
		for (int j = 0; j < n; j++) {
			if (c_num[i] == num[j]) {
				count = 1;
				break;
			}
		}
		printf("%d ", count);
	}
}