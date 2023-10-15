#pragma once
#include "WeaponType.h"
#include <string>
using namespace std;

class Creature;
class Weapon {

private:
	string mName;
	WeaponType mType;
	int mWeight;
	int mCost;
	float mDurability;
	int* mDice;

public:
	Weapon(){}
	Weapon(string name,WeaponType type, int weight, int cost, float durability,int dice[2]);
	Weapon(WeaponType type);
	~Weapon();

	void resolve(Creature& target);
	string getName();
	WeaponType getType();
	int getWeight();
	int getCost();
	float getDurability();
	void setDurability(float newDurablity);
};