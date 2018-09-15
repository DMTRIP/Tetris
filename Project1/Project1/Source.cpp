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

int figRand = 5; // определяет какая фигура появится на поле

enum eDirection { STOP = 0, LEFT, RIGHT, DOWN, CHANGEPOS, FINISHED};
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
struct figuer_4
{
	int x1 = 0;
	int y1 = fieldWidth / 2;

	int x2 = 1;
	int y2 = (fieldWidth / 2) + 1;

	int x3 = 1;
	int y3 = fieldWidth / 2;

	int x4 = 1;
	int y4 = (fieldWidth / 2) - 1;
};
struct figuer_5
{
	int x1 = 0;
	int y1 = (fieldWidth / 2) - 1 ;

	int x2 = 1;
	int y2 = (fieldWidth / 2) + 1;

	int x3 = 1;
	int y3 = fieldWidth / 2;

	int x4 = 1;
	int y4 = (fieldWidth / 2) - 1;
};
struct figuer_6
{
	int x1 = 0;
	int y1 = (fieldWidth / 2) - 1;

	int x2 = 1;
	int y2 = (fieldWidth / 2) - 1;

	int x3 = 1;
	int y3 = fieldWidth / 2;

	int x4 = 2;
	int y4 = (fieldWidth / 2) ;
};
figuer_1 kooF1;
figuer_2 kooF2;
figuer_3 kooF3;
figuer_4 kooF4;
figuer_5 kooF5;
figuer_6 kooF6;

void Setup();
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

	/*do
	{
		srand(time(0));
		figRand = rand() % 6 + 1;

	} while (dir == FINISHED);*/
	
	
	
	while (!gameOver)
	{
		Setup();
		Draw(field);
		Input();
		Logic();
	}
	
	


	system("pause");
}
void Setup()
{
	gameOver = false;
	/*dir = DOWN;*/
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
					arr[kooF1.x1][kooF1.y1] = 'x';
					arr[kooF1.x2][kooF1.y2] = 'x';
					arr[kooF1.x3][kooF1.y3] = 'x';
					arr[kooF1.x4][kooF1.y4] = 'x';
			
			
			//// FIGURE 2
			//	arr[kooF2.x1][kooF2.y1] = 'x';
			//	arr[kooF2.x2][kooF2.y2] = 'x';
			//	arr[kooF2.x3][kooF2.y3] = 'x';
			//	arr[kooF2.x4][kooF2.y4] = 'x';
			//
			//

			//// FIGURE 3
			//
			//	arr[kooF3.x1][kooF3.y1] = 'x';
			//	arr[kooF3.x2][kooF3.y2] = 'x';
			//	arr[kooF3.x3][kooF3.y3] = 'x';
			//	arr[kooF3.x4][kooF3.y4] = 'x';
			//
			//

			//// FIGURE 4
			//
			//	arr[kooF4.x1][kooF4.y1] = 'x';
			//	arr[kooF4.x2][kooF4.y2] = 'x';
			//	arr[kooF4.x3][kooF4.y3] = 'x';
			//	arr[kooF4.x4][kooF4.y4] = 'x';
			//
			//

			//// FIGURE 5
			//
			//	arr[kooF5.x1][kooF5.y1] = 'x';
			//	arr[kooF5.x2][kooF5.y2] = 'x';
			//	arr[kooF5.x3][kooF5.y3] = 'x';
			//	arr[kooF5.x4][kooF5.y4] = 'x';
			//
			//
			//
			//// FIGURE 6
			//
			//	arr[kooF6.x1][kooF6.y1] = 'x';
			//	arr[kooF6.x2][kooF6.y2] = 'x';
			//	arr[kooF6.x3][kooF6.y3] = 'x';
			//	arr[kooF6.x4][kooF6.y4] = 'x';
			
			

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
	case CHANGEPOS:
	{
		
		// CHANGEPOS for fig 1 

		if (counterPos == 0)
		{
			counterPos++;
			
			int nx = kooF1.x1;
			int ny = kooF1.y1;

			kooF1.x1 = nx;
			kooF1.x2 = nx;
			kooF1.x3 = nx;
			kooF1.x4 = nx;

			kooF1.y1 = ny;
			kooF1.y2 = ny - 1;
			kooF1.y3 = ny - 2;
			kooF1.y4 = ny - 3;
		}
		else if (counterPos == 1)
		{
			counterPos++;

			int nx = kooF1.x1;
			int ny = kooF1.y1;

				kooF1.x1 = nx;
				kooF1.x2 = nx - 1;
				kooF1.x3 = nx - 2;
				kooF1.x4 = nx - 3;

				kooF1.y1 = ny;
				kooF1.y2 = ny;
				kooF1.y3 = ny;
				kooF1.y4 = ny; 
		}
			else if (counterPos == 2)
			{
				counterPos++;
				int nx = kooF1.x1;
				int ny = kooF1.y1;

				kooF1.x1 = nx;
				kooF1.x2 = nx;
				kooF1.x3 = nx;
				kooF1.x4 = nx;

				kooF1.y1 = ny;
				kooF1.y2 = ny + 1;
				kooF1.y3 = ny + 2;
				kooF1.y4 = ny + 3;
			}
			else if (counterPos == 3)
			{
			
				int nx = kooF1.x1;
				int ny = kooF1.y1;

				kooF1.x1 = nx;
				kooF1.x2 = nx + 1;
				kooF1.x3 = nx + 2;
				kooF1.x4 = nx + 3;

				kooF1.y1 = ny;
				kooF1.y2 = ny;
				kooF1.y3 = ny;
				kooF1.y4 = ny;
				counterPos = 0;
			}
				
			
		
		
		dir = STOP;
		
		break;
	}
	
	case LEFT:
	{
		
			//  STATR MOVE FIGURE 1 LEFT
		/*
			X
			X
			X
			X
		*/
		if (kooF1.y1 > 0)
		{
			kooF1.y1--;
			kooF1.y2--;
			kooF1.y3--;
			kooF1.y4--;
			dir = STOP;
		}
			


			//  FINISH MOVE FIGURE 1 LEFT

			//  STATR MOVE FIGURE 2 LEFT
			/*
				 X X
			   X X
			*/
		if (kooF2.y4 > 0)
		{
			kooF2.y1--;
			kooF2.y2--;
			kooF2.y3--;
			kooF2.y4--;
			dir = STOP;
		}
			
			//FINISH MOVE FIGURE 2 LEFT

			//  STATR MOVE FIGURE 3 LEFT
			/*
			   X X
			   X X
			*/
		if (kooF3.y2 > 0)
		{
			kooF3.y1--;
			kooF3.y2--;
			kooF3.y3--;
			kooF3.y4--;
			dir = STOP;
		}
			
			//FINISH MOVE FIGURE 3 LEFT

			//  STATR MOVE FIGURE 4 LEFT
			/*
				X
			  X X X
			*/
		if (kooF4.y4 > 0)
		{
			kooF4.y1--;
			kooF4.y2--;
			kooF4.y3--;
			kooF4.y4--;
			dir = STOP;
		}
			
			//FINISH MOVE FIGURE 4 LEFT

			//  STATR MOVE FIGURE 5 LEFT
			/*
			  X
			  X X X
			*/
		if (kooF5.y1 > 0)
		{
			kooF5.y1--;
			kooF5.y2--;
			kooF5.y3--;
			kooF5.y4--;
			dir = STOP;
		}
			
			//FINISH MOVE FIGURE 5 LEFT

			//  STATR MOVE FIGURE 6 LEFT
			/*
			  X
			  X X
				X			  
			*/
		if (kooF6.y1 > 0)
		{
			kooF6.y1--;
			kooF6.y2--;
			kooF6.y3--;
			kooF6.y4--;
			dir = STOP;
		}
			
			//FINISH MOVE FIGURE 5 LEFT
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
		if (kooF1.y1 < 9)
		{
			kooF1.y1++;
			kooF1.y2++;
			kooF1.y3++;
			kooF1.y4++;
			dir = STOP;
		}
		
		//FINISH MOVE FIGURE 1 RIGHT

		//  STATR MOVE FIGURE 2 RIGHT
		/*
			 X X
		   X X
		*/
		if (kooF2.y1 < 9)
		{
			kooF2.y1++;
			kooF2.y2++;
			kooF2.y3++;
			kooF2.y4++;
			dir = STOP;
		}
		
		//FINISH MOVE FIGURE 2 RIGHT

		//  STATR MOVE FIGURE 3 RIGHT
		/*
		   X X
		   X X
		*/
		if (kooF3.y1 < 9)
		{
			kooF3.y1++;
			kooF3.y2++;
			kooF3.y3++;
			kooF3.y4++;
			dir = STOP;
		}
		
		//FINISH MOVE FIGURE 3 RIGHT

		//  STATR MOVE FIGURE 4 RIGHT
		/*
			X
		  X X X
		*/
		if (kooF4.y2 < 9)
		{
			kooF4.y1++;
			kooF4.y2++;
			kooF4.y3++;
			kooF4.y4++;
			dir = STOP;
		}
		
		//FINISH MOVE FIGURE 4 RIGHT

		//  STATR MOVE FIGURE 5 RIGHT
		/*
		  X
		  X X X
		*/
		if (kooF5.y2 < 9)
		{
			kooF5.y1++;
			kooF5.y2++;
			kooF5.y3++;
			kooF5.y4++;
			dir = STOP;
		}
		
		//FINISH MOVE FIGURE 5 RIGHT

		//  STATR MOVE FIGURE 6 RIGHT
		/*
		  X
		  X X
		    X
		*/
		if (kooF6.y3 < 9)
		{
			kooF6.y1++;
			kooF6.y2++;
			kooF6.y3++;
			kooF6.y4++;
			dir = STOP;
		}
			
		
		
		//FINISH MOVE FIGURE 6 RIGHT
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
		if (kooF1.x4 < 19)
		{
			kooF1.x1++;
			kooF1.x2++;
			kooF1.x3++;
			kooF1.x4++;
			dir = STOP;
			if (kooF2.x4 > 18)
			{
				dir = FINISHED;
			}
		}
			
			
		
		//FINISH MOVE FIGURE 2 DOWN

		//  STATR MOVE FIGURE 2 DOWN
		/*
			 X X
		   X X
		*/
		if (kooF2.x4 < 19)
		{
			kooF2.x1++;
			kooF2.x2++;
			kooF2.x3++;
			kooF2.x4++;
			dir = STOP;
			if (kooF2.x4 > 18)
			{
				dir = FINISHED;
			}
		}
		
		//FINISH MOVE FIGURE 2 DOWN

		//  STATR MOVE FIGURE 3 DOWN
		/*
		   X X
		   X X
		*/
		if (kooF3.x4 < 19)
		{
			kooF3.x1++;
			kooF3.x2++;
			kooF3.x3++;
			kooF3.x4++;
			dir = STOP;
			if (kooF3.x4 > 18)
			{
				dir = FINISHED;
			}
		}
		
		//FINISH MOVE FIGURE 3 DOWN

		//  STATR MOVE FIGURE 4 DOWN
		/*
			X
		  X X X
		*/
		if (kooF4.x4 < 19)
		{
			kooF4.x1++;
			kooF4.x2++;
			kooF4.x3++;
			kooF4.x4++;
			dir = STOP;
			if (kooF4.x4 > 18)
			{
				dir = FINISHED;
			}
		}
		
		//FINISH MOVE FIGURE 4 DOWN

		//  STATR MOVE FIGURE 5 DOWN
		/*
		  X
		  X X X
		*/
		if (kooF5.x4 < 19)
		{
			kooF5.x1++;
			kooF5.x2++;
			kooF5.x3++;
			kooF5.x4++;
			dir = STOP;
			if (kooF5.x4 > 18)
			{
				figRand = 1;
			}
			
		}
		
		//FINISH MOVE FIGURE 5 DOWN

		//  STATR MOVE FIGURE 6 DOWN
		/*
		  X
		  X X 
			X
		*/
		if (kooF6.x4 < 19)
		{
			kooF6.x1++;
			kooF6.x2++;
			kooF6.x3++;
			kooF6.x4++;
			dir = STOP;
			if (kooF6.x4 == 18)
			{
				dir = FINISHED;
			}
		}
		
		//FINISH MOVE FIGURE 6 DOWN
		break;
	}

	
	}
}