#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>


using namespace std;

int max_size = 7, i, j, start, num;
int* DIST = (int*)malloc(max_size * sizeof(int));

void BSFD(int st, int** b, int num_of_elem, int* vis) {
	queue<int> Q;
	int t;
	Q.push(st);
	vis[st] = 0;

	while (!Q.empty())
	{
		t = Q.front();
		Q.pop();
		printf("%d ", t + 1);
		for (int i = 0; i < num_of_elem; i++)
		{
			if (b[t][i] > 0 && vis[i] == 1000)
			{
				vis[i] = vis[t] + b[t][i];
				Q.push(i);
			}
		}
	}

}

void no_orient_graph()
{
	int** a = new int* [max_size];
	for (i = 0; i < max_size; i++)
	{
		a[i] = new int[max_size];
	}

	for (i = 0; i < max_size; i++)
	{
		for (j = i + 1; j < max_size; j++)
		{
			num = rand() % 7;
			if (num <= 3)
			{
				a[i][j] = 0;
				a[j][i] = a[i][j];
			}
			else
			{
				a[i][j] = (rand() % 6) + 1;
				a[j][i] = a[i][j];
			}
		}
	}
	printf("\nНеориентированный взвешенный:\n");
	for (i = 0; i < max_size; i++)
	{
		DIST[i] = 1000;
		for (j = 0; j < max_size; j++)
		{
			if (i == j)
				a[i][j] = 0;
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}

	printf("\nВведите стартовую вершину - ");
	scanf_s("%d", &start);
	BSFD(start - 1, a, max_size, DIST);
	printf("\nПоиск расстояний:\n");
	for (i = 0; i < max_size; i++) {
		printf("До %d = %d\n", i + 1, DIST[i]);
		DIST[i] = 1000;
	}
	_getch();
}

void no_orient_graph_NW()
{
	int** a = new int* [max_size];
	for (i = 0; i < max_size; i++)
	{
		a[i] = new int[max_size];
	}

	for (i = 0; i < max_size; i++)
	{
		for (j = i + 1; j < max_size; j++)
		{
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
	}
	printf("\nНеориентированный невзвешенный :\n");
	for (i = 0; i < max_size; i++)
	{
		DIST[i] = 1000;
		for (j = 0; j < max_size; j++)
		{
			if (i == j)
				a[i][j] = 0;
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}

	printf("\nВведите стартовую вершину  - ");
	scanf_s("%d", &start);
	BSFD(start - 1, a, max_size, DIST);
	printf("\nПоиск расстояний:\n");
	for (i = 0; i < max_size; i++) {
		printf("До %d = %d\n", i + 1, DIST[i]);
		DIST[i] = 1000;
	}
	_getch();
}


void orient_graph() {
	int** a = new int* [max_size];
	for (i = 0; i < max_size; i++)
	{
		a[i] = new int[max_size];
	}

	for (i = 0; i < max_size; i++)
	{
		for (j = 0; j < max_size; j++)
		{
			num = rand() % 7;
			if (num <= 3)
			{
				a[i][j] = 0;
			}
			else
			{
				a[i][j] = (rand() % 6) + 1;
			}
		}
	}
	printf("\n Ориентированный взвешенный:\n");
	for (i = 0; i < max_size; i++)
	{
		DIST[i] = 1000;
		for (j = 0; j < max_size; j++)
		{
			if (i == j)
				a[i][j] = 0;
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}

	printf("\nВведите стартовую вершину - ");
	scanf_s("%d", &start);
	BSFD(start - 1, a, max_size, DIST);
	printf("\nПоиск расстояний:\n");
	for (i = 0; i < max_size; i++) {
		printf("До %d = %d\n", i + 1, DIST[i]);
		DIST[i] = 1000;
	}
	_getch();
}
void orient_grap_NW() {
	int** a = new int* [max_size];
	for (i = 0; i < max_size; i++)
	{
		a[i] = new int[max_size];
	}

	for (i = 0; i < max_size; i++)
	{
		for (j = 0; j < max_size; j++)
		{
			a[i][j] = rand() % 2;
		}
	}
	printf("\n Ориентированный невзвешенный:\n");
	for (i = 0; i < max_size; i++)
	{
		DIST[i] = 1000;
		for (j = 0; j < max_size; j++)
		{
			if (i == j)
				a[i][j] = 0;
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}

	printf("\nВведите стартовую вершину - ");
	scanf_s("%d", &start);
	BSFD(start - 1, a, max_size, DIST);
	printf("\nПоиск расстояний:\n");
	for (i = 0; i < max_size; i++) {
		printf("До %d = %d\n", i + 1, DIST[i]);
		DIST[i] = 1000;
	}
	_getch();
}


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int counter_argc = 1;

	if (argc > 1)
	{
		while (counter_argc <= argc)
		{ 
			if (strcmp(argv[counter_argc-1], "NW") == 0)
				no_orient_graph();
			else if (strcmp(argv[counter_argc-1], "OW") == 0)
				orient_graph();
			else if (strcmp(argv[counter_argc-1], "NN") == 0)
				no_orient_graph_NW();
			else if (strcmp(argv[counter_argc-1], "ON") == 0)
				orient_grap_NW();
			counter_argc++;
		}
	}
	else
	{
		no_orient_graph();
		orient_graph();
		no_orient_graph_NW();
		orient_grap_NW();
	}
}