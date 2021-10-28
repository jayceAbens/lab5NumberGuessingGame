/*
Jayce Abens
FA2021
Due : October 27, 2021
Lab 5 Number Guessing Game

Write a number-guessing game in which the computer selects a random number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
the end of each game, users should be told whether they won or lost, and then be asked whether they want to play again. When the user quits, the program should output the
total number of wins and losses. To make the game more interesting, the program should vary the wording of the messages that it outputs for winning, for losing, and for
asking for another game. Create 10 different messages for each of these cases, and use random numbers to choose among them. This application should use at least one Do-
While loop and at least one Switch statement. Write your C++ code using good style and documenting comments. You should use functions in your code as well. Your source
code file should be called Lab5.cpp.

*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int randomNumber(int max);
void printIntro();
void playGame(int& wins, int& losses);
void playAgain(bool& again, int wins_, int losses_);

using namespace std;

int main()
{
	int wins = 0;
	int losses = 0;
	bool again;

	do {
		printIntro();
		playGame(wins, losses);
		playAgain(again, wins, losses);
	} while (again);
	return 0;
}

int randomNumber(int max)
{
	srand(time(0)); //sets the current time as the seed for generating a psudo-random number
	return (rand() % max); // returns a random number 0-max
}

void printIntro()
{
	cout << "***** WELCOME TO THE NUMBER GUESSING GAME *****\n\n";
	cout << "A random number between 0 and 100 has been generated. You have 20 tries to guess it!\n\n";
}

void playGame(int& wins, int& losses)
{
	int randNum = randomNumber(101);
	int guess;

	cout << randNum << "\n\n";

	cout << "Enter your guesses bellow.\n";

	for (int attempt = 1; attempt <= 20; attempt++)
	{
		bool invalidGuess;
		do {
			cout << "\nGuess " << attempt << ": ";
			cin >> guess;
			if (guess < 0 || guess > 100)
			{
				cout << "\nYour guess was out of range. Try again between 0 and 100!\n";
				invalidGuess = true;
			}
			else invalidGuess = false;
		} while (invalidGuess == true);

		if (guess == randNum)
		{
			cout << endl;
			switch (randomNumber(10))
			{
			case 0: cout << "You guessed it!";
				break;
			case 1: cout << "Hip hip Huray! That was it!";
				break;
			case 2: cout << "How did you know? That's it!";
				break;
			case 3: cout << "Are you clairvoyant because that was it!";
				break;
			case 4: cout << "Want to play again?";
				break;
			case 5: cout << "Huraah!! You got it!";
				break;
			case 6: cout << "You better buy a lottery ticket because it's your lucky day! That's it!";
				break;
			case 7: cout << "1/101 and you got it!";
				break;
			case 8: cout << "You got it!";
				break;
			case 9: cout << "Congrats! You win!";
				break;
			}
			cout << endl << endl;
			wins++;
			break;
		}
		else if (attempt == 20)
		{
			cout << endl;
			switch (randomNumber(10))
			{
			case 0: cout << "That's all the guesses you get!";
				break;
			case 1: cout << "You're all out of guesses!";
				break;
			case 2: cout << "That's 20! You lose!";
				break;
			case 3: cout << "Nice try... if you were a todler! You lose!";
				break;
			case 4: cout << "You lose! Better luck next time!";
				break;
			case 5: cout << "Uh oh! Looks like you're out of guesses!";
				break;
			case 6: cout << "You lost.";
				break;
			case 7: cout << "Nice try! The number was " << randNum << "!";
				break;
			case 8: cout << "Almost! It was " << randNum << "!";
				break;
			case 9: cout << "The number was " << randNum << "!How could you not guess it!";
				break;
			}
			cout << endl << endl;
			losses++;
		}
	}
}

void playAgain(bool& again, int wins_, int losses_)
{
	switch (randomNumber(10))
	{
			case 0: cout << "Would you like to play again?";
				break;
			case 1: cout << "One more game?";
				break;
			case 2: cout << "Another game?";
				break;
			case 3: cout << "How about another round?";
				break;
			case 4: cout << "Want to play again?";
				break;
			case 5: cout << "Restart?";
				break;
			case 6: cout << "Again?";
				break;
			case 7: cout << "Ready for another round?";
				break;
			case 8: cout << "Want a new number and 20 more guesses?";
				break;
			case 9: cout << "Want to keep the guessing train rolling?";
				break;
	}
	cout << " (y/n)\n";

	string response;
	bool invalidResponse;
	do
	{
		cin >> response;
		if (response == "yes" ||
			response == "Yes" ||
			response == "YES" ||
			response == "y" ||
			response == "Y"
			)
		{
			again = true;
			invalidResponse = false;
		}
		else if (response == "no" ||
			response == "No" ||
			response == "NO" ||
			response == "n" ||
			response == "N"
			)
		{
			again = false;
			invalidResponse = false;
		}
		else
		{
			cout << "Your answer was not understood. Please enter a yes or no answer: ";
			invalidResponse = true;
		}
	} while (invalidResponse == true);

	cout << "\n\n Wins: " << wins_ << "\tLosses: " << losses_ << endl << endl;
}