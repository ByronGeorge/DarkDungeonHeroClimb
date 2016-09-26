// Practice1.cpp : Defines the entry point for the console application.
//

/* 
8/22/2016 || Idea for short story rpg 
	1 class, 4 weapon types, 1 armor type, 20 weapons (5 weapons per type), 10 sets of armor, items, 4 legendary pieces
	Experience/Levels maybe, No stats, Maybe implement a battle floor system 
	
	Going to begin by programming the character creation
		consists of : name and starting weapon type

8/23/2016 || Character creation progress
	Made functions that allow for character creation. The character information is stored into a vector name is position 0, weapon type is position 1

8/25/2016 || Character creation progress
	Making the armors for the character. Going to store the 10 pieces into an array. Still need to figure out how the players receives the armor.
	*UPDATE* Player receives a "starting" armor based on what weapon type they chose. As Player progresses They unlock more armors

8/27/2016 || Character creation progress
	Finished the character creation function which creates a character with starting dialogue. Everything is set in this function so nothing has to be put into
	the main except this one function. Character information consists of name, weapon type, and HP 

8/29/2016 || WeaponSkills class creation
	Just made the weapon skills class. Decided to ditch the 20 weapons idea and just give each weapon type its own unique skill set
	As the player levels up they will unlock more skills in their "Skill Vector". GOing to make it so the player can have only a few skills at time
	Going to have to implement some resource system and a skill that generates those resources.

8/29/2016 || WeaponSkills progress
	Made function that takes in player level and weapon type to assign skills. This part is going to take a bit

8/30/2016 || WeaponSkills Progress
	FInished skills up to level 12 because doing them all will take awhile. Want to start adding values to the attacks and testing it 

8/31/2016 || WeaponSkills Progress
	Figured out base damage algorithim. Applying to every weapon. For dual wield cutting damage in half and letting user attack twice
	

*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <time.h>
#include <stdlib.h>

//This class deals with the character and character creation
class Character {

	int health, level;
	std::string name, weaponType, armor;	//created variables to store name and weapontype info, and armor
	std::vector<std::string> character;		//vector that stores the character information
	

public:
	void chooseWeaponType(std::string arr[], int choice);		//function header for choosing weapon type. Acts like a setter function
	std::string getWeaponType();								//function header for getting the weapon type string
	void setName(std::string n);								//function header for setting character name
	std::string getName();										//function header for getting the character name string
	void setCharacterInformationVector();						//function header for setting the character vector	
	std::vector<std::string> getCharacterInformationVector();	//function header for getting the character vector
	void chooseArmorType(std::string arr[]);
	std::string getArmor();
	void setHealth(int x);
	int getHealth();	
	std::string convertIntToString(int x);
	void characterCreation();
	void setLevel(int x);
	int getLevel();

};

//function that takes in an array and integer to determine what weapon type the user wants
void Character::chooseWeaponType(std::string arr[], int choice)
{
	
	//using if statements to determine the selection and setting waepon type to the choice in the array
	//array is static
	if (choice == 1)
	{
		this->weaponType = arr[0];
		
	}
	else if (choice == 2)
	{
		this->weaponType = arr[1];
	}
	else if (choice == 3)
	{
		this->weaponType = arr[2];
	}
	else if (choice == 4)
	{
		this->weaponType = arr[3];
	}

	
}

void Character::chooseArmorType(std::string arr[])
{
	if (this->weaponType.compare("Greatsword") == 0 || this->weaponType.compare("Sword and Shield") == 0)
	{
		this->armor = arr[0];
	}
	else if (this->weaponType.compare("Dual-Wield") == 0)
	{
		this->armor = arr[1];
	}
	else
	{
		this->armor = arr[4];
	}
}

std::string Character::getArmor()
{
	return armor;
}

//Function that sets the characters name
void Character::setName(std::string n)
{
	this->name = n;
}

//function to return the characters name since private variables
std::string Character::getName()
{
	return name;
}

//Function that puts the characters name and weapon type into a vector
void Character::setCharacterInformationVector()
{
	
	this->character.clear();
	this->character.push_back(getName());
	this->character.push_back(getWeaponType());
	this->character.push_back(getArmor());
	this->character.push_back(convertIntToString(getHealth()));
	this->character.push_back(convertIntToString(getLevel()));

	std::cout << "Character created successfully!\n";
	

}

//Function that returns the character information vector
std::vector<std::string> Character::getCharacterInformationVector()
{
	return character;
}

//function that returns the characters weapon type
std::string Character::getWeaponType()
{
	return weaponType;
}

void Character::setHealth(int x)
{
	this->health = x;
}

int Character::getHealth()
{
	return health;
}

std::string Character::convertIntToString(int x)
{
	std::string  s = std::to_string(x);

	return s;
}

//Function that guides user through character creation process
void Character::characterCreation()
{
	int menuSelect;
	std::string enter;

	std::cout << "Welcome to Dank Dungeons! Enter any key to begin... " << std::endl;
	std::cin >> enter;
	std::cout << "1. Continue Game\n" << "2. New Game\n" << "3. Exit Game" << std::endl;

	std::cin >> menuSelect;

	if (menuSelect == 1)
	{
		//
	}
	else if (menuSelect == 2)
	{
		//creates new game
		int wepSelect;
		std::string weaponTypes[4] = { "Sword and Shield", "Greatsword", "Bow", "Dual-Wield" };
		std::string Armor[10] = { "Bronze" , "Flakked Leather" , "Steel" , "Obsidian" , "Huntsman" , "Barbarian" , "Berserker" , "Ranger", "Savage", "Celestial" };

		std::cout << "New Player? Tell us your name!\n";
		std::cin >> this->name;

		std::cout << "Greetings " << getName() << "!\n"; 
		std::cout << "What kind of weapon do you see your self starting with?\n" << "1. Sword and Shield\n" << "2. Greatsword\n"
			<< "3. Bow\n" << "4. Dual-Wield\n";
		
		std::cin >> wepSelect;

		chooseWeaponType(weaponTypes, wepSelect);
		chooseArmorType(Armor);
		setHealth(50);
		setLevel(1);

		std::cout << "Ahhh classic " << getWeaponType() << ". With your weapon you are given the " << getArmor() << " armor!\n"
			<< "Even though you have a shiny new weapon and armor don't get ahead of yourself. Many dangers await in the DANKKKK DUNGEOOOOOONSS!!!\n";

		std::cout << "Creating Character please wait...";
		setCharacterInformationVector();
		
	}
	else
	{
		// breaks game loop
	}


}

void Character::setLevel(int x)
{
	this->level = x;
}

int Character::getLevel()
{
	return level;
}

class WeaponSkills : public Character
{
	int charLevel;
	int baseDamage;
	int skillDamage;
	std::vector<std::string>skills;

public:

	void setBaseDamage(int l, std::string wepType);
	std::vector<std::string> assignSkills(int level, std::string wepType);
	int baseDamageMultiplier(int l);
	int getBaseDamage();
	/*std::string skills[23] = { "Slash" , "Shoot", "Shield Bash", "Courageous Strike", "Reflect" , "Reversal" , "Shield Block", "Opprotunity" , //concludes short sword skills
		"Mighty Swing", "Sweeping Arc", "Beserker Stance" , "Mighty Slam" , "Shatter Earth", "Quake", //conldues greatSword abilities
		"Aimed Shot", "Steady Aim", "Power Shot", "Deadly Percision", "Volley", "Final Shot", "Shot from the heavens" , "LightningBolt", //Concludes bow abilities
		"Double-Slah" , "Wild Strike", "Dual Impale", "Pincir Strike", "Twin-Dragon Fangs", "Blade Frenzy", "X-Blade" }; //Concludes dual-wield abilities*/		
};

std::vector<std::string> WeaponSkills::assignSkills(int l, std::string wepType)
{
	
	if (l >= 1)
	{
		if (wepType.compare("Bow") == 0)
		{
			this->skills.push_back("Shoot");
		}
		else if (wepType.compare("Bow") != 0)
		{
			this->skills.push_back("Slash");
		}
	}

	if (l >= 2)
	{
		if (wepType.compare("Bow") == 0)
		{
			this->skills.push_back("Steady Aim");
		}
		else if (wepType.compare("Sword and Shield") == 0)
		{
			this->skills.push_back("Courageous Strike");
		}
		else if (wepType.compare("Greatsword") == 0)
		{
			this->skills.push_back("Mighty Swing");
		}
		else if (wepType.compare("Dual-Wield") == 0)
		{
			this->skills.push_back("Wild Strike");
		}
	}
	if (l >= 5)
	{
		if (wepType.compare("Bow") == 0)
		{
			this->skills.push_back("Aimed Shot");
		}
		else if (wepType.compare("Sword and Shield") == 0)
		{
			this->skills.push_back("Shield Bash");
		}
		else if (wepType.compare("Greatsword") == 0)
		{
			this->skills.push_back("Sweeping Arc");
		}
		else if (wepType.compare("Dual-Wield") == 0)
		{
			this->skills.push_back("Pincir Strike");
		}
	}
	if (l >= 8)
	{
		if (wepType.compare("Bow") == 0)
		{
			this->skills.push_back("Deadly Precision");
		}
		else if (wepType.compare("Sword and Shield") == 0)
		{
			this->skills.push_back("Shield Block");
		}
		else if (wepType.compare("Greatsword") == 0)
		{
			this->skills.push_back("Berserker Stance");
		}
		else if (wepType.compare("Dual-Wield") == 0)
		{
			this->skills.push_back("Impale");
		}
	}
	if (l >= 12)
	{
		if (wepType.compare("Bow") == 0)
		{
			this->skills.push_back("Lightning Shot");
		}
		else if (wepType.compare("Sword and Shield") == 0)
		{
			this->skills.push_back("Opprotunity");
		}
		else if (wepType.compare("Greatsword") == 0)
		{
			this->skills.push_back("Earth Shatter");
		}
		else if (wepType.compare("Dual-Wield") == 0)
		{
			this->skills.push_back("Dragon Fangs");
		}
	}


	return skills;
}

void WeaponSkills::setBaseDamage(int l, std::string wep)
{
	if (wep.compare("Bow") == 0)
	{
		this->baseDamage = baseDamageMultiplier(l);
	}
}

int WeaponSkills::baseDamageMultiplier(int l)
{
	
	float mult = l * 0.5;
	mult = mult + 0.5;
	int multiplier = (int)mult;
	int baseDamage = ((rand() % 5) + 5) * multiplier;

	return baseDamage;
}

int WeaponSkills::getBaseDamage()
{
	return baseDamage;
}



int main()
{
	srand(time(NULL));

	std::vector<std::string> characterInfo;
	std::vector<std::string> skills;
	std::vector<std::string> * skillsPtr = &skills;
	std::vector<std::string> * cInfoPtr = &characterInfo;
	
	Character rando;
	WeaponSkills skilz;
	rando.characterCreation();

	
	*cInfoPtr = rando.getCharacterInformationVector();
	//*skillsPtr = skilz.assignSkills(1, rando.getWeaponType());
	*skillsPtr = skilz.assignSkills(2, rando.getWeaponType());

	skilz.setBaseDamage(3, rando.getWeaponType());

	


	std::cout << cInfoPtr->at(1) << std::endl;
	std::cout << cInfoPtr->at(2) << std::endl;
	std::cout << cInfoPtr->at(3) << std::endl;
	std::cout << cInfoPtr->at(4) << std::endl;
	std::cout << skillsPtr->at(0) << std::endl;
	std::cout << skillsPtr->at(1) << std::endl;
	std::cout << skilz.getBaseDamage() << std::endl;

	


	


	

    return 0;
}

