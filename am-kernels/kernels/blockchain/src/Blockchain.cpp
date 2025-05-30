#include <klib.h>
#include "Blockchain.h"

Blockchain::Blockchain(int difficulty) {
	_vChain[0].block_init(0, "Genesis Block", "");
  _nrBlock = 1;
  assert(difficulty <= MAX_DIFFICULTY);
  memset(_diffStr, '0', difficulty); //填充数组，使数组的前difficulty位都为0，作为难度。
	_diffStr[difficulty] = '\0';
}

void Blockchain::AddBlock(uint32_t nIndexIn, const char *sDataIn) {
  assert(_nrBlock < MAXBLOCK);
  Block *b = &_vChain[_nrBlock];
  b->block_init(nIndexIn, sDataIn, _vChain[_nrBlock - 1].GetHash());
	b->MineBlock(_diffStr);
  _nrBlock ++;
}
