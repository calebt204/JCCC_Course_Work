//Caleb Turner
//FloodFill.h
#ifndef FLOOD_FILL_H
#define FLOOD_FILL_H

class FloodFill
{
public:
	FloodFill(int);
	/**
	*  Creates a new array pointed to by imagePtr. The array should be
	*  randomly populated with the chars ‘c’, ‘m’, ‘y’, and ‘k’
	*  with each char being equally likely. The char stored in each 
	*  element represents a color.
	*	
	*  @param	int		number passed into imageSize
	**/
	void generateImage(int);
	/**
	*  Displays the current chars in the array pointed to by imagePtr.
	*  Should also display row numbers above the image and column 
	*  numbers to the left of the image. 
	**/
	void displayImage();
	/**
	*  Flood fills beginning at [row][col] and replacing color there with newColor character.  
	*  fill() should display to the screen:
	*
	*	@param	int		row flood fill starts at
	*	@param	int		col flood fill starts at
	*	@param	char	color to fill board with 
	**/
	void fill(int row, int col, char newColor);
private:
	char** imagePtr;
	int imageSize;
};
#endif