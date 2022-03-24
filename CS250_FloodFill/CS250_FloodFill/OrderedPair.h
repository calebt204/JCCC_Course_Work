//Caleb Turner
//OrderedPair.cpp
#ifndef ORDERED_PAIR_H
#define ORDERED_PAIR_H

class OrderedPair {
	
public:
	OrderedPair(int, int);
	void setRow(int);
	void setCol(int);
	int getRow();
	int getCol();

private:
	int row;
	int col;
};

#endif