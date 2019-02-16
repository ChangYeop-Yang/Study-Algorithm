#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_VECTOR vector<int>
#define INT_PAIR pair<int, int>

class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

                vector<int> degree = vector<int>(numCourses);
                vector<INT_VECTOR> adj = vector<INT_VECTOR>(numCourses);

                for (const auto pre : prerequisites) {
                    adj[pre.first].push_back(pre.second);
                    degree[pre.second]++;
                }
                
                priority_queue<int> pq;
                for (int ii = 0; ii < numCourses; ii++) { if (degree[ii] == 0) { pq.push(-ii); } }
            
                vector<int> answer;
                while (!pq.empty()) {
                    const int here = -pq.top(); pq.pop();
                    answer.push_back(here);
                    
                    for (int ii = 0; ii < adj[here].size(); ii++) {
                        const int there = adj[here][ii];
                        degree[there]--;
                        
                        if (degree[there] == 0) { pq.push(-there); }
                    }
                }
                
                std::reverse(answer.begin(), answer.end());
                return answer.size() == numCourses ? answer : vector<int>();
        }
};
