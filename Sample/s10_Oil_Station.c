#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int distance[100000];
    int price[100000];

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &distance[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    int total_cost = 0;
    int min_price = price[0];

    for (int i = 0; i < n - 1; i++) {
        if (price[i] < min_price) {
            min_price = price[i];
        }
        total_cost += min_price * distance[i];
    }

    printf("%d\n", total_cost);
    return 0;
}