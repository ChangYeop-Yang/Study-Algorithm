#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define MAX_V 2
#define INT_PAIR pair<int, int>
#define INT_VECTOR vector<INT_PAIR>
#define STRING_INT_PAIR pair<string, int>

const bool compare(const STRING_INT_PAIR & first, const STRING_INT_PAIR & second) {
	return first.second > second.second;
}

const bool compareMusic(const INT_PAIR & first, const INT_PAIR & second) {
	/* MARK: - 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다. */
	if (first.second == second.second) { return first.first < second.first; }
	/* MARK: - 장르 내에서 많이 재생된 노래를 먼저 수록합니다. */
	else { return first.second > second.second; }
}

vector<int> solution(vector<string> genres, vector<int> plays) {

	unordered_map<string, int> music_type;
	unordered_map<string, INT_VECTOR> music_inf;

	for (int ii = 0; ii < plays.size(); ii++) {
		const auto value = make_pair(genres[ii], plays[ii]);
		/* MARK: - Music Type Counting */           music_type[value.first] += value.second;
		/* MARK: - Music Index and Play Counting */ music_inf[value.first].push_back(make_pair(ii, value.second));
	}

	// Case 속한 노래가 많이 재생된 장르를 먼저 수록한다.
	vector<STRING_INT_PAIR> rank_type = vector<STRING_INT_PAIR>(music_type.begin(), music_type.end());
	std::sort(rank_type.begin(), rank_type.end(), compare);

	// Case 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
	for (auto & music : music_inf) { 
		std::sort(music.second.begin(), music.second.end(), compareMusic); 
	}

	vector<int> answer;
	/* ※ CAPTION : genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다. */
	for (auto type : rank_type) {
		// 스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다.
		if (music_inf[type.first].size() > 1) { 
			answer.push_back(music_inf[type.first][0].first);
            answer.push_back(music_inf[type.first][1].first);
		}
        // 장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
        else { answer.push_back(music_inf[type.first].front().first); }
	}

	return answer;
}