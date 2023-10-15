#pragma once
#include "Creature.h"

class Monster: public Creature{
private:
	Weapon mWeapon;
	int mMoney;

public:
	Monster();
	~Monster();
	Monster(string name, string desc, int maxHealth, vector<Attack> moves, int defence, Weapon weapon, int money, int health = -1);
	Weapon getWeapon();
	void setWeapon(Weapon newWeapon);
	int getMoney();
	void setMoney(int newMoney);
	void attack(Creature& target, int moveIndex);
};

