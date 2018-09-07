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
			Sleep(time);

			
			arr[i][j] = ' ';
			if (i == koo.x1 && j == koo.y1)
				arr[i][j] = 'x';

			if (i == koo.x2 && j == koo.y2)
				arr[i][j] = 'x';

			if (i == koo.x3 && j == koo.y3)
				arr[i][j] = 'x';

			if (i == koo.x4 && j == koo.y4)
				arr[i][j] = 'x';

			/*arr[koo.x1][koo.y1] = 'x';
			arr[koo.x2][koo.y2] = 'x';
			arr[koo.x3][koo.y3] = 'x';
			arr[koo.x4][koo.y4] = 'x';*/

			
			
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
		koo.y1-1;
		koo.y2-1;
		koo.y3-1;
		koo.y4-1;

		
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
		koo.x1+1;
		koo.x2+1;
		koo.x3+1;
		koo.x4+1;
		break;
	}

	
	}
}