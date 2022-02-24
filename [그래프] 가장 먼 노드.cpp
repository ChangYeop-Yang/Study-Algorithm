#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define ZERO 0

typedef vector<int> NodeMap;
typedef vector<bool> VisitMap;

int findAwayNode(vector<NodeMap> nodeMap, vector<bool> & isVisit, const int index, const int length) {
    
    int answer = ZERO;
    int awayMaxValue = ZERO;
    
    vector<int> dist = vector<int>(length, ZERO);
   
    queue<int> bucket = queue<int>();
    bucket.push(index);
    
    dist[index] = 1;
    isVisit[index] = true;
    
    while(bucket.empty() == false) {
        
        const auto value = bucket.front();
        bucket.pop();
        
        for (const auto node : nodeMap[value]) {
            if (isVisit[node]) { continue; }
            
            dist[node] = dist[value] + 1;
            awayMaxValue = std::max(dist[node], awayMaxValue);
            
            bucket.push(node);
            isVisit[node] = true;
        }
    };
    
    // 주어진 노드에서 가장 멀리 떠어진 노드의 간선의 수에 해당하는 노드를 찾습니다.
    for (const int value : dist) {
        if (value == awayMaxValue) { answer++; }
    }
    
    return answer;
}

int solution(int n, vector<vector<int>> edge) {
    
    vector<NodeMap> map = vector<NodeMap>(n, NodeMap());
    
    // 주어진 간선을 통하여 무방향의 그래프를 생성합니다.
    for (const auto pos : edge) {
        const auto first = pos.front();
        const auto second = pos.back();
        
        map[first - 1].push_back(second - 1);
        map[second - 1].push_back(first - 1);
    }
    
    VisitMap visit = VisitMap(n, false);
    int answer = findAwayNode(map, visit, ZERO, n);
    
    // NOTE: - 가장 멀리 떨어진 노드란 최단경로로 이동했을 때 간선의 개수가 가장 많은 노드를 구합니다.
    return answer;
}
