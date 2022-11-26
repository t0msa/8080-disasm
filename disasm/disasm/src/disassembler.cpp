#include "disassembler.hpp"

#include <format>
#include <iostream>

#include "instruction.hpp"

namespace disasm {

    auto c_disassembler::display() const -> void {
        for ( const auto& instruction : m_parsed_instructions )
            util::print_color( instruction );
    }

    auto c_disassembler::parse_instructions() -> void {
        for ( auto i = 0u; i < m_raw_image.size(); ) {
            const auto& instruction_to_parse = instruction_table[m_raw_image[i]];

            switch ( instruction_to_parse.m_opcode ) {
            case 0x00:
                {
                    m_parsed_instructions.
                        emplace_back( std::move( std::format( "[col=dark_grey]{:04X}\t[col=yellow]{:02X}\t\t[col=light_blue]NOP\n", i,
                                                              instruction_to_parse.m_opcode ) ) );
                    break;
                }
            case 0x76:
                {
                    m_parsed_instructions.emplace_back(
                        std::move( std::format( "[col=dark_grey]{:04X}\t[col=yellow]{:02X}\t\t[col=light_blue]HLT\n", i,
                                                instruction_to_parse.m_opcode ) ) );
                    break;
                }
            case 0x40:
            case 0x41:
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
            case 0x46:
            case 0x47:
            case 0x48:
            case 0x49:
            case 0x4A:
            case 0x4B:
            case 0x4C:
            case 0x4D:
            case 0x4E:
            case 0x4F:
            case 0x50:
            case 0x51:
            case 0x52:
            case 0x53:
            case 0x54:
            case 0x55:
            case 0x56:
            case 0x57:
            case 0x58:
            case 0x59:
            case 0x5A:
            case 0x5B:
            case 0x5C:
            case 0x5D:
            case 0x5E:
            case 0x5F:
            case 0x60:
            case 0x61:
            case 0x62:
            case 0x63:
            case 0x64:
            case 0x65:
            case 0x66:
            case 0x67:
            case 0x68:
            case 0x69:
            case 0x6A:
            case 0x6B:
            case 0x6C:
            case 0x6D:
            case 0x6E:
            case 0x6F:
            case 0x70:
            case 0x71:
            case 0x72:
            case 0x73:
            case 0x74:
            case 0x75:
            case 0x77:
            case 0x78:
            case 0x79:
            case 0x7A:
            case 0x7B:
            case 0x7C:
            case 0x7D:
            case 0x7E:
            case 0x7F:
                {
                    const std::uint8_t destination_register = instruction_to_parse.m_opcode >> 3 & 0x7;
                    const std::uint8_t source_register = instruction_to_parse.m_opcode & 0x7;

                    m_parsed_instructions.emplace_back(
                        std::move( std::format( "[col=dark_grey]{:04X}\t[col=yellow]{:02X}\t\t[col=light_blue]MOV {}, {}\n", i,
                                                instruction_to_parse.m_opcode,
                                                register_table[destination_register % 8],
                                                register_table[source_register % 8] ) ) );
                    break;
                }
            case 0x80:
            case 0x81:
            case 0x82:
            case 0x83:
            case 0x84:
            case 0x85:
            case 0x86:
            case 0x87:
            case 0x88:
            case 0x89:
            case 0x8A:
            case 0x8B:
            case 0x8C:
            case 0x8D:
            case 0x8E:
            case 0x8F:
            case 0x90:
            case 0x91:
            case 0x92:
            case 0x93:
            case 0x94:
            case 0x95:
            case 0x96:
            case 0x97:
            case 0x98:
            case 0x99:
            case 0x9A:
            case 0x9B:
            case 0x9C:
            case 0x9D:
            case 0x9E:
            case 0x9F:
            case 0xA0:
            case 0xA1:
            case 0xA2:
            case 0xA3:
            case 0xA4:
            case 0xA5:
            case 0xA6:
            case 0xA7:
            case 0xA8:
            case 0xA9:
            case 0xAA:
            case 0xAB:
            case 0xAC:
            case 0xAD:
            case 0xAE:
            case 0xAF:
            case 0xB0:
            case 0xB1:
            case 0xB2:
            case 0xB3:
            case 0xB4:
            case 0xB5:
            case 0xB6:
            case 0xB7:
            case 0xB8:
            case 0xB9:
            case 0xBA:
            case 0xBB:
            case 0xBC:
            case 0xBD:
            case 0xBE:
            case 0xBF:
                {
                    const std::uint8_t instruction_index = instruction_to_parse.m_opcode >> 3 & 0x7;
                    const std::uint8_t target_register = instruction_to_parse.m_opcode & 0x7;

                    m_parsed_instructions.emplace_back( std::move( std::format(
                        "[col=dark_grey]{:04X}\t[col=yellow]{:02X}\t\t[col=light_blue]{} {}\n", i,
                        instruction_to_parse.m_opcode,
                        mapped_arithmetic_inst_table[instruction_index % 8],
                        register_table[target_register % 8] ) ) );
                    break;
                }
            case 0xC2:
            case 0xC3:
            case 0xCA:
            case 0xD2:
            case 0xDA:
            case 0xE2:
            case 0xEA:
            case 0xF2:
            case 0xFA:
                {
                    const std::uint16_t dst_address = m_raw_image[i + 2] << 8 | m_raw_image[i + 1];

                    if ( const bool jmp_bit = instruction_to_parse.m_opcode & 0x1; jmp_bit ) {
                        m_parsed_instructions.emplace_back( std::move( std::format(
                            "[col=dark_grey]{0:04X}\t[col=yellow]{1:02X} {2:02X} {3:02X}\t[col=light_blue]JMP {4:04X}h\n", i,
                            instruction_to_parse.m_opcode, m_raw_image[i + 1],
                            m_raw_image[i + 2], dst_address ) ) );
                    }
                    else {
                        const std::uint8_t instruction_index = instruction_to_parse.m_opcode >> 3 & 0x7;

                        m_parsed_instructions.emplace_back( std::move( std::format(
                            "[col=dark_grey]{0:04X}\t[col=yellow]{1:02X} {2:02X} {3:02X}\t[col=light_blue]{4} {5:04X}h\n", i,
                            instruction_to_parse.m_opcode,
                            m_raw_image[i + 1],
                            m_raw_image[i + 2],
                            mapped_jmp_inst_table[instruction_index % 8],
                            dst_address ) ) );
                    }
                    break;
                }
            case 0xC4:
            case 0xCC:
            case 0xD4:
            case 0xDC:
            case 0xE4:
            case 0xEC:
            case 0xF4:
            case 0xFC:
                {
                    const std::uint16_t dst_address = m_raw_image[i + 2] << 8 | m_raw_image[i + 1];

                    if ( const bool call_bit = instruction_to_parse.m_opcode & 0x1; call_bit ) {
                        m_parsed_instructions.emplace_back( std::move( std::format(
                            "[col=dark_grey]{0:04X}\t[col=yellow]{1:02X} {2:02X} {3:02X}\t[col=light_blue]CALL {4:04X}h\n", i,
                            instruction_to_parse.m_opcode, m_raw_image[i + 1],
                            m_raw_image[i + 2], dst_address ) ) );
                    }
                    else {
                        const std::uint8_t instruction_index = instruction_to_parse.m_opcode >> 3 & 0x7;

                        m_parsed_instructions.emplace_back( std::move( std::format(
                            "[col=dark_grey]{0:04X}\t[col=yellow]{1:02X} {2:02X} {3:02X}\t[col=light_blue]{4} {5:04X}h\n", i,
                            instruction_to_parse.m_opcode, m_raw_image[i + 1],
                            m_raw_image[i + 2],
                            mapped_call_inst_table[instruction_index % 8],
                            dst_address ) ) );
                    }
                    break;
                }
            case 0xC0:
            case 0xC8:
            case 0xD0:
            case 0xD8:
            case 0xE0:
            case 0xE8:
            case 0xF0:
            case 0xF8:
                {
                    if ( const bool ret_bit = instruction_to_parse.m_opcode & 0x1; ret_bit ) {
                        m_parsed_instructions.emplace_back( std::move( std::format(
                            "[col=dark_grey]{:04X}\t[col=yellow]{:02X}\t\t[col=light_blue]RET\n", i, instruction_to_parse.m_opcode ) ) );
                    }
                    else {
                        const std::uint8_t instruction_index = instruction_to_parse.m_opcode >> 3 & 0x7;

                        m_parsed_instructions.emplace_back( std::move( std::format(
                            "[col=dark_grey]{:04X}\t[col=yellow]{:02X}\t\t[col=light_blue]{}\n", i, instruction_to_parse.m_opcode,
                            mapped_ret_inst_table[instruction_index % 8] ) ) );
                    }
                    break;
                }
            case 0xC6:
            case 0xCE:
            case 0xD6:
            case 0xDE:
            case 0xE6:
            case 0xEE:
            case 0xF6:
            case 0xFE:
                {
                    const std::uint8_t instruction_index = instruction_to_parse.m_opcode >> 3 & 0x7;
                    const std::uint8_t target_register = instruction_to_parse.m_opcode & 0x7;

                    m_parsed_instructions.emplace_back( std::move( std::format(
                        "[col=dark_grey]{0:04X}\t[col=yellow]{1:02X} {2:02X}\t\t[col=light_blue]{3} {4}, {2:02X}h\n", i,
                        instruction_to_parse.m_opcode,
                        m_raw_image[i + 1],
                        mapped_imm_arithmetic_inst_table[instruction_index % 8],
                        register_table[target_register % 8] ) ) );
                    break;
                }
            default:
                m_parsed_instructions.
                    emplace_back( std::move( std::format( "[col=dark_grey]{:04X}\t[col=yellow]{:02X}\t\t[col=light_blue]N/A\n", i,
                                                          instruction_to_parse.m_opcode ) ) );
                break;
            }

            i += instruction_to_parse.m_length;
        }
    }
}
