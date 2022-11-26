#pragma once

#include <Windows.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <unordered_map>
#include <vector>

namespace util {
    inline std::unordered_map<std::string_view, std::uint8_t> color_map = {
        { "black", 0 },
        { "dark_blue", 1 },
        { "green", 2 },
        { "light_blue", 3 },
        { "red", 4 },
        { "dark_purple", 5 },
        { "orange", 6 },
        { "default", 7 },
        { "dark_grey", 8 },
        { "blue", 9 },
        { "bright_green", 10 },
        { "turquoise", 11 },
        { "bright_red", 12 },
        { "bright_purple", 13 },
        { "yellow", 14 },
        { "white", 15 }
    };

    inline auto read_binary_file_into_memory( const std::filesystem::path& path ) -> std::optional<std::vector<std::uint8_t>> {
        std::ifstream file_in( path, std::ios::binary | std::ios::ate );

        if ( !file_in.good() )
            return std::nullopt;

        file_in.unsetf( std::ios::skipws );

        const auto file_size = static_cast<std::size_t>(file_in.tellg());

        file_in.seekg( std::ios::beg );

        std::vector<std::uint8_t> raw_data;

        raw_data.reserve( file_size );

        raw_data.insert( raw_data.begin(), std::istream_iterator<std::uint8_t>( file_in ), std::istream_iterator<std::uint8_t>() );
        return { raw_data };
    }

    inline auto print_color( const std::string_view formatted_message ) -> void {
        std::vector<std::string_view> parsed_message_parts;

        static HANDLE output_handle = GetStdHandle( STD_OUTPUT_HANDLE );

        std::size_t found_start = formatted_message.find( '[', 0 );

        auto last_found = found_start;

        if ( last_found != 0 )
            parsed_message_parts.emplace_back( formatted_message.substr( 0, last_found - 1 ) );

        while ( true ) {
            found_start = formatted_message.find( '[', last_found );

            last_found = found_start;

            if ( last_found != std::string_view::npos ) {
                last_found = formatted_message.find( "col=", last_found );

                parsed_message_parts.emplace_back(
                    formatted_message.substr( last_found, formatted_message.find( ']', last_found ) - last_found ) );
            }

            last_found = formatted_message.find( ']', last_found );

            if ( last_found != std::string_view::npos ) {
                parsed_message_parts.emplace_back(
                    formatted_message.substr( last_found + 1, formatted_message.find( '[', last_found ) - (last_found + 1) ) );
            }

            if ( formatted_message.find( '[', last_found + 1 ) == std::string_view::npos )
                break;
        }

        for ( const auto part : parsed_message_parts ) {

            if ( const std::size_t found_col = part.find( "col=" ); found_col != std::string_view::npos ) {
                const auto col = part.substr( found_col + 4, part.find( ']', found_col + 4 ) - (found_col + 4) );

                if ( color_map.find( col ) != color_map.end() ) {
                    SetConsoleTextAttribute( output_handle, color_map[col] );

                    // No need to do anything this iteration anymore.
                    continue;
                }
            }

            std::cout << part;
            SetConsoleTextAttribute( output_handle, 7 );
        }
    }
}
