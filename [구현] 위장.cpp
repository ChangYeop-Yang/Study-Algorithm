#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

#define STRING_VECTOR vector<string>
#define STRING_PAIR pair<string, string>

int solution(vector<vector<string>> clothes) {
    
    int answer = 1;
    
    unordered_map<string, STRING_VECTOR> clothesMap;
    for (const auto out : clothes) {
        
        const STRING_PAIR input = make_pair(out.front(), out.back());
        
        if (clothesMap.find(input.second) == clothesMap.end()) { 
            const auto item = make_pair(input.second, STRING_VECTOR());
            clothesMap.insert(item); 
        }
        
        clothesMap[input.second].push_back(input.first);
    }
    
    for (auto begin = clothesMap.begin(); begin != clothesMap.end(); begin++) { 
        const auto clothe = *begin;
        answer *= (clothe.second.size() + 1);
    }
    
    return answer - 1;
}
