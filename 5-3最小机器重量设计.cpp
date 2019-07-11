#include<iostream>
#include<fstream>
using namespace std;
int n;
int m;
int w[100][100];
int c[100][100];
int bestx[100];//最优解
int bestw = 1 << 18;//当前最小重量
int x[100];//当前解
int cw = 0;
int cc = 0;
int d;
int main()
{
	ifstream infile("input.txt", ios::in);
	void backtrack(int i);
	infile >> n >> m >> d;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			infile >> c[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			infile >> w[i][j];
	infile.close();
	backtrack(1);
	ofstream outfile("output.txt", ios::out);
	outfile << bestw << endl;
	for (int i = 1; i <= n; i++)
		outfile << bestx[i] << "  ";
	outfile.close();
	return 0;
}

void backtrack(int i)
{
	if (i > n)
	{
		if (cw < bestw || x[i] == -1) {
			for (int j = 1; j <= n; j++)
				bestx[j] = x[j];
			bestw = cw;
			return;
		}
	}
	else
	{
		for (int j = 1; j <= m; j++)
		{

			cw += w[i][j];
			cc += c[i][j];
			x[i] = j;
			if (cc <= d && cw < bestw)
				backtrack(i + 1);
			cw -= w[i][j];
			cc -= c[i][j];
			x[i] = -1;

		}
	}
}

