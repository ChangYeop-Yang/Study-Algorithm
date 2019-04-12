#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_PAIR pair<int, int>
#define INT_VECTOR vector<int>
#define INT_PAIR_VECTOR vector<INT_PAIR>

int answer = 0;

const vector<INT_PAIR_VECTOR> tetris = {

	/* ■■■■ */
	{make_pair(0, 0), make_pair(0, 1), make_pair(0, 2), make_pair(0, 3)},
	{make_pair(0, 0), make_pair(1, 0), make_pair(2, 0), make_pair(3, 0)}, // (R)

	/* ■■
	   ■■ */
	{make_pair(0, 0), make_pair(0, 1), make_pair(1, 0), make_pair(1, 1)},

	/*
		■								■
		■■	  ■■		■■	  ■■
		  ■	■■		  ■■	  ■
	*/
	{make_pair(0, 0), make_pair(1, 0), make_pair(1, 1), make_pair(2, 1)},
	{make_pair(0, 0), make_pair(0, 1), make_pair(1, 0), make_pair(1, -1)},	 // (R)
	{make_pair(0, 0), make_pair(0, 1), make_pair(1, 1), make_pair(1, 2)},	 // (CR)
	{make_pair(0, 0), make_pair(1, 0), make_pair(1, -1), make_pair(2, -1)},   // (CR)

	/* 
		■■■	■        ■		  ■
	      ■    ■■    ■■■		■■
		        ■					  ■
	*/
	{make_pair(0, 0), make_pair(0, -1), make_pair(0, 1), make_pair(1, 0)},
	{make_pair(0, 0), make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1)},	// (R)
	{make_pair(0, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)},	// 凸 (R)
	{make_pair(0, 0), make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1)},	// (R)
	
	/*
		■		■■
		■	      ■		■		■■■
		■■      ■	■■■		■
	*/
	{make_pair(0, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(-2, 0)},
	{make_pair(0, 0), make_pair(0, -1), make_pair(1, 0), make_pair(2, 0)},
	{make_pair(0, 0), make_pair(-1, 0), make_pair(0, -1), make_pair(0, -2)},
	{make_pair(0, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, 2)},

	/*
		   ■			■■	
		   ■	■		■		■■■
		 ■■	■■■	■			■
	*/
	{make_pair(0, 0), make_pair(-1, 0), make_pair(-2, 0), make_pair(0, -1)},
	{make_pair(0, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, 2)},
	{make_pair(0, 0), make_pair(0, 1), make_pair(1, 0), make_pair(2, 0)},
	{make_pair(0, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, -2)}
};

int main(void)
{
	INT_PAIR input = make_pair(0, 0);
	cin >> input.first >> input.second;

	vector<INT_VECTOR> map = vector<INT_VECTOR>(input.first, vector<int>(input.second));
	for (int ii = 0; ii < input.first; ii++) {
		for (int jj = 0; jj < input.second; jj++) { cin >> map[ii][jj]; }
	}
	
	for (const auto block : tetris) {
		
		for (int ii = 0; ii < input.first; ii++) {
			for (int jj = 0; jj < input.second; jj++) {

				pair<int, bool> val = make_pair(0, false);
				for (const auto index : block) {
					INT_PAIR xy = make_pair(ii + index.first, jj + index.second);
					
					// Case Out of Range
					if (xy.first < 0 || xy.first > input.first - 1 || xy.second < 0 || xy.second > input.second - 1) { val.second = true; break; }
					val.first += map[xy.first][xy.second];
				}

				if (val.second) { continue; }
				answer = max(answer, val.first);
			}
		}

	}
		
	cout << answer << endl;

	return 0;
}
