//Algorithms and Data Structures Coursework
//Written by Lewis Wood

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


//global variables
int squares[3][3] = { {0,0,0}, {0,0,0},{0,0,0} }; //create an array of nullable booleans that will be used to store noughts and crosses: 0=O, 1=X, NULL = ?
bool player = false; //create the player boolean
char symbol;//symbol to use for the first player
bool win = false; //win condition for the game, used to terminate the game loop
int turns = 0;

void printGrid(int squares[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == 3)
			{
				if (i < 2)
				{
					printf("\n-----------");
				}
				printf("\n");
			}
			else
			{
				if (squares[i][j] != 0)
				{
					if (squares[i][j] == 1)
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
}

void playerTurn(char symbol)
{
	char moveSelection[7];
	int xAxis = 3;
	int yAxis = 3;
	bool occupied = true;

	while (occupied = true)
	{
		//find the y axis of the box the player wants to claim
		printf("Player %c, Which row would you like to claim? (eg 'Top / Bottom / Middle')\n", symbol);
		scanf("%6c", &moveSelection);

		//make sure the user input is valid

		while (yAxis = 3)
		{

			if (moveSelection == "Top")
			{
				yAxis = 0;

			}
			else if (moveSelection == "Middle")
			{
				yAxis = 1;

			}
			else if (moveSelection == "Bottom")
			{
				yAxis = 2;

			}
			else
			{
				printf("please enter a valid square (Remember Capital Letters!)\n");
				scanf("%6c", &moveSelection);
			}

		}

		//find the x axis of the box the player wants to claim
		printf("Player %c, Which row would you like to claim? (eg 'Left / Right / Middle')\n", symbol);
		scanf("%6c", &moveSelection);

		//make sure the user input is valid

		while (xAxis = 3)
		{
			if (moveSelection == "Left")
			{
				xAxis = 0;

			}
			else if (moveSelection == "Middle")
			{
				xAxis = 1;

			}
			else if (moveSelection == "Right")
			{
				xAxis = 2;

			}
			else
			{
				printf("please enter a valid square (Remember Capital Letters!)\n");
				scanf("%6c", &moveSelection);
			}
		}



		//check if the block is already occupied

		if (squares[xAxis][yAxis] == 0)
		{

			//if it isn't, mark the player's symbol in to the box

			if (strcmp(&symbol, "x") == 0)
			{
				squares[xAxis][yAxis] = 1; //mark the players symbol in to the box

			}

			else
			{
				squares[xAxis][yAxis] = 2;
				&symbol == "x"; //change who's turn it is
				occupied = false; //set the occupied boolean to false to break the loop
			}


		}
		//if it is, display an error and ask the player again
		else
		{
			printf("This box has already been claimed, please enter another");

		}
	}
}

void checkForWin(int squares[3][3])
{
	if (turns = 9)
	{
		win = true;
	}
}
int main()

{
	printf("Welcome to Tic Tac Toe. \n");


	// char board[40]; //create the string that will be the game board



	//ask which symbol the player wants to play as
	printf("Would you like to be noughts or crosses (Please enter either 'x' or 'o'): \n");
	scanf("%2c", &symbol);

	while (player = false)
	{

		if (strcmp(&symbol, "x") == 0 || strcmp(&symbol, "o") == 0)
		{
			player = true;
		}
		else
		{
			printf("\nEnter either x or o	.");
		}

	}

	while (win = false)
	{
		//print game board to console
		printGrid(squares);

		//ask the player which square they wish to own?
		playerTurn(symbol);
		checkForWin(squares);
	}
}

