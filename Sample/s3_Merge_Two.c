// 1 ~ 1000000 사이 수열 a 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
	printf("array size(n) >> ");
	int n;
	scanf_s("%d", &n);

	srand(time(NULL));
	
	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		a[i] = rand() % 1000000 + 1;
	}
	printf("enter x(2 ~ 2000000) >> ");
	int x;
	scanf_s("%d", &n);
	if (x > 2000000 || x < 2) {
		printf("Over range\n");
		return;
	}
	printf("=== Array ===\n");
	for (int i = 0;i < n;i++) {
		printf("%d ", a[i]);
		if (i % 10 == 0) {
			printf("\n");
		}
	}

	int count = 0;

	if (n % 2 == 0) {
		for (int i = 0; i < n / 2; i++) {
			for (int j = 1; j < n; j++) {
				if (a[i] + a[j] == x) {
					count++;
				}
			}
		}
		printf("a[i] + a[j] = x 만족하는 순서쌍 개수 >> \'%d\'", count);
	}
	else {
		for (int i = 0; i < n / 2 + 1; i++) {
			for (int j = 1; j < n; j++) {
				if (a[i] + a[j] == x) {
					count++;
				}
			}
		}
		printf("a[i] + a[j] = x 만족하는 순서쌍 개수 >> \'%d\'", count);
	}

}