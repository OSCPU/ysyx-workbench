#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"

#define MAX_DIFFICULTY 9 //难度值设置3基本上秒出结果，4可以看出差距，5大约要等2分钟左右。
#define MAXBLOCK 10

class Blockchain {
public:
	Blockchain(int difficulty);//默认构造函数
	void AddBlock(uint32_t nIndexIn, const char* sDataIn);//增加区块函数
private:
  char _diffStr[MAX_DIFFICULTY + 3];
	Block _vChain[MAXBLOCK];//保存区块的变量
  int _nrBlock;
};
#endif
