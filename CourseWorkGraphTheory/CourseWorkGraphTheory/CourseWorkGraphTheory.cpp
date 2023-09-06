//#include "stdafx.h"
#include <iostream>
using namespace std;

int gagatCount = 7;
int koghmCount = 10;

bool NotUsed(int v, int* usedV, int usedVLength)
{
	for (int i = 0; i < usedVLength; i++)
	{
		if (usedV[i] == v)
		{
			return false;
		}
	}
	return true;
}

int FindMinWeight(int* weightMatrix, int* usedV, int usedVLength)
{
	int min = 9999999;
	int minIndex = 0;
	for (int i = 0; i < gagatCount; i++)
	{
		if (min > weightMatrix[i] && NotUsed(i, usedV, usedVLength))
		{
			min = weightMatrix[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int* FindDistance(int startPoint, int* weightMatrix, int harevanutyanMatric[][20])
{
	int v = startPoint;
	int usedV[20];
	int usedVLength = 1;

	//int weightMatrix[20];
	int path[20];
	for (int i = 0; i < gagatCount; i++)
	{
		weightMatrix[i] = 99999;
		path[i] = 1;
	}
	usedV[0] = v;
	weightMatrix[startPoint] = 0;

	for (int i = 0; i < gagatCount; i++)
	{
		for (int j = 0; j < gagatCount; j++)
		{
			if (harevanutyanMatric[v][j] == 1 && NotUsed(j, usedV, usedVLength))
			{
				if ((harevanutyanMatric[v][j] + weightMatrix[v]) < weightMatrix[j])
				{
					weightMatrix[j] = harevanutyanMatric[v][j] + weightMatrix[v];
					path[j] = v;
				}
			}
		}
		usedV[usedVLength++] = v;
		v = FindMinWeight(weightMatrix, usedV, usedVLength);
	}

	return path;
}

struct Graph
{
	int a;
	int b;
};

int main()
{
	//setlocale(LC_ALL, "hy_AM.UTF-8");

	/*
	cout << "Nermuceq gagatneri qanaky: ";
	cin >> gagatner;
	cout << "Nermuceq kogheri qanaky: ";
	cin >> kogher;
	*/

	Graph E[10] =
	{
		{0, 3},
		{3, 5},
		{3, 6},
		{5, 6},
		{6, 1},
		{6, 4},
		{6, 2},
		{1, 4},
		{1, 2},
		{2, 4},
	};

	int harevanutyanMatric[20][20] = {};
	int kcutyanMatric[20][20];

	//Zroyacum	
	{
		for (int i = 0; i < gagatCount; i++)
		{
			for (int j = 0; j < gagatCount; j++)
			{
				harevanutyanMatric[i][j] = 0;
			}
		}

		for (int i = 0; i < koghmCount; i++)
		{
			for (int j = 0; j < koghmCount; j++)
			{
				kcutyanMatric[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < koghmCount; i++)
	{
		harevanutyanMatric[E[i].a][E[i].b] = 1;
		harevanutyanMatric[E[i].b][E[i].a] = 1;
	}

	for (int i = 0; i < koghmCount; i++)
	{
		kcutyanMatric[i][E[i].a] = 1;
		kcutyanMatric[i][E[i].b] = 1;
	}

	cout << "Harevanutyan Matric: " << endl;
	for (int i = 0; i < gagatCount; i++)
	{
		if (i == 0)
		{
			cout << "\t\t    ";
			for (int j = 0; j < gagatCount; j++)
				cout << "V" << j << " ";
			cout << endl;
		}

		cout << "\t\tV" << i << "  ";
		for (int j = 0; j < gagatCount; j++)
		{
			cout << harevanutyanMatric[i][j] << "  ";
		}
		cout << endl;
	}

	cout << "\nKcutyan Matric: " << endl;
	for (int i = 0; i < koghmCount; i++)
	{
		if (i == 0)
		{
			cout << "\t\t    ";
			for (int j = 0; j < gagatCount; j++)
				cout << "V" << j << " ";
			cout << endl;
		}

		cout << "\t\tE" << i << "  ";
		for (int j = 0; j < gagatCount; j++)
		{
			cout << kcutyanMatric[i][j] << "  ";
		}
		cout << endl;
	}


	int maxGagat = 0;
	int maxGagatIndex = 0;
	int gagatAstichanner[20];
	for (int i = 0; i < gagatCount; i++)
	{
		int count = 0;
		for (int j = 0; j < gagatCount; j++)
		{
			if (harevanutyanMatric[i][j] == 1)
			{
				count++;
			}
		}

		gagatAstichanner[i] = count;
		if (maxGagat < gagatAstichanner[i])
		{
			maxGagat = gagatAstichanner[i];
			maxGagatIndex = i;
		}
	}

	cout << "\n3)Maximum gagati astichan unecox gagaty V" << maxGagatIndex << " - " << maxGagat << " gagat" << endl;

	cout << "\n4)Gagatneri astichannery dasavorvac achman kargov:" << endl;
	int count = 0;
	bool isMekusacvac = false;
	bool isKaxvac = false;
	for (int i = 0; i < gagatCount; i++)
	{
		for (int j = 0; j < gagatCount; j++)
		{
			if (gagatAstichanner[j] == count)
			{
				cout << "\t\tV" << j << " = " << gagatAstichanner[j] << endl;
			}
		}
		count++;

		if (gagatAstichanner[i] == 0)
		{
			isMekusacvac = true;
		}
		if (gagatAstichanner[i] == 1)
		{
			isKaxvac = true;
		}
	}

	cout << "\n5)";
	if (isMekusacvac)
	{
		cout << "Grafy uni mekusacvac gagat" << endl;
	}
	if (isKaxvac)
	{
		cout << "Grafy uni kaxvac gagat" << endl;
	}
	else
	{
		cout << "Grafy chuni kaxvac ev mekusacvac gagatner" << endl;
	}

	cout << "\n7)Graphi ciklomatik tivy` C(G) = " << koghmCount << " - " << gagatCount << " + 1 = " << (koghmCount - gagatCount + 1) << endl;

	bool isFind;
	int ankax[20][2];
	int h = 0;
	for (int i = 0; i < gagatCount; i++)
	{
		for (int j = 0; j < gagatCount; j++)
		{
			if (harevanutyanMatric[i][j] == 0 && i != j)
			{
				isFind = true;
				for (int l = 0; l < h; l++)
				{
					if (ankax[l][0] == i || ankax[l][1] == i || ankax[l][0] == j || ankax[l][1] == j)
					{
						isFind = false;

						break;
					}
				}

				if (isFind)
				{
					ankax[h][0] = i;
					ankax[h][1] = j;
					h++;

					break;
				}
			}
		}
	}

	cout << "\n8)Graphi ankaxutyan tivy` L(G) = " << h << endl;
	cout << "Vercvac gagatnern en: " << endl;
	for (int i = 0; i < h; i++)
	{
		cout << "\t\t\t";
		for (int j = 0; j < 2; j++)
		{
			cout << ankax[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\n2) Amenakarch chanaparhy: " << endl;

	int startPoint = 0;
	int endPoint = 2;

	int weightMatrix[20];
	int* path = FindDistance(startPoint, weightMatrix, harevanutyanMatric);

	int l = endPoint;
	int nearestPath[20];
	int nearestPathLength = 1;
	nearestPath[0] = endPoint;
	while (true)
	{
		nearestPath[nearestPathLength++] = path[l];
		if (path[l] == startPoint)
		{
			break;
		}
		l = path[l];
	}
	cout << "\t\t\t";
	for (int i = nearestPathLength - 1; i >= 0; i--)
	{
		cout << "V" << nearestPath[i];
		if (i != 0)
		{
			cout << " -> ";
		}
	}

	cout << "\n\n6) Grafi tramagicy ev sharavighy: " << endl;

	int distanceMatrix[20][20];

	for (int i = 0; i < gagatCount; i++)
	{
		FindDistance(i, distanceMatrix[i], harevanutyanMatric);
	}

	int maxList[20];
	int max;
	for (int i = 0; i < gagatCount; i++)
	{
		max = distanceMatrix[i][0];
		for (int j = 0; j < gagatCount; j++)
		{
			if (max < distanceMatrix[i][j])
			{
				max = distanceMatrix[i][j];
			}
		}
		maxList[i] = max;
	}

	int radius = maxList[0];
	int diameter = maxList[0];
	cout << endl;
	cout << "Gagatneri maximum heravorutyuny 0-6 hajordakanutyamb: ";
	for (int i = 0; i < gagatCount; i++)
	{
		if (radius > maxList[i])
			radius = maxList[i];

		if (diameter < maxList[i])
			diameter = maxList[i];

		cout << maxList[i] << " ";
	}

	cout << "\nR = " << radius;
	cout << "\nd = " << diameter;
	cout << endl;
	return 0;
}

