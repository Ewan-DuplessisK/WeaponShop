#pragma once
#include <string>
#include "DamageType.h"
using namespace std;

class Creature;

class Attack
{
private:
	string mLabel;
	int* mDamage;
	DamageType mDamageType;
	int mAttackBonus;

public:
	Attack(string label, int damage[2], DamageType type, int bonus);
	Attack() {};
	~Attack() {};

	int* getDamage();
	string getLabel();
	DamageType getDamageType();

	void resolve(Creature& target);
};

