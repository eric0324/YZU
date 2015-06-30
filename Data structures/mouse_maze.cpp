/***********************************************************************************************/
/*                                                                                             */
/*元智大學資訊工程學系 1013353 吳冠賢                                                             */
/*problem:Using a two-dimensional array to construct a maze and solve the mazing problem.      */
/*                                                                                             */
/***********************************************************************************************/
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include <ctime>

using namespace std;
#define N 50

int **maze;
int row;
int col;

int stack[50];//存放路徑的堆疊

void CreateMaze()//用於創建迷宮
{
	int i, j;
	cout << "Enter the number of rows in the maze：";
	cin >> row;

	cout << "Enter the number of columns in the maze：";
	cin >> col;

	if (row <= 0 || col <= 0) //檢查
	{
		cout << "Error input！\n";
		exit(1);
	}

	//創建二維陣列(動態記憶體)
	maze = (int **)malloc((row + 2)*sizeof(int *));

	for (i = 0; i<row + 2; i++)
	{
		maze[i] = (int *)malloc((col + 2)*sizeof(int));
	}

	//迷宮左右兩邊外牆
	for (i = 0; i<row + 2; i++)
	{
		maze[i][0] = 1;
		maze[i][col + 1] = 1;
	}

	//迷宮上下兩邊外牆
	for (i = 0; i<col + 2; i++)
	{

		if (i == 1)
			maze[0][i] = 0;//入口
		else 
			maze[0][i] = 1;

		if (i == col)
			maze[row + 1][col] = 0;//出口
		else 
			maze[row + 1][i] = 1;
	}

	//隨機產生內部的牆
	for (i = 1; i <= row; i++)
	{

		for (j = 1; j <= col; j++) 
		{
			int road = rand() % 2;
			maze[i][j] =road;
		}
	}

	for (i = 0; i<row + 2; i++)
	{
		for (j = 0; j<col + 2; j++)
		{
			cout << maze[i][j];
		}
		cout << endl;
	}
}

void ShowMaze()//輸出迷宮
{
	int i, j;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			cout << maze[i][j];
		}
		cout << endl;
	}
}

//釋放剛剛宣告的動態記憶體
void DestroyMaze()
{
	int i;
	for (i = 0; i<row + 2; i++)
		free(maze[i]);
	free(maze);
}

//找迷宮的路徑
//印出2代表可以走的路徑
int FindPath()
{
	int i, j, k, count, x, y, direction;

	count = 0;
	x = 1, y = 1;
	direction = 0;
	j = 0, k = 0;

	//初始化陣列
	for (i = 0; i<N; i++)
	{
		stack[i] = 0;
	}

	i = 0;
	while (1)
	{
		count = 0;//用count判斷是否有路可走

		{
			if (x == 1 && y == 1)
				maze[x][y] = 2;

			if (maze[x][y + 1] == 0)//東
			{
				count++;
				maze[x][y + 1] = 2;
				y = y + 1;
				stack[i] = -1;
				i++;
				if (x == row&&y == col)
					return 1;
			}
			else if (maze[x + 1][y] == 0)//南
			{
				if (maze[x + 1][y] == 0)
					count++;
				{
					maze[x + 1][y] = 2;
					x = x + 1;
					stack[i] = -2;
					i++;
					if (x == row&&y == col)
						return 1;
				}
			}
			else if (maze[x][y - 1] == 0)//西
			{
				count++;
				if (maze[x][y - 1] == 0)
				{
					maze[x][y - 1] = 2;
					y = y - 1;
					stack[i] = -3;
					i++;
					if (x == row&&y == col)
						return 1;
				}
			}
			else if (maze[x - 1][y] == 0)//北
			{
				count++;
				if (maze[x - 1][y] == 0)
				{
					maze[x - 1][y] = 2;
					x = x - 1;
					stack[i] = -4;
					i++;
					if (x == row&&y == col)
						return 1;
				}
			}
		}

		if (count == 0)
		{
			if (i<0)
				return 0;
			direction = stack[i--];
			switch (direction)
			{
			case -1:y = y - 1; break;
			case -2:x = x - 1; break;
			case -3:y = y + 1; break;
			case -4:x = x + 1; break;
			default:break;
			}
		}
	}
}

int main()
{
	unsigned seed;
	seed = (unsigned)time(NULL); // 取得時間序列
	srand(seed); // 以時間序列當亂數種子

	CreateMaze();
	if (FindPath())
	{
		cout << "已經找到了一條路徑，如下:\n";
		ShowMaze();
	}
	else
	{
		cout << "沒有合適的路徑走出當前迷宮！\n";
	}

	DestroyMaze();

	system("pause");
}
