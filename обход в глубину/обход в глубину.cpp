// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<conio.h>
#include<locale.h>
#include<iostream>
#include <stack>

int main()
{
	int n, t;
	std::stack<int> vertex;
	setlocale(0, "Russian");
	std::cout << "Введите количество вершин:" << std::endl;
	std::cin >> n;
	int** matrix = new int*[n];
	for (int y = 0; y < n; y++)
		matrix[y] = new int[n];
	int* mas = new int[n];
	std::cout << "Введите матрицу смежности:" << std::endl;
	for (int o = 0; o < n; o++)
	{
		mas[o] = 0;
		for (int h = 0; h < n; h++)
			std::cin >> matrix[o][h];
	}
	vertex.push(mas[0]);
	while (!vertex.empty())
	{
		t = vertex.top();
		vertex.pop();
		if (mas[t] == 2) continue; // в этой вершине были, идем к следующей
		mas[t] = 2;
		for (int i = n; i > 0; i--)//в обратном порядке, так как стек
		{
			if ((matrix[t][i] == 1) && (mas[i] !=2))
			{
				mas[i] = 1;//обнаружили, что они смежные
				vertex.push(i);
			}
		}
		std::cout << t + 1 << std::endl;
	}
	_getch();
	return 0;
}

