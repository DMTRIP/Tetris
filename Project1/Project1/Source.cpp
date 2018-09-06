#include <iostream>
#include <iomanip>
using namespace std;

int const width = 10; // ?????? ? ??????? ????
int const height = 20;

struct figuer_1
{
	char fig_1[2][2]
	{
		'#','#',
		'#','#'
	};
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
void Draw(char arr[][width]); // ?????? ????????? ????

int main()
{
	char pole[height][width];
	Draw(pole);
	system("pause");
}

void Draw(char arr[][width])
{
	cout << "-----------------------\n";
	for (int i = 0; i < height; i++)
	{
		cout << '|';
		for (int j = 0; j < width; j++)
		{
			arr[i][j] = '@';
			cout << setw(2) << arr[i][j];
		}
		cout << " |";
		cout << endl;
	}
	cout << "-----------------------\n";
}