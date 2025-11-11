#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
문제
상근이네 집 앞의 아스키 거리는 알파벳 소문자가 적혀 있는 타일 N개로 이루어져 있다. 
정부는 알 수 없는 이유 때문에 거리의 타일을 자주 바꾼다. 
하지만, 글자가 적혀있는 타일은 공급이 수요를 따라갈 수 없기 때문에 정부는 M종류의 묶음 타일만 사용할 수 있다.

i번째 묶음 타일은 Li개의 글자로 이루어져 있다. 
묶음 타일은 회전하거나 조각으로 나눌 수 없다.
또, 거리와 연속해서 글자가 모두 일치하는 경우에만 그 묶음을 사용해서 타일을 교체할 수 있다.
타일은 겹쳐도 상관없고, 한 묶음을 여러 번 사용해도 된다.

현재 거리에 쓰여 있는 타일과 묶음 타일의 정보가 주어졌을 때, 그 어떤 타일로도 바꿀 수 없는 칸의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 거리의 길이 N이 주어진다. 
다음 줄에는 거리에 원래 적혀져있는 알파벳이 주어진다. 
셋째 줄에는 묶음 타일의 종류의 개수 M이 주어진다.
다음 M개 줄에는 각 묶음 타일에 적혀져있는 알파벳이 주어진다.
(1 ≤ N ≤ 300,000, 1 ≤ M ≤ 5000, 1 ≤ 각 묶음 타일의 길이 ≤ 5000)

출력
첫째 줄에 그 어떤 묶음 타일로도 바꿀 수 없는 타일의 개수를 출력한다.
*/

int main() {
	int n;
	scanf("%d", &n);
	char* road = (char*)malloc(sizeof(char) * n);
	scanf("%s", &road);

	int* comp_list = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n;i++) {
		comp_list[i] = 0;
	}

	int m;
	scanf("%d", &m);
	char** tile = (char**)malloc(sizeof(char) * m);
	for (int i = 0; i < m;i++) {
		tile[i] = (char*)malloc(sizeof(char) * n);
	}

	for (int i = 0; i < m;i++) {
		scanf("%s", tile[i]);
	}
	
	for (int i = 0; i < m; i++) {
		int tile_len = strlen(tile[i]);
		for (int j = 0; j <= n - tile_len; j++) {
			if (strncmp(road + j, tile[i], tile_len) == 0) {
				for (int k = j; k < j + tile_len; k++) {
					comp_list[k] = 1;
				}
			}
		}
	}
	
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (comp_list[i] == 0) {
			count++;
		}
	}

	printf("%d\n", count);

}