// MarcoLoPiccolo_Lab10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>      //Preprocessor directive
#include <string>         //allows us to use string type and string class functions
using namespace std;     //allows us to use all functions in namespace std without needing std: in front of a function

class WeaponType {             //Creates a parent class that is a weapon type for something like in a videogame
protected:
	string weaponName;         //The protected values are the name of the weapon as type string and the rarity of the weapon as a string
	string rarity;             //protected allows the child classes to access these variables when calling the functions below

public:                          //Public functions that can access the protected variables
	WeaponType(string n) {        //Constructor function that has input parameter n which then sets the weapon name
		weaponName = n;
	}

	void setName(string n) {       //Mutator functions allows the user to change the name after the fact using string n and then gets set in the weaponname protected variable
		weaponName = n;
	}

	string getName() const {        //Accessor function returns the weaponName saved in the class
		return weaponName;
	}

	void setRarity(string r) {      //Mutator function allows the user to set a rarity of a weapon with input string r and then sets in the rarity protected variable
		rarity = r;
	}

	string getRarity() const {       //Accessor function that returns the rarity variable saved in the class
		return rarity;
	}
	
};

class LongBow : public WeaponType{    //Declares child class that has the ": public WeaponType" notation to allow access to the public functions in WeaponType

private:
	double range;        //Private variables of range and damage of the bow that are set by public functions
	double damage;

public:
	LongBow(string n, double r, double d) : WeaponType(n) {        //Constructor that has inputs of n which uses the parent class constructor to automatically set the name
		range = r;                                                 //with the other two variables being r which sets the value for range and d for setting damage
		damage = d;
	}

	void setRange(double r) {                  //mutator and accessor functions that set the range with input r and then can output the new range which is const since that will be unchanging
		range = r;
	}

	double getRange() const {
		return range;
	}

	void setDamage(double d) {             //mutator and accessor functions that set the damage with input d and then can output the new damage which is const since that will be unchanging
		damage = d;
	}

	double getDamage() const {
		return damage;
	}
};

class LongSword : public WeaponType {    //Declares child class that has the ": public WeaponType" notation to allow access to the public functions in WeaponType

private:
	double range;                    //Private variables of range, damage, and heavy damage of the sword that are set by public functions
	double damage;
	double heavyDamage;

public:
	LongSword(string n, double r, double d, double hd) : WeaponType(n) {  //Constructor that has inputs of n which uses the parent class constructor to automatically set the name
		range = r;                                                        //with the other three variables being r which sets the value for range and d for setting damage and hd for setting heavy damage
		damage = d;
		heavyDamage = hd;
	}

	void setRange(double r) {             //mutator and accessor functions that set the range with input r and then can output the new range which is const since that will be unchanging
		range = r;
	}

	double getRange() const {
		return range;
	}

	void setDamage(double d) {            //mutator and accessor functions that set the damage with input d and then can output the new damage which is const since that will be unchanging
		damage = d;
	}

	double getDamage() const {
		return damage;
	}

	void setHeavyDamage(double hd) {       //mutator and accessor functions that set the heavy damage with input hd and then can output the new heavy damage which is const since that will be unchanging
		heavyDamage = hd;
	}

	double getHeavyDamage() const {
		return heavyDamage;
	}

};

int main()
{
	LongBow L("DragonSlayer", 10, 10);         //Declares a variable of class type LongBow with L being called as a placeholder, since the constructor was created above then the name, range, and damage is input
	LongSword S("NightBringer", 3, 13, 26);
	//Declares a variable of class type LongSword with S being called as a placeholder, since the constructor was created above then the name, range, damage, and heavy damage is input

	cout << "The name of the LongBow you picked up is " << L.getName()                                    //Outputs a message as if you just picked a new weapon in a videogame which uses both the parent and child
		<< " and it has range of " << L.getRange() << " and the damage is " << L.getDamage() << endl;     //classes

	L.setName("Inquisitor");            //uses parent class mutator functions to set a new name and set the rarity of the weapon
	L.setRarity("Very Rare");
	L.setRange(20);                    //uses child class mutator functions to set the range and the damage
	L.setDamage(20);
	
	cout << "The new name of the LongBow you upgraded is " << L.getName()          //Outputs the changes using both the parent and child classes with their accessor functions, 
		<< " and it has range of " << L.getRange() << " and the damage is "        //it is output as if you just upgraded the weapon
		<< L.getDamage() << ". It has a rarity of " << L.getRarity() << endl; 

	cout << "The name of the LongSword you picked up is " << S.getName()                         //Outputs a message as if you just picked a new weapon in a videogame which uses both the parent and child
		<< " and it has range of " << S.getRange() << " and the damage is " << S.getDamage() <<  //classes
		". It's special heavy damage is " << S.getHeavyDamage() << endl;

	S.setName("Executioner's Blade");      //uses parent and child class's mutator functions to change the stats of the weapon along with the name and rarity
	S.setRarity("Legendary");
	S.setRange(5);
	S.setDamage(20);
	S.setHeavyDamage(40);

	cout << "The new name of the LongSword you picked up is " << S.getName()                     //Outputs the changes using both the parent and child classes with their accessor functions, 
		<< " and it has range of " << S.getRange() << " and the damage is " << S.getDamage() <<  //it is output as if you just upgraded the weapon
		". It's special heavy damage is " << S.getHeavyDamage() <<
		" and it's new rarity is " << S.getRarity() << endl;

	system("Pause");
	return 0;
}


