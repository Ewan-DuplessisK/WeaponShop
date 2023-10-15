#include "Merchant.h"
#include <cmath>

Merchant::Merchant(string name, string shopName, string description, string catchphrase, int money, vector<Weapon> inventory) {
	mName = name;
	mShopName = shopName;
	mDescription = description;
	mCatchphrase = catchphrase;
	mMoney = money;
	mInventory = inventory;
}
Merchant::~Merchant() {}
string Merchant::getName() { return mName; }
string Merchant::getShopName() { return mShopName; }
string Merchant::getIntroduction() { return "Hello traveller, and welcome to " + mShopName + " I\'m " + mName + " " + mCatchphrase; }
string Merchant::getDescription() { return mDescription; }
vector<Weapon> Merchant::getInventory() { return mInventory; }


void Merchant::sell(Character& character, int weaponIndex) {
	int charMoney = character.getMoney();
	float trueCost = (int)floor(mInventory[weaponIndex].getCost() * (0.2f + mInventory[weaponIndex].getDurability()));
	if (charMoney >= trueCost) {
		character.add(mInventory[weaponIndex]);
		mInventory.erase(mInventory.begin() + weaponIndex);//TODO risque de suppression chez le perso, verifier si copie ou pointeur
		character.setMoney(charMoney - trueCost);
		mMoney += trueCost;
	}
}
void Merchant::buy(Character& character,int weaponIndex) {
	int trueCost = (int)floor(character.getWeapon().getCost() * character.getWeapon().getDurability());
	if (mMoney >= trueCost) {
		mInventory.push_back(character.remove(weaponIndex));
		character.setMoney(character.getMoney() + trueCost);
		mMoney -= trueCost;
	}
}
