#ifndef _BATTLESHIP_H
#define _BATTLESHIP_H
#include <iostream>
using namespace std;
class Battleship {
private:
	int length;
	static int ShipPlace;
public:
	Battleship();
	void setShipPlace();
	void setLength(int x);
	int getlen() const;  
	int getShipPlace() const;
};
#endif // !_BATTLESHIP_H
