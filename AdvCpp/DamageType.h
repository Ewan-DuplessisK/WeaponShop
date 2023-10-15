#pragma once
#include <string>
#include <map>
enum DamageType {
	BLUDGEONING,
	PIERCING,
	SLASHING,
	HEALING
};

const std::map<DamageType, std::string> damageName = { {BLUDGEONING,"bludgeoning"},{PIERCING,"piercing"},{SLASHING,"slashing"},{HEALING,"healing"}};