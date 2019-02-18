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

        void backtracking(vector<STRING_VECTOR> & answer, vector<BOOL_VECTOR> board, const INT_PAIR index, const int size, int depth) {

            // Case Depth Equal N.
            if (depth == size) {
                vector<string> subAnswer = vector<string>(size, string());
                for (int ii = 0; ii < size; ii++) {
                    for (int jj = 0; jj < size; jj++) { 
                        const char letter = board[ii][jj] == QUEEN ? 'Q' : '.';
                        subAnswer[ii].push_back(letter);
                    }
                }
                answer.push_back(subAnswer);
                return;
            }

            for (int ii = 0; ii < size; ii++) {
                // Case Check Queen Position.
                if (promissing(board, make_pair(depth, ii), size) == HOLE) {
                    board[depth][ii] = QUEEN; // Queen을 놓아 본다.
                    backtracking(answer, board, make_pair(depth, ii), size, depth + 1);
                    board[depth][ii] = HOLE; // Queen을 빼본다.
                }
            }
        }
        
        vector<vector<string>> solveNQueens(int n) {

            vector<STRING_VECTOR> answer;
            vector<BOOL_VECTOR> board = vector<BOOL_VECTOR>(n, vector<bool>(n));

            backtracking(answer, board, make_pair(0, 0), n, 0);
            
            return answer;
        }
};
