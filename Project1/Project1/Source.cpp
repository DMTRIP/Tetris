#include <iostream>
#include <iomanip>
#include <dos.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>



using namespace std;

bool gameOver = false;

int const fieldWidth = 10; // 
int const fieldHeight = 20;
int score = 0;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

struct figuer_1
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
struct figuer_1*  pKoo;
figuer_1 koo;

void Draw(char arr[][fieldWidth]); 

void Input();
void Logic();

// temp
int x1 = 0;
int* px1 = &x1;

//int y1 = fieldWidth / 2;
//int* py1 = &y1;

//int y0 = fieldWidth / 2;
//int* py0 = &y0;

int x2 = 1;
int* px2 = &x2;

int y2 = fieldWidth / 2;
int* py2 = &y2;

int x3 = 2;
int* px3 = &x3;

int y3 = fieldWidth / 2;
int* py3 = &y3;

int x4 = 3;
int* px4 = &x4;

int y4 = fieldWidth / 2;
int* py4 = &y4;

//temp 2



int main()
{
	char field[fieldHeight][fieldWidth];

	//while (!gameOver)
	//{
	//	// GAME TIMING =======================


	//	// INPUT =============================


	//	// GAME LOGIC ========================


	//	// RENDER OUTPUT =====================


	//	// DRAW FIELD
	//	

	//}
	while (!gameOver)
	{
		
		Draw(field);
		Input();
		Logic();
		
	}
		
	
	


	system("pause");
}

void Draw(char arr[][fieldWidth])
{
	
	int time = 0;
	

	cout << "-----------------------\n";

	for (int i = 0; i < fieldHeight; i++)
	{
		cout << '|';
		for (int j = 0; j < fieldWidth; j++)
		{
			

			
			arr[i][j] = ' ';
			/*if (i == *px1-- && j == 5)
				arr[i][j] = 'x';

			if (i == *px2-- && j == *py2)
				arr[i][j] = 'x';

			if (i == *px3-- && j == *py3)
				arr[i][j] = 'x';

			if (i == *px4-- && j == *py4)
				arr[i][j] = 'x';*/

			arr[*px1][5] = 'x';
			arr[*px2][*py2] = 'x';
			arr[*px3][*py3] = 'x';
			arr[*px4][*py4] = 'x';

			
			Sleep(time);
			cout << setw(2) << arr[i][j];
		}
		cout << " |";
		cout << endl;
	}
	cout << "-----------------------\n";
	



	system("cls");
}

void Input()
{
	if ( _kbhit() )
	{
		switch (_getch())
		{
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
		case 'w':
		{
			dir = UP;
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
		pKoo->y1-1;
		pKoo->y2-1;
		pKoo->y3-1;
		pKoo->y4-1;

		
		break;
	}
		
	case RIGHT:
	{
		/*koo.y1++;
		koo.y2++;
		koo.y3++;
		koo.y4++;*/
		break;
	}		  
		
	case UP:
	{
		/*koo.x1--;
		koo.x2--;
		koo.x3--;
		koo.x4--;*/
		break;
	}
		
	case DOWN:
	{
		px1+1;
		px2+1;
		px3+1;
		px4+1;
		break;
	}

	
	}
}