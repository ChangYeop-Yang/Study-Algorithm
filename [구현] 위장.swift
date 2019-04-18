import Foundation

func solution(_ clothes: [[String]]) -> Int {
    
    var answer = 1
    var clotheType: [String: Array<String>] = [:]
    
    for apperal in clothes {
        let type = apperal.last!, name = apperal.first!
        
        if clotheType.keys.contains(type) == false {
            clotheType[type] = [name]
            continue
        }
        
        clotheType[type]?.append(name)
    }
    
    /*
         ※ Soluction
         각각 종류마다 n1,n2,n3 가지고 있다면 (n1) x (n2) x (n3) 이다.
         하지만 문제에서 제시 된 각각 종류를 입지 않는 경우도 있으므로 경우의 수 +1 하게되면
         (n1 + 1) x (n2 + 1) x (n3 + 1) 의 식이된다.
         그리고 이후 마지막에는 모두 입지 않은 경우의수 -1 를 하게되면 답이 나오게 된다.
     */
    
    for value in clotheType { answer *= (value.value.count + 1) }
    
    return answer - 1
}
