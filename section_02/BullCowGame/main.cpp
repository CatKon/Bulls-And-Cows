#include<iostream>
#include<string>
#include "FBullCOwGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;


// pocz¹tek naszej aplikacji
int main()
{
	std::cout << BCGame.GetCurrentTry();

	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	std::cout << std::endl;

	return	0;
}

void PlayGame()
{

	BCGame.Reset();
	int MaxTryies = BCGame.GetMaxTries(); 
	std::cout << MaxTryies << std::endl;

	//Lopp for number of turns asking for guesses
	for (int count = 1; count <= MaxTryies; count++) {
		std::string Guess = GetGuess(); //TODO make loop checking valid

		//submit valid gues to the game
		//print nymber of bulls and cows

		std::cout << "Your Guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	//TODO summarise game
}

//poczatek gierki
void PrintIntro()
{

	constexpr int WOLD_LENGHT = 5; // dziêki temu mo¿emy na bierz¹co kontrolowaæ zmienn¹ nie musz¹c jej zmieniac w ka¿dym miejscu w kodzie gdzie chcemy jej u¿yæ
	std::cout << "Welcome to bulls and Cows, the wirdest game i've ever seen xD\n";
	std::cout << "So you realy try play of this? Ok, Then Lets start\n";
	std::cout << "Can you guess the " << WOLD_LENGHT;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


// get a guess
std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << " Enter your Guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you wont play again? (y/n) ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

