#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disasm.h"
#include <llvm-c/Disassembler.h>
#include <stdint.h>
#include <inttypes.h>
#include "llvm-c/ExternC.h"
#include "llvm-c/Target.h"
void dasm(char *asm_str, int size, uint32_t inst, uint32_t pc) {
    // 使用 RISC-V 32 位目标 triple，实际可根据需要调整 triple 和 CPU 参数
      // 初始化目标和MC组件，确保反汇编器能正常工作
    LLVMInitializeAllTargetInfos();
    LLVMInitializeAllTargets();
    LLVMInitializeAllTargetMCs();
    LLVMInitializeAllAsmPrinters();
		    LLVMInitializeAllDisassemblers();
const char *triple = "riscv32-unknown-linux-gnu";
LLVMDisasmContextRef dc = LLVMCreateDisasmCPU(triple,"", NULL, 0, NULL, NULL);
		// 创建 LLVM 反汇编上下文（这里不启用符号回调）

		if (!dc) {
        snprintf(asm_str, size, "ERROR: failed to create disasm context");
        return;
    }
    
    // 将 32 位指令转换为 4 字节数组（注意小端格式）
    uint8_t bytes[4];
    bytes[0] = inst & 0xff;
    bytes[1] = (inst >> 8) & 0xff;
    bytes[2] = (inst >> 16) & 0xff;
    bytes[3] = (inst >> 24) & 0xff;
    
    // 调用 LLVMDisasmInstruction 进行反汇编
    size_t inst_size = LLVMDisasmInstruction(dc, bytes, 4, (uint64_t)pc, asm_str, size);
    if (inst_size == 0) {
        // 如果反汇编失败，则输出 unknown
        snprintf(asm_str, size, "unknown");
    }
    
    LLVMDisasmDispose(dc);
}

