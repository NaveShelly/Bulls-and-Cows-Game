#include "BattleshipHw2.2.h"
Battleship::Battleship()
{
	length = 0;
	ShipPlace = 0;
}
int Battleship::ShipPlace = 0;
void Battleship::setShipPlace()
{
	ShipPlace++;
}
void Battleship::setLength(int x)
{
	x = x - 1;
	if (x == 4)
		length = 3;
	if (x == 3)
		length = 2;
	if (x == 2)
		length = 3;
	if (x == 1)
		length = 4;
	if (x == 0)
		length = 5;
}

int Battleship::getlen() const { return length; }
int Battleship::getShipPlace()const{ return ShipPlace; }