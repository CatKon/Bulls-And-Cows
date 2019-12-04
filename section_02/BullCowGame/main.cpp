#include<iostream>
#include<string>

using namespace std;
void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();


// pocz¹tek naszej aplikacji
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	cout << endl;

	return	0;
}

void PlayGame()
{
	//Lopp for number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 3;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {
		string Guess = GetGuess();
		cout << "Your Guess was: " << Guess << endl;
		cout << endl;
	}
}

//poczatek gierki
void PrintIntro()
{

	constexpr int WORLD_LENGHT = 5; // dziêki temu mo¿emy na bierz¹co kontrolowaæ zmienn¹ nie musz¹c jej zmieniac w ka¿dym miejscu w kodzie gdzie chcemy jej u¿yæ
	cout << "Welcome to bulls and Cows, the wirdest game i've ever seen xD\n";
	cout << "So you realy try play of this? Ok, Then Lets start\n";
	cout << "Can you guess the " << WORLD_LENGHT;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}


// get a guess
string GetGuess()
{

	string Guess = "";
	cout << "Enter your Guess: ";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you wont play again? (y/n) ";
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

