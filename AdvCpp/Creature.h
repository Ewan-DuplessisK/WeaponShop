#pragma once
#include <string>
#include <vector>
#include "Attack.h"
#include "Weapon.h"
using namespace std;

class Creature
{
protected:
	string mName;
	string mDescription;
	int mHealthPoints;
	int mMaxHealth;
	vector<Attack> mMoveSet;
	int mDefenceScore;

public:
	Creature(string name, string desc, int maxHealth=100, vector<Attack> moves= {}, int defence=10, int health = -1);
	Creature();
	~Creature();

	string getName();
	void setHealthPoints(int newHealth);
	int getHealthPoints();
	int getDefenceScore();
	int getMaxHealth();

	void attack(Creature& creature,int moveIndex);
};

