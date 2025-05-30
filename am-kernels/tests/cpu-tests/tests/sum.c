#include "trap.h"

int main() {
	int i = 1;
	volatile int sum = 0;
	while(i <= 100) {
		sum += i;
		i ++;
	}

	check(sum == 5050);

	return 0;
}
