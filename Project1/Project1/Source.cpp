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


int nx;
int ny;

int nx2;
int ny2;

int nx3;
int ny3;

int nx4;
int ny4;

int & pnx = nx;
int & pny = ny;

int & pnx2 = nx2;
int & pny2 = ny2;

int & pnx3 = nx3;
int & pny3 = ny3;

int & pnx4 = nx4;
int & pny4 = ny4;


int counter_pos_1 = 0;
int& pcounter_pos_1 = counter_pos_1;



/*int figRand = 5;*/ // определяет какая фигура появится на поле

enum eDirection { STOP = 0, LEFT, RIGHT, DOWN, CHANGEPOS, FINISHED,SCORE };
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




///void getKoo(int);
void Setup();
void Draw(char arr[][fieldWidth], int);
void Input();
void Logic(int numberFigure,int& counterPos);
void getKoo(figure_1 &f);
void DrawNextFigure(int a);
char field[fieldHeight][fieldWidth];
void ShowNextFig(char[][4]);
void finished(int numberFigure,int& counterPos);
void score();

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
	f.x1 = 1;
	f.y1 = fieldWidth / 2;

	f.x2 = 0;
	f.y2 = (fieldWidth / 2) + 1;

	f.x3 = 0;
	f.y3 = fieldWidth / 2;

	f.x4 = 0;
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
	field[kooF1.x1][kooF1.y1] = '1';
	field[kooF1.x2][kooF1.y2] = '2';
	field[kooF1.x3][kooF1.y3] = '3';
	field[kooF1.x4][kooF1.y4] = '4';
}

void ClearFigure()
{
	field[kooF1.x1][kooF1.y1] = ' ';
	field[kooF1.x2][kooF1.y2] = ' ';
	field[kooF1.x3][kooF1.y3] = ' ';
	field[kooF1.x4][kooF1.y4] = ' ';
}
                
int RandFigNumb = rand() % 5;
int figNumber;
int* pFigNumber = &figNumber;


int main()
{
	//pcounter_pos_1 = 0;
	figNumber = 4;

	while (true)
	{
		//рандомим фигуру 
		if (kooF1.y3 >= 0)
		{
			srand(time(0));
			RandFigNumb = rand() % 5;
		}
		
		switch (figNumber)
		{
		case 0: InitFig1(kooF1); break;
		case 1: InitFig2(kooF1); break;
		case 2: InitFig3(kooF1); break;
		case 3: InitFig4(kooF1); break;
		case 4: InitFig5(kooF1); break;
		//case 5: InitFig6(kooF1); break;
		}

		while (!gameOver)
		{
			//getKoo(1);
			Setup();
			Draw(field, figNumber);
			Input();
			Logic(figNumber,pcounter_pos_1);
			finished(figNumber,pcounter_pos_1);
			//score();
			if (dir == FINISHED)
			{
				pcounter_pos_1 = 0;
				//figNumber = RandFigNumb;
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
	cout<<"fig: "<<figNumber<<endl;
	DrawNextFigure(RandFigNumb);

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

void Logic(int numberFigure, int& counterPos)
{
	switch (dir)
	{
	case LEFT:
	{

		//  STATR MOVE FIGURE  LEFT
		if (kooF1.y1 > 0 && kooF1.y2 > 0 && kooF1.y3 > 0 && kooF1.y4 > 0)
		{
			if (numberFigure == 0)
			{
				if (counterPos == 0)
				{
					if (!(field[kooF1.x1][kooF1.y1 - 1] == 'x' || field[kooF1.x2][kooF1.y2 - 1] == 'x' || field[kooF1.x3][kooF1.y3 - 1] == 'x' || field[kooF1.x4][kooF1.y4 - 1] == 'x'))
					{
						kooF1.y1--;
						kooF1.y2--;
						kooF1.y3--;
						kooF1.y4--;
						dir = STOP;
					}

				}
				else if (counterPos == 1)
				{
					if (!(field[kooF1.x1][kooF1.y1 - 1] == 'x'))
					{
						kooF1.y1--;
						kooF1.y2--;
						kooF1.y3--;
						kooF1.y4--;
						dir = STOP;
					}
				}

			}
			else if (numberFigure == 1)
			{
				if (counterPos == 0)
				{
					if (!(field[kooF1.x4][kooF1.y4 - 1] == 'x' || field[kooF1.x2][kooF1.y2 - 1] == 'x'))
					{
						kooF1.y1--;
						kooF1.y2--;
						kooF1.y3--;
						kooF1.y4--;
						dir = STOP;
					}
				}
				else if (counterPos == 1)
				{
					if (!(field[kooF1.x3][kooF1.y3 - 1] == 'x' || field[kooF1.x2][kooF1.y2 - 1] == 'x' || field[kooF1.x4][kooF1.y4 - 1] == 'x'))
					{
						kooF1.y1--;
						kooF1.y2--;
						kooF1.y3--;
						kooF1.y4--;
						dir = STOP;
					}
				}


			}
			else if (numberFigure == 2)
			{
				if (field[kooF1.x4][kooF1.y4 - 1] == 'x' || field[kooF1.x2][kooF1.y2 - 1] == 'x')
				{

				}
				else
				{
					kooF1.y1--;
					kooF1.y2--;
					kooF1.y3--;
					kooF1.y4--;
					dir = STOP;
				}
			}
			else if (numberFigure == 3)
			{
				if (field[kooF1.x4][kooF1.y4 - 1] == 'x' || field[kooF1.x1][kooF1.y1 - 1] == 'x')
				{

				}
				else
				{
					kooF1.y1--;
					kooF1.y2--;
					kooF1.y3--;
					kooF1.y4--;
					dir = STOP;
				}
			}
			else if (numberFigure == 4)
			{
				if (field[kooF1.x4][kooF1.y4 - 1] == 'x' || field[kooF1.x1][kooF1.y1 - 1] == 'x')
				{

				}
				else
				{
					kooF1.y1--;
					kooF1.y2--;
					kooF1.y3--;
					kooF1.y4--;
					dir = STOP;
				}
			}
			else if (numberFigure == 5)
			{
				if (field[kooF1.x2][kooF1.y2 - 1] == 'x' || field[kooF1.x1][kooF1.y1 - 1] == 'x' || field[kooF1.x4][kooF1.y4 - 1] == 'x')
				{

				}
				else
				{
					kooF1.y1--;
					kooF1.y2--;
					kooF1.y3--;
					kooF1.y4--;
					dir = STOP;
				}
			}


		}
		break;
	}

	case RIGHT:
	{
		//  STATR MOVE FIGURE  RIGHT
		if (kooF1.y1 < 9 && kooF1.y2 < 9 && kooF1.y3 < 9 && kooF1.y4 < 9)
		{
			if (numberFigure == 0)
			{
				if (counterPos == 0)
				{
					if (!(field[kooF1.x1][kooF1.y1 + 1] == 'x' || field[kooF1.x2][kooF1.y2 + 1] == 'x' || field[kooF1.x3][kooF1.y3 + 1] == 'x' || field[kooF1.x4][kooF1.y4 + 1] == 'x'))
					{
						kooF1.y1++;
						kooF1.y2++;
						kooF1.y3++;
						kooF1.y4++;
						dir = STOP;
					}
				}
				else if (counterPos == 1)
				{
					if (!(field[kooF1.x4][kooF1.y1 + 4] == 'x'))
					{
						kooF1.y1++;
						kooF1.y2++;
						kooF1.y3++;
						kooF1.y4++;
						dir = STOP;
					}
				}

			}
			else if (numberFigure == 1)
			{
				if (counterPos == 0)
				{
					if (!(field[kooF1.x1][kooF1.y1 + 1] == 'x' || field[kooF1.x3][kooF1.y3 + 1] == 'x'))
					{
						kooF1.y1++;
						kooF1.y2++;
						kooF1.y3++;
						kooF1.y4++;
						dir = STOP;
					}
				}
				else if (counterPos == 1)
				{
					if (!(field[kooF1.x1][kooF1.y1 + 1] == 'x' || field[kooF1.x2][kooF1.y2 + 1] == 'x' || field[kooF1.x4][kooF1.y4 + 1] == 'x'))
					{
						kooF1.y1++;
						kooF1.y2++;
						kooF1.y3++;
						kooF1.y4++;
						dir = STOP;
					}
				}


			}
			else if (numberFigure == 2)
			{
				if (field[kooF1.x1][kooF1.y1 + 1] == 'x' || field[kooF1.x3][kooF1.y3 + 1] == 'x')
				{

				}
				else
				{
					kooF1.y1++;
					kooF1.y2++;
					kooF1.y3++;
					kooF1.y4++;
					dir = STOP;
				}
			}
			else if (numberFigure == 3)
			{
				if (field[kooF1.x1][kooF1.y1 + 1] == 'x' || field[kooF1.x2][kooF1.y2 + 1] == 'x')
				{

				}
				else
				{
					kooF1.y1++;
					kooF1.y2++;
					kooF1.y3++;
					kooF1.y4++;
					dir = STOP;
				}
			}
			else if (numberFigure == 4)
			{
				if (field[kooF1.x2][kooF1.y2 + 1] == 'x' || field[kooF1.x1][kooF1.y1 + 1] == 'x')
				{

				}
				else
				{
					kooF1.y1++;
					kooF1.y2++;
					kooF1.y3++;
					kooF1.y4++;
					dir = STOP;
				}
			}
			else if (numberFigure == 5)
			{
				if (field[kooF1.x1][kooF1.y1 + 1] == 'x' || field[kooF1.x3][kooF1.y3 + 1] == 'x' || field[kooF1.x4][kooF1.y4 + 1] == 'x')
				{

				}
				else
				{
					kooF1.y1++;
					kooF1.y2++;
					kooF1.y3++;
					kooF1.y4++;
					dir = STOP;
				}
			}
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
		getKoo(kooF1);
		if (numberFigure == 0)
		{
			if (counterPos == 0 && kooF1.y1 < 8 && kooF1.y1 > 0)
			{

				kooF1.x1 = pnx + 1;
				kooF1.y1 = pny - 1;

				kooF1.x2 = pnx2;
				kooF1.y2 = pny2;

				kooF1.x3 = pnx3 - 1;
				kooF1.y3 = pny3 + 1;

				kooF1.x4 = pnx4 - 2;
				kooF1.y4 = pny4 + 2;
				counterPos += 1;
			}
			else if (counterPos == 1 && kooF1.x1 < 18)
			{

				kooF1.x1 -= 1;
				kooF1.y1 += 1;

				kooF1.x2;
				kooF1.y2;

				kooF1.x3 += 1;
				kooF1.y3 -= 1;

				kooF1.x4 += 2;
				kooF1.y4 -= 2;
				counterPos = 0;
			}



		}

		else if (numberFigure == 1)
		{
			if (counterPos == 0)
			{
				kooF1.x1 = pnx + 1;
				kooF1.x2 = pnx2;
				kooF1.x3 = pnx3;
				kooF1.x4 = pnx + 2;

				kooF1.y1 = pny;
				kooF1.y2 = pny2;
				kooF1.y3 = pny3;
				kooF1.y4 = pny4 + 2;
				counterPos = 1;
			}
			else if (counterPos == 1)
			{
				kooF1.x1 = pnx - 1;
				kooF1.x2 = pnx2;
				kooF1.x3 = pnx3;
				kooF1.x4 = pnx;

				kooF1.y1 = pny;
				kooF1.y2 = pny2;
				kooF1.y3 = pny3;
				kooF1.y4 = pny4 - 2;
				counterPos = 0;
			}		

		}



		else if (numberFigure == 3)
		{
			if (counterPos == 0)
			{
				kooF1.x1 = pnx;
				kooF1.y1 = pny;

				kooF1.x2 = pnx2 - 1;
				kooF1.y2 = pny2 - 1;

				kooF1.x3 = pnx3;
				kooF1.y3 = pny3;

				kooF1.x4 = pnx4;
				kooF1.y4 = pny4;
				counterPos += 1;
			}
			else if (counterPos == 1)
			{
				kooF1.x1 = pnx;
				kooF1.y1 = pny;

				kooF1.x2 = pnx2;
				kooF1.y2 = pny2;

				kooF1.x3 = pnx3;
				kooF1.y3 = pny3;

				kooF1.x4 = pnx4;
				kooF1.y4 = pny4 + 2;
				counterPos += 1;
			}
			else if (counterPos == 2)
			{
				kooF1.x1 = pnx - 2;
				kooF1.y1 = pny;

				kooF1.x2 = pnx2 + 1;
				kooF1.y2 = pny2 - 1;

				kooF1.x3 = pnx3;
				kooF1.y3 = pny3;

				kooF1.x4 = pnx4;
				kooF1.y4 = pny4;
				counterPos += 1;
			}
			else if (counterPos == 3)
			{
				kooF1.x1 = pnx + 2;
				kooF1.y1 = pny;

				kooF1.x2 = pnx2;
				kooF1.y2 = pny2 + 2;

				kooF1.x3 = pnx3;
				kooF1.y3 = pny3;

				kooF1.x4 = pnx4;
				kooF1.y4 = pny4 - 2;
				counterPos = 0;
			}
		}

		else if (numberFigure == 4)
		{
		if (counterPos == 0)
		{
			kooF1.x1 = pnx;
			kooF1.x2 = pnx2 - 1;
			kooF1.x3 = pnx3 + 1;
			kooF1.x4 = pnx4;
					   
			kooF1.y1 = pny;
			kooF1.y2 = pny2 - 1;
			kooF1.y3 = pny3 - 1;
			kooF1.y4 = pny4;
			counterPos++;
		}
		else if (counterPos == 1)
		{

			kooF1.x1 = nx;
			kooF1.x2 = nx2;
			kooF1.x3 = nx3 - 1;
			kooF1.x4 = nx4 - 1;

			kooF1.y1 = ny;
			kooF1.y2 = ny2;
			kooF1.y3 = ny3 + 1;
			kooF1.y4 = ny4 - 1;
			counterPos++;
		}
		else if (counterPos == 2)
		{
			kooF1.x1 = nx + 2;
			kooF1.x2 = nx2;
			kooF1.x3 = nx3;
			kooF1.x4 = nx4 + 2;

			kooF1.y1 = ny + 1;
			kooF1.y2 = ny2;
			kooF1.y3 = ny3;
			kooF1.y4 = ny4 + 1;
			counterPos++;
		}
		else if (counterPos == 3)
		{
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


		dir = STOP;
	}


	}
}


void finished(int numberFigure,int& counterPos)
{
	const int bottom = 18;
	//проветка дошла ли фигура до конца масива
	if (kooF1.x1 > bottom || kooF1.x2 > bottom || kooF1.x3 > bottom || kooF1.x4 > bottom)
	{
		dir = FINISHED;
	}
	
	//first figure
	if (numberFigure == 0)
	{
		if (counterPos == 0)
		{
			if (field[kooF1.x4 + 1][kooF1.y4] == 'x')
			{
				dir = FINISHED;
			}
		}
		else if (counterPos == 1)
		{
			if (field[kooF1.x1 + 1][kooF1.y1] == 'x' || field[kooF1.x2 + 1][kooF1.y2] == 'x' || field[kooF1.x3 + 1][kooF1.y3] == 'x' || field[kooF1.x4 + 1][kooF1.y4] == 'x')
			{
				dir = FINISHED;
			}
		}
		
	}
	else if (numberFigure == 1)
	{
		if (counterPos == 0)
		{
			if (field[kooF1.x4 + 1][kooF1.y4] == 'x' || field[kooF1.x3 + 1][kooF1.y3] == 'x' || field[kooF1.x1 + 1][kooF1.y1] == 'x')
			{
				dir = FINISHED;
			}
		}
		else if (counterPos == 1)
		{
			if (field[kooF1.x3 + 1][kooF1.y3] == 'x' || field[kooF1.x4 + 1][kooF1.y4] == 'x' || field[kooF1.x1 + 1][kooF1.y1] == 'x')
			{
				dir = FINISHED;
			}
		}
		
	}
	else if (numberFigure == 2)
	{
		if (field[kooF1.x4 + 1][kooF1.y4] == 'x' || field[kooF1.x3 + 1][kooF1.y3] == 'x')
		{
			dir = FINISHED;
		}
	}
	else if (numberFigure == 3)
	{
		if (field[kooF1.x4 + 1][kooF1.y4] == 'x' || field[kooF1.x3 + 1][kooF1.y3] == 'x' || field[kooF1.x2 + 1][kooF1.y2] == 'x')
		{
			dir = FINISHED;
		}
	}
	else if (numberFigure == 4)
	{
		if (field[kooF1.x4 + 1][kooF1.y4] == 'x' || field[kooF1.x3 + 1][kooF1.y3] == 'x' || field[kooF1.x2 + 1][kooF1.y2] == 'x')
		{
			dir = FINISHED;
		}
	}
	else if (numberFigure == 5)
	{
		if (field[kooF1.x4 + 1][kooF1.y4] == 'x' || field[kooF1.x2 + 1][kooF1.y2] == 'x')
		{
			dir = FINISHED;
		}
	}

	
		
	

}

//void score()
//{
//	//if (field[19][0] == 'x' && field[19][1] == 'x' && field[19][2] == 'x' && field[19][3] == 'x' && field[19][4] == 'x' && field[19][5] == 'x' && field[19][6] == 'x' && field[19][7] == 'x' && field[19][8] == 'x' && field[19][9] == 'x')
//	
//	for (int i = 0; i < fieldHeight; i++)
//	{
//		for (int j = 0; j < fieldWidth; j++)
//		{
//			if (field[i][j]);
//		}
//	}
//
//		for (int i = 0; i < 10; i++)
//		{
//			field[19][i] = ' ';
//		}
//		
//		dir = SCORE;
//	
//}

void DrawNextFigure(int a)
{
	const short sz = 4, sz1 = 4;
	char showfig[sz][sz1] =
	{
		' ','x',' ',' ',
		' ','x',' ',' ',
		' ','x',' ',' ',
		' ','x',' ',' ',
	};
	switch (a)
	{
	case 0:
	{
		ShowNextFig(showfig);
		break;
	}
	case 1:
	{
		char showfig[sz][sz1] =
		{
			' ',' ',' ',' ',
			' ','x','x',' ',
			'x','x',' ',' ',
			' ',' ',' ',' ',
		};
		ShowNextFig(showfig);
		
		break;
	}
	case 2:
	{
		char showfig[sz][sz1] =
		{
			' ',' ',' ',' ',
			' ','x','x',' ',
			' ','x','x',' ',
			' ',' ',' ',' ',
		};
		ShowNextFig(showfig);
		break;
	}
	case 3:
	{
		char showfig[sz][sz1] =
		{
			' ',' ',' ',' ',
			' ','x',' ',' ',
			'x','x','x',' ',
			' ',' ',' ',' ',
		};
		ShowNextFig(showfig);
		break;
	}
	case 4:
	{
		char showfig[sz][sz1] =
		{
			' ',' ',' ',' ',
			'x',' ',' ',' ',
			'x','x','x',' ',
			' ',' ',' ',' ',
		};
		ShowNextFig(showfig);
		break;
	}
	case 5:
	{
		char showfig[sz][sz1] =
		{
			' ','x',' ',' ',
			' ','x','x',' ',
			' ',' ','x',' ',
			' ',' ',' ',' ',
		};
		ShowNextFig(showfig);
		break;
	}
	}
}

void ShowNextFig(char arr[][4])
{
	cout << "----------\n";
	for (short i = 0; i < 4; i++)
	{
		cout << "|";
		for (short j = 0; j < 4; j++)
		{
			cout << setw(2) << arr[i][j];
		}
		cout << "|";
		cout << endl;
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