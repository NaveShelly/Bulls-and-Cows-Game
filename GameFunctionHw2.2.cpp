#include "GameHw2.2.h"
#include <time.h>
Game::Game()//Ctor
{
	cout << "Game Starting!" << endl;
	CellsCount = 0;
}
Game::Game(int x)//Ctor Set
{
	if (x <= 5 && x >= 1)
	{
		ships = new Battleship[x];
		for (int i = 1; i <= x; i++)
		{
			ships[i].setShipPlace();
			ships[i].setLength(i);
		}
	}
	else 
		ships = new Battleship[1];
	if (x <= 5 && x >= 1)
	{
		for (int i = 1; i <= x; i++)
		{
			CellsCount =CellsCount+ships[i].getlen();
		}
	}
	else
		CellsCount=ships[0].getlen();
}
Game ::~Game()//d'ctor
{
	delete ships;
}
void Game::ClearBoard()//New Strating Board
{
	for(int i = 0; i < BS; i++)
	{
		for (int j = 0; j < BS; j++)
		{
			board[i][j] = '~';
		}
	}
}
bool Game::CheckPlace (int x, int y, int z, int &place) const//check free place's for ships
{
	int c = 0, s = y, flag = 1,d,flag1[4];
	//for (int i = 0; i < ships[z].getlen(); i++)
	//{
	//	if (board[x][s] == '~' && s >= 0 && s <= 9)
	//	{
	//		for (int j = 0; j < ships[z].getlen(); j++)
	//		{
	//			if (board[x][s + 1] == '~' && board[x][s - 1] == '~' && board[x-1][s] == '~' && board[x+1][s] == '~' )
	//			{
	//				c++;
	//			}
	//		}
	//	}
	//	else c--;
	//	s++;
	//}
	for (int i = 0; i < ships[z].getlen(); i++)
	{
		if (board[x][s] == '~' && s >= 0 && s <= 9)
			 c++;
		else c--;
			s++;
	}
	if (c == ships[z].getlen())
	{
		flag = 0;
		flag1[0] = 0;
	}
	s = y;
	c = 0;
	/*for (int i = 0; i < ships[z].getlen(); i++)
	{
		if (board[x][s] == '~' && s >= 0 && s <= 9)
		{
			for (int j = 0; j < ships[z].getlen(); j++)
			{
				if (board[x][s-1] == '~' && board[x][s + 1] == '~' && board[x-1][s] == '~' && board[x+1][s + 1] == '~')
				{
					c++;
				}
			}
		}
		else c--;
		s--;
	}*/
	for (int i = 0; i < ships[z].getlen(); i++)
	{
		if (board[x][s] == '~' &&s >= 0 && s <= 9)
			c++;
		else c--;
			s--;
	}
	if (c == ships[z].getlen())
	{
		flag = 0;
		flag1[1] = 0;
	}

	s = x;
	c = 0;
	for (int i = 0; i < ships[z].getlen(); i++)
	{
		if (board[s][y] == '~' &&s >= 0 && s <= 9)
			c++;
		else c--;
			s++;
	}
	/*for (int i = 0; i < ships[z].getlen(); i++)
	{
		if (board[x][s] == '~' && s >= 0 && s <= 9)
		{
			for (int j = 0; j < ships[z].getlen(); j++)
			{
				if (board[s + 1][y] == '~' && board[s - 1][y] == '~' && board[s][y + 1] == '~' && board[s][y - 1] == '~')
				{
					c++;
				}
			}
		}
		else c--;
		s++;
	}*/
	if (c == ships[z].getlen())
	{
		flag = 0;
		flag1[2] = 0;
	}
	s = x;
	c = 0;
	for (int i = 0; i < ships[z].getlen(); i++)
	{
		if (board[s][y] == '~' && s >= 0 && s <= 9)
			c++;
		else c--;
			s--;
	}
	/*for (int i = 0; i < ships[z].getlen(); i++)
	{
		if (board[x][s] == '~' && s >= 0 && s <= 9)
		{
			for (int j = 0; j < ships[z].getlen(); j++)
			{
				if (board[s + 1][y] == '~' && board[s - 1][y] == '~' && board[s][y + 1] == '~' && board[s][y - 1] == '~')
				{
					c++;
				}
			}
		}
		else c--;
		s--;
	}*/
	if (c == ships[z].getlen())
	{
		flag = 0;
		flag1[3] = 0;
	}
	if (flag == 0 || flag1[0] == 0 || flag1[1] == 0 || flag1[2] == 0 || flag1[3]==0)
	{
		//cout << "Place Are Allowed" << endl;
		int d=1;
		int ch;
		while (d == 1)
		{
			ch = (rand() % 4);
			if (flag1[ch] == 0 && d != 0)
			{
				place = ch;
				d = 0;
				return 1;
			}
		}
	}
	if (flag == 1)
	{
		return 0;
		//cout << "Place Are Busy";
	}
}
void Game::BuildBoard(int counter)//Build Ships And boards for play
{
	int Cordx, Cordy, answer, flag = 1, c = 0, s, flag1 = 1,ch;
	srand(time(NULL));
	ClearBoard();
	Cordx = (rand() % 9);
	Cordy = (rand() % 9);
	for(int z=0;z<=counter;z++)
	{
		while (flag == 1)
		{
			cout << endl;
			while (flag1 == 1)
		 {
			Cordx = (rand() % 9);
			Cordy = (rand() % 9);
			for (int i = 0; i < 3; i++)
			{
				if (board[(Cordx + i)][Cordy] == 'S' || board[(Cordx - i)][Cordy] == 'S' || board[(Cordx)][Cordy + i] == 'S' || board[(Cordx)][Cordy - i]=='S')
				{
					flag1 == 1;
				}
				if (board[(Cordx + i+1)][Cordy] == 'S' || board[(Cordx - i-1)][Cordy] == 'S' || board[(Cordx)][Cordy + i+1] == 'S' || board[(Cordx)][Cordy - i-1] == 'S')
				{
					flag1 == 1;
				}
				else
					flag1 = 0;
			}
		 }
			c = 0;
			flag1 = 1;
			int place;
			int answer2[4] = {0,0,0,0};
			answer = CheckPlace(Cordx, Cordy, z, place);
			answer2[0] = CheckPlace(Cordx + 1, Cordy, z, place);
			answer2[1] = CheckPlace(Cordx - 1, Cordy, z, place);
			answer2[2] = CheckPlace(Cordx , Cordy+1, z, place);
			answer2[3] = CheckPlace(Cordx , Cordy-1, z, place);
			
			if (answer2[0]==1&&answer2[1]==1&&answer2[2]==1&&answer2[3]==1)
			 {
					ch = (rand() % 2);
				if (ch == 0)
				{
					s = Cordy;
					if (place == 0)
					{
						for (int i = 0; i < ships[z].getlen() && flag != 0; i++)
						{
							if (board[Cordx][s] == '~')
								c++;
							else c--;
							s++;
						}
						if (c == ships[z].getlen())
						{
							flag = 0;
							for (int j = 0; j < ships[z].getlen(); j++)
							{
								board[Cordx][Cordy] = 'S';
								Cordy++;
							}
						}
					}
					s = Cordy;
					c = 0;
					if (place == 1)
					{
						for (int i = 0; i < ships[z].getlen() && flag != 0; i++)
						{
							if (board[Cordx][s] == '~')
								c++;
							else c--;
							s--;
						}
						if (c == ships[z].getlen())
						{
							flag = 0;
							for (int j = 0; j < ships[z].getlen(); j++)
							{
								board[Cordx][Cordy] = 'S';
								Cordy--;
							}
						}
					}
				}
			if (ch==1)
				{
					s = Cordx;
					c = 0;
					if (place == 2)
					{
						for (int i = 0; i < ships[z].getlen() && flag != 0; i++)
						{
							if (board[s][Cordy] == '~')
								c++;
							else c--;
							s++;
						}
						if (c == ships[z].getlen())
						{
							flag = 0;
							for (int j = 0; j < ships[z].getlen(); j++)
							{
								board[Cordx][Cordy] = 'S';
								Cordx++;
							}
							flag = 0;
						}
					}
					s = Cordx;
					c = 0;
					if (place==3)
					{ 
					for (int i = 0; i < ships[z].getlen() && flag != 0; i++)
					{
						if (board[s][Cordy] == '~')
							c++;
						else c--;
						s--;
					}
					if (c == ships[z].getlen())
					{
						flag = 0;
						for (int j = 0; j < ships[z].getlen(); j++)
						{
							board[Cordx][Cordy] = 'S';
							Cordx--;
						}
					}
					}
				}
			}
			answer=3;
		}
		flag = 1;
	}
	cout << "All The Ships Are Buileded Up" << endl;
}
void Game::PrintOriginalBoard()const //Board For The Hint of the Game
{
	char var = 65;
	cout << " ";
	for (int i = 0; i < BS; i++)
	{
		cout <<" "<< (char)(var + i);
	}
	cout << endl;
	for (int i = 0; i < BS; i++)
	{
		cout << i<<" ";
		for (int j = 0; j < BS; j++)
		{
			cout << board[i][j]<< " ";
		}
		cout << endl;
	}
}
char Game::Printboard(char boardt[BS][BS],int x,int y,int b)const // Print The Board after Hit or Miss
{
	cout << endl;
	char var = 65;
	cout << " ";
	if (boardt[0][0] != '~')
	{
		for (int i = 0; i < BS; i++)
		{
			for (int j = 0; j < BS; j++)
			{
				boardt[i][j] = '~';
			}
		}
		cout << " ";
	}
	for (int i = 0; i < BS; i++)
	{
		cout << " " << (char)(var + i);
	}
	cout << endl;
	if (b == 1)
	{
		boardt[x][y] = '@';
	}
	else if(board[x][y]!='@')
		boardt[x][y] = 'X';
	for (int i = 0; i < BS; i++)
	{
		cout << i << " ";
		for (int j = 0; j < BS; j++)
		{
			cout << boardt[i][j] << " ";
		}
		cout << endl;
	}
	return boardt[BS][BS];
	cout << endl;
}
int Game::CheckHit(int x, int y) //Check Hit Or miss
{
	if (board[x][y] == 'S')
	{
		cout << "Nice Shot! you hit the ship" << endl;
		board[x][y] = '@';
		return 1;
	}
	else
	{
		cout << "you miss" << endl;
		if (board[x][y] != '@')
		{
			board[x][y] = 'X';
		}
		return 0;
	}
}
void Game::CheckSunk(int cordx, int cordy) const//Check If Ship destroied or not
{
	int flag[4] = { 0,0,0,0 };
	for (int i = 0; i < 5; i++)
	{
		if (board[cordx + i][cordy]  != 'S' && flag[0] != 1)
		{
			flag[0] = 0;
		}
		else if(board[cordx + i][cordy] == 'S')
			flag[0] = 1;
	}
	for (int i = 0; i < 5; i++)
	{
		if (board[cordx - i][cordy] != 'S'&&flag[1]!=1)
		{
			flag[1] = 0;
		}
		else if (board[cordx - i][cordy] == 'S')
			flag[1] = 1;
	}
	for (int i = 0; i < 5; i++)
	{
		if (board[cordx][cordy+i] != 'S'&&flag[2]!=1)
		{
			flag[2] = 0;
		}
		else if (board[cordx ][cordy-i] == 'S')
			flag[2] = 1;
	}
	for (int i = 0; i < 5; i++)
	{
		if (board[cordx][cordy - i] != 'S'&&flag[3]!=1)
		{
			flag[3] = 0;
		}
		else if (board[cordx][cordy + i] == 'S')
			flag[3] = 1;
	}
	if ((flag[0] == 0 && flag[1]==0) && (flag[2]==0 && flag[3]==0))
	{
		cout << "You destroied the Ship" << endl;
	}
}
void Game::Play()const//Game Play
{
	int Leaving = 0;
	while (Leaving == 0)
	{
		int x, rounds = 0, cordx = 99, cordy = 99, answer;
		char boardt[BS][BS];
		cout << "How many battleships do you want to place on board ?" << endl;
		cin >> x;
		Game Fun(x);
		Fun.BuildBoard(x);
		do
		{
			cout << "Do you want a Hint? 1[Yes] \ 0[No]" << endl;
			cin >> x;
		} while (x != 0 && x != 1);
		if (x == 1)
		{
			Fun.PrintOriginalBoard();
		}
		while (Fun.CellsCount != 0)
		{
			cout << endl;
			while (cordx < 0 || cordx > 9 || cordy < 0 || cordy > 9)
			{
				cout << "Enter cordention for try to hit the ships " << endl;
				cout << "Enter X cordention(0-9) only" << endl;
				cin >> cordx;
				cout << "Enter Y cordention(0-9) only" << endl;
				cin >> cordy;
			}
			cout << endl;
			answer = Fun.CheckHit(cordx, cordy);
			boardt[BS][BS] = Fun.Printboard(boardt, cordx, cordy, answer);
			if (answer == 1)
			{
				Fun.CellsCount--;
				Fun.CheckSunk(cordx, cordy);
			}
			rounds++;
			cordx = 99;
			cordy = 99;
			int answer;
		}
		cout << "You Won!" << endl;
		Leaving = 2;
		do
		{
			cout << "New Game? 1[Yes] 0[No]" << endl;
			cin >> Leaving;
		} while (Leaving != 0 && Leaving != 1);
	}
	cout << "Good Bye" << endl;
}
