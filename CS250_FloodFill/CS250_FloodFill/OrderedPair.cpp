//Caleb Turner
//OrderedPair.cpp
#include "OrderedPair.h"
using namespace std;

OrderedPair::OrderedPair(int r, int c) : row(r), col(c)
{
}
void OrderedPair::setCol(int c)
{
	col = c;
}
void OrderedPair::setRow(int r)
{
	row = r;
}

int OrderedPair::getCol()
{
	return col;
}
int OrderedPair::getRow()
{
	return row;
}
