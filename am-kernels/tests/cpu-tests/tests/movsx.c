#include "trap.h"

volatile int A[10];
volatile int b;
volatile signed char C[10];
int main() {
	A[0] = 0;
	A[1] = 1;
	A[2] = 2;
	A[3] = 3;
	A[4] = 4;

	b = A[3];
	A[5] = b;
	C[0] = 'a';
	check(C[0] == 'a');
	C[1] = C[0];
	check(C[1] == 'a');
	A[0] = (int)C[0];
	check(A[0] == 'a');
	C[1] = 0x80;
	A[0] = (int)C[1];
	check(A[1] == 1);
	check(A[2] == 2);
	check(A[3] == 3);
	check(A[4] == 4);
	check(b == 3);
	check(A[5] == 3);
	check(C[1] == 0xffffff80);
	check(A[0] == 0xffffff80);

	return 0;
}
