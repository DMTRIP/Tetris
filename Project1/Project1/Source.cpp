#include <iostream>
#include <iomanip>
#include <ctime>
#include <dos.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>



using namespace std;

bool gameOver;

int const fieldWidth = 10;
int const fieldHeight = 20;
int score = 0;

int counter = 0;
int counterPos = 0;



/*int figRand = 5;*/ // определяет какая фигура появится на поле

enum eDirection { STOP = 0, LEFT, RIGHT, DOWN, CHANGEPOS, FINISHED };
eDirection dir;


struct figure_1
{
	int x1 = 0;
	int y1 = fieldWidth / 2;

	int x2 = 1;
	int y2 = fieldWidth / 2;

	int x3 = 2;
	int y3 = fieldWidth / 2;

	int x4 = 3;
	int y4 = fieldWidth / 2;
};
figure_1 kooF1;


// koo

int nx;
int ny;

int nx2;
int ny2;

int nx3;
int ny3;

int nx4;
int ny4;
//
int & pnx = nx;
int & pny = ny;

int & pnx2 = nx2;
int & pny2 = ny2;

int & pnx3 = nx3;
int & pny3 = ny3;

int & pnx4 = nx4;
int & pny4 = ny4;

///void getKoo(int);
void Setup();
void Draw(char arr[][fieldWidth], int);
void Input();
void Logic();
void getKoo(figure_1 &f);

char field[fieldHeight][fieldWidth];

void finished();

void InitFig1(figure_1 &f)
{
	f.x1 = 0;
	f.y1 = fieldWidth / 2;

	f.x2 = 1;
	f.y2 = fieldWidth / 2;

	f.x3 = 2;
	f.y3 = fieldWidth / 2;

	f.x4 = 3;
	f.y4 = fieldWidth / 2;
}
void InitFig2(figure_1 &f)
{
	f.x1 = 0;
	f.y1 = (fieldWidth / 2) + 1;

	f.x2 = 0;
	f.y2 = fieldWidth / 2;

	f.x3 = 1;
	f.y3 = fieldWidth / 2;

	f.x4 = 1;
	f.y4 = (fieldWidth / 2) - 1;
}
void InitFig3(figure_1 &f)
{
	f.x1 = 0;
	f.y1 = fieldWidth / 2;

	f.x2 = 0;
	f.y2 = (fieldWidth / 2) - 1;

	f.x3 = 1;
	f.y3 = fieldWidth / 2;

	f.x4 = 1;
	f.y4 = (fieldWidth / 2) - 1;
}
void InitFig4(figure_1 &f)
{
	f.x1 = 0;
	f.y1 = fieldWidth / 2;

	f.x2 = 1;
	f.y2 = (fieldWidth / 2) + 1;

	f.x3 = 1;
	f.y3 = fieldWidth / 2;

	f.x4 = 1;
	f.y4 = (fieldWidth / 2) - 1;
}
void InitFig5(figure_1 &f)
{
	f.x1 = 0;
	f.y1 = (fieldWidth / 2) - 1;

	f.x2 = 1;
	f.y2 = (fieldWidth / 2) + 1;

	f.x3 = 1;
	f.y3 = fieldWidth / 2;

	f.x4 = 1;
	f.y4 = (fieldWidth / 2) - 1;
}
void InitFig6(figure_1 &f)
{
	f.x1 = 0;
	f.y1 = (fieldWidth / 2) - 1;

	f.x2 = 1;
	f.y2 = (fieldWidth / 2) - 1;

	f.x3 = 1;
	f.y3 = fieldWidth / 2;

	f.x4 = 2;
	f.y4 = (fieldWidth / 2);
}
void RememerFigure()
{
	field[kooF1.x1][kooF1.y1] = 'x';
	field[kooF1.x2][kooF1.y2] = 'x';
	field[kooF1.x3][kooF1.y3] = 'x';
	field[kooF1.x4][kooF1.y4] = 'x';
}

void ClearFigure()
{
	field[kooF1.x1][kooF1.y1] = ' ';
	field[kooF1.x2][kooF1.y2] = ' ';
	field[kooF1.x3][kooF1.y3] = ' ';
	field[kooF1.x4][kooF1.y4] = ' ';
}

int* pFigNumber;
int main()
{
	srand(time(0));

	while (true)
	{
		int figNumber = 0;// rand() % 6;
		pFigNumber = &figNumber;
		switch (figNumber)
		{
		case 0: InitFig1(kooF1); break;
		case 1: InitFig2(kooF1); break;
		case 2: InitFig3(kooF1); break;
		case 3: InitFig4(kooF1); break;
		case 4: InitFig5(kooF1); break;
		case 5: InitFig5(kooF1); break;
		}

		while (!gameOver)
		{
			//getKoo(1);
			Setup();
			Draw(field, figNumber);
			Input();
			Logic();
			finished();
			if (dir == FINISHED)
			{
				RememerFigure();
				break;
			}
		}
	}
	system("pause");
}
void Setup()
{
	gameOver = false;
	//dir = DOWN;
}
void Draw(char arr[][fieldWidth], int figNumber)
{

	int time = 0;
	int randa = 1;

	cout << "-----------------------\n";

	for (int i = 0; i < fieldHeight; i++)
	{
		cout << '|';
		for (int j = 0; j < fieldWidth; j++)
		{
			RememerFigure();
			cout << setw(2) << arr[i][j];
		}
		cout << " |";
		cout << endl;
	}
	cout << "-----------------------\n";
	system("cls");
	ClearFigure();
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
		{
			dir = CHANGEPOS;
			break;
		}

		case 'a':
		{
			dir = LEFT;
			break;
		}
		case 'd':
		{
			dir = RIGHT;
			break;
		}
		case 's':
		{
			dir = DOWN;
		}
		}
	}
}

void Logic()
{
	switch (dir)
	{
	case LEFT:
	{

		//  STATR MOVE FIGURE  LEFT
		if (kooF1.y1 > 0 && kooF1.y2 > 0 && kooF1.y3 > 0 && kooF1.y4 > 0)
		{
			kooF1.y1--;
			kooF1.y2--;
			kooF1.y3--;
			kooF1.y4--;
			dir = STOP;
		}
		break;
	}

	case RIGHT:
	{
		//  STATR MOVE FIGURE  RIGHT
		if (kooF1.y1 < 9 && kooF1.y2 < 9 && kooF1.y3 < 9 && kooF1.y4 < 9)
		{
			kooF1.y1++;
			kooF1.y2++;
			kooF1.y3++;
			kooF1.y4++;
			dir = STOP;
		}
		break;
	}


	case DOWN:
	{
		//  STATR MOVE FIGURE  DOWN
		if (kooF1.x1 < 19 && kooF1.x2 < 19 && kooF1.x3 < 19 && kooF1.x4 < 19)
		{
			if (!(field[kooF1.x4 + 1][kooF1.y4] == 'x'))
			{
				kooF1.x1++;
				kooF1.x2++;
				kooF1.x3++;
				kooF1.x4++;

			}
			dir = STOP;

		}
		break;
	}


	case CHANGEPOS:
	{
		if ((*pFigNumber) == 0)
		{
			//first figure
			if (kooF1.y4 < 10 && kooF1.y1 < 8 && kooF1.y1 >= 0 && kooF1.y4  > 0 && kooF1.x1 < 17)//fix вихода фигуры за поле 
			{
				if (counterPos == 0)
				{

					getKoo(kooF1);

					kooF1.x1 = nx + 1;
					kooF1.x2 = nx2;
					kooF1.x3 = nx3 - 1;
					kooF1.x4 = nx4 - 2;

					kooF1.y1 = ny - 1;
					kooF1.y2 = ny2;
					kooF1.y3 = ny3 + 1;
					kooF1.y4 = ny4 + 2;
					counterPos++;

				}
				else if (counterPos == 1)
				{
					getKoo(kooF1);
					kooF1.x1 = nx - 1;
					kooF1.x2 = nx2;
					kooF1.x3 = nx3 + 1;
					kooF1.x4 = nx4 + 2;

					kooF1.y1 = ny + 1;
					kooF1.y2 = ny2;
					kooF1.y3 = ny3 - 1;
					kooF1.y4 = ny4 - 2;

					counterPos = 0;
				}
			}
		}
		else if ((*pFigNumber) == 1)
		{
			//second figure
			if (kooF1.y1 < 10 && kooF1.y4 >= 0 && kooF1.y3 > 0 && kooF1.x4 < 19) // fix  вихода фигуры за поле
			{
				if (counterPos == 0)
				{
					getKoo(kooF1);

					kooF1.x1 = nx + 1;
					kooF1.x2 = nx2;
					kooF1.x3 = nx3;
					kooF1.x4 = nx + 2;

					kooF1.y1 = ny;
					kooF1.y2 = ny2;
					kooF1.y3 = ny3;
					kooF1.y4 = ny4 + 2;


					counterPos++;
				}
				else if (counterPos == 1)
				{
					getKoo(kooF1);

					kooF1.x1 = nx - 1;
					kooF1.x2 = nx2;
					kooF1.x3 = nx3;
					kooF1.x4 = nx;

					kooF1.y1 = ny;
					kooF1.y2 = ny2;
					kooF1.y3 = ny3;
					kooF1.y4 = ny4 - 2;

					counterPos = 0;

				}
			}
		}
		else if ((*pFigNumber) == 3)
		{
			//fouth figure
			if (kooF1.y3 > 0 && kooF1.y3 < 9 && kooF1.x3 < 18)
			{

				if (counterPos == 0)
				{
					getKoo(kooF1);

					kooF1.x1 = nx;
					kooF1.x2 = nx2;
					kooF1.x3 = nx3;
					kooF1.x4 = nx4 + 1;

					kooF1.y1 = ny;
					kooF1.y2 = ny2;
					kooF1.y3 = ny3;
					kooF1.y4 = ny4 + 1;
					counterPos++;
				}
				else if (counterPos == 1)
				{

					getKoo(kooF1);
					kooF1.x1 = nx + 2;
					kooF1.x2 = nx2;
					kooF1.x3 = nx3;
					kooF1.x4 = nx4 - 1;

					kooF1.y1 = ny;
					kooF1.y2 = ny2;
					kooF1.y3 = ny3;
					kooF1.y4 = ny4 - 1;
					counterPos++;
				}

				else if (counterPos == 2)
				{

					getKoo(kooF1);
					kooF1.x1 = nx - 2;
					kooF1.x2 = nx2 + 1;
					kooF1.x3 = nx3;
					kooF1.x4 = nx4;

					kooF1.y1 = ny;
					kooF1.y2 = ny2 - 1;
					kooF1.y3 = ny3;
					kooF1.y4 = ny4;
					counterPos++;
				}
				else if (counterPos == 3)
				{

					getKoo(kooF1);
					kooF1.x1 = nx;
					kooF1.x2 = nx2 - 1;
					kooF1.x3 = nx3;
					kooF1.x4 = nx4;

					kooF1.y1 = ny;
					kooF1.y2 = ny2 + 1;
					kooF1.y3 = ny3;
					kooF1.y4 = ny4;
					counterPos = 0;
				}
			}
		}
		else if ((*pFigNumber) == 4)
		{
			//fivth figure
			if (counterPos == 0)
			{
				if (kooF1.x4 < 18)
				{
					counterPos++;
					getKoo(kooF1);

					kooF1.x1 = nx;
					kooF1.x2 = nx2 - 1;
					kooF1.x3 = nx3 + 1;
					kooF1.x4 = nx4;

					kooF1.y1 = ny;
					kooF1.y2 = ny2 - 1;
					kooF1.y3 = ny3 - 1;
					kooF1.y4 = ny4;
				}

			}
			else if (counterPos == 1)
			{
				if (kooF1.y1 > 0)
				{
					counterPos++;
					getKoo(kooF1);

					kooF1.x1 = nx;
					kooF1.x2 = nx2;
					kooF1.x3 = nx3 - 1;
					kooF1.x4 = nx4 - 1;

					kooF1.y1 = ny;
					kooF1.y2 = ny2;
					kooF1.y3 = ny3 + 1;
					kooF1.y4 = ny4 - 1;
				}

			}
			else if (counterPos == 2)
			{
				if (kooF1.x3 < 18)
				{
					counterPos++;
					getKoo(kooF1);
					kooF1.x1 = nx + 2;
					kooF1.x2 = nx2;
					kooF1.x3 = nx3;
					kooF1.x4 = nx4 + 2;

					kooF1.y1 = ny + 1;
					kooF1.y2 = ny2;
					kooF1.y3 = ny3;
					kooF1.y4 = ny4 + 1;
				}

			}
			else if (counterPos == 3)
			{
				if (kooF1.y3 < 9)
				{
					counterPos++;
					getKoo(kooF1);
					kooF1.x1 = nx - 2;
					kooF1.x2 = nx2 + 1;
					kooF1.x3 = nx3;
					kooF1.x4 = nx4 - 1;

					kooF1.y1 = ny - 1;
					kooF1.y2 = ny2 + 1;
					kooF1.y3 = ny3;
					kooF1.y4 = ny4;
					counterPos = 0;
				}
			}
		}
		else if ((*pFigNumber) == 5)
		{

		}
		dir = STOP;
	}
	}
}

void finished()
{
	const int bottom = 18;
	//проветка дошла ли фигура до конца масива
	if (kooF1.x1 > bottom || kooF1.x2 > bottom || kooF1.x3 > bottom || kooF1.x4 > bottom)
	{
		dir = FINISHED;
	}

}

void getKoo(figure_1 &f)
{
	pnx = f.x1;
	pny = f.y1;

	pnx2 = f.x2;
	pny2 = f.y2;

	pnx3 = f.x3;
	pny3 = f.y3;

	pnx4 = f.x4;
	pny4 = f.y4;
}
