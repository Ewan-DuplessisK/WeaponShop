#include <cstdlib>
#include <iostream>
#include "Character.h"

Character::Character(string firstName, string lastName, string catchPhrase, int money, int maxHealth, vector<Attack> moves,Races race, CharacterClasses characterClass, int defence, Weapon weapon,int health): Creature(lastName,"A "+races.at(race)+" "+characterClasses.at(characterClass),maxHealth,moves,defence,health) {
	mFirstName = firstName;
	mCatchPhrase = catchPhrase;
	mMoney = money;
	mRace = race;
	mCharacterClass = characterClass;
	mWeapon = weapon;
	mInventory = {};
}

Character::Character(string firstName, string lastName, string catchPhrase, int money, Races race, CharacterClasses characterClass, int health = -1, vector<Attack> addMoves = {},Weapon weapon=Weapon(WeaponType::DEFAULT)) : Creature(lastName,"tempdesc") {
	switch (characterClass) {
	case WARRIOR:
		mMaxHealth = 100;
		mHealthPoints = 100;
		mDefenceScore = 10;
		mMoveSet = { Attack("Cleave",new int[2] { 3,4 },DamageType::SLASHING,3), Attack("Wide slash",new int[2] { 2,3 },DamageType::SLASHING,8),Attack("Thrust",new int[2] { 2,12 },DamageType::PIERCING,2) };
		mWeapon =(weapon.getType()!=WeaponType::DEFAULT)?weapon:Weapon("Basic sword", WeaponType::SWORD, 3, 20, 1.0f, new int[2]{1, 6});
		break;
	case ARCHER:
		mMaxHealth=80;
		mHealthPoints=80;
		mDefenceScore=6;
		mMoveSet= {Attack("Three shots",new int[2]{3,2},DamageType::PIERCING,4),Attack("Snipe",new int[2]{1,8},DamageType::PIERCING,8),Attack("Arrows rain",new int[2]{8,2},DamageType::PIERCING,4)};
		mWeapon =(weapon.getType()!=WeaponType::DEFAULT)?weapon:Weapon("Training bow",WeaponType::BOW,2,15,1.0f,new int[2]{2,2});
		break;
	case BARBARIAN:
		mMaxHealth = 120;
		mHealthPoints = 120;
		mDefenceScore = 8;
		mMoveSet= { Attack("Mace swing",new int[2] { 3,4 },DamageType::BLUDGEONING,2), Attack("Sucker punch",new int[2] { 2,3 },DamageType::BLUDGEONING,8),Attack("WAAAGHH",new int[2] { 8,6 },DamageType::BLUDGEONING,0) };
		mWeapon=(weapon.getType()!=WeaponType::DEFAULT)?weapon:Weapon("Small club",WeaponType::MACE,3,20,1.0f,new int[2]{1,6});
		break;
	case PRIEST:
		mMaxHealth=60;
		mHealthPoints=60;
		mDefenceScore=5;
		mMoveSet={Attack("Heal (self)",new int[2]{4,4},DamageType::HEALING,19)};
		mWeapon= (weapon.getType()!=WeaponType::DEFAULT)?weapon:Weapon("Worn out staff",WeaponType::STAFF,3,25,1.0f,new int[2]{2,4});
		break;
	}
	mFirstName=firstName;
	mName=lastName;
	mCatchPhrase=catchPhrase;
	mMoney=money;
	mRace=race;
	mCharacterClass=characterClass;
	mDescription="a "+races.at(race)+" "+characterClasses.at(characterClass);
	if(addMoves.size()>0){
		mMoveSet.insert(mMoveSet.end(),addMoves.begin(),addMoves.end());
	}
}

Character::~Character() {};

string Character::getFirstName() { return mFirstName; }
string Character::getLastName() { return getName(); }
string Character::introduction() { return "Hello I\'m " + mFirstName + " " + mName + ". " + mCatchPhrase; }
int Character::getMoney() { return mMoney; }
void Character::setMoney(int newMoney) {mMoney = newMoney; }
Races Character::getRace() { return mRace; }
CharacterClasses Character::getCharacterClass() { return mCharacterClass; }
Weapon Character::getWeapon() { return mWeapon; }

int Character::fight(Creature& target) {
	cout << "You are fighting " + target.getName() << endl;
	cout << "What do you want to do ?" << endl;
	cout << "1: Normal attack" << endl;
	cout << "2: Special moves" << endl;
	cout << "Choice:";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		 mWeapon.resolve(target);
		return 0;
	case 2:
		int moveChoice;
		do {
			cout << displayMoves();
			cout << "Choice:";
			cin >> moveChoice;
			if (moveChoice<1 || moveChoice > mMoveSet.size()) {
				cout << "invalid input" << endl;
			}
			else {
				if(mMoveSet.at(moveChoice - 1).getDamageType()==DamageType::HEALING){
					mMoveSet.at(moveChoice - 1).resolve(*this);
				}
				else mMoveSet.at(moveChoice - 1).resolve(target);
			}
			
		} while (moveChoice<1 || moveChoice > mMoveSet.size());
		return 1;
	default:
		return -1;
	}
}

void Character::loot(Character& character) {
	setMoney(getMoney() + character.getMoney());
	character.setMoney(0);
	mInventory.push_back(character.getWeapon());
}

void Character::loot(Monster& monster) {
	setMoney(getMoney() + monster.getMoney());
	mInventory.push_back(monster.getWeapon());
}

void Character::add(Weapon weapon) {
	mInventory.push_back(weapon);
}
string Character::displayMoves() {
	string moveText="";
	for (int i = 0; i < mMoveSet.size(); i++) {
		Attack move = mMoveSet.at(i);
		moveText += to_string(i + 1) + ": " + move.getLabel() + " (" + to_string(move.getDamage()[0]) + "d" + to_string(move.getDamage()[1]) + ")\n";
	}
	return moveText;
}

void Character::attack(Creature& target, int moveIndex) {
	if (moveIndex == -1) {
		mWeapon.resolve(target);
	}
	else mMoveSet.at(moveIndex).resolve(target);
}

vector<Weapon> Character::getInventory() { return mInventory; }
Weapon Character::remove(int weaponIndex) {
	Weapon weap = mInventory.at(weaponIndex);
	mInventory.erase(mInventory.begin()+weaponIndex);
	return weap;
}

void Character::openInventory() {
	cout << "Your health: " + mHealthPoints << endl;
	cout << "Your money: " + mMoney << endl;
	cout << "Your current weapon: "+ mWeapon.getName() + " remaining durability : " + to_string(mWeapon.getDurability()) + " cost: " + to_string(mWeapon.getCost())<< endl;
	cout << "Your inventory:" << endl;
	int index = 1;
	for (Weapon weapon : mInventory) {
		cout << to_string(index) + ": " + weapon.getName() + " remaining durability : " + to_string(weapon.getDurability()) + " cost: " + to_string((int)floor(weapon.getCost() * (0.2f + weapon.getDurability()))) << endl;
		index++;
	}
	cout << "1. Switch weapon" << endl;
	cout << "2. Leave inventory" << endl;
	int choice;
	cout << "Choice:";
	cin >> choice;
	if (choice == 1) {
		cout << "Which weapon do you want to use ?" << endl;
		int wChoice;
		cout << "Choice:";
		cin >> wChoice;
		mInventory.push_back(mWeapon);
		mWeapon = remove(wChoice - 1);
		return;
	}
	else return;
}