#include <am.h>
#include <stdio.h>
#include "Blockchain.h"

int main(const char *args) {
  int difficulty = 3;
  if (args != NULL && args[0] >= '0' && args[0] <= '9') {
    difficulty = args[0] - '0';
  }
  printf("Using difficulty = %d\n", difficulty);

  ioe_init();

  Blockchain bChain(difficulty);
	printf("Mining block 1...\n");
	bChain.AddBlock(1, "Block 1 Data");

	printf("Mining block 2...\n");
	bChain.AddBlock(2, "Block 2 Data");

	printf("Mining block 3...\n");
	bChain.AddBlock(3, "Block 3 Data");

	return 0;
}
