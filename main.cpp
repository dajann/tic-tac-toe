#include <iostream>

char table[3][3] = {32, 32, 32, 32, 32, 32, 32, 32, 32};
char player1, player2;
int x, y;
int counter = 0;
bool gameOver = false;

void board();
void choosePlayer(char&, char&);
void player1Turn();
void player2Turn();
int checkwin();

int main()
{
	

	choosePlayer(player1, player2);
	board();


	while(!checkwin() && counter < 9) // we check to see if the game is over
	{
		if (!checkwin() && counter < 9) // we check to see if the game is over
		{
			player1Turn();


			if (!checkwin() && counter < 9) // we check to see if the game is over
			{
				player2Turn();
			}
			
			else if (checkwin()) // we check if player 1 is the winner
			{
				std::cout << "Player " << player1 << " won" << std::endl;
				gameOver = true;
			}
			else // the game is a draw
			{
				std::cout << "Draw" << std::endl;
				gameOver = true;
			}
		}
	}
	if (gameOver == false)//  we check to see if the game is over
	{
		if (checkwin()) // we check if player 2 is the winner
		{
			std::cout << "Player " << player2 << " won" << std::endl;
		}
		else // the game is a draw
		{
			std::cout << "Draw" << std::endl;
		}
	}
}
//-----------------------------------------------------------------------------------------------------------------------


void board()
{
	std::cout << "-----------------" << std::endl;
	std::cout << "  " << table[0][0] << "  |  " << table[0][1] << "  |  " << table[0][2] << "  " << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "  " << table[1][0] << "  |  " << table[1][1] << "  |  " << table[1][2] << "  " << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "  " << table[2][0] << "  |  " << table[2][1] << "  |  " << table[2][2] << "  " << std::endl;
	std::cout << "-----------------" << std::endl;


}

void choosePlayer(char& player1, char& player2)
{
	std::cout << "Choose 'X' or 'O': ";
	std::cin >> player1;

	if (player1 == 79 || player1 == 111 || player1 == 88 || player1 == 120)
	{

		if (player1 == 79 || player1 == 111)
		{
			player1 = 79;
			player2 = 88;
		}
		else
		{
			player1 = 88;
			player2 = 79;
		}
	}
}
void player1Turn()
{
	std::cout << "Player " << player1 << " move (x, y coordinate):" << std::endl;
			std::cin >> x >> y;

			while (table[x][y] != 32)
			{
				std::cout << "Select the available field:" << std::endl;
				std::cin >> x >> y;
			}
			table[x][y] = player1;
			counter++;
			board();
}

void player2Turn()
{
		std::cout << "Player " << player2 << " move (x, y coordinate):" << std::endl;
				std::cin >> x >> y;

				while (table[x][y] != 32)
				{
					std::cout << "Select the available field:" << std::endl;
					std::cin >> x >> y;
				}
				table[x][y] = player2;
				counter++;
				board();
	
}

int checkwin()
{
	if (table[0][0] != 32 && table[0][0] == table[0][1] && table[0][0] == table[0][2])
		return 1;

	else if (table[1][0] != 32 && table[1][0] == table[1][1] && table[1][0] == table[1][2])
		return 1;

	else if (table[2][0] != 32 && table[2][0] == table[2][1] && table[2][0] == table[2][2])
		return 1;

	else if (table[0][0] != 32 && table[0][0] == table[1][0] && table[0][0] == table[2][0])
		return 1;

	else if (table[0][1] != 32 && table[0][1] == table[2][1] && table[0][1] == table[3][1])
		return 1;

	else if (table[0][2] != 32 && table[0][2] == table[1][2] && table[0][2] == table[2][2])
		return 1;

	else if (table[0][0] != 32 && table[0][0] == table[1][1] && table[0][0] == table[2][2])
		return 1;

	else if (table[0][2] != 32 && table[0][2] == table[1][1] && table[0][2] == table[2][0])
		return 1;

	else
		return 0;
}
