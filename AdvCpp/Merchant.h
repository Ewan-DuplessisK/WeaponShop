#pragma once
#include "Weapon.h"
#include "Character.h"
#include <vector>
using namespace std;

class Merchant
{
private:
	string mName;
	string mShopName;
	string mDescription;
	string mCatchphrase;
	int mMoney;
	vector<Weapon> mInventory;

public: 
	Merchant(string name, string shopName,string description,string catchphrase, int money, vector<Weapon> inventory);
	~Merchant();
	string getName();
	string getShopName();
	string getIntroduction();
	string getDescription();
	vector<Weapon> getInventory();
	void sell(Character& character, int weaponIndex);
	void buy(Character& character,int weaponIndex);
};

