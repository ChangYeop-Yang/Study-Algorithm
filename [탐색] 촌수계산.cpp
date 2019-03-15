#include <queue>
#include <vector>
#include <iostream>
using namespace std;

#define NOT_CONNECT 0
#define INT_VECTOR vector<int>
#define INT_PAIR pair<int, int>

void breadth_first_search(const int length, const int start, const vector<INT_VECTOR> & board, vector<int> & distance) {

	queue<int> que;
	que.push(start);

	while (!que.empty()) {

		const int here = que.front(); que.pop();
		const int cost = distance[here] + 1;

		for (int vertax = 0; vertax < length; vertax++) {

			// Case Not Connect Vertax and Already Visited Vertax.
			if (board[here][vertax] == NOT_CONNECT || distance[vertax] != NOT_CONNECT) { continue; }
			
			// Case Connected Vertax and Not Visited Vertax.
			que.push(vertax);
			distance[vertax] += cost;
		}
	}
}

void depth_first_search(const int length, const int index, const vector<INT_VECTOR> & board, vector<int> & distance) {
	
	for (int vertax = 0; vertax < length; vertax++) {

		const int cost = distance[index] + 1;

		if (board[index][vertax] != NOT_CONNECT && distance[vertax] == 0) {
			distance[vertax] += cost;
			depth_first_search(length, vertax, board, distance);
		}
	}

}

int main(void)
{
	int length = 0; cin >> length;

	INT_PAIR target = make_pair(0, 0);
	cin >> target.first >> target.second;

	int relationship = 0; cin >> relationship;
	
	vector<int> visited = vector<int>(length);
	vector<INT_VECTOR> board = vector<INT_VECTOR>(length, INT_VECTOR(length));
	for (int ii = 0; ii < relationship; ii++) {
		INT_PAIR relation = make_pair(0, 0);
		cin >> relation.first >> relation.second;

		board[relation.first - 1][relation.second - 1] = board[relation.second - 1][relation.first - 1] = 1;
	}

	//breadth_first_search(length, target.first - 1, board, visited);
	depth_first_search(length, target.first - 1, board, visited);
	cout << (visited[target.second - 1] == 0 ? -1 : visited[target.second - 1]) << endl;

	return 0;
}