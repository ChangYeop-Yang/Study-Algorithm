import Foundation

// MARK: - 항상 ICN 공항에서 출발합니다.
let ICN: String = "ICN"

func findTrip(depth: Int, airport: String, ticket: [[String]], answer: inout [String], visited: inout [Bool], path: inout [String]) {
    
    path.append(airport)
    
    // MARK: - 주어진 항공권을 통하여 모든 경로를 탐색하여 완료한 경우
    if depth == ticket.count { answer = path; return }
    
    for index in 0..<ticket.count where answer.isEmpty {
        
        let information: (start: String, end: String) = (ticket[index].first!, ticket[index].last!)
        
        // MARK: - tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
        if visited[index] == false && airport == information.start {
            visited[index] = true
            findTrip(depth: depth + 1, airport: information.end, ticket: ticket, answer: &answer, visited: &visited, path: &path)
            visited[index] = false
        }
    }
    
    path.removeLast()
}

func solution(_ tickets:[[String]]) -> [String] {

    // MARK: - 만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
    var path = Array<String>()
    var answer = Array<String>()
    var visited = Array<Bool>(repeating: false, count: tickets.count)

    let ticket = tickets.sorted { $0.last! < $1.last! }
    findTrip(depth: 0, airport: ICN, ticket: ticket, answer: &answer, visited: &visited, path: &path)
    
    return answer
}
