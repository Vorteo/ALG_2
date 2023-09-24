#include "Header.h"

/// <summary>
/// Funkce, ktera prida hranu mezi danymi vrcholy grafu. 
/// Nastavi hodnotu pro dane vrcholy.
/// </summary>
/// <param name="graph">matice grafu</param>
/// <param name="i">vrchol, ktery je ulozeny v promenne i</param>
/// <param name="j">vrchol, ktery je ulozeny v promenne j</param>
void addEdge(int** graph, int i, int j)
{
	graph[i][j] = 1;
	graph[j][i] = 1;
}

/// <summary>
/// Naplneni matice defaultni hodnotou INF
/// </summary>
/// <param name="graph">matice grafu</param>
/// <param name="n">pocet vrcholu v grafu</param>
void fillGraph(int** graph, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = INF;		
		}
	}
}

/// <summary>
/// Nalezeni pomoci Floyd Warshallova algoritmu nejkratsi cestu mezi vrcholy.
/// Algoritmus jsem pouzil z ukolu ze cviceni, kde jsme tento algoritmus implementovali.
/// </summary>
/// <param name="graph">matice grafu</param>
/// <param name="n">pocet vrcholu v grafu</param>
void floydWarshall(int** graph, int n)
{
	for (int k = 0; k < n; k++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				if (graph[i][k] + graph[k][j] < graph[i][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

/// <summary>
///  Funkce, ktera se stara u urceni center grafu.
///  Nejprve je potreba urcit excentricitu pro kazdy vrchol. 
///  Excentricita je nejvetsi vzdalenost z jednoho vrcholu do druheho.
///  Dale potrebuje nalezt radius grafu, coz je nejmensi hodnota z Excentricity.
///  Na zaver zbyvu urcit centrum grafu. Centrem grafu jsou vrcholy kde jejich excentricita je rovna radiusu grafu.
/// </summary>
/// <param name="graph">matice grafu</param>
/// <param name="n">pocet vrcholu v grafu</param>
void findCenter(int** graph, int n)
{
	int* eccArray = new int[n]();						
	int radius = INF;

	for (int i = 0; i < n; i++)									
	{
		for (int j = 0; j < n; j++)
		{
			eccArray[i] = max(eccArray[i], graph[i][j]);
		}
	}

	for (int i = 0; i < n; i++)									
	{
		radius = min(radius, eccArray[i]);
	}

	for (int i = 0; i < n; i++)								
	{
		if (eccArray[i] == radius) 
		{
			cout <<i <<"\t ";
		}
	}

	delete[] eccArray;
}

/// <summary>
/// Vypis matice grafu.
/// </summary>
/// <param name="graph">matice grafu</param>
/// <param name="n">pocet vrcholu v grafu</param>
void printGraph(int** graph, int n)		
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == INF)
			{
				cout << "INF \t";
			}
			else
			{
				cout << graph[i][j] <<"\t";
			}
		}
		cout << "\n";;
	}
}