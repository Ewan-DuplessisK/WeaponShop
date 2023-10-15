#pragma once
#include <string>
#include <map>
enum CharacterClasses {
	WARRIOR,
	ARCHER,
	BARBARIAN,
	PRIEST
};

const std::map<CharacterClasses, std::string> characterClasses = { {WARRIOR,"warrior"},{ARCHER,"archer"},{BARBARIAN,"barbarian"},{PRIEST,"priest"} };