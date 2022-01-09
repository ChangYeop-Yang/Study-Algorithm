class Solution {
    
    func largestNumber(_ nums: [Int]) -> String {
    
        let strNums = nums.map { String($0) }.sorted { $0 + $1 > $1 + $0 }
        
        let result = strNums.joined()
        
        // 처음 시작하는 숫자가 0인 경우에는 연속적인 0이 입력이 되어도 0을 반환합니다.
        guard result.first == "0" else { return result }
    
        return "0"
    }
}
