#include <string>
#include <vector>
using namespace std;

// prices은 하나의 주식 가격 목록 초당 주식 가격 (개별이 아닌 하나의 주식의 가격 목록)
vector<int> solution(vector<int> prices) {
    
    vector<int> answer;
    
    int length = prices.size();
    for (int ii = 0; ii < length - 1; ii++) { 
        // 마지막의 주식 가격은 떨어지지 않으므로 마지막의 그 전 주식 가격만 확인한다.
        int count = 0;
        for (int jj = ii + 1; jj < length; jj++) {
            if (prices[ii] <= prices[jj]) { count++; } // 주식의 가격이 크거나 같은 경우에는 주식의 가격이 떨어지지 않았으므로 Count를 하나 증가시킨다.
            else { count++; break; } // 주식의 가격이 떨어졌을 경우
        }
        
        answer.push_back(count);
    }
    
    // 마지막 주식 가격은 떨어질 수가 없기에 무조건 0을 넣어준다.
    answer.push_back(0);
    
    // 가격이 떨어지지 않은 기간은 몇 초인지를 return 하도록 solution 함수를 완성하세요.
    return answer;
}
