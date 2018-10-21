//#include <iostream>
//#include <iomanip>
//#include <ctime>
//#include <dos.h>
//#include <Windows.h>
//#include <stdlib.h>
//#include <conio.h>
//
//
//
//using namespace std;
//
//bool gameOver;
//
//int const fieldWidth = 10;
//int const fieldHeight = 20;
//int score = 0;
//char field[fieldHeight][fieldWidth];
//int pcounter_pos_1 = 0;
//
//
//
///*int figRand = 5;*/ // определяет какая фигура появится на поле
//
//enum eDirection { STOP = 0, LEFT, RIGHT, DOWN, CHANGEPOS, FINISHED };
//eDirection dir;
//
//int nx;
//int ny;
//
//int nx2;
//int ny2;
//
//int nx3;
//int ny3;
//
//int nx4;
//int ny4;
//
//int & pnx = nx;
//int & pny = ny;
//
//int & pnx2 = nx2;
//int & pny2 = ny2;
//
//int & pnx3 = nx3;
//int & pny3 = ny3;
//
//int & pnx4 = nx4;
//int & pny4 = ny4;
//
//struct Figure
//{
//private:
//	int figureNumber;
//
//	
//	
//public:
//
//	Figure(int diget)
//	{
//		figureNumber = diget;
//	}
//
//	int x1 = 0;
//	int y1 = fieldWidth / 2;
//
//	int x2 = 1;
//	int y2 = fieldWidth / 2;
//
//	int x3 = 2;
//	int y3 = fieldWidth / 2;
//
//	int x4 = 3;
//	int y4 = fieldWidth / 2;
//
//	void Move()
//	{
//		switch (dir)
//		{
//		case LEFT:
//		{
//			if (y1 > 0 && y2 > 0 && y3 > 0 && y4 > 0)
//			{
//				y1--;
//				y2--;
//				y3--;
//				y4--;
//				dir = STOP;
//			}
//			break;
//		}
//		case RIGHT:
//		{
//			if (y1 < 9 && y2 < 9 && y3 < 9 && y4 < 9)
//			{
//				y1++;
//				y2++;
//				y3++;
//				y4++;
//				dir = STOP;
//			}
//			break;
//		}
//
//		case DOWN:
//		{
//			if (x1 < 19 && x2 < 19 && x3 < 19 && x4 < 19)
//			{
//				//if (!(field[kooF1.x4 + 1][kooF1.y4] == 'x'))
//				
//					x1++;
//					x2++;
//					x3++;
//					x4++;
//				
//				dir = STOP;
//			}
//			break;
//		}
//		case CHANGEPOS:
//		{
//			switch (figureNumber)
//			{
//			case 0:
//			{
//				if (pcounter_pos_1 == 0)
//				{
//					x1 = pnx + 1;
//					y1 = pny - 1;
//
//					x2 = pnx2;
//					y2 = pny2;
//
//					x3 = pnx3 - 1;
//					y3 = pny3 + 1;
//
//					x4 = pnx4 - 2;
//					y4 = pny4 + 2;
//					
//					pcounter_pos_1 = 1;
//					if (dir == FINISHED)
//					{
//						pcounter_pos_1 = 0;
//					}
//				}
//				else if (pcounter_pos_1 == 1)
//				{
//					x1 = pnx - 1;
//					y1 = pny + 1;
//
//					x2 = pnx2;
//					y2 = pny2;
//
//					x3 = pnx3 + 1;
//					y3 = pny3 - 1;
//
//					x4 = pnx4 + 2;
//					y4 = pny4 - 2;
//
//					pcounter_pos_1 = 0;
//				}
//			}
//			}
//		}
//
//		}
//		
//	}
//	void RememerFigure()
//	{
//		field[x1][y1] = '1';
//		field[x2][y2] = '2';
//		field[x3][y3] = '3';
//		field[x4][y4] = '4';
//	}
//	void ClearFigure()
//	{
//		field[x1][y1] = ' ';
//		field[x2][y2] = ' ';
//		field[x3][y3] = ' ';
//		field[x4][y4] = ' ';
//	}
//	void finished()
//	{
//		const int bottom = 18;
//		//проветка дошла ли фигура до конца масива
//		if (x1 > bottom || x2 > bottom || x3 > bottom || x4 > bottom)
//		{
//			dir = FINISHED;
//		}
//		//first figure
//		//if (figNumber = 0)
//		//{
//		//	if ((field[x4 + 1][y4] == 'x'))
//		//	{
//		//		//dir = FINISHED;
//		//	}
//		//}
//	}
//};
//Figure kooF1(0);
//Figure kooF2(1);
//
// 
//
//
//
//void getKoo();
//void Setup();
//void Draw(char arr[][fieldWidth], int);
//void Input();
////void Logic();
//
//
//
//
//void InitFig1(Figure &f)
//{
//	f.x1 = 0;
//	f.y1 = fieldWidth / 2;
//
//	f.x2 = 1;
//	f.y2 = fieldWidth / 2;
//
//	f.x3 = 2;
//	f.y3 = fieldWidth / 2;
//
//	f.x4 = 3;
//	f.y4 = fieldWidth / 2;
//}
//void InitFig2(Figure &f)
//{
//	f.x1 = 0;
//	f.y1 = (fieldWidth / 2) + 1;
//
//	f.x2 = 0;
//	f.y2 = fieldWidth / 2;
//
//	f.x3 = 1;
//	f.y3 = fieldWidth / 2;
//
//	f.x4 = 1;
//	f.y4 = (fieldWidth / 2) - 1;
//}
//void InitFig3(Figure &f)
//{
//	f.x1 = 0;
//	f.y1 = fieldWidth / 2;
//
//	f.x2 = 0;
//	f.y2 = (fieldWidth / 2) - 1;
//
//	f.x3 = 1;
//	f.y3 = fieldWidth / 2;
//
//	f.x4 = 1;
//	f.y4 = (fieldWidth / 2) - 1;
//}
//void InitFig4(Figure &f)
//{
//	f.x1 = 0;
//	f.y1 = fieldWidth / 2;
//
//	f.x2 = 1;
//	f.y2 = (fieldWidth / 2) + 1;
//
//	f.x3 = 1;
//	f.y3 = fieldWidth / 2;
//
//	f.x4 = 1;
//	f.y4 = (fieldWidth / 2) - 1;
//}
//void InitFig5(Figure &f)
//{
//	f.x1 = 0;
//	f.y1 = (fieldWidth / 2) - 1;
//
//	f.x2 = 1;
//	f.y2 = (fieldWidth / 2) + 1;
//
//	f.x3 = 1;
//	f.y3 = fieldWidth / 2;
//
//	f.x4 = 1;
//	f.y4 = (fieldWidth / 2) - 1;
//}
//void InitFig6(Figure &f)
//{
//	f.x1 = 0;
//	f.y1 = (fieldWidth / 2) - 1;
//
//	f.x2 = 1;
//	f.y2 = (fieldWidth / 2) - 1;
//
//	f.x3 = 1;
//	f.y3 = fieldWidth / 2;
//
//	f.x4 = 2;
//	f.y4 = (fieldWidth / 2);
//}
//
////void RememerFigure()
////{	
////	field[kooF1.x1][kooF1.y1] = 'x';
////	field[kooF1.x2][kooF1.y2] = 'x';
////	field[kooF1.x3][kooF1.y3] = 'x';
////	field[kooF1.x4][kooF1.y4] = 'x';
////}
////
////void ClearFigure()
////{
////	field[kooF1.x1][kooF1.y1] = ' ';
////	field[kooF1.x2][kooF1.y2] = ' ';
////	field[kooF1.x3][kooF1.y3] = ' ';
////	field[kooF1.x4][kooF1.y4] = ' ';
////}
//int main()
//{
//	srand(time(0));
//
//	while (true)
//	{
//		int figNumber = rand() % 2;
//		switch (figNumber)
//		{
//		case 0: InitFig1(kooF1); break;
//		case 1: InitFig2(kooF2); break;
//		}
//		const int bottom = 18;
//		while (!gameOver)
//		{
//			getKoo();
//			Setup();
//			Draw(field, figNumber);
//			kooF1.finished();
//			kooF2.finished();
//			Input();
//			//Logic();
//			if (dir == FINISHED)
//			{
//				kooF1.RememerFigure();
//				kooF2.RememerFigure();
//				break;
//			}
//		}
//	}
//	system("pause");
//}
//void Setup()
//{
//	gameOver = false;
//	/*dir = DOWN;*/
//}
//void Draw(char arr[][fieldWidth], int figNumber)
//{
//
//	int time = 0;
//	int randa = 1;
//
//	cout << "-----------------------\n";
//
//	for (int i = 0; i < fieldHeight; i++)
//	{
//		cout << '|';
//		for (int j = 0; j < fieldWidth; j++)
//		{
//			kooF1.RememerFigure();
//			kooF2.RememerFigure();
//			cout << setw(2) << arr[i][j];
//		}
//		cout << " |";
//		cout << endl;
//	}
//	cout << "-----------------------\n";
//	system("cls");
//	kooF1.ClearFigure();
//	kooF2.ClearFigure();
//}
//
//void Input()
//{
//	if (_kbhit())
//	{
//		switch (_getch())
//		{
//		case 'w':
//		{
//			dir = CHANGEPOS;
//			break;
//		}
//
//		case 'a':
//		{
//			dir = LEFT;
//			break;
//		}
//		case 'd':
//		{
//			dir = RIGHT;
//			break;
//		}
//		case 's':
//		{
//			dir = DOWN;
//		}
//		}
//	}
//}
//
//void getKoo()
//{
//	
//		pnx = kooF1.x1;
//		pny = kooF1.y1;
//
//		pnx2 = kooF1.x2;
//		pny2 = kooF1.y2;
//
//		pnx3 = kooF1.x3;
//		pny3 = kooF1.y3;
//
//		pnx4 = kooF1.x4;
//		pny4 = kooF1.y4;
//	
//}
