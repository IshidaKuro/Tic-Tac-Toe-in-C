//Algorithms and Data Structures Coursework
//Written by Lewis Wood

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


//global variables
int squares[3][3] = { {0,0,0}, {0,0,0},{0,0,0} }; //create an array of nullable booleans that will be used to store noughts and crosses: 0=O, 1=X, NULL = ?
bool player = false; //create the player boolean
char symbol = 'r';//symbol to use for the first player
bool win = false; //win condition for the game, used to terminate the game loop
int turns = 0;

void printGrid(int squares[3][3])
{
	printf("\n");

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

	printf("   ------------- \n");
	printf("     0   1   2 \n");
}

void playerTurn(char symbol)
{
	int moveSelection;
	int xAxis = 3;
	int yAxis = 3;
	bool occupied = true;

	while (occupied == true)
	{
		//find the y axis of the box the player wants to claim
		
		xAxis = 3;
		yAxis = 3;
		//make sure the user input is valid

		while (xAxis == 3)
		{
			printf("Player %c, Please enter the x co-ordinate of the square you wish to claim\n", symbol);
			scanf("%d", &moveSelection); 



			if (-1 < moveSelection < 3)
			{
				xAxis = moveSelection;
			}
			else
			{
				printf("please enter a valid square\n");
				//scanf("%6c", &moveSelection);
			}

		}

		//find the x axis of the box the player wants to claim
		

		//make sure the user input is valid

		while (yAxis == 3)
		{
			printf("Player %c, Please enter the y co-ordinate of the square you wish to claim\n", symbol);
			scanf("%d", &moveSelection);



			if (-1 < moveSelection < 3)
			{
				yAxis = 2 - moveSelection;
			}
			else
			{
				printf("please enter a valid square\n");
				
			}

		}



		//check if the block is already occupied

		if (squares[xAxis][yAxis] == 0)
		{

			//if it isn't, mark the player's symbol in to the box

			if (strcmp(&symbol, "x") == 0)
			{
				squares[yAxis][xAxis] = 1; //mark the players symbol in to the box

			}

			else
			{
				squares[yAxis][xAxis] = 2;
				//symbol = "x"; //change who's turn it is
				
			}
			occupied = false; //set the occupied boolean to false to break the loop

		}
		//if it is, display an error and ask the player again
		else
		{
			printf("This box has already been claimed, please enter another\n");

		}
	}

	turns++;
}

void checkForWin(int squares[3][3])
{
	if (turns == 9)
	{
		win = true;
	}
}

int main()

{
	printf("Welcome to Tic Tac Toe. \n");


	// char board[40]; //create the string that will be the game board


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
			symbol = 'x';
			player = true;
		}

	}

	while (win == false)
	{
		//print game board to console
		printGrid(squares);

		//ask the player which square they wish to own?
		playerTurn(symbol);
		checkForWin(squares);
	}
}

