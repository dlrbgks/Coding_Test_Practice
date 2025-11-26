//m일에 n세로 사망
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 시간 제한은 어캐 지킬지 모르겠으니 일단 만들어는 봅니다.
// 뭐 해야할진 알겠는데 시간제한 저거 어카냐

#define DIV 100007

int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result = (result * i) % DIV;
	}
	return result;
}

int nCr(int n, int r) {
	if (r < 0 || r > n) return 0;
	int son = factorial(n);
	int mom = (factorial(r) * factorial(n - r)) % DIV;
	// 난 분자 분모가 영어로 뭔지 몰라요
	return (son / mom) % DIV;
}



int main() {
	// 마지막 날에 먹는 떡국 수 0 고정 => 그래야 죽음
	// 분할하면 기준점은 n-1개 만큼 생길 것임

	// 고등학교 수학책 꺼내기는 오랜만이네...
	// n - 1 에서 m - 2 개를 고르는 경우의 수
	// (n - 1)! / (m - 2)! * (n - m + 1)!

	int t;
	scanf("%d", &t);
	int n, m;
	printf("n, m\n");
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		int result = nCr(n - 1, m - 2);
		printf("%d\n", result);
	}

}