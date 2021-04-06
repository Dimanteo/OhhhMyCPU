#pragma once
#include "../linker.h"
#include <vector>
#include <string>

class Core;

class Insn
{
    CMD_CODE m_code;
    bool m_isBranch;
    int m_argc;
    std::vector<word_t> m_argv;
    std::string opcode;

    using execFunc_t = void (*)(Core *core);
    execFunc_t m_exec;

    public:
        void exec(Core *core) const;
        void decode(const char *pc);
        bool isBranch() const;
        int argc() const;
        word_t getArg(int argi) const;
};