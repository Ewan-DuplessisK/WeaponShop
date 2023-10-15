#include "Monster.h"

Monster::Monster(string name, string desc, int maxHealth, vector<Attack> moves, int defence, Weapon weapon, int money, int health):Creature(name, desc, maxHealth, moves, defence, health = -1) {
	mWeapon = weapon;
	mMoney = money;
}

Weapon Monster::getWeapon() { return mWeapon; }
int Monster::getMoney() { return mMoney; }
void Monster::setWeapon(Weapon newWeapon) { mWeapon = newWeapon; }
void Monster::setMoney(int newMoney) { mMoney = newMoney; }
void Monster::attack(Creature& target, int moveIndex) {
	if (moveIndex == -1) {
		mWeapon.resolve(target);
	}else mMoveSet.at(moveIndex).resolve(target);
}
