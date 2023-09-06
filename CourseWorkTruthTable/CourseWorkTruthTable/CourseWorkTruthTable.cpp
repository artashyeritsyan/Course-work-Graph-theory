//#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


bool EQ(bool x, bool y)
{
	return ((x || !y) && (!x || y));
}

bool AND(bool x, bool y)
{
	return (x && y);
}

bool OR(bool x, bool y)
{
	return (x || y);
}

bool XOR(bool x, bool y)
{
	return ((x || y) && ((!x) || (!y)));
}


bool IMPL(bool x, bool y)
{
	return (!x || y);
}

bool DetectFictive(int* Function, int* ColumnX, int* ColumnY, int* ColumnZ)
{
	bool isFictive = true;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			if ((ColumnX[i] != ColumnX[j]) && (ColumnY[i] == ColumnY[j]) && (ColumnZ[i] == ColumnZ[j]))
			{
				if (Function[i] != Function[j])
					isFictive = false;
			}
		}
	}
	return isFictive;
}

void KDNZ(int variable, char symbol, string* dnzRow, int columnIndex)
{
	if (variable == 1)
	{
		cout << symbol;
		dnzRow[columnIndex] = symbol;
	}
	else
	{
		cout << "!" << symbol;
		dnzRow[columnIndex] = "!";
		dnzRow[columnIndex] += symbol;
	}
}

void KKNZ(int variable, char symbol, string* knzRow, int columnIndex)
{
	if (variable == 0)
	{
		cout << symbol;
		knzRow[columnIndex] = symbol;
	}
	else
	{
		cout << "!" << symbol;
		knzRow[columnIndex] = "!";
		knzRow[columnIndex] += symbol;
	}
}

void Dnz(string* dnz1, string* dnz2, string* dnz3)
{
	if (dnz1[0] != dnz2[0])
	{
		if (dnz1[1] == dnz2[1])
		{
			if (dnz1[2] == dnz2[2])
			{
				cout << dnz1[1] << dnz1[2];
				cout << "||";
				for (int i = 0; i < 3; i++)
					cout << dnz3[i];
			}

		}
	}
}

void Multiply(string arajinBazm[], string erkrordBazm[], string* multiple, int length)
{
	int row = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			multiple[row++] = arajinBazm[i] + erkrordBazm[j];
		}
	}
	for (int i = 0; i < row; i++)
	{
		cout << multiple[i];
		if (i == row - 1)
		{
			cout << endl;
		}
		else
		{
			cout << " v ";
		}
	}
}

int Anorosh(int an[], int xyz[], int function, int n);

int main()
{
	//setlocale(LC_ALL, "hy_AM.UTF-8");

	int Function[8];
	int ColumnX[8];
	int ColumnY[8];
	int ColumnZ[8];

	int i = 0;

	cout << "1)Funkciayi iskutyan aghyusaky ev iskutyan vektory \nx y z  f(x,y,z)" << endl;
	for (int x = 0; x <= 1; x++)
	{
		for (int y = 0; y <= 1; y++)
		{
			for (int z = 0; z <= 1; z++)
			{
				cout << x << " " << y << " " << z << "\t";
				Function[i] = XOR(!AND(EQ(IMPL(x, IMPL(y, !AND(x, z))), y), IMPL(z, x)), (IMPL(y, !AND(AND(x, y), z))));

				cout << Function[i] << endl;

				ColumnX[i] = x;
				ColumnY[i] = y;
				ColumnZ[i] = z;

				i++;
			}
		}
	}
	cout << endl;
	//texerov poxum em x, y, z u 3 angam kanchum em nuyn funkcian
	cout << "2)Gtnel ev heracnel funkciayi fiktiv popoxakannery" << endl;
	if (DetectFictive(Function, ColumnX, ColumnY, ColumnZ))
		cout << "X popoxakany Fiktiv e" << endl;
	else
		cout << "X popoxakany Eakan e" << endl;

	if (DetectFictive(Function, ColumnY, ColumnX, ColumnZ))
		cout << "Y popoxakany Fiktiv e" << endl;
	else
		cout << "Y popoxakany Eakan e" << endl;

	if (DetectFictive(Function, ColumnZ, ColumnX, ColumnY))
		cout << "Z popoxakany Fiktiv e" << endl;
	else
		cout << "Z popoxakany Eakan e" << endl;

	char sX = 'X';
	char sY = 'Y';
	char sZ = 'Z';
	string dnz[3][3];
	string knz[5][5];
	int rowIndex = 0;
	int columnIndex = 0;

	cout << "\n3)Stanal bulyan funkciayi KDNDZ ev KKNDZ" << endl;
	cout << "Kdnz:" << endl;
	for (int i = 0; i < 8; i++)
	{
		columnIndex = 0;
		if (Function[i] == 1)
		{
			cout << "(";
			KDNZ(ColumnX[i], sX, dnz[rowIndex], columnIndex++);
			cout << "&";
			KDNZ(ColumnY[i], sY, dnz[rowIndex], columnIndex++);
			cout << "&";
			KDNZ(ColumnZ[i], sZ, dnz[rowIndex], columnIndex++);
			cout << ")";
			rowIndex++;

			if (i != 7)
				cout << " v ";
		}
	}


	rowIndex = 0;
	cout << endl << endl << "Kknz:" << endl;
	for (int i = 0; i < 8; i++)
	{
		columnIndex = 0;
		if (Function[i] == 0)
		{
			cout << "(";
			KKNZ(ColumnX[i], sX, knz[rowIndex], columnIndex++);
			cout << "v";
			KKNZ(ColumnY[i], sY, knz[rowIndex], columnIndex++);
			cout << "v";
			KKNZ(ColumnZ[i], sZ, knz[rowIndex], columnIndex++);
			cout << ")";
			rowIndex++;

			if (i != 5)
				cout << " & ";
		}
	}

	cout << "\n\nDnz:\n";
	Dnz(dnz[0], dnz[1], dnz[2]);

	cout << "\n\nKnz:\n";
	//string* p1;
	string firstMultiple[9];
	string secondMultiple[9];

	cout << "\n1 * 2:\n";
	Multiply(knz[0], knz[1], firstMultiple, 3);

	cout << "\n4 * 5:\n";
	Multiply(knz[3], knz[4], secondMultiple, 3);

	string krchat1[2] = { "X", "Y" };
	string krchat2[2] = { "!X", "Y" };
	string Multiple1245[4];

	cout << "\n(1*2) * (4*5):\n";
	Multiply(krchat1, krchat2, Multiple1245, 2);

	string krchat1245 = "Y";
	string FinalKnz[3];
	cout << "\nVerjnakan Knz:\n";
	for (int i = 0; i < 3; i++)
	{
		FinalKnz[i] = knz[2][i] + krchat1245;
		cout << FinalKnz[i];
		if (i == 2)
		{
			cout << endl;
		}
		else
		{
			cout << " v ";
		}
	}



	cout << "\n4)Stanal bulyan funkciayi Jegalkini bazmandamy" << endl;

	int an[8];
	int xyz[8];
	xyz[0] = 1;
	int n = 0;
	for (int x = 0; x <= 1; x++)
	{
		for (int y = 0; y <= 1; y++)
		{
			for (int z = 0; z <= 1; z++)
			{
				xyz[1] = z;
				xyz[2] = y;
				xyz[3] = y * z;
				xyz[4] = x;
				xyz[5] = x * z;
				xyz[6] = x * y;
				xyz[7] = x * y * z;

				an[n] = Anorosh(an, xyz, Function[n], n);
				cout << "b" << n << " = " << an[n] << endl;
				n++;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (an[i] == 1)
		{
			if (ColumnX[i] == 1)
				cout << "x";
			if (ColumnY[i] == 1)
				cout << "y";
			if (ColumnZ[i] == 1)
				cout << "z";
			if (i != n - 1)
			{
				cout << " XOR ";
			}

		}
	}
	cout << endl;

	return 0;
}

int Anorosh(int an[], int xyz[], int function, int n)
{

	if (n == 0)
	{

		return 0;
	}

	an[n] = function;
	int res = an[0];

	for (int j = 1; j <= n; j++)
	{
		if (xyz[j] == 0)
		{
			continue;
		}
		res = XOR(an[j], res);
	}
	return res;
}