/**
    - NOTE:
        - 지도는 한 변의 길이가 n인 정사각형 배열 형태로, 각 칸은 "공백"(" ") 또는 "벽"("#") 두 종류로 이루어져 있다.
        - 전체 지도는 두 장의 지도를 겹쳐서 얻을 수 있다. 각각 "지도 1"과 "지도 2"라고 하자. 지도   1 또는 지도 2 중 어느 하나라도 벽인 부분은 전체 지도에서도 벽이다. 지도 1과 지도 2에서 모두 공백인 부분은 전체 지도에서도 공백이다.
        - "지도 1"과 "지도 2"는 각각 정수 배열로 암호화되어 있다.
        - 암호화된 배열은 지도의 각 가로줄에서 벽 부분을 1, 공백 부분을 0으로 부호화했을 때 얻어지는 이진수에 해당하는 값의 배열이다.
*/
func solution(_ n: Int, _ arr1: [Int], _ arr2: [Int]) -> [String] {
    
    var answer: [String] = []
    
    let length = arr1.count
    for index in Int.zero..<length {
        let leftValue = arr1[index]
        let rightValue = arr2[index]
        
        var result = String(leftValue | rightValue, radix: 2)
        
        // 계산되어 진 값에 대한 길이가 동일하지 않은 경우
        while result.count != n {
            result.insert("0", at: result.startIndex)
        }
        
        result = result.compactMap { $0 == "0" ? " " : "#" }.joined()
        answer.append(result)
    }
    
    return answer
}
