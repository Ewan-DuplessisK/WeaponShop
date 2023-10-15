#include <iostream>
#include "Creature.h"

Creature::Creature(string name, string desc, int maxHealth, vector<Attack> moves, int defence, int health) {
	mName = name;
	mDescription = desc;
	mMaxHealth = maxHealth;
	mHealthPoints = (health == -1) ? maxHealth : health;
	mMoveSet = moves;
	mDefenceScore = defence;
}

Creature::Creature() {}
Creature::~Creature() {}

string Creature::getName() { return mName; }
int Creature::getMaxHealth(){return mMaxHealth;}
void Creature::setHealthPoints(int newHealth) { mHealthPoints = newHealth; }
int Creature::getHealthPoints() { return mHealthPoints; }
int Creature::getDefenceScore() { return mDefenceScore; }

void Creature::attack(Creature& target,int moveIndex) {
	mMoveSet.at(moveIndex).resolve(target);
}