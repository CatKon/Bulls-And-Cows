#include "FBullCOwGame.h"

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8

	MyCurrentTry = 1;

	MyMaxTry = MAX_TRIES;
	


	return;
}

FBullCowGame::FBullCowGame() { Reset(); }

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidiaty(std::string)
{
	return false;
}
