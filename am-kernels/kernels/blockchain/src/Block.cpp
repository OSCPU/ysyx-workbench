#include <klib.h>
#include <klib-macros.h>
#include "Block.h"
#include "sha256.h"

void Block::block_init(uint32_t nIndexIn, const char *sDataIn, const char *sPrevHashIn) {
  _nIndex = nIndexIn;
  _sData = sDataIn;
  _sPrevHash = sPrevHashIn;
	_nNonce = -1;//Nounce设置为-1
	_tTime = io_read(AM_TIMER_UPTIME).us / 1000000;//设置时间
}

const char* Block::GetHash() { //返回哈希值函数的实现
	return _sHash;
}

void Block::MineBlock(const char *diffStr) { //挖矿函数，参数为难度值。
	int nDifficulty = strlen(diffStr);
	do {
		_nNonce++;
		_CalculateHash(_sHash);
	} while (memcmp(_sHash, diffStr, nDifficulty) != 0);
	//要寻找一个Nounce使得总体哈希值的前n位的0（即0的个数）和难度值的个数相同，则挖矿成功。
	printf("Block mined:%s\n", _sHash);
}

inline void Block::_CalculateHash(char *buf) {
  static char str[1024];
  sprintf(str, "%d%d%s%d%s", _nIndex, _tTime, _sData, _nNonce, _sPrevHash);
  sha256(buf, str);
  sha256(buf, buf);
}
