#include <iostream>
using namespace std;

#define SIZE 126
#define INF 999999L

int anArray[SIZE][SIZE];
int anDestin[SIZE][SIZE];

int main(void)
{
	pair<int, int> apMovePath[] = {make_pair(+1, 0), make_pair(0, +1), make_pair(-1, 0), make_pair(0, -1)};

	for (int qq = 1; true; qq++)
	{
		int nMatrix = 0; cin >> nMatrix;

		if (nMatrix == 0) { break; }

		for (int ii = 0; ii < nMatrix; ii++)
			for (int jj = 0; jj < nMatrix; jj++)
				anArray[ii][jj] = anDestin[ii][jj] = INF;

		for (int ii = 0; ii < nMatrix; ii++)
			for (int jj = 0; jj < nMatrix; jj++)
				cin >> anArray[ii][jj];

		pair<int, int> pLoation = make_pair(0, 0);
		anDestin[pLoation.first][pLoation.second] = anArray[pLoation.first][pLoation.second];

		for (int nMin = INF; true; nMin = INF)
		{
			for (int ii = 0; ii < nMatrix; ii++)
				for (int jj = 0; jj < nMatrix; jj++)
				{ if (anDestin[ii][jj] != -1 && anDestin[ii][jj] <= nMin) { nMin = anDestin[ii][jj]; pLoation = make_pair(ii, jj); } }

			if (pLoation.first == nMatrix - 1 && pLoation.second == nMatrix - 1) { break; }

			for (int ii = 0; ii < 4; ii++)
			{
				int nLowX = pLoation.first + apMovePath[ii].first;
				int nLowY = pLoation.second + apMovePath[ii].second;

				if ((nLowX < 0 || nLowY < 0) || (nLowX > nMatrix || nLowY > nMatrix)) { continue; }
				if (anDestin[nLowX][nLowY] != INF) { continue; }

				anDestin[nLowX][nLowY] = anDestin[pLoation.first][pLoation.second] + anArray[nLowX][nLowY];
			}

			anDestin[pLoation.first][pLoation.second] = -1;
		}

		cout << "Problem " << qq << ": " << anDestin[nMatrix - 1][nMatrix - 1] << endl;
	}

	return 0;
}
