#include "Attack.h"
#include "Creature.h"

Attack::Attack(string label, int damage[2], DamageType type, int bonus)
{
	mLabel = label;
	mDamage = damage;
	mDamageType = type;
	mAttackBonus = bonus;
}

void Attack::resolve(Creature& target) {
	int dieThrow = rand() % 19 + 1;
	if (dieThrow + mAttackBonus >= target.getDefenceScore()) {
		int finalDamage = 0;
		for (int i = 0; i < mDamage[0]; i++) {
			finalDamage += (rand() % (mDamage[1] - 1) + 1);
		}
		if(mDamageType==DamageType::HEALING){
			target.setHealthPoints(min(target.getHealthPoints()+finalDamage,target.getMaxHealth()));
		}
		else target.setHealthPoints(target.getHealthPoints() - finalDamage);
	}
}

int* Attack::getDamage() { return mDamage; }
string Attack::getLabel() { return mLabel; }
DamageType Attack::getDamageType(){return mDamageType;}