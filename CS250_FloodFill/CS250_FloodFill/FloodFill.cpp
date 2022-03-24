//Caleb Turner
//FloodFill.cpp
#include "FloodFill.h"
#include <stdlib.h>
#include "OrderedPair.h"
#include <iostream>
#include <queue>
using namespace std;

FloodFill::FloodFill(int size):imageSize(size),imagePtr(nullptr)
{

	generateImage(size);
}

void FloodFill::generateImage(int size)
{
	imageSize = size;
	imagePtr = new char* [size];
	for (int i = 0; i < size; ++i)
		imagePtr[i] = new char[size];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int cell = rand() % 4;
			switch (cell)
			{
				case 0:
					imagePtr[i][j] = 'c';
					break;
				case 1:
					imagePtr[i][j] = 'm';
					break;
				case 2:
					imagePtr[i][j] = 'y';
					break;
				case 3:
					imagePtr[i][j] = 'k';
					break;
			}
		}
	}
}
void FloodFill::displayImage()
{
	cout << "  ";
	for (int i = 0; i < imageSize; i++)
	{
		if (i < 10)
			cout << i << " ";
		else
			cout << i % 10 << " ";
	}
	cout << endl;
	for (int i = 0; i < imageSize; i++)
	{
		if (i < 10)
			cout << i << " ";
		else
			cout << i % 10 << " ";
		for (int j = 0; j < imageSize; j++)
		{
			cout << imagePtr[i][j] << " ";
		}
		cout << endl;
	}
}

void FloodFill::fill(int row, int col, char newColor)
{
	cout << endl<<"Beginning at["<<row<<"]["<<col<<"] I will flood fill and replace whatever color is currently at["<<row<<"]["<<col<<"] with "<<newColor << endl;
	queue<OrderedPair> aQueue;
	OrderedPair curPair(row, col);
	char matchColor = imagePtr[row][col];
	aQueue.push(curPair);

	while (!aQueue.empty())
	{
		curPair = aQueue.front();
		aQueue.pop();
		imagePtr[curPair.getRow()][curPair.getCol()] = newColor;
		for (int i = curPair.getRow() - 1; i <= curPair.getRow() + 1; i++)
		{
			for (int j = curPair.getCol() - 1; j <= curPair.getCol() + 1; j++)
			{
				if (i >= 0 && j >= 0 && i < imageSize && j < imageSize && imagePtr[i][j]==matchColor)
				{
					
						OrderedPair insertPair(i, j);
						aQueue.push(insertPair);		
				}
			}
		}
	}
}

//My attempt at keeping track of processed cells that was in the if statement, but did not work
//Had another queue processedQueue defined at the start of the function
/*
	queue<OrderedPair> checkQueue = processedQueue;
	bool processed = false;
	while (!checkQueue.empty())
	{
		OrderedPair checkPair = checkQueue.front();
		if (checkPair.getCol() == curPair.getCol() && checkPair.getRow() == curPair.getRow())
		{
			processed = true;
			break;
		}
		checkQueue.pop();
	}
	if (!processed)
	{
		OrderedPair insertPair(i, j);
		aQueue.push(insertPair);
		processedQueue.push(insertPair);
	}
*/