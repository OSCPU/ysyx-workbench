#include "trap.h"

volatile int A[10];
volatile int b;

int main() {
	A[0] = 0;
	A[1] = 1;
	A[2] = 2;
	A[3] = 3;
	A[4] = 4;

	b = A[3];
	A[5] = b;

	check(A[0] == 0);
	check(A[1] == 1);
	check(A[2] == 2);
	check(A[3] == 3);
	check(A[4] == 4);
	check(b == 3);
	check(A[5] == 3);

	return 0;
}
