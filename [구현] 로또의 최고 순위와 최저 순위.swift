import Foundation

/**
    - NOTE:
        - 알아볼 수 없는 번호를 0으로 표기합니다.
        - 0은 알아볼 수 없는 숫자를 의미합니다.
        - 0을 제외한 다른 숫자들은 lottos에 2개 이상 담겨있지 않습니다.
        - win_nums에는 같은 숫자가 2개 이상 담겨있지 않습니다.
        - 순서와 상관없이, 구매한 로또에 당첨 번호와 일치하는 번호가 있으면 맞힌 걸로 인정됩니다.
*/
func solution(_ lottos: [Int], _ win_nums: [Int]) -> [Int] {
  
    var rate: (Int) -> Int = { value in
        // 당첨 된 번호가 1개 이하 경우에는 6등 (낙첨) 처리합니다.
        if value <= 1 { return 6 }
        return 7 - value
    }
    
    // 주어진 숫자들을 모두 알아볼 수가 없는 경우
    let zeroCount = lottos.filter { $0 == Int.zero }.count
    
    var matching = Set(win_nums)
    for number in lottos where matching.contains(number) {
        matching.remove(number)
    }
    
    let containZeroWin = (win_nums.count - matching.count) + zeroCount
    let nonContainZeroWin = win_nums.count - matching.count
    
    // MARK: 당첨 가능한 최고 순위와 최저 순위를 차례대로 배열에 담아서 return 합니다.
    return [rate(containZeroWin), rate(nonContainZeroWin)]
}
