#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

bool checkGapWord(const string comp, const string target) {
	int gap = 0;
	for (int ii = 0; ii < comp.size(); ii++) { if (comp[ii] != target[ii]) { gap++; } }
	return (gap == 1 ? true : false);
}

void reculsiveDFS(int & answer, string begin, int count, const string target, const vector<string> words, vector<bool> & visit) {

	// Case Find Target.
	if (target == begin) { answer = min(answer, count); return; }

	for (int ii = 0; ii < words.size(); ii++) {
        
        // Case Not Used Word
        if (visit[ii] && checkGapWord(begin, words[ii])) {
            visit[ii] = false; // Used Word
            reculsiveDFS(answer, words[ii], count + 1, target, words, visit);
            visit[ii] = true;  // Unused Word
        }
	}
}

int solution(string begin, string target, vector<string> words) {
	
	int answer = INT_MAX;
    
    vector<bool> visit = vector<bool>(words.size(), true);
	reculsiveDFS(answer, begin, 0, target, words, visit);   

    // 변환할 수 없는 경우에는 0를 return 합니다. (return 0)
	return (answer == INT_MAX ? 0 : answer);
}
