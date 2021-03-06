#include "Pawn.h"


Pawn::Pawn(bool taken, string location, string type, string side) : Pieces(taken, location, type, side)
{

}

char Pawn::move(Pieces* arr[][8], string dst)
{
	char ans = '0';
	if (_taken != true || _side[0] != dst[4])
	{
		ans = '2';
	}
	else if (arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken() && this != arr[int('8' - dst[3])][int(dst[2] - 'a')] && _side[0] == arr[int('8' - dst[3])][int(dst[2] - 'a')]->getSide()[0])
	{
		ans = '3';
	}
	else if ((dst[1] > '8' || dst[1] < '0') || (dst[3] > '8' || dst[3] < '0') || (dst[0] > 'h' || dst[0] < 'a') || (dst[2] > 'h' || dst[2] < 'a'))
	{
		ans = '5';
	}
	else if (squareCheck(arr, dst))
	{
		ans = '6';
	}
	else if (_location[0] == dst[2] && _location[1] == dst[3])
	{
		ans = '7';
	}
	return ans;
}


/*

*/
bool Pawn::squareCheck(Pieces* arr[][8], string dst)
{
	bool ans = false;
	int y1 = int(dst[1] - '0'), y2 = int(dst[3] - '0'), x1 = int(dst[0] - 'a') + 1, x2 = int(dst[2] - 'a') + 1;
	// Indexes are as follows: x1 and y1 are the source indexes, x2 and y2 are the destination indexes
	if (_side[0] == 'W' && y1 == 2 && y2 == y1 + 2 && x1 == x2) // White pawn special move up, if they are white and in the second row from the bottom
	{
		if (!(arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken())) // Check if destination is not taken
		{
			return ans;
		}
	}

	if (_side[0] == 'B' && y1 == 7 && y2 == y1 - 2 && x1 == x2) // Black pawn special move down, if they are black and in the second row from the top
	{
		if (!(arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken())) // Check if destination is not taken
		{
			return ans;
		}
	}

	if (_side[0] == 'W' && x1 == x2 && y1 == y2 - 1 && !(arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken())) // White move one up and its free
	{ // Check if white and if only one step up and if it is not taken
		return ans;
	}

	if (_side[0] == 'B' && x1 == x2 && y1 == y2 + 1 && !(arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken())) // Black move one down and its free
	{ // Check if black and if only one step down and if it is not taken
		return ans;
	}

	if ((_side[0] == 'W' && x1 == x2 + 1 && y1 == y2 - 1) /* UP LEFT */ && (arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken()) || (_side[0] == 'W' && x1 == x2 - 1 && y1 == y2 - 1) /* UP RIGHT */ && (arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken())) // White eating
	{ // Check if white and for each side check if taken, if yes then eat
		return ans;
	}
	
	if ((_side[0] == 'B' && x1 == x2 + 1 && y1 == y2 + 1) /* DOWN LEFT */ && (arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken()) || (_side[0] == 'B' && x1 == x2 - 1 && y1 == y2 + 1) /* DOWN RIGHT */ && (arr[int('8' - dst[3])][int(dst[2] - 'a')]->getTaken())) // Black eating
	{ // Check if black and for each side check if taken, if yes then eat
		return ans;
	}

	ans = true;
	return ans;
}
