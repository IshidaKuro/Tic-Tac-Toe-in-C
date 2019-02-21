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
	char moveSelection[16];
	int xAxis = 3;
	int yAxis = 3;
	
	//find which block the player wants
	printf("Player %c, Which row would you like to claim? (eg 'Top / Bottom / Middle')\n", symbol);
	scanf("%c", moveSelection);

	while (yAxis = 3)
	{
		switch (moveSelection)
		{
			case 'Top':
			{
				yAxis = 0;
				break;
			}
			case 'Middle':
			{
				yAxis = 1;
				break;
			}
			case 'Bottom':
			{
				yAxis = 2;
				break;
			}
			default:
			{
					printf("please enter a valid square (Remember Capital Letters!)\n");
					break;
			}
		}
	}
	

	printf("Player %c, Which row would you like to claim? (eg 'Left / Right / Middle')\n", symbol);
	scanf("%c", moveSelection);

	while (xAxis = 3)
	{
		switch (moveSelection)
		{
			case 'Left':
			{
				xAxis = 0;
				break;
			}
			case 'Middle':
			{
				xAxis = 1;
				break;
			}
			case 'Right':
			{
				xAxis = 2;
				break;
			}
			default:
			{
				printf("please enter a valid square (Remember Capital Letters!)\n");
				break;

			}
		}
	}

	//make sure the user input is valid

	//check if the block is already occupied

	//if it isn't, mark the player's symbol in to the box

	if (symbol = "x")
	{
		squares[xAxis][yAxis] = 1;
	}

	else
	{
		squares[xAxis][yAxis] = 2;
	}

	//if it is, display an error and ask the player again
}


int main()

{
    printf("Welcome to Tic Tac Toe. \n");

    
    // char board[40]; //create the string that will be the game board



	//ask which symbol the player wants to play as
    printf("Would you like to be noughts or crosses (Please enter either 'x' or 'o'): \n");
    scanf("%c", &symbol);

	while (player = false)
	{
		switch (symbol)
		{
		case 'x':
			symbol = "x";
			player = true;
			break;
		case 'o':
			symbol = "o";
			player = true;
			break;
		default: printf("\nEnter either x or o	.");
			break;
		}
	}

	while (win = false)
	{
		//print game board to console
		printGrid(squares);

		//ask the player which square they wish to own?
		playerTurn(symbol);
		//manipulate array based on player input 
	}
}

