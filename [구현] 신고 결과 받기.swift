import Foundation

public typealias Result = [String: Set<String>]

/**
    - NOTE:
        - 각 유저는 한 번에 한 명의 유저를 신고할 수 있습니다.
            - 신고 횟수에 제한은 없습니다. 서로 다른 유저를 계속해서 신고할 수 있습니다.
            - 한 유저를 여러 번 신고할 수도 있지만, 동일한 유저에 대한 신고 횟수는 1회로 처리됩니다.
        - k번 이상 신고된 유저는 게시판 이용이 정지되며, 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송합니다.
            - 유저가 신고한 모든 내용을 취합하여 마지막에 한꺼번에 게시판 이용 정지를 시키면서 정지 메일을 발송합니다.
 
    - Parameters:
        - id_list: 이용자의 ID가 담긴 문자열 배열
        - report: 각 이용자가 신고한 이용자의 ID 정보가 담긴 문자열 배열
        - k: 정지 기준이 되는 신고 횟수
 */
func solution(_ id_list: [String], _ report: [String], _ k: Int) -> [Int] {
    
    var list: Result = [:]
    var email: [String: Int] = [:]
    
    // ID 목록 초기값을 설정합니다.
    id_list.forEach {
        email[$0] = Int.zero
        list[$0] = .init()
    }
    
    for item in report {
        let split = item.split(separator: " ").compactMap { String($0) }
        let left = split.first ?? .init(), right = split.last ?? . init()
        
        list[right]?.insert(left)
    }
    
    for (key, value) in list where value.count >= k {
        value.forEach { email[$0]? += 1 }
    }
    
    // 유저별로 처리 결과 메일을 받은 횟수를 배열로 반환합니다.
    var answer: [Int] = []
    id_list.forEach { answer.append(email[$0] ?? Int.zero) }
    
    return answer
}
