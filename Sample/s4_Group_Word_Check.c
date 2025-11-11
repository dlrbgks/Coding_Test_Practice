#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char word[100];
	printf("Enter word's number >> ");
	int n;
	int count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n;i++) {
		printf("Enter word (%d) >> ", i + 1);
		scanf("%s", word);
		char temp = word[0];
		int check = 1;
		int state[100];
		for (int i = 0;i < 100;i++) {
			state[i] = -1;
		}

		for (int i = 0; i < strlen(word); i++) {
			for (int j = 1; j < strlen(word); j++) {

				check = 0;

				if (temp == word[j]) {
					break;
				}

				check = 1;

			}
			if (i != strlen(word) - 1) {
				temp = word[i + 1];
			}
			if (check == 1) {
				state[i] = 1;
			}
			else {
				state[i] = 0;
			}
		}

		for (int i = 0; i < 100;i++) {
			if (state[i] == -1) {
				break;
			}
			if (state[i] == 1) {
				count++;
			}
		}
	}

	printf("%d", count);

}