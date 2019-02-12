#include <string>
#include <vector>
using namespace std;

#define INT_VECTOR vector<int>

void reculsiveDFS(int index, vector<INT_VECTOR> map, vector<bool> & visit) {
    
    visit[index] = false;
    for (int ii = 0; ii < map.size(); ii++) { 
        if (map[index][ii] == 1 && visit[ii]) { reculsiveDFS(ii, map, visit); }   
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visit = vector<bool>(computers.size(), true);
    
    int length = computers.size();
    for (int ii = 0; ii < length; ii++) {
        if (visit[ii]) { reculsiveDFS(ii, computers, visit); answer++; }
    }
    
    return answer;
}
