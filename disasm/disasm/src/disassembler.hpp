#pragma once

#include "util.hpp"

#include <cassert>

namespace disasm {
    class c_disassembler {
    public:
        explicit c_disassembler( const std::filesystem::path& path ) {

                const auto read_image = util::read_binary_file_into_memory( path );
                assert( read_image.has_value() !=  );
                m_raw_image = read_image.value();
        }

        auto display() const -> void;
        auto parse_instructions() -> void;

    private:
        std::vector<std::string> m_parsed_instructions;
        std::vector<std::uint8_t> m_raw_image;
    };
}
