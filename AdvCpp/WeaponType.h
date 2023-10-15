#pragma once
#include <string>
#include <map>
enum WeaponType {
	DEFAULT,
	SWORD,
	BOW,
	STAFF,
	MACE,
	WAND,
	OTHER
};

const std::map<WeaponType, std::string> weaponName = { {STAFF,"staff"},{DEFAULT,"default"},{SWORD,"sword"},{BOW,"dagger"},{MACE,"mace"},{WAND,"wand"}};