#pragma once
#include <string>
#include <map>
enum Races {
	HUMAN,
	ELF,
	ORC,
	DWARF
};

const std::map<Races, std::string> races = { {HUMAN,"human"},{ELF,"elf"},{ORC,"orc"},{DWARF,"dwarf"} };