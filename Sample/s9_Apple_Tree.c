#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int tree_count;
	scanf("%d", &tree_count);
	int sum = 0;
	int require_height;
	for (int i = 0; i < tree_count; i++) {
		scanf("%d", &require_height);
		sum += require_height;
	}
	if (sum % 3 == 0)
		printf("YES");
	else
		printf("NO");

}