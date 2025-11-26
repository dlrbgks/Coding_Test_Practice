#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int* coin = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (coin[i] <= k) {
            count += k / coin[i];
            k = k % coin[i];
        }
    }

    printf("%d\n", count);
    free(coin);


}