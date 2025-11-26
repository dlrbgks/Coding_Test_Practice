#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 오랜만에 포인터 배열말고 구조체 써봅세 - 배열 쓰면 나도 햇갈릴 것 같음
typedef struct {
    int start;
    int end;
} Meeting;

int compare(void* a, void* b) {
    Meeting* m1 = (Meeting*)a;
    Meeting* m2 = (Meeting*)b;
    if (m1->end == m2->end) 
        //m1 기준으로
        //종료 시간이 같으면 시작 시간으로 순서 구분
        return m1->start - m2->start;
    // 아니면 종료시간으로 구분
    return m1->end - m2->end;
}

int main() {
    int n;
    scanf("%d", &n);
    Meeting* arr = (Meeting*)malloc(sizeof(Meeting) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Meeting), compare);

    int count = 0;
    int last_end = 0;

    // 최대한 간격이 짧은 걸로 선택 - 중복은 안되는 걸로
    for (int i = 0; i < n; i++) {
        if (arr[i].start >= last_end) {
            count++;
            last_end = arr[i].end;
        }
    }

    printf("%d\n", count);

    free(arr);
    return 0;
}