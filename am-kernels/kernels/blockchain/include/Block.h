#ifndef BLOCK_H
#define BLOCK_H

#include <stdint.h>
#include "sha256.h"

//创建区块类
class Block {
public:
  Block() { }
	void block_init(uint32_t nIndexIn, const char* sDataIn, const char* sPrevHashIn);
	const char* GetHash();//返回哈希值
	void MineBlock(const char* diffStr);//挖矿

private:
	uint32_t _nIndex;//区块索引值，第几个区块，从0开始计算
	uint32_t _nNonce;//区块随机数
	const char *_sData;//区块描述字符
	char _sHash[2 * SHA256::DIGEST_SIZE + 1];//区块Hash值
	const char *_sPrevHash;//前一个区块的哈希值
	uint32_t _tTime;//区块生成时间
	void _CalculateHash(char *buf);//计算Hash值
};
#endif
