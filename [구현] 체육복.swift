import Foundation

func solution(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    
    // MARK: - 전체 학생의 수 n, 체육복을 도난당한 학생들의 번호가 담긴 배열 lost, 여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve가 매개변수
    var person: [Int] = Array<Int>(repeating: 1, count: n)
    
    for index in lost { person[index - 1] -= 1 }
    
    for index in reserve { person[index - 1] += 1 }
    
    // MARK: - 체육복이 없으면 수업을 들을 수 없기 때문에 체육복을 적절히 빌려 최대한 많은 학생이 체육수업을 들어야 합니다.
    for index in person.indices {
        // MARK: - 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다.
        let nextIndex = person.index(after: index)
        let priviousIndex = person.index(before: index)
        
        if person[index] == Int.zero {
            if person.indices.contains(priviousIndex) && person[priviousIndex] > 1 {
                person[priviousIndex] -= 1
                person[index] += 1
                continue
            }
            if person.indices.contains(nextIndex) && person[nextIndex] > 1 {
                person[nextIndex] -= 1
                person[index] += 1
                continue
            }
        }
    }
    
    return person.filter { $0 > Int.zero }.count
}
