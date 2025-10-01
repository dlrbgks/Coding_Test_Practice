#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int ki, q, l, b, kn, p;
	ki = 0;
	q = ki;
	l = ki;
	b = ki;
	kn = ki;
	p = ki;
	printf("King, Queen, Look, Bishop, Pawn\n");
	scanf("%d %d %d %d %d %d", &ki, &q, &l, &b, &kn, &p);
	
	int run = 1;

	if (ki > 1 || q > 1 || l > 2 || b > 2 || kn > 2 || p > 8) {
		printf("Over max unit exist!\n");
		return;
	}
	else if (ki < 0 || q < 0 || l < 0 || b < 0 || kn < 0 || p < 0) {
		printf("Under 0 unit exist!\n");
		return;
	}

	printf("%d %d %d %d %d", 1 - ki, 1 - q, 2 - l, 2 - b, 2 - kn, 8 - p);

}