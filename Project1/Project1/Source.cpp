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
figuer_1 koo;
figuer_1 *pKoo = &koo;

void Draw(char arr[][fieldWidth]); 

void Input();
void Logic();





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

			arr[pKoo->x1][pKoo->y1] = 'x';
			arr[pKoo->x2][pKoo->y2] = 'x';
			arr[pKoo->x3][pKoo->y3] = 'x';
			arr[pKoo->x4][pKoo->y4] = 'x';

			
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
		pKoo->y1+1;
		pKoo->y2+1;
		pKoo->y3+1;
		pKoo->y4+1;
		break;
	}		  
		
	case UP:
	{
		pKoo->x1-1; 
		pKoo->x2-1; 
		pKoo->x3-1; 
		pKoo->x4-1; 
		break;
	}
		
	case DOWN:
	{
		pKoo->x1 + 1;
		pKoo->x2 + 1;
		pKoo->x3 + 1;
		pKoo->x4 + 1;
		break;
	}

	
	}
}