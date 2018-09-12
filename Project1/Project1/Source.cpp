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
struct figuer_2
{
	int x1 = 0;
	int y1 = (fieldWidth / 2) + 1;

	int x2 = 0;
	int y2 = fieldWidth / 2;

	int x3 = 1;
	int y3 = fieldWidth / 2;

	int x4 = 1;
	int y4 = (fieldWidth / 2) - 1;
};
struct figuer_3
{
	int x1 = 0;
	int y1 = fieldWidth / 2;

	int x2 = 0;
	int y2 = (fieldWidth / 2) - 1;

	int x3 = 1;
	int y3 = fieldWidth / 2;

	int x4 = 1;
	int y4 = (fieldWidth / 2) - 1;
};
figuer_1 kooF1;
figuer_2 kooF2;
figuer_3 kooF3;
void Draw(char arr[][fieldWidth]); 

void Input();
void Logic();


char field[fieldHeight][fieldWidth];


int main()
{
	

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
			//SPACE ARREY
			arr[i][j] = ' ';
			
			
			// FIGURE 1
			/*arr[kooF1.x1][kooF1.y1] = 'x';
			arr[kooF1.x2][kooF1.y2] = 'x';
			arr[kooF1.x3][kooF1.y3] = 'x';
			arr[kooF1.x4][kooF1.y4] = 'x';*/
			
			// FIGURE 2
			/*arr[kooF2.x1][kooF2.y1] = 'x';
			arr[kooF2.x2][kooF2.y2] = 'x';
			arr[kooF2.x3][kooF2.y3] = 'x';
			arr[kooF2.x4][kooF2.y4] = 'x';*/

			// FIGURE 3
			arr[kooF3.x1][kooF3.y1] = 'x';
			arr[kooF3.x2][kooF3.y2] = 'x';
			arr[kooF3.x3][kooF3.y3] = 'x';
			arr[kooF3.x4][kooF3.y4] = 'x';

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
		//  STATR MOVE FIGURE 1 LEFT
		/*
		    X
		    X
		    X
		    X
		*/

		kooF1.y1--;
		kooF1.y2--;
		kooF1.y3--;
		kooF1.y4--;
		dir = STOP; 

		//  FINISH MOVE FIGURE 1 LEFT

		//  STATR MOVE FIGURE 2 LEFT
		/*
			 X X 
		   X X
		*/
		kooF2.y1--;
		kooF2.y2--;
		kooF2.y3--;
		kooF2.y4--;
		dir = STOP;
		//FINISH MOVE FIGURE 2 LEFT

		//  STATR MOVE FIGURE 3 LEFT
		/*
		   X X
		   X X
		*/
		kooF3.y1--;
		kooF3.y2--;
		kooF3.y3--;
		kooF3.y4--;
		dir = STOP;
		//FINISH MOVE FIGURE 3 LEFT
		break;
	}
		
	case RIGHT:
	{
		//  STATR MOVE FIGURE 1 RIGHT
		/*
			X
			X
			X
			X
		*/
		kooF1.y1++;
		kooF1.y2++;
		kooF1.y3++;
		kooF1.y4++;
		dir = STOP;
		//FINISH MOVE FIGURE 1 RIGHT

		//  STATR MOVE FIGURE 2 RIGHT
		/*
			 X X
		   X X
		*/
		kooF2.y1++;
		kooF2.y2++;
		kooF2.y3++;
		kooF2.y4++;
		dir = STOP;
		//FINISH MOVE FIGURE 2 RIGHT

		//  STATR MOVE FIGURE 3 RIGHT
		/*
		   X X
		   X X
		*/
		kooF3.y1++;
		kooF3.y2++;
		kooF3.y3++;
		kooF3.y4++;
		dir = STOP;
		//FINISH MOVE FIGURE 3 RIGHT

		break;
	}		  
		
		
	case DOWN:
	{
		//  STATR MOVE FIGURE 1 DOWN
		/*
			X
			X
			X
			X
		*/
		kooF1.x1++;
		kooF1.x2++;
		kooF1.x3++;
		kooF1.x4++;
		dir = STOP;
		//FINISH MOVE FIGURE 2 DOWN

		//  STATR MOVE FIGURE 2 DOWN
		/*
			 X X
		   X X
		*/
		kooF2.x1++;
		kooF2.x2++;
		kooF2.x3++;
		kooF2.x4++;
		dir = STOP;
		//FINISH MOVE FIGURE 2 DOWN

		//  STATR MOVE FIGURE 3 DOWN
		/*
		   X X
		   X X
		*/
		kooF3.x1++;
		kooF3.x2++;
		kooF3.x3++;
		kooF3.x4++;
		dir = STOP;
		//FINISH MOVE FIGURE 3 DOWN
		break;
	}

	
	}
}