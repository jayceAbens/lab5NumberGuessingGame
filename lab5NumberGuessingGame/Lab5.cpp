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
int playGame(int& wins, int& losses);
void playAgain(bool& again, int wins_, int losses_);

using namespace std;

int main()
{
	int wins = 0;		// total wins
	int losses = 0;		// total losses
	bool again;			// true if player wishes to play again

	do {
		printIntro();	
		if (playGame(wins, losses) == 1) // if error code is returned, output error message
		{
			cout << "User input error. Stream in failed state. Exiting program...\n";
			return 1; // returns error code and exits the program
		}
		playAgain(again, wins, losses);
	} while (again);
	return 0;
}

// Precondition : The stdlib.h and time.h headers are included. An integer is passed to the function.
// Postcondition : a random number is returned between zero and max
int randomNumber(int max)
{
	srand(time(0)); //sets the current time as the seed for generating a psudo-random number
	return (rand() % max); // returns a random number 0-max
}

// Precondition : The iostream library is included. Using namespace std
// Postcondition : The welcome message and game instructions are printed to the screen
void printIntro()
{
	cout << "***** WELCOME TO THE NUMBER GUESSING GAME *****\n\n";
	cout << "A random number between 0 and 100 has been generated. You have 20 tries to guess it!\n\n";
}

// Precondition : The iostream library is included. Using namespace std. Variables "wins" and "losses" exist to be passed by reference
// Postcondition : A random number is generated 0-100. The player recieves 20 attempts to guess it. If the player wins or loses,
//							a random messages is outputted accordingly. Variables "wins" and "losses" are incremneted accordingly.
//							Must handle guesses out of range, asking for a new guess. Must exit the program gracefully if stream enters failed state.
int playGame(int& wins, int& losses)
{
	int randNum = randomNumber(101);	// generates random number 0-100, stores it in variable
	int guess;	// variable to store player guess

	// cout << randNum << "\n\n";	// line of code use for debuging, outputs random number so you can reliably guess it. 

	cout << "Enter your guesses bellow.\n";

	for (int attempt = 1; attempt <= 20; attempt++)
	{
		bool invalidGuess;
		do {
			cout << "\nGuess " << attempt << ": ";
			cin >> guess;	// inputs player guess
			if (!cin) return 1; // if the stream enters failed state, return error code and exit function
			if (guess < 0 || guess > 100)	// if guess is not between 0 and 100, asks for guess again
			{
				cout << "\nYour guess was out of range. Try again between 0 and 100!\n";
				invalidGuess = true;
			}
			else invalidGuess = false; // if not out of range, continue
		} while (invalidGuess == true);	// repeats prompt for guess if not in range

		if (guess == randNum)	// if player guess equals the random number, the player wins
		{
			cout << endl;
			switch (randomNumber(10))	// generates a random number 0-9, outputs the correspnding response
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
			wins++;	// increments win count by 1
			break;	// exits the guessing loop
		}
		else if (attempt == 20)	// if 20 guesses have been made without winning, the player loses
		{
			cout << endl;
			switch (randomNumber(10))	// generates a random number 0-9, outputs the correspnding response
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
			losses++;	// increments loss count by 1
		}
	}
	return 0;
}

// Precondition : The iostream library is included. Using namespace std. Variable again exists to be passed by reference. 
//							Integer values of wins and losses are passed to the function.
// Postcondition : A random question is asked if the player would like to play again. The player's yes/no response is then checked and
//							the game is either repeated or exited accordingly 
void playAgain(bool& again, int wins_, int losses_)
{
	switch (randomNumber(10))	// generates a random number 0-9, outputs the correspnding question
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

	string response;	// variable to store player yes/no response
	bool invalidResponse;	// true if player response is not deemed valid
	do
	{
		cin >> response;	// inputs player response
		if (response == "yes" ||
			response == "Yes" ||
			response == "YES" ||
			response == "y" ||
			response == "Y"
			)	// accepts various yes answer cases
		{
			again = true;	// sets again to true, repeating the game loop
			invalidResponse = false;	// sets invalidResponse to false as the answer was understood
		}
		else if (response == "no" ||
			response == "No" ||
			response == "NO" ||
			response == "n" ||
			response == "N"
			)	// accepts various no answer cases
		{
			again = false;	// sets again to false, ending the game loop
			invalidResponse = false;	// sets invalidResponse to false as the answer was understood
		}
		else
		{
			cout << "Your answer was not understood. Please enter a yes or no answer: ";	// if answer was not understood as yes or no, asks again
			invalidResponse = true;		// sets invalidResponse to true as the answer was not understood
		}
	} while (invalidResponse == true);	// repeats question if answer is not understood

	cout << "\n\n Wins: " << wins_ << "\tLosses: " << losses_ << endl << endl;	// outputs total wins and losses
}