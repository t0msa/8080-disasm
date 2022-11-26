#include <iostream>

#include "disassembler.hpp"

#include "util.hpp"

int main( int argc, char* argv[] ) {
    disasm::c_disassembler disasm("C:\\Users\\tomiz\\Desktop\\invaders.bin");
    
    disasm.parse_instructions();
    disasm.display();
    
    std::cin.get();
    return 0;
}
