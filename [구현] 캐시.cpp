#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define INT_PAIR pair<int, int>
#define STR_INT_PAIR pair<string, int>

const bool compare (const STR_INT_PAIR & left, const STR_INT_PAIR & right) {
	return left.second > right.second;
}

/*
	페이지 교체 알고리즘은 페이징 기법으로 메모리를 관리하는 운영체제에서, 페이지 부재가 발생 하여 새로운 페이지를 할당하기 위해 현재 할당된 페이지 중 어느 것과 교체할지를 결정하는 방법이다. 이 알고리즘이 사용되는 시기는 페이지 부재가 발생해 새로운 페이지를 적재 해야하나 페이지를 적재할 공간이 없어 이미 적재되어 있는 페이지 중 교체할 페이지를 정할 때 사용된다. 
	빈 페이지가 없는 상황에서 메모리에 적재된 페이지와 적재할 페이지를 교체함으로 페이지 부재 문제를 해결할 수 있다.

	캐시 교체 알고리즘은 LRU (Least Recently Used)를 사용한다.
	ⓐ Cache Hit일 경우 실행시간은 1이다.
	ⓑ Cache Miss일 경우 실행시간은 5이다.
*/

int solution(int cacheSize, vector<string> cities) {

	int answer = 0;
	unordered_set<string> cache;
	vector<STR_INT_PAIR> cache_time;
	const INT_PAIR CACHE_VALUE = make_pair(1, 5); // (HIT = 1, FALUT = 5)

	// 캐시의 크기가 0인 경우에는 모든 캐시 미스가 발생하므로 예외처리한다.
	if (cacheSize == 0) { return cities.size() * CACHE_VALUE.second; }
	
	for (string city : cities) {

		// CAPTION : 각 도시 이름은 공백, 숫자, 특수문자 등이 없는 영문자로 구성되며, 대소문자 구분을 하지 않는다. 도시 이름은 최대 20자로 이루어져 있다.
		std::transform(city.begin(), city.end(), city.begin(), ::tolower);

		// 캐시 내부에 현재의 내용이 저장되어 있는 경우
		if ( cache.find(city) != cache.end() ) {
			// 캐시가 새롭게 저장이 되었으므로 시간을 초기화한다.
			for (int index = 0; index != cacheSize; index++) {
				if (cache_time[index].first.compare(city) == 0) { cache_time[index].second = 0; break; }
			}
			answer += CACHE_VALUE.first;
		}
		// 캐시 내부에 현재의 내용이 저장되어 있지 않은 경우
		else {
			const auto item = make_pair(city, 0);

			// 캐시의 크기가 지정 된 용량만큼 채워지지 않은 경우
			if (cache.size() < cacheSize) {
				answer += CACHE_VALUE.second;
			}
			// 캐시의 크기가 지정 된 용량만큼 채워진 경우
			else {
				// 캐시의 내용이 저장 된 순서를 내림차순으로 정렬한다.
				std::sort(cache_time.begin(), cache_time.end(), compare);

				const auto item = *cache_time.begin();
				cache.erase(item.first);
				cache_time.erase(cache_time.begin());

				answer += CACHE_VALUE.second;
			}

			cache.insert(city);
			cache_time.push_back(item);
		}

		for (auto & item : cache_time) { item.second++; }
	}

	// 입력된 도시이름 배열을 순서대로 처리할 때, 총 실행시간을 출력한다.
	return answer;
}
