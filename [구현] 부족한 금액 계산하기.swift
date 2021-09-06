import Foundation

/**
    - 놀이기구의 이용료 price : 1 ≤ price ≤ 2,500, price는 자연수
    - 처음 가지고 있던 금액 money : 1 ≤ money ≤ 1,000,000,000, money는 자연수
    - 놀이기구의 이용 횟수 count : 1 ≤ count ≤ 2,500, count는 자연수
*/
func solution(_ price: Int, _ money: Int, _ count: Int) -> Int64 {
    
    var result: Int64 = Int64.zero
    for number in 0...count { result += Int64(price) * Int64(number) }
    
    if Int64(money) - result >= Int64.zero { return Int64.zero }
    
    // 단, 금액이 부족하지 않으면 0을 return 하세요.
    return result - Int64(money)
}

print(solution(3, 20, 4))
