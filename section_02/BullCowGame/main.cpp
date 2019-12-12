/*This is the console executable, that makes use of the BullCow Class
This acts as the view in a MVC pattern, and is responsible for all 
user int32eraction.For game logic see the FBullCowGame class.*/

#include<iostream>
#include<string>
#include "FBullCOwGame.h"



using FText = std::string;
using int32 = int;

void Print32int32ro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;


// pocz¹tek naszej aplikacji
int main()
{
	std::cout << BCGame.GetCurrentTry();

	bool bPlayAgain = false;
	do {
		Print32int32ro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	std::cout << std::endl;

	return	0;
}

void PlayGame()
{

	BCGame.Reset();
	int32 MaxTryies = BCGame.GetMaxTries(); 
	std::cout << MaxTryies << std::endl;

	//Lopp for guesses
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTryies) {
		FText Guess = GetValidGuess(); 

		
		//submit valid gues to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << " Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
	}

	//TODO summarise game
}

//poczatek gierki
void Print32int32ro()
{

	constexpr int32 WOLD_LENGHT = 5; // dziêki temu mo¿emy na bierz¹co kontrolowaæ zmienn¹ nie musz¹c jej zmieniac w ka¿dym miejscu w kodzie gdzie chcemy jej u¿yæ
	std::cout << "Welcome to bulls and Cows, the wirdest game i've ever seen xD\n";
	std::cout << "So you realy try play of this? Ok, Then Lets start\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}



FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " Enter your Guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidiaty(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "please enter a " << BCGame.GetHiddenWordLength() << "Letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word witout repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Pleas enter all lowercase letters.\n";
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looking until we get no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you wont play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

