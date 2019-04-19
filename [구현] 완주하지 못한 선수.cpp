#include <string>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {

	map<string, int> result;
	
	for (const string person : participant) {
		
		if (result.find(person) != result.end()) {
			result.at(person)++;
			continue;
		}

		result.insert(make_pair(person, 1));
	}

	for (const string person : completion) {

		if (result.at(person) > 1) {
			result.at(person)--;
			continue;
		}

		result.erase(person);
	}

	return (*result.begin()).first;
}
