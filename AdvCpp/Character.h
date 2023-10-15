#pragma once
#include <string>
#include "Creature.h"
#include "Races.h"
#include "CharacterClasses.h"
#include "Monster.h"

using namespace std;
class Character:public Creature{
private:
	string mFirstName;
	string mCatchPhrase;
	int mMoney;
	Races mRace;
	CharacterClasses mCharacterClass;
	vector<Weapon> mInventory;
	Weapon mWeapon;

public:
	Character(string firstName, string lastName, string catchPhrase, int money, int maxHealth,vector<Attack> moves, Races race, CharacterClasses characterClass,int defence, Weapon weapon,int health=-1);
	Character(string firstName, string lastName, string catchPhrase, int money, Races race, CharacterClasses characterClass, int health, vector<Attack> addMoves, Weapon weapon);
	~Character();

	string getFirstName();
	string getLastName();
	string introduction();
	int getMoney();
	void setMoney(int newMoney);
	Races getRace();
	CharacterClasses getCharacterClass();
	Weapon getWeapon();
	void add(Weapon weapon);
	Weapon remove(int weaponIndex);
	vector<Weapon> getInventory();

	int fight(Creature& target);
	void loot(Character& target);
	void loot(Monster& target);
	string displayMoves();
	void openInventory();

	void attack(Creature& target, int moveIndex);

};

