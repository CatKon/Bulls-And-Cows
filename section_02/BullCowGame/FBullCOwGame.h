#pragma once
#include <string>



class FBullCowGame
{
public:

	FBullCowGame(); // Constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidiaty(std::string);// -||-
	void Reset(); // to do make a mroe rich return value

	//previde a method for counting bulls & cows, and incresing turn #


// please try and ignore this and focus on the interface above
private:
	// constructors for inicialization
	int MyCurrentTry;
	int MyMaxTries;
};