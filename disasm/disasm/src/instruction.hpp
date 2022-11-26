#pragma once

#include <cstddef>
#include <cstdint>

namespace disasm {
    struct instruction_t {
        std::uint8_t m_opcode;
        std::size_t m_length;
    };

    constexpr inline const char* register_table[8] = {
        "B",
        "C",
        "D",
        "E",
        "H",
        "L",
        "M",
        "A"
    };

    constexpr inline const char* mapped_arithmetic_inst_table[8] = {
        "ADD",
        "ADC",
        "SUB",
        "SBB",
        "ANA",
        "XRA",
        "ORA",
        "CMP",
    };

    constexpr inline const char* mapped_imm_arithmetic_inst_table[8] = {
        "ADI",
        "ACI",
        "SUI",
        "SBI",
        "ANI",
        "XRI",
        "ORI",
        "CPI"
    };

    constexpr inline const char* mapped_jmp_inst_table[8] = {
        "JNZ",
        "JZ",
        "JNC",
        "JC",
        "JPO",
        "JPE",
        "JP",
        "JM"
    };

    constexpr inline const char* mapped_call_inst_table[8] = {
        "CNZ",
        "CZ",
        "CNC",
        "CC",
        "CPO",
        "CPE",
        "CP",
        "CM"
    };

    constexpr inline const char* mapped_ret_inst_table[8] = {
        "RNZ",
        "RZ",
        "RNC",
        "RC",
        "RPO",
        "RPE",
        "RP",
        "RM"
    };

    constexpr inline instruction_t instruction_table[256] = {
        { .m_opcode = 0x00, .m_length = 1 }, // NOP
        { .m_opcode = 0x01, .m_length = 3 }, // LXI B, D16
        { .m_opcode = 0x02, .m_length = 1 }, // STAX B
        { .m_opcode = 0x03, .m_length = 1 }, // INX B
        { .m_opcode = 0x04, .m_length = 1 }, // INR B
        { .m_opcode = 0x05, .m_length = 1 }, // DCR B
        { .m_opcode = 0x06, .m_length = 2 }, // MVI B, D8
        { .m_opcode = 0x07, .m_length = 1 }, // RLC
        { .m_opcode = 0x08, .m_length = 1 }, // NOP
        { .m_opcode = 0x09, .m_length = 1 }, // DAD B
        { .m_opcode = 0x0A, .m_length = 1 }, // LDAX B
        { .m_opcode = 0x0B, .m_length = 1 }, // DCX B
        { .m_opcode = 0x0C, .m_length = 1 }, // INR C
        { .m_opcode = 0x0D, .m_length = 1 }, // DCR C
        { .m_opcode = 0x0E, .m_length = 2 }, // MVI C, D8
        { .m_opcode = 0x0F, .m_length = 1 }, // RRC
        { .m_opcode = 0x10, .m_length = 1 }, // NOP
        { .m_opcode = 0x11, .m_length = 3 }, // LXI D, D16
        { .m_opcode = 0x12, .m_length = 1 }, // STAX D
        { .m_opcode = 0x13, .m_length = 1 }, // INX D
        { .m_opcode = 0x14, .m_length = 1 }, // INR D
        { .m_opcode = 0x15, .m_length = 1 }, // DCR D
        { .m_opcode = 0x16, .m_length = 3 }, // MVI D, D8
        { .m_opcode = 0x17, .m_length = 1 }, // RAL
        { .m_opcode = 0x18, .m_length = 1 }, // NOP
        { .m_opcode = 0x19, .m_length = 1 }, // DAD D
        { .m_opcode = 0x1A, .m_length = 1 }, // LDAX D
        { .m_opcode = 0x1B, .m_length = 1 }, // DCX D
        { .m_opcode = 0x1C, .m_length = 1 }, // INR E
        { .m_opcode = 0x1D, .m_length = 1 }, // DCR E
        { .m_opcode = 0x1E, .m_length = 2 }, // MVI E, D8
        { .m_opcode = 0x1F, .m_length = 1 }, // RAR
        { .m_opcode = 0x20, .m_length = 1 }, // NOP
        { .m_opcode = 0x21, .m_length = 3 }, // LXI E, D16
        { .m_opcode = 0x22, .m_length = 3 }, // SHLD A16
        { .m_opcode = 0x23, .m_length = 1 }, // INX H
        { .m_opcode = 0x24, .m_length = 1 }, // INR H
        { .m_opcode = 0x25, .m_length = 1 }, // DCR H
        { .m_opcode = 0x26, .m_length = 2 }, // MVI H, D8
        { .m_opcode = 0x27, .m_length = 1 }, // DAA
        { .m_opcode = 0x28, .m_length = 1 }, // NOP
        { .m_opcode = 0x29, .m_length = 1 }, // DAD H
        { .m_opcode = 0x2A, .m_length = 3 }, // LHLD A16
        { .m_opcode = 0x2B, .m_length = 1 }, // DCX H
        { .m_opcode = 0x2C, .m_length = 1 }, // INR L
        { .m_opcode = 0x2D, .m_length = 1 }, // DCR L
        { .m_opcode = 0x2E, .m_length = 2 }, // MVI L, D8
        { .m_opcode = 0x2F, .m_length = 1 }, // CMA
        { .m_opcode = 0x30, .m_length = 1 }, // NOP
        { .m_opcode = 0x31, .m_length = 3 }, // LXI SP, D16
        { .m_opcode = 0x32, .m_length = 3 }, // STA A16
        { .m_opcode = 0x33, .m_length = 1 }, // INX SP
        { .m_opcode = 0x34, .m_length = 1 }, // INR M
        { .m_opcode = 0x35, .m_length = 1 }, // DCR M
        { .m_opcode = 0x36, .m_length = 2 }, // MVI M, D8
        { .m_opcode = 0x37, .m_length = 1 }, // STC
        { .m_opcode = 0x38, .m_length = 1 }, // NOP
        { .m_opcode = 0x39, .m_length = 1 }, // DAD SP
        { .m_opcode = 0x3A, .m_length = 3 }, // LDA A16
        { .m_opcode = 0x3B, .m_length = 1 }, // DCX SP
        { .m_opcode = 0x3C, .m_length = 1 }, // INR A
        { .m_opcode = 0x3D, .m_length = 1 }, // DCR A
        { .m_opcode = 0x3E, .m_length = 2 }, // MVI A, D8
        { .m_opcode = 0x3F, .m_length = 1 }, // CMC

        { .m_opcode = 0x40, .m_length = 1 }, // MOV B, B
        { .m_opcode = 0x41, .m_length = 1 }, // MOV B, C
        { .m_opcode = 0x42, .m_length = 1 }, // MOV B, D
        { .m_opcode = 0x43, .m_length = 1 }, // MOV B, E
        { .m_opcode = 0x44, .m_length = 1 }, // MOV B, H
        { .m_opcode = 0x45, .m_length = 1 }, // MOV B, L
        { .m_opcode = 0x46, .m_length = 1 }, // MOV B, M
        { .m_opcode = 0x47, .m_length = 1 }, // MOV B, A

        { .m_opcode = 0x48, .m_length = 1 }, // MOV C, B
        { .m_opcode = 0x49, .m_length = 1 }, // MOV C, C
        { .m_opcode = 0x4A, .m_length = 1 }, // MOV C, D
        { .m_opcode = 0x4B, .m_length = 1 }, // MOV C, E
        { .m_opcode = 0x4C, .m_length = 1 }, // MOV C, H
        { .m_opcode = 0x4D, .m_length = 1 }, // MOV C, L
        { .m_opcode = 0x4E, .m_length = 1 }, // MOV C, M
        { .m_opcode = 0x4F, .m_length = 1 }, // MOV C, A

        { .m_opcode = 0x50, .m_length = 1 }, // MOV D, B
        { .m_opcode = 0x51, .m_length = 1 }, // MOV D, C
        { .m_opcode = 0x52, .m_length = 1 }, // MOV D, D
        { .m_opcode = 0x53, .m_length = 1 }, // MOV D, E
        { .m_opcode = 0x54, .m_length = 1 }, // MOV D, H
        { .m_opcode = 0x55, .m_length = 1 }, // MOV D, L
        { .m_opcode = 0x56, .m_length = 1 }, // MOV D, M
        { .m_opcode = 0x57, .m_length = 1 }, // MOV D, A

        { .m_opcode = 0x58, .m_length = 1 }, // MOV E, B
        { .m_opcode = 0x59, .m_length = 1 }, // MOV E, C
        { .m_opcode = 0x5A, .m_length = 1 }, // MOV E, D
        { .m_opcode = 0x5B, .m_length = 1 }, // MOV E, E
        { .m_opcode = 0x5C, .m_length = 1 }, // MOV E, H
        { .m_opcode = 0x5D, .m_length = 1 }, // MOV E, L
        { .m_opcode = 0x5E, .m_length = 1 }, // MOV E, M
        { .m_opcode = 0x5F, .m_length = 1 }, // MOV E, A

        { .m_opcode = 0x60, .m_length = 1 }, // MOV H, B
        { .m_opcode = 0x61, .m_length = 1 }, // MOV H, C
        { .m_opcode = 0x62, .m_length = 1 }, // MOV H, D
        { .m_opcode = 0x63, .m_length = 1 }, // MOV H, E
        { .m_opcode = 0x64, .m_length = 1 }, // MOV H, H
        { .m_opcode = 0x65, .m_length = 1 }, // MOV H, L
        { .m_opcode = 0x66, .m_length = 1 }, // MOV H, M
        { .m_opcode = 0x67, .m_length = 1 }, // MOV H, A

        { .m_opcode = 0x68, .m_length = 1 }, // MOV L, B
        { .m_opcode = 0x69, .m_length = 1 }, // MOV L, C
        { .m_opcode = 0x6A, .m_length = 1 }, // MOV L, D
        { .m_opcode = 0x6B, .m_length = 1 }, // MOV L, E
        { .m_opcode = 0x6C, .m_length = 1 }, // MOV L, H
        { .m_opcode = 0x6D, .m_length = 1 }, // MOV L, L
        { .m_opcode = 0x6E, .m_length = 1 }, // MOV L, M
        { .m_opcode = 0x6F, .m_length = 1 }, // MOV L, A

        { .m_opcode = 0x70, .m_length = 1 }, // MOV M, B
        { .m_opcode = 0x71, .m_length = 1 }, // MOV M, C
        { .m_opcode = 0x72, .m_length = 1 }, // MOV M, D
        { .m_opcode = 0x73, .m_length = 1 }, // MOV M, E
        { .m_opcode = 0x74, .m_length = 1 }, // MOV M, H
        { .m_opcode = 0x75, .m_length = 1 }, // MOV M, L
        { .m_opcode = 0x76, .m_length = 1 }, // HLT
        { .m_opcode = 0x77, .m_length = 1 }, // MOV M, A

        { .m_opcode = 0x78, .m_length = 1 }, // MOV A, B  
        { .m_opcode = 0x79, .m_length = 1 }, // MOV A, C
        { .m_opcode = 0x7A, .m_length = 1 }, // MOV A, D
        { .m_opcode = 0x7B, .m_length = 1 }, // MOV A, E
        { .m_opcode = 0x7C, .m_length = 1 }, // MOV A, H
        { .m_opcode = 0x7D, .m_length = 1 }, // MOV A, L
        { .m_opcode = 0x7E, .m_length = 1 }, // MOV A, M
        { .m_opcode = 0x7F, .m_length = 1 }, // MOV A, A

        { .m_opcode = 0x80, .m_length = 1 }, // ADD B
        { .m_opcode = 0x81, .m_length = 1 }, // ADD C
        { .m_opcode = 0x82, .m_length = 1 }, // ADD D
        { .m_opcode = 0x83, .m_length = 1 }, // ADD E
        { .m_opcode = 0x84, .m_length = 1 }, // ADD H
        { .m_opcode = 0x85, .m_length = 1 }, // ADD L
        { .m_opcode = 0x86, .m_length = 1 }, // ADD M
        { .m_opcode = 0x87, .m_length = 1 }, // ADD A

        { .m_opcode = 0x88, .m_length = 1 }, // ADC B
        { .m_opcode = 0x89, .m_length = 1 }, // ADC C
        { .m_opcode = 0x8A, .m_length = 1 }, // ADC D
        { .m_opcode = 0x8B, .m_length = 1 }, // ADC E
        { .m_opcode = 0x8C, .m_length = 1 }, // ADC H
        { .m_opcode = 0x8D, .m_length = 1 }, // ADC L
        { .m_opcode = 0x8E, .m_length = 1 }, // ADC M
        { .m_opcode = 0x8F, .m_length = 1 }, // ADC A

        { .m_opcode = 0x90, .m_length = 1 }, // SUB B
        { .m_opcode = 0x91, .m_length = 1 }, // SUB C
        { .m_opcode = 0x92, .m_length = 1 }, // SUB D
        { .m_opcode = 0x93, .m_length = 1 }, // SUB E
        { .m_opcode = 0x94, .m_length = 1 }, // SUB H
        { .m_opcode = 0x95, .m_length = 1 }, // SUB L
        { .m_opcode = 0x96, .m_length = 1 }, // SUB M
        { .m_opcode = 0x97, .m_length = 1 }, // SUB A

        { .m_opcode = 0x98, .m_length = 1 }, // SBB B
        { .m_opcode = 0x99, .m_length = 1 }, // SBB C
        { .m_opcode = 0x9A, .m_length = 1 }, // SBB D
        { .m_opcode = 0x9B, .m_length = 1 }, // SBB E
        { .m_opcode = 0x9C, .m_length = 1 }, // SBB H
        { .m_opcode = 0x9D, .m_length = 1 }, // SBB L
        { .m_opcode = 0x9E, .m_length = 1 }, // SBB M
        { .m_opcode = 0x9F, .m_length = 1 }, // SBB A

        { .m_opcode = 0xA0, .m_length = 1 }, // ANA B
        { .m_opcode = 0xA1, .m_length = 1 }, // ANA C
        { .m_opcode = 0xA2, .m_length = 1 }, // ANA D
        { .m_opcode = 0xA3, .m_length = 1 }, // ANA E
        { .m_opcode = 0xA4, .m_length = 1 }, // ANA H
        { .m_opcode = 0xA5, .m_length = 1 }, // ANA L
        { .m_opcode = 0xA6, .m_length = 1 }, // ANA M
        { .m_opcode = 0xA7, .m_length = 1 }, // ANA A

        { .m_opcode = 0xA8, .m_length = 1 }, // XRA B
        { .m_opcode = 0xA9, .m_length = 1 }, // XRA C
        { .m_opcode = 0xAA, .m_length = 1 }, // XRA D
        { .m_opcode = 0xAB, .m_length = 1 }, // XRA E
        { .m_opcode = 0xAC, .m_length = 1 }, // XRA H
        { .m_opcode = 0xAD, .m_length = 1 }, // XRA L
        { .m_opcode = 0xAE, .m_length = 1 }, // XRA M
        { .m_opcode = 0xAF, .m_length = 1 }, // XRA A

        { .m_opcode = 0xB0, .m_length = 1 }, // ORA B
        { .m_opcode = 0xB1, .m_length = 1 }, // ORA C
        { .m_opcode = 0xB2, .m_length = 1 }, // ORA D
        { .m_opcode = 0xB3, .m_length = 1 }, // ORA E
        { .m_opcode = 0xB4, .m_length = 1 }, // ORA H
        { .m_opcode = 0xB5, .m_length = 1 }, // ORA L
        { .m_opcode = 0xB6, .m_length = 1 }, // ORA M
        { .m_opcode = 0xB7, .m_length = 1 }, // ORA A

        { .m_opcode = 0xB8, .m_length = 1 }, // CMP B
        { .m_opcode = 0xB9, .m_length = 1 }, // CMP C
        { .m_opcode = 0xBA, .m_length = 1 }, // CMP D
        { .m_opcode = 0xBB, .m_length = 1 }, // CMP E
        { .m_opcode = 0xBC, .m_length = 1 }, // CMP H
        { .m_opcode = 0xBD, .m_length = 1 }, // CMP L
        { .m_opcode = 0xBE, .m_length = 1 }, // CMP M
        { .m_opcode = 0xBF, .m_length = 1 }, // CMP A

        { .m_opcode = 0xC0, .m_length = 1 }, // RNZ
        { .m_opcode = 0xC1, .m_length = 1 }, // POP B
        { .m_opcode = 0xC2, .m_length = 3 }, // JNZ A16
        { .m_opcode = 0xC3, .m_length = 1 }, // JMP A16
        { .m_opcode = 0xC4, .m_length = 3 }, // CNZ A16
        { .m_opcode = 0xC5, .m_length = 1 }, // PUSH B
        { .m_opcode = 0xC6, .m_length = 2 }, // ADI D8
        { .m_opcode = 0xC7, .m_length = 1 }, // RST 0
        { .m_opcode = 0xC8, .m_length = 1 }, // RZ
        { .m_opcode = 0xC9, .m_length = 1 }, // RET
        { .m_opcode = 0xCA, .m_length = 3 }, // JZ A16
        { .m_opcode = 0xCB, .m_length = 3 }, // *JMP A16 (alternative opcode for jmp)
        { .m_opcode = 0xCC, .m_length = 3 }, // CZ A16
        { .m_opcode = 0xCD, .m_length = 3 }, // CALL A16
        { .m_opcode = 0xCE, .m_length = 2 }, // ACI D8
        { .m_opcode = 0xCF, .m_length = 1 }, // RST 1
        { .m_opcode = 0xD0, .m_length = 1 }, // RNC
        { .m_opcode = 0xD1, .m_length = 1 }, // POP D
        { .m_opcode = 0xD2, .m_length = 3 }, // JNC A16
        { .m_opcode = 0xD3, .m_length = 2 }, // OUT D8
        { .m_opcode = 0xD4, .m_length = 3 }, // CNC A16
        { .m_opcode = 0xD5, .m_length = 1 }, // PUSH D
        { .m_opcode = 0xD6, .m_length = 2 }, // SUI D8
        { .m_opcode = 0xD7, .m_length = 1 }, // RST 2
        { .m_opcode = 0xD8, .m_length = 1 }, // RC
        { .m_opcode = 0xD9, .m_length = 1 }, // *RET (alternative opcode for ret)
        { .m_opcode = 0xDA, .m_length = 3 }, // JC A16
        { .m_opcode = 0xDB, .m_length = 2 }, // IN D8
        { .m_opcode = 0xDC, .m_length = 3 }, // CC A16
        { .m_opcode = 0xDD, .m_length = 3 }, // *CALL A16 (alternative opcode for call)
        { .m_opcode = 0xDE, .m_length = 2 }, // SBI D8
        { .m_opcode = 0xDF, .m_length = 1 }, // RST 3
        { .m_opcode = 0xE0, .m_length = 1 }, // RPO
        { .m_opcode = 0xE1, .m_length = 1 }, // POP H
        { .m_opcode = 0xE2, .m_length = 3 }, // JPO A16
        { .m_opcode = 0xE3, .m_length = 1 }, // XTHL
        { .m_opcode = 0xE4, .m_length = 3 }, // CPO A16
        { .m_opcode = 0xE5, .m_length = 1 }, // PUSH H
        { .m_opcode = 0xE6, .m_length = 2 }, // ANI D8
        { .m_opcode = 0xE7, .m_length = 1 }, // RST 4
        { .m_opcode = 0xE8, .m_length = 1 }, // RPE
        { .m_opcode = 0xE9, .m_length = 1 }, // PCHL
        { .m_opcode = 0xEA, .m_length = 3 }, // JPE A16
        { .m_opcode = 0xEB, .m_length = 1 }, // XCHG
        { .m_opcode = 0xEC, .m_length = 3 }, // CPE A16
        { .m_opcode = 0xED, .m_length = 3 }, // *CALL A16 (alternative opcode for call)
        { .m_opcode = 0xEE, .m_length = 2 }, // XRI D8
        { .m_opcode = 0xEF, .m_length = 1 }, // RST 5
        { .m_opcode = 0xF0, .m_length = 1 }, // RP
        { .m_opcode = 0xF1, .m_length = 1 }, // POP PSW
        { .m_opcode = 0xF2, .m_length = 3 }, // JP A16
        { .m_opcode = 0xF3, .m_length = 1 }, // DI
        { .m_opcode = 0xF4, .m_length = 3 }, // CP A16
        { .m_opcode = 0xF5, .m_length = 1 }, // PUSH PSW
        { .m_opcode = 0xF6, .m_length = 2 }, // ORI D8
        { .m_opcode = 0xF7, .m_length = 1 }, // RST 6
        { .m_opcode = 0xF8, .m_length = 1 }, // RM
        { .m_opcode = 0xF9, .m_length = 1 }, // SPHL
        { .m_opcode = 0xFA, .m_length = 3 }, // JM A16
        { .m_opcode = 0xFB, .m_length = 1 }, // EI
        { .m_opcode = 0xFC, .m_length = 3 }, // CM A16
        { .m_opcode = 0xFD, .m_length = 3 }, // *CALL A16 (alternative opcode for call)
        { .m_opcode = 0xFE, .m_length = 2 }, // CPI D8
        { .m_opcode = 0xFF, .m_length = 1 }, // RST 7
    };
}
