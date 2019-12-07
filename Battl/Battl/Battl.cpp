// Battl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <random>

void printArray(int board[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

void fillShips(int board[5][5])
{
	int generator, xPos, yPos;
	for (int i = 0; i < 3; i++)
	{
		generator = rand() % 4;
		xPos = generator;
		generator = rand() % 4;
		yPos = generator;
		if (board[xPos][yPos] == 1)
			i--;
		else
			board[xPos][yPos] = 1;
	}
}

void checkHit(int board[5][5], int xPos, int yPos)
{
	if (board[xPos][yPos] == 0)
	{
		//Check top left corner
		if (xPos == 0 && yPos == 0)
		{
			if (board[1][0] == 1 || board[0][1] == 1 || board[1][1] == 1)
				std::cout << "NEAR MISS" << std::endl;
			else
				std::cout << "MISS" << std::endl;
		}
		//Check top right corner
		else if (xPos == 4 && yPos == 0)
		{
			if (board[3][0] == 1 || board[4][1] == 1 || board[3][1] == 1)
				std::cout << "NEAR MISS" << std::endl;
			else
				std::cout << "MISS" << std::endl;
		}
		//Check bottom left corner
		else if (xPos == 0 && yPos == 4)
		{
			if (board[0][3] == 1 || board[1][4] == 1 || board[1][3] == 1)
				std::cout << "NEAR MISS" << std::endl;
			else
				std::cout << "MISS" << std::endl;
		}
		//Check bottom right corner
		else if (xPos == 4 && yPos == 4)
		{
			if (board[4][3] == 1 || board[3][4] == 1 || board[3][3] == 1)
				std::cout << "NEAR MISS" << std::endl;
			else
				std::cout << "MISS" << std::endl;
		}
		//Check the top row
		else if (yPos == 0)
		{
			if (board[xPos - 1][yPos] == 1 || board[xPos + 1][yPos] == 1 || board[xPos][yPos + 1] == 1 ||
				board[xPos - 1][yPos + 1] == 1 || board[xPos + 1][yPos + 1] == 1)
				std::cout << "NEAR MISS" << std::endl;
			else
				std::cout << "MISS" << std::endl;
		}
		//Check the bottom row
		else if (yPos == 4)
		{
			if (board[xPos - 1][yPos] == 1 || board[xPos + 1][yPos] == 1 || board[xPos][yPos - 1] == 1 ||
				board[xPos - 1][yPos - 1] == 1 || board[xPos + 1][yPos - 1] == 1)
				std::cout << "NEAR MISS" << std::endl;
			else
				std::cout << "MISS" << std::endl;
		}
		//Check the left side
		else if (xPos == 0)
		{
			if (board[xPos][yPos - 1] == 1 || board[xPos][yPos + 1] == 1 || board[xPos + 1][yPos] == 1 ||
				board[xPos + 1][yPos - 1] == 1 || board[xPos + 1][yPos + 1] == 1)
				std::cout << "NEAR MISS" << std::endl;
			else
				std::cout << "MISS" << std::endl;
		}
		//Check the right side
		else if (xPos == 4)
		{
			if (board[xPos][yPos - 1] == 1 || board[xPos][yPos + 1] == 1 || board[xPos - 1][yPos] == 1 ||
				board[xPos - 1][yPos - 1] == 1 || board[xPos - 1][yPos + 1] == 1)
				std::cout << "NEAR MISS" << std::endl;
			else
				std::cout << "MISS" << std::endl;
		}
		//Check the inner coordinates
		else
		{
			if (board[xPos][yPos - 1] == 1 || board[xPos][yPos + 1] == 1 || board[xPos - 1][yPos] == 1 || board[xPos + 1][yPos] == 1 ||
				board[xPos - 1][yPos - 1] == 1 || board[xPos + 1][yPos - 1] == 1 || board[xPos - 1][yPos + 1] == 1 || board[xPos + 1][yPos + 1] == 1)
				std::cout << "NEAR MISS" << std::endl;
			else
				std::cout << "MISS" << std::endl;
		}
	}
}

void startAI(int board[5][5])
{
	int numHits = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << "The guessing position is ";
			std::cout << i;
			std::cout << " ";
			std::cout << j << std::endl;
			if (board[i][j] == 1)
			{
				std::cout << "HIT" << std::endl;
				numHits++;
			}
			else
				checkHit(board, i, j);
			std::cout << std::endl;

			if (numHits == 3)
			{
				std::cout << "Congratulations! You hit all the ships!" << std::endl;
				break;
			}
		}
		if (numHits == 3)
			break;
	}
}

int main()
{
	int board[5][5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			board[i][j] = 0;
		}
	}
	printArray(board);
	std::cout << std::endl;
	fillShips(board);
	printArray(board);
	startAI(board);
}