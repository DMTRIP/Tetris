#include <iostream>
#include <iomanip>
#include <dos.h>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

bool gameOver = false;
int const fieldWidth = 10; // 
int const fieldHeight = 20;

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
struct figuger_2
{
	char fig_2[1][4]
	{
		'#','#','#','#'

	};
};
struct figuger_3
{
	char fig_3[2][3]
	{
		' ','#',' ',
		'#','#','#'

	};
};
struct figuger_4
{
	char fig_4[2][3]
	{
		' ','#','#',
		'#','#',' '

	};
};
struct figuger_5
{
	char fig_2[3][3]
	{
		'#',' ',' ',
		'#',' ',' ',
		'#','#','#'

	};
};
void Draw(char arr[][fieldWidth]); // ?????? ????????? ????

int main()
{
	char field[fieldHeight][fieldWidth];

	while(!gameOver)
	{
		// GAME TIMING =======================

	
		// INPUT =============================


		// GAME LOGIC ========================


		// RENDER OUTPUT =====================


		// DRAW FIELD

		Draw(field);
	}
		
	
	
	system("pause");
}

void Draw(char arr[][fieldWidth])
{
	figuer_1 koo;
	int time = 50;
	for (int i = 0; i < fieldHeight; i++){
		for (int j = 0; j < fieldWidth; j++){
			arr[i][j] = ' ';
		}
	}

	for (int i = 0; i < fieldHeight; i++)
	{
		for (int j = 0; j < fieldWidth; j++)
		{
			arr[koo.x1++][koo.y1] = 'X';
			arr[koo.x2++][koo.y1] = 'X';
			arr[koo.x3++][koo.y1] = 'X';
			arr[koo.x4++][koo.y1] = 'X';
			
		}
	}
	
	cout << "-----------------------\n";

	for (int i = 0; i < fieldHeight; i++)
	{
		cout << '|';
		for (int j = 0; j < fieldWidth; j++)
		{
			Sleep(time);
			cout << setw(2) << arr[i][j];
		}
		cout << " |";
		cout << endl;
	}
	cout << "-----------------------\n";

	
	/*for (int i = 0; i < height; i++)
	{
		cout << '|';
		for (int j = 0; j < width; j++)
		{
			arr[j][i] = ' ';
			Sleep(time);
			cout << setw(2) << arr[i][j];
		}
		cout << " |";
		cout << endl;
	}*/

	
}