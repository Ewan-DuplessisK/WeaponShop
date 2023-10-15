#include "Weapon.h"
#include "Creature.h"

Weapon::Weapon(string name, WeaponType type, int weight, int cost, float durability, int dice[2]){
	mName = name;
	mType = type;
	mWeight = weight;
	mCost = cost;
	mDurability = durability;
	mDice = dice;
}

Weapon::Weapon(WeaponType type){
	if (type == WeaponType::DEFAULT) {
		mName = "fist";
		mType = type;
		mWeight = 1;
		mCost = 0;
		mDurability = 0;
		mDice = new int[2]{ 1,4 };
	}
}

Weapon::~Weapon() {};

string Weapon::getName() { return mName; }
WeaponType Weapon::getType() { return mType; }
int Weapon::getWeight() { return mWeight; };
int Weapon::getCost() { return mCost; };
float Weapon::getDurability() { return mDurability; };
void Weapon::setDurability(float newDurability) { mDurability = newDurability; }

void Weapon::resolve(Creature& target) {
	int dieThrow = rand() % 19 + 1;
	if (dieThrow >= target.getDefenceScore()) {
		int finalDamage = 0;
		for (int i = 0; i < mDice[0]; i++) {
			finalDamage += (rand() % (mDice[1] - 1) + 1);
		}
		target.setHealthPoints(target.getHealthPoints() - finalDamage);
	}
}