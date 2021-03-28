#ifndef _Game_H
#include "BattleshipHw2.2.h"
#define _BATTLESHIP_H
#define _Game_H
#define BS 10
class Game {
private:
	char board[BS][BS];
	Battleship *ships;
	int CellsCount;
	void ClearBoard();
	bool CheckPlace(int x, int y, int z, int &place) const;
	int CheckHit(int x, int y) ;
	void BuildBoard(int counter);
	void CheckSunk(int cordx, int cordy)const;
public:
	friend class Battleship;
	Game();
	Game(int x);
	~Game();
	void PrintOriginalBoard() const;
	char Printboard(char boardt[BS][BS],int x,int y,int b) const;
	void Play() const;
};
#endif // !_BATTLESHIP_H