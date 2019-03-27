//Algorithms and Data Structures Coursework
//Written by Lewis Wood

#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdbool.h>


//global variables
int squares[3][3] = { {0,0,0}, {0,0,0},{0,0,0} }; //create a 2D array that will be used to store the board, 0 = blank, 1 = X, 2 = O

bool player = false; //used to find out if a player has allocated themselves as x or o
bool playerX = false; //if the player is using the X character
bool gameEnd = false; //win condition for the game, used to terminate the game loop
bool xFirst = false;

bool replayAnswer = false; // boolean for input validation of replay
char replay = 'r';

int winner = 0;
int turns = 0; //turn counter for game, used for checking for wins and replays

int xAxis[10]; //used for x axis entry in player move
int yAxis[10]; //used for y axis entry in player move

char winStatement[64] = "There is no Winner\0"; //set to draw condition as default
char winCondition[64] = "The Game is a tie\0"; //used to describe how the player has won the game, default is tie, used when 9 turns have been played with no winner

char symbol = 'r';//symbol for the player -- set to R for declerations sake

void printGrid(int squares[3][3])
{
	printf("\n ____________________________\n\n");

	for (int i = 0; i < 3; i++)
	{
		
		printf("%d | ", 2-i);

		for (int j = 0; j < 4; j++)
		{
			
			if (j == 3)
			{
				if (i < 2)
				{
					printf("\n  | -----------");
				}
				printf("\n");
			}
			else
			{
				if (squares[j][i] != 0)
				{
					if (squares[j][i] == 1)
					{
						printf(" X ");
					}
					else
					{
						printf(" O ");
					}
				}
				else
				{
					printf("   ");
				}
				if (j < 2)
				{
					printf("|");
				}
			}
		}
	}

	printf("   ------------- \n");
	printf("     0   1   2 \n");
	printf("\n ____________________________\n\n");
}

void playerTurn()
{
	int moveSelection;
	

	if (playerX)
	{
		symbol = 'x';
	}
	else
	{
		symbol = 'o';
	}
	
	bool occupied = true;
	while (occupied == true)
	{
	
		//set the x and y axis to invalid values
		xAxis[turns] = 3;
		yAxis[turns] = 3;

		//make sure the entered x axis is valid

		while (xAxis[turns] == 3)
		{
			printf("Player %c, Please enter the x co-ordinate of the square you wish to claim\n", symbol);
			scanf("%d", &moveSelection);



			if (-1 < moveSelection < 3)
			{
				xAxis[turns] = moveSelection;
			}
			else
			{
				printf("please enter a valid square\n");
				//scanf("%6c", &moveSelection);
			}

		}

		//make sure the entered y axis is valid

		while (yAxis[turns] == 3)
		{
			printf("Player %c, Please enter the y co-ordinate of the square you wish to claim\n", symbol);
			scanf("%d", &moveSelection);



			if (-1 < moveSelection && moveSelection < 3)
			{
				yAxis[turns] = 2 - moveSelection;
			}
			else
			{
				printf("please enter a valid square\n");

			}

		}



		//check if the block is already occupied

		if (squares[xAxis[turns]][yAxis[turns]] == 0)
		{

			//if it isn't, mark the player's symbol in to the box

			if (playerX)
			{
				squares[xAxis[turns]][yAxis[turns]] = 1;

			}
			else
			{
				squares[xAxis[turns]][yAxis[turns]] = 2;
				

			}
			occupied = false; //set the occupied boolean to false to break the loop

		}
		//if it is, display an error and ask the player again
		else
		{
			printf("This box has already been claimed, please enter another\n");

		}
	}

	//switch the player's turn
	playerX = !playerX;

	//add to the turn number
	turns++;
}

void checkForWin(int squares[3][3])
{
	
	

	//check to see if there are any wins after turn 3, any less turns is impossible
	if (turns > 3)
	{
		//here's where the fun begins
		{
			if ((squares[0][0] * squares[0][1] * squares[0][2]) == 1 || (squares[0][0] * squares[0][1] * squares[0][2]) == 8) //left win
			{
				winner = squares[0][0];
				strcpy(winCondition, "The player has won by completing the left column\0");
			}
			else if ((squares[1][0] * squares[1][1] * squares[1][2]) == 1 || (squares[1][0] * squares[1][1] * squares[1][2]) == 8) //middle (|) win
			{
				winner = squares[1][0];
				strcpy(winCondition, "The player has won by completing the middle column\0");
			}
			else if ((squares[2][0] * squares[2][1] * squares[2][2]) == 1 || (squares[2][0] * squares[2][1] * squares[2][2]) == 8) //right win
			{
				winner = squares[2][0];
				strcpy(winCondition, "The player has won by completing the right column\0");
			}
			else if ((squares[0][0] * squares[1][1] * squares[2][2]) == 1 || (squares[0][0] * squares[1][1] * squares[2][2]) == 8) // diagonal (\) win
			{
				winner = squares[0][0];
				strcpy(winCondition, "The player has won by completing the top left to bottom right diagonal\0");
			}
			else if ((squares[0][2] * squares[1][1] * squares[2][0]) == 1 || (squares[0][2] * squares[1][1] * squares[2][0]) == 8) //diagonal (/) win
			{
				winner = squares[0][2];
				strcpy(winCondition, "The player has won by completing the bottom left to top right diagonal\0");
			}
			else if ((squares[0][0] * squares[1][0] * squares[2][0]) == 1 || (squares[0][0] * squares[1][0] * squares[2][0]) == 8) //top win
			{
				winner = squares[0][0];
				strcpy(winCondition, "The player has won by completing the top row\0");
			}
			else if ((squares[0][1] * squares[1][1] * squares[2][1]) == 1 || (squares[0][1] * squares[1][1] * squares[2][1]) == 8) //middle(-) win
			{
				winner = squares[0][1];
				strcpy(winCondition, "The player has won by completing the middle row\0");
			}
			else if ((squares[0][2] * squares[1][2] * squares[2][2]) == 1 || (squares[0][2] * squares[1][2] * squares[2][2]) == 8) //bottom win
			{
				winner = squares[0][2];
				strcpy(winCondition, "The player has won by completing the bottom row\0");
			}
		}
	}

	

	//if there have been 9 turns, the game must end as there are no more boxes to claim
	if (turns == 9)
	{
		gameEnd = true;
	}
}

void replayGame(int turns)
{
	//reset the board
	int replayBoard[3][3] = { {0,0,0}, {0,0,0},{0,0,0} };
	if (xFirst)
	{
		playerX = true;
	}

	for (int i = 0; i <= turns; i++)
	{
		//print the grid
		printGrid(replayBoard);
		//wait for a bit
		Sleep(2500);
		//play the moves back in order
		if (playerX)
		{
			replayBoard[xAxis[i]][yAxis[i]] = 1;

		}

		else
		{
			replayBoard[xAxis[i]][yAxis[i]] = 2;

		}

		playerX = !playerX;
	}
	

	

}

int main()

{
	printf("Welcome to Tic Tac Toe. \n");

	while (player == false)
	{
	//ask which symbol the player wants to play as
	printf("Would you like to be noughts or crosses (Please enter either 'x' or 'o'): \n");
	scanf("%c", &symbol);


		if (strcmp(&symbol, "x") != 0 && strcmp(&symbol, "o") != 0)
		{
			
			printf("\nEnter either x or o	.");
		}
		else
		{
			if (strcmp(&symbol, "x") == 0)
			{
				playerX = true;
				xFirst = true;
			}
			else
			{
				playerX = false;
				xFirst = false;
			}
			player = true;
		}

	}

	while (gameEnd == false && winner == 0)
	{
		//print game board to console
		printGrid(squares);

		//ask the player which square they wish to own?
		playerTurn();
		//check to see if anyone has won
		checkForWin(squares);
	}
	//print the grid one last time
	printGrid(squares);

	//declare winner

	if (winner == 1)
	{
		strcpy(winStatement, "The Winner is Player X");
	}
	else if (winner == 2)
	{
		strcpy(winStatement, "The Winner is player O");
	}

	//print the end game message
	printf("%s\n", &winStatement);
	printf("%s\n", &winCondition);


	//ask the player if they would like a replay

	

	while (replayAnswer==false)
	{
		//ask if the player would like to see a replay
		printf("Would you like to view a replay? (Please enter either 'y' for yes or 'n' for no): \n");
		scanf("%c", &replay);

		
		if (strcmp(&replay, "y") != 1 && strcmp(&replay, "n") != 1)
		{
			
			printf("\nEnter either 'y' or 'n'. \n");
		}
		else
		{
			if (strcmp(&replay, "y") == 1)
			{
				replayGame(turns);
				
			}
			
			replayAnswer = true;
		}
	}
	
	//ask the player if they would like to play again
}

