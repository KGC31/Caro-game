#include<iostream>

using namespace std;

bool horizontal(int** a, int x, int y)
{
	if (a[y][x] == 0)
		return false;
	int count = 0;
	for (int i =x; count < 5; i++)
	{
		if (a[y][i] != a[y][x])
			return false;
		count++;
	}
	return true;
}


bool vertical(int** a, int x, int y)
{
	if (a[y][x] == 0)
		return false;
	int count = 0;
	for (int i = y; count < 5; i++)
	{
		if (a[i][x] != a[y][x])
			return false;
		count++;
	}
	return true;
}

bool backward_slash(int** a, int x, int y)
{
	if (a[y][x] == 0)
		return false;
	int count = 0, j = x;
	for (int i = y; count < 5; i++)
	{
		if (a[i][j] != a[y][x])
			return false;
		count++; j++;
	}
	return true;
}

bool forward_slash(int** a, int x, int y)
{
	if (a[y][x] == 0)
		return false;
	int count = 0, j = x;
	for (int i = y; count < 5; i++)
	{
		if (a[i][j] != a[y][x])
			return false;
		count++; j--;
	}
	return true;
}


bool win_check(int** a, int row, int col)
{
	for (int i = 0; i < 9; i++)
	{
		int j = 0;
		while(j < 10)
		{

			if (vertical(a, j, i) == true)
				return true;
			if (horizontal(a, j, i) == true)
					return true;
			if (backward_slash(a, j, i) == true)
					return true;
			if (forward_slash(a, j, i) == true)
					return true;
			j++;
		}
	}
	return false;
}