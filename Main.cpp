#include "Header.h"
/// 
///  Main soubor obsahuje: 
///							- otevreni textoveho souboru
///							- nacteni hodnot ze souboru
///							- volani funkce k vytvoreni defaultni matice
///							- volani funkce, ktera nalezne nejkratsi cestu mezi vrcholy
///							- volani funkce, ktera nalezne centra grafu
///							- postupne vypisy kroku
/// Pouzite zdroje:
/// Nektere casti kodu jsem pouzil z teto stranky https://codeforces.com/blog/entry/17974?fbclid=IwAR0ypmtJ1UPH4HFu8ybipE5ijWqSZZuiJtelhX_JGDJbvWsyt0LF91gpV3o
/// O danem tematu jsem cerpal z https://www.geeksforgeeks.org/graph-measurements-length-distance-diameter-eccentricity-radius-center/
/// 

int main()
{
	string filename; 

	cout << "Napiste nazev souboru: ";	
	cin >> filename;

	cout << endl;
	cout << "*****************************";

	ifstream file;
	file.open(filename);

	if (!file)								
	{
		cout << "Soubor nelze otevrit " << endl;
		exit(1);
	}

	int n;					
	if (file >> n)
	{
		cout << endl;
		cout << "Pocet vrcholu: " << n << endl;
		cout << "*****************************" << endl;;
	}

	int** graph = new int* [n];					
	for (int i = 0; i < n; i++)
	{
		graph[i] = new int[n];
	}

	fillGraph(graph, n);			

	int i, j;					
	while (file >> i >> j)
	{
		addEdge(graph, i, j);			
	}

	file.close(); 


	cout << "Matice sousednosti grafu:" << endl;
	printGraph(graph, n);
	cout << endl;

	cout << "*****************************" << endl;;

	cout << "Matice nejkratsich cest:" << endl;
	floydWarshall(graph, n);							
	printGraph(graph, n);
	cout << endl;

	cout << "Cislo vrcholu centra grafu: ";
	findCenter(graph, n);								
	cout << endl;

	for (int i = 0; i < n; ++i)					
	{
		delete[] graph[i];
	}

	delete[] graph;
	return 0;
}