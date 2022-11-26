#include <iostream>

#include "disassembler.hpp"

#include "util.hpp"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf_s("Usage: <file in>\n");
		return 0;
	}

	disasm::c_disassembler disasm(argv[1]);

	disasm.parse_instructions();
	disasm.display();

	std::cin.get();
	return 0;
}
