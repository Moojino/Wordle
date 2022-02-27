//Programmer: Ian Tognoni
//Date: 2/22/2022
//File: IanHW3.cpp
//Assignment: HW3
//Purpose: Creating a fun word game for friends to play together 
#include <iostream>
#include <string>
using namespace std;

//Discription: Greets the user
//Pre: none
//Post: Prints out a greeting 
void greet();

//Discription: Start a new game
//Pre: 8 strings and 4 ints
//Post: Outputs the game and uses pass by refrence to update info
void newGame(string & name1, string & name2, string & attempt1, string & attempt2, string & attempt3, string & attempt4,
string & attempt5, string & attempt6, const int round, int & chance, int & befLevel, int & aftLevel);

//Discription: Start a new round with the same players
//Pre: 8 strings and 4 ints
//Post: Outputs the game and uses pass by refrence to update info
void newRound(const string name1, const string name2, string & attempt1, string & attempt2, string & attempt3,
string & attempt4, string & attempt5, string & attempt6, const int round, int & chance, const int befLevel, int & afLevel);


//Discription: Gives the players a summary of the games so far
//Pre: 2 strings and 4 ints
//Post: Prints a summary of the player's games and updateds friendship level
void printGameSummary(const string name1, const string name2, const int round, const int befLevel, int & aftLevel); 

//Discription: Gives the pl
//Pre: 8 strings and 1 int
//Post: Prints a summary of the resutls last round
void shareWordle(const string name1, const string name2, const string attempt1, const string attempt2, 
const string attempt3, const string attempt4, const string attempt5, const string attempt6, const int chance);

int main()
{
	//variable used throughout the main function
	int round = 0; //Keeps track of rounds
	int chance = 0; //Keeps track of trys
	int befLevel = 0; //friendship before a round
	int aftLevel = 0; //friendship after a round
	
	char gameMenu = ' '; //Player selection value
	
	string name1 = " "; //Player one's name
	string name2 = " "; //Player two's name
	
	//Saves the faces from attempts 1 to 6
	string attempt1 = ""; 
	string attempt2 = "";
	string attempt3 = "";
	string attempt4 = "";
	string attempt5 = "";
	string attempt6 = "";
	
	greet();
	
	while(gameMenu != '5')
	{
		gameMenu = ' '; //Stops infinte loop
		
		//game menu
		cout << "The Wordle's Menu" << endl;
		cout << "-----------------" << endl;
		cout << "1. Start a new game (with new players)" << endl;
		cout << "2. Start a new round (with exisiting players)" << endl;
		cout << "3. Print game summary (of exisiting players)" << endl;
		cout << "4. Share result (of last round)" << endl;
		cout << "5. Exit the game (are you sure?)" << endl << endl;
		cout << "Plesase select an option from above: ";
		
		//player choice
		while(gameMenu != '1' && gameMenu != '2' && gameMenu != '3' && gameMenu != '4' && gameMenu != '5')
		{
			cin >> gameMenu;
			
			switch(gameMenu)
			{
				//new game
				case '1' : 
					//reset attemps
					attempt1 = ""; 
					attempt2 = "";
					attempt3 = "";
					attempt4 = "";
					attempt5 = "";
					attempt6 = "";
				
					round = 1;
					chance = 0;
					
					newGame(name1, name2, attempt1, attempt2, attempt3, attempt4, attempt5, attempt6, round, chance, befLevel, aftLevel);
				break;
				
				//another round with the same players
				case '2' :
				if(round == 0)
				{
					cout << "\nSorry, no existing player info found. Please start a new game and choose again: ";
					gameMenu = ' ';
				}
				else
				{
					//Resets and updates values
					attempt1 = ""; 
					attempt2 = "";
					attempt3 = "";
					attempt4 = "";
					attempt5 = "";
					attempt6 = "";
					
					befLevel = aftLevel;
					chance = 0;
					round ++;
					
					newRound(name1, name2, attempt1, attempt2, attempt3, attempt4, attempt5, attempt6, round, chance, befLevel, aftLevel);
				}
				break;
				
				//Print game summary
				case '3' :
					if(round == 0)
					{
						cout << "\nSorry, no round records found. Please choose again: ";
						gameMenu = ' ';
					}
					else
					{
						printGameSummary(name1, name2, round, befLevel, aftLevel);
					}
					break;
				
				//print round summary
				case '4' :
					if(round == 0)
					{
						cout << "\nSorry, no round records found. Please choose again: ";
						gameMenu = ' ';
					}
					else
					{
						shareWordle(name1, name2, attempt1, attempt2, attempt3, attempt4, attempt5, attempt6, chance);
					}
					break;
				
				case '5':
					break;
				
				// Invalid inputs
				default :
					cout << endl << gameMenu << " is not a valid option! Please choose again: ";
			}
		}
	}
	
	cout << endl << "OK, good bye! See you soon, Wordle Wordle!" << endl;
	cout << "Remember, a real friend is one who always Wordles with you when " << endl;
	cout << "the rest of the world won't!"; 
}

void greet()
{
	cout << "Welcome to Wordle For Friends! \n<^.^>" << endl << endl;
}


void newGame(string & name1, string & name2, string & attempt1, string & attempt2, string & attempt3, string & attempt4,
string & attempt5, string & attempt6, const int round, int & chance, int & befLevel, int & aftLevel)
{
	//Intialization for vars in NewGame
	bool inRange = true; //Checks if the friendship level is in range
	bool noNums = true; //Checks the words for special characters and nums
	bool goodLen = true; //Checks the word's length
	
	int length = 0; //saves the length of the word
	
	string word = " "; //Saves the player's word
	string guess = " "; //Saves players guess
	
	//gets Player one's name
	cout << endl << "Player 1, please enter  your name: ";
	cin >> name1;
	cout << "Welcome, " << name1 << "!" << endl;
	
	//gets Player two's name
	cout << "\nPlayer 2, please enter  your name: ";
	cin >> name2;
	cout << "Welcome, " << name2 << "!"<< endl;
	
	//gets the friendship level
	while(inRange)
	{
		cout << endl << name1 << ", please rate the friendship level you have with " << name2 << endl;
		cout << "(enter an integer value in [0, 100]): ";
		cin >> befLevel;
		cout << endl;
		if(befLevel >= 0 && befLevel <= 100)
			inRange = false;
		else
			cout << "Can't you read, " << name1 << "? The friendship level you input is invalid!" << endl; 
	}
	
	cout << "Hooray, that's an admirable friendship between you two!" << endl;
	
	//getting the word and checking it
	while(goodLen || noNums)
	{
		//gets the word
		cout << endl << name1 << ", please enter a five letter word in all uppercase." << endl;
		cin >> word;
		cout << endl;
		
		//checks for illegal characters and length
		if (word.length() != 5)//length
		{
			cout << "Please enter a 5 letter word instead of a " << word.length() << " letter word.";
			goodLen = true;
		}
		else //illegal characters
		{
			goodLen = false;
			length = word.length();
			for(int x = 0; x < length; x++)//for x
			{
				if(isalpha(word[x]))
					noNums = false;
				else
				{
					noNums = true;
					x = length;
					cout << "Illegal characters dedected, please try again.";
				}
			}
		}
	}
	
	//Player 2 guesses
	cout << name2 << ", it's your turn." << endl;
	for(int j = 1; j <= 6; j++)//for j
	{
		goodLen = true;
		noNums = true;
		while(goodLen == 1 || noNums == 1) //checks word
		{
			cout << "Try #" << j << ") " << name2 << ", please guess the 5 letter word " << name1 << " entered." << endl;
			cin >> guess;
			cout << endl;
			if (guess.length() != 5)
			{
				cout << "Please enter a 5 letter word instead of a " << guess.length() << " letter word." << endl;
				goodLen = true;
			}
			else
			{
				goodLen = false;
				length = guess.length();
				for(int i = 0; i < length; i++)//for i
				{
					if(isalpha(guess[i]))
						noNums = false;
					else
					{
						noNums = true;
						i = length;
						cout << "Illegal characters dedected, please try again." << endl;
					}
				}
			}
		}
		
		if(guess == word)
		{
			//Saves the when face based on attempt
			if(j == 1)
				attempt1 = "^o^ ^o^ ^o^ ^o^ ^o^";
			if(j == 2)
				attempt2 = "^o^ ^o^ ^o^ ^o^ ^o^";
			if(j == 3)
				attempt3 = "^o^ ^o^ ^o^ ^o^ ^o^";
			if(j == 4)
				attempt4 = "^o^ ^o^ ^o^ ^o^ ^o^";
			if(j == 5)
				attempt5 = "^o^ ^o^ ^o^ ^o^ ^o^";
			if(j == 6)
				attempt6 = "^o^ ^o^ ^o^ ^o^ ^o^";
			
			chance = j;
			j = 7;
			cout << "You entered " << guess << ". Congratulations, " << word << " is it!" << endl;
			cout << name2 << ", you got it in only " << chance << " attempt(s)!" << endl << endl;
			
			if(befLevel == 100)
			{
				aftLevel = befLevel;
				cout << "Friendship level cannot go any higher." << endl;
			}
			else 
			{
				aftLevel = befLevel + chance;
				cout << name1 << ", your friendship with " << name2 << " went from " << befLevel;
				cout << " to " << aftLevel << " through round " << round << "." << endl << endl;
			}
		}
		else // compares letters in each of the word
		{
			//Sorry for this but each if is for a different attempt to save the result
			if(j == 1)
			{
				for(int z = 0; z < 5; z++)// for z
				{
					for(int y = 0; y < 5; y++)//for y
					{
						if(word[z] == guess[z])
						{
							cout << guess[z] << ": ^o^" <<endl;
							attempt1 += "^o^ ";
							y = 6;
						}
						else if(word[y] == guess[z])
						{
							cout << guess[z] << ": ^-^" <<endl;
							attempt1 += "^-^ ";
							y = 6;
						}
						
						if(y == 4)
						{
							cout << guess[z] << ": @.@"<<endl;
							attempt1 += "@.@ ";
						}
					}
				}
				cout << endl;
			}
			else if(j == 2)
			{
				for(int z = 0; z < 5; z++)// for z
				{
					for(int y = 0; y < 5; y++)//for y
					{
						if(word[z] == guess[z])
						{
							cout << guess[z] << ": ^o^" <<endl;
							attempt2 += "^o^ ";
							y = 6;
						}
						else if(word[y] == guess[z])
						{
							cout << guess[z] << ": ^-^" <<endl;
							attempt2 += "^-^ ";
							y = 6;
						}
						
						if(y == 4)
						{
							cout << guess[z] << ": @.@"<<endl;
							attempt2 += "@.@ ";
						}
					}
				}
				cout << endl;
			}
			else if(j == 3)
			{
				for(int z = 0; z < 5; z++)// for z
				{
					for(int y = 0; y < 5; y++)//for y
					{
						if(word[z] == guess[z])
						{
							cout << guess[z] << ": ^o^" <<endl;
							attempt3 += "^o^ ";
							y = 6;
						}
						else if(word[y] == guess[z])
						{
							cout << guess[z] << ": ^-^" <<endl;
							attempt3 += "^-^ ";
							y = 6;
						}
						
						if(y == 4)
						{
							cout << guess[z] << ": @.@"<<endl;
							attempt3 += "@.@ ";
						}
					}
				}
				cout << endl;
			}
			else if(j == 4)
			{
				for(int z = 0; z < 5; z++)// for z
				{
					for(int y = 0; y < 5; y++)//for y
					{
						if(word[z] == guess[z])
						{
							cout << guess[z] << ": ^o^" <<endl;
							attempt4 += "^o^ ";
							y = 6;
						}
						else if(word[y] == guess[z])
						{
							cout << guess[z] << ": ^-^" <<endl;
							attempt4 += "^-^ ";
							y = 6;
						}
						
						if(y == 4)
						{
							cout << guess[z] << ": @.@"<<endl;
							attempt4 += "@.@ ";
						}
					}
				}
				cout << endl;
			}
			else if(j == 5)
			{
				for(int z = 0; z < 5; z++)// for z
				{
					for(int y = 0; y < 5; y++)//for y
					{
						if(word[z] == guess[z])
						{
							cout << guess[z] << ": ^o^" <<endl;
							attempt5 += "^o^ ";
							y = 6;
						}
						else if(word[y] == guess[z])
						{
							cout << guess[z] << ": ^-^" <<endl;
							attempt5 += "^-^ ";
							y = 6;
						}
						
						if(y == 4)
						{
							cout << guess[z] << ": @.@"<<endl;
							attempt5 += "@.@ ";
						}
					}
				}
				cout << endl;
			}
			else
			{
				for(int z = 0; z < 5; z++)// for z
				{
					for(int y = 0; y < 5; y++)//for y
					{
						if(word[z] == guess[z])
						{
							cout << guess[z] << ": ^o^" <<endl;
							attempt6 += "^o^ ";
							y = 6;
						}
						else if(word[y] == guess[z])
						{
							cout << guess[z] << ": ^-^" <<endl;
							attempt6 += "^-^ ";
							y = 6;
						}
						
						if(y == 4)
						{
							cout << guess[z] << ": @.@"<<endl;
							attempt6 += "@.@ ";
						}
					}
				}
				cout << endl;
			}
		}
		
		// if player 2 loses
		if(j == 6)
		{
			aftLevel = befLevel;
			chance = j;
			cout << "Sorry " << name2 << ", you lost round " << round << "." << endl << endl;
		}
	}
}


void newRound(const string name1, const string name2, string & attempt1, string & attempt2, string & attempt3,
string & attempt4, string & attempt5, string & attempt6, const int round, int & chance, const int befLevel, int & aftLevel)
{
	//Intialization for vars in NewGame
	bool noNums = true; //Checks the words for special characters and nums
	bool goodLen = true; //Checks the word's length
	
	int length = 0; //saves the length of the word
	
	string word = " "; //Saves the player's word
	string guess = " "; //Saves players guess
	
	//getting the word and checking it
	while(goodLen || noNums)
	{
		//gets the word
		cout << endl << name1 << ", please enter a five letter word in all uppercase." << endl;
		cin >> word;
		cout << endl;
		
		//checks for illegal characters and length
		if (word.length() != 5)//length
		{
			cout << "Please enter a 5 letter word instead of a " << word.length() << " letter word.";
			goodLen = true;
		}
		else //illegal characters
		{
			goodLen = false;
			length = word.length();
			for(int x = 0; x < length; x++)//for x
			{
				if(isalpha(word[x]))
					noNums = false;
				else
				{
					noNums = true;
					x = length;
					cout << "Illegal characters dedected, please try again.";
				}
			}
		}
	}
	
	//Player 2 guesses
	cout << name2 << ", it's your turn." << endl;
	for(int j = 1; j <= 6; j++)//for j
	{
		goodLen = true;
		noNums = true;
		while(goodLen == 1 || noNums == 1) //checks word
		{
			cout << "Try #" << j << ") " << name2 << ", please guess the 5 letter word " << name1 << " entered." << endl;
			cin >> guess;
			cout << endl;
			if (guess.length() != 5)
			{
				cout << "Please enter a 5 letter word instead of a " << guess.length() << " letter word." << endl;
				goodLen = true;
			}
			else
			{
				goodLen = false;
				length = guess.length();
				for(int i = 0; i < length; i++)//for i
				{
					if(isalpha(guess[i]))
						noNums = false;
					else
					{
						noNums = true;
						i = length;
						cout << "Illegal characters dedected, please try again." << endl;
					}
				}
			}
		}
		
		if(guess == word)
		{
			//Saves the when face based on attempt
			if(j == 1)
				attempt1 = "^o^ ^o^ ^o^ ^o^ ^o^";
			if(j == 2)
				attempt2 = "^o^ ^o^ ^o^ ^o^ ^o^";
			if(j == 3)
				attempt3 = "^o^ ^o^ ^o^ ^o^ ^o^";
			if(j == 4)
				attempt4 = "^o^ ^o^ ^o^ ^o^ ^o^";
			if(j == 5)
				attempt5 = "^o^ ^o^ ^o^ ^o^ ^o^";
			if(j == 6)
				attempt6 = "^o^ ^o^ ^o^ ^o^ ^o^";
			
			chance = j;
			j = 7;
			cout << "You entered " << guess << ". Congratulations, " << word << " is it!" << endl;
			cout << name2 << ", you got it in only " << chance << " attempt(s)!" << endl << endl;
			
			if(befLevel == 100)
			{
				aftLevel = befLevel;
				cout << "Friendship level cannot go any higher." << endl;
			}
			else 
			{
				aftLevel = befLevel + chance;
				cout << name1 << ", your friendship with " << name2 << " went from " << befLevel;
				cout << " to " << aftLevel << " through round " << round << "." << endl << endl;
			}
		}
		else // compares letters in each of the word
		{
			//Sorry for this but each if is for a different attempt to save the result
			if(j == 1)
			{
				for(int z = 0; z < 5; z++)// for z
				{
					for(int y = 0; y < 5; y++)//for y
					{
						if(word[z] == guess[z])
						{
							cout << guess[z] << ": ^o^" <<endl;
							attempt1 += "^o^ ";
							y = 6;
						}
						else if(word[y] == guess[z])
						{
							cout << guess[z] << ": ^-^" <<endl;
							attempt1 += "^-^ ";
							y = 6;
						}
						
						if(y == 4)
						{
							cout << guess[z] << ": @.@"<<endl;
							attempt1 += "@.@ ";
						}
					}
				}
				cout << endl;
			}
			else if(j == 2)
			{
				for(int z = 0; z < 5; z++)// for z
				{
					for(int y = 0; y < 5; y++)//for y
					{
						if(word[z] == guess[z])
						{
							cout << guess[z] << ": ^o^" <<endl;
							attempt2 += "^o^ ";
							y = 6;
						}
						else if(word[y] == guess[z])
						{
							cout << guess[z] << ": ^-^" <<endl;
							attempt2 += "^-^ ";
							y = 6;
						}
						
						if(y == 4)
						{
							cout << guess[z] << ": @.@"<<endl;
							attempt2 += "@.@ ";
						}
					}
				}
				cout << endl;
			}
			else if(j == 3)
			{
				for(int z = 0; z < 5; z++)// for z
				{
					for(int y = 0; y < 5; y++)//for y
					{
						if(word[z] == guess[z])
						{
							cout << guess[z] << ": ^o^" <<endl;
							attempt3 += "^o^ ";
							y = 6;
						}
						else if(word[y] == guess[z])
						{
							cout << guess[z] << ": ^-^" <<endl;
							attempt3 += "^-^ ";
							y = 6;
						}
						
						if(y == 4)
						{
							cout << guess[z] << ": @.@"<<endl;
							attempt3 += "@.@ ";
						}
					}
				}
				cout << endl;
			}
			else if(j == 4)
			{
				for(int z = 0; z < 5; z++)// for z
				{
					for(int y = 0; y < 5; y++)//for y
					{
						if(word[z] == guess[z])
						{
							cout << guess[z] << ": ^o^" <<endl;
							attempt4 += "^o^ ";
							y = 6;
						}
						else if(word[y] == guess[z])
						{
							cout << guess[z] << ": ^-^" <<endl;
							attempt4 += "^-^ ";
							y = 6;
						}
						
						if(y == 4)
						{
							cout << guess[z] << ": @.@"<<endl;
							attempt4 += "@.@ ";
						}
					}
				}
				cout << endl;
			}
			else if(j == 5)
			{
				for(int z = 0; z < 5; z++)// for z
				{
					for(int y = 0; y < 5; y++)//for y
					{
						if(word[z] == guess[z])
						{
							cout << guess[z] << ": ^o^" <<endl;
							attempt5 += "^o^ ";
							y = 6;
						}
						else if(word[y] == guess[z])
						{
							cout << guess[z] << ": ^-^" <<endl;
							attempt5 += "^-^ ";
							y = 6;
						}
						
						if(y == 4)
						{
							cout << guess[z] << ": @.@"<<endl;
							attempt5 += "@.@ ";
						}
					}
				}
				cout << endl;
			}
			else
			{
				for(int z = 0; z < 5; z++)// for z
				{
					for(int y = 0; y < 5; y++)//for y
					{
						if(word[z] == guess[z])
						{
							cout << guess[z] << ": ^o^" <<endl;
							attempt6 += "^o^ ";
							y = 6;
						}
						else if(word[y] == guess[z])
						{
							cout << guess[z] << ": ^-^" <<endl;
							attempt6 += "^-^ ";
							y = 6;
						}
						
						if(y == 4)
						{
							cout << guess[z] << ": @.@"<<endl;
							attempt6 += "@.@ ";
						}
					}
				}
				cout << endl;
			}
		}
		
		//If player 2 loses
		if(j == 6)
		{
			aftLevel = befLevel;
			chance = j;
			cout << "Sorry " << name2 << ", you lost round " << round << "." << endl << endl;
		}
	}
}

void printGameSummary(const string name1, const string name2, const int round, const int befLevel, int & aftLevel)
{
	cout << endl << "Game summary" << endl;
	cout << "\tPlayer 1: " << name1 << endl;
	cout << "\tPlayer 2: " << name2 << endl;
	cout << "\tNumber of rounds played: " << round << endl;
	cout << "\tInitial friendship level: " << befLevel << endl;
	
	//Checks if the friendship level is less than 20
	if(aftLevel < 20)
	{
		aftLevel += 2;
		cout << "\tCurrent friendship level: " << aftLevel << " (2 bonus levels added)" << endl << endl;
	}
	else
	{
		cout << "\tCurrent friendship level: " << aftLevel << endl << endl;
	}
}

void shareWordle(const string name1, const string name2, const string attempt1, const string attempt2,
const string attempt3, const string attempt4, const string attempt5, const string attempt6, const int chance)
{
	cout << endl << "Wordle For Friends (" << name1 << " and " << name2  << ")" << endl << endl;
	
	//Checks if attemps were used
	if(attempt1 != "")
		cout << attempt1 << endl;
	if(attempt2 != "")
		cout << attempt2 << endl;
	if(attempt3 != "")
		cout << attempt3 << endl;
	if(attempt4 != "")
		cout << attempt4 << endl;
	if(attempt5 != "")
		cout << attempt5 << endl;
	if(attempt6 != "")
		cout << attempt6 << endl;
		
	cout << endl;
	cout << "Wordle	Round " << chance << "/6" << endl;
	cout << "This is your Wordle journey for the day to be shared!" << endl << endl;
}
