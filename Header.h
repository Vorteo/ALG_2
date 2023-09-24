#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <algorithm>

/// Konstanta, kterou naplnim defaultne matici
#define INF 9999 

using namespace std;

void addEdge(int** graph, int i, int j);		
void fillGraph(int** graph,int n);				
void floydWarshall(int** graph, int n);			
void findCenter(int** graph, int n);			
void printGraph(int** graph, int);				