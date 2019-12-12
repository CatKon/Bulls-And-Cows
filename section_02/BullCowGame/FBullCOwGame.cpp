#include "FBullCOwGame.h"

using int32 = int;

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;

	MyMaxTries = MAX_TRIES;
	
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	bGameIsWon = false;

	return;
}

// recives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	
	MyCurrentTry++;
	FBullCowCount BullCowCount;



	// loop through all letters in the Hidden word
	int32 WordLength = MyHiddenWord.length();// assuming same length as guess

	for (int32 HWChar = 0; HWChar < WordLength; HWChar++) {
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {

			if (Guess[GChar] == MyHiddenWord[HWChar]) {
				
				if (HWChar == GChar) {// if they match then 
					BullCowCount.Bulls++;

					}
				else {
					BullCowCount.Cows++;// must be a cow
					}
				
				}
			}
		}
	if (BullCowCount.Bulls == WordLength) 
	{
		bGameIsWon = true;
	}
	else 
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

FBullCowGame::FBullCowGame() { Reset();}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }



EGuessStatus FBullCowGame::CheckGuessValidiaty(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if(false){
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}







	// if the guess isn;t  an isogram
		// return an error
	// if the guess isn;t all lowercase
		//return error
	//
}