// AdvCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include "Merchant.h"
#include "Character.h"
using namespace std;

int inputHandler() {
    int num;
    while (cout << "Choice: " && !(cin >> num)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input" << endl;
    }
    return num;
}

Character startup() {
    cout << "Welcome adventurer, let me ask a few questions about yourself" << endl;
    cout << "What is your first name ?" << endl;
    string firstName;
    getline(cin, firstName);
    cout << "Okay. What is your last name ?" << endl;
    string lastName;
    getline(cin, lastName);
    cout << "Good. What would be your catchphrase ?" << endl;
    string catchPhrase;
    getline(cin, catchPhrase);
    cout << "Nice one. And how much money do you carry right now ?" << endl;
    int money = inputHandler();
    cout<< "What is your race ?"<<endl;
    cout<< "1. Human   2. Elf\n3. Orc   4. Dwarf"<<endl;
    int choice=inputHandler();
    while(choice<1 || choice>4){
        cout<<"Invalid input"<<endl;
        choice=inputHandler();
    }
    Races race;
    switch(choice){
        case 1:
        race = Races::HUMAN;
        break;
        case 2:
        race = Races::ELF;
        break;
        case 3:
        race=Races::ORC;
        break;
        case 4:
        race =Races::DWARF;
        break;
    }
    cout<< "And last but not least. What is your class ?"<<endl;
    cout<< "1. Warrior   2. Archer\n3. Barbarian   4. Priest"<<endl;
    choice=inputHandler();
    while(choice<1 || choice>4){
        cout<<"Invalid input"<<endl;
        choice=inputHandler();
    }
    CharacterClasses characterClass;
    switch(choice){
        case 1:
        characterClass = CharacterClasses::WARRIOR;
        break;
        case 2:
        characterClass = CharacterClasses::ARCHER;
        break;
        case 3:
        characterClass = CharacterClasses::BARBARIAN;
        break;
        case 4:
        characterClass = CharacterClasses::PRIEST;
        break;
    }
    return Character(firstName, lastName, catchPhrase, money, race, characterClass, -1,{}, Weapon(WeaponType::DEFAULT));

}

void characterInteraction(Character& character, Character& playerCharacter) {
    cout << endl;
    if (character.getHealthPoints() <= 0) {
        cout << character.getFirstName() + " " + character.getLastName() + " is lying dead on the ground"<<endl;
        cout << "1: Loot"<<endl;
        cout << "2: Leave" << endl;
        int choice=inputHandler();
        if (choice == 1) {
            playerCharacter.loot(character);
        }
        else return;
    }
    else {
        cout << character.introduction() << endl;
        cout << "1: Fight" << endl;
        cout << "2: Leave" << endl;
        int choice = inputHandler();
        if (choice == 1) {
            playerCharacter.fight(character);
            character.attack(playerCharacter,-1);
            cout << "Your HP: " + to_string(playerCharacter.getHealthPoints()) + "   Your weapon\'s durability: " + to_string(playerCharacter.getWeapon().getDurability()) << endl;
        }
        else return;
    }
}

void merchantInteraction(Merchant& merchant, Character& playerCharacter) {
    cout << endl;
    cout << merchant.getIntroduction()<<endl;
    cout << merchant.getName() + "\'s wares:"<<endl;
    int index = 1;
    for (Weapon weapon : merchant.getInventory()) {
        cout << to_string(index) + ": " + weapon.getName() + " remaining durability : " + to_string(weapon.getDurability()) + " cost: " + to_string((int)floor(weapon.getCost() * (0.2f + weapon.getDurability()))) << endl;
        index++;
    }
    cout << endl;
    cout << "1: Buy a weapon" << endl;
    cout << "2: Sell a weapon" << endl;
    cout << "3: Go back" << endl;
    int choice = inputHandler();
    if (choice == 1) {
        cout << "Which weapon do you want to buy ?" << endl;
        cout << to_string(index)+": Go back" << endl;
        int wChoice = inputHandler();
        if (wChoice <= merchant.getInventory().size() && wChoice > 0) {
            merchant.sell(playerCharacter, wChoice - 1);
        }
        else return;
    }
    else if (choice == 2) {
        cout << "Which of your weapon do you want to sell ?" << endl;
        int wChoice = inputHandler();
        merchant.buy(playerCharacter,wChoice-1);
    }
    else return;
}

int main()
{
    srand(time(0));
    Character playerCharacter = startup();
    Character dummy = Character("Training", "Dummy", "Gimme your best shot", 0, 100000, vector<Attack>{}, Races::DWARF, CharacterClasses::BARBARIAN, 0, Weapon(WeaponType::DEFAULT), -1);
    Character corpse = Character("Loot", "Goblin", "", 101, 0, vector<Attack>{},Races::ORC,CharacterClasses::ARCHER,0, Weapon("Le baton",WeaponType::STAFF, 3, 20, 0.56f,new int[2]{1,4}));
    Merchant merchant = Merchant("Jabba", "Jabba\'s hut", "nondescript", "I don\'t have much and I\'ll rip you off", 350, { Weapon("Steel sword",WeaponType::SWORD, 4, 30, 0.7f,new int [2,4]),Weapon("Longbow",WeaponType::BOW, 2, 20, 0.56f,new int[2]{2,3})});

    bool game = true;
    while (game) {
        cout << endl;
        cout << "1:" + dummy.getFirstName() + " " + dummy.getLastName() + ((dummy.getHealthPoints()<=0)?" (dead)":"") << endl;
        cout << "2:" + corpse.getFirstName() + " " + corpse.getLastName() + ((corpse.getHealthPoints() <= 0) ? " (dead)" : "") << endl;
        cout << "3:" + merchant.getName() << endl;
        cout << "4: Open inventory" << endl;
        cout << "5: exit game" << endl;
        cout << "Who do you want to interact with ?" << endl;
        int choice = inputHandler();
        switch (choice) {
        case 1: {characterInteraction(dummy, playerCharacter); break; }
        case 2: {characterInteraction(corpse, playerCharacter); break; }
        case 3: {merchantInteraction(merchant,playerCharacter); break; }
        case 4: {playerCharacter.openInventory(); break; }
        default: game = false;
        }
    }
    cout << "Exiting" << endl;
}




