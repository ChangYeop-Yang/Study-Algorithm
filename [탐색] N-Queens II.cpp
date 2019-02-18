#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define HOLE false
#define QUEEN true
#define INT_PAIR pair<int, int>
#define BOOL_VECTOR vector<bool>
#define STRING_VECTOR vector<string>

class Solution {
    public:
        void fillBoard(vector<BOOL_VECTOR> & board, const INT_PAIR index, const int size) {

            const vector<INT_PAIR> direct = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0)
                , make_pair(1, 1), make_pair(-1, -1), make_pair(1, -1), make_pair(-1, 1) };

            for (int ii = 0; ii < direct.size(); ii++) {

                INT_PAIR there = index;
                while (true) {
                    // Case Out Of Range
                    if (there.first < 0 || there.first >= size || there.second < 0 || there.second >= size) { break; }
                    // Case Fill
                    board[there.first][there.second] = true;
                    there.first += direct[ii].first, there.second += direct[ii].second;
                }
            }
        }

        vector<INT_PAIR> findQueenPos(const int size, vector<BOOL_VECTOR> board) {

            vector<INT_PAIR> location;

            for (int ii = 0; ii < size; ii++) {
                for (int jj = 0; jj < size; jj++) {
                    if (board[ii][jj] == QUEEN) { location.push_back(make_pair(ii, jj)); }
                }
            }

            return location;
        }

        bool promissing(vector<BOOL_VECTOR> board, const INT_PAIR index, const int size) {

            const vector<INT_PAIR> location = findQueenPos(size, board);
            for (const auto pos : location) { fillBoard(board, pos, size); }
            return board[index.first][index.second]; // TRUE - QUEEN, FALSE - HOLE
        }

        void backtracking(vector<BOOL_VECTOR> board, const INT_PAIR index, const int size, int depth, int & answer) {

            // Case Depth Equal N.
            if (depth == size) { answer++; return; }

            for (int ii = 0; ii < size; ii++) {
                // Case Check Queen Position.
                if (promissing(board, make_pair(depth, ii), size) == HOLE) {
                    board[depth][ii] = QUEEN; // Queen을 놓아 본다.
                    backtracking(board, make_pair(depth, ii), size, depth + 1, answer);
                    board[depth][ii] = HOLE; // Queen을 빼본다.
                }
            }
        }    
    
        int totalNQueens(int n) {
            
            int answer = 0;
	        vector<BOOL_VECTOR> board = vector<BOOL_VECTOR>(n, vector<bool>(n));
            backtracking(board, make_pair(0, 0), n, 0, answer);
            
            return answer;
        }
};
