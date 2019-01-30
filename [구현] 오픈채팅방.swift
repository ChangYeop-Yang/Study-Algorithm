import Foundation

private enum Commend: String {
    case Enter  = "Enter"
    case Leave  = "Leave"
    case Change = "Change"
}

func solution(_ record:[String]) -> [String] {
    
    var user: [String: String] = [:]
    var result: [(message: String, uid: String)] = []
    
    for item in record {
        let rec: [String] = item.split(separator: " ").map(String.init)
        
        if let commend: Commend = Commend(rawValue: rec[0]) {
            switch commend {
            case .Enter:
                user[rec[1]] = rec[2]
                result.append(("님이 들어왔습니다.", rec[1]))
            case .Leave:
                result.append(("님이 나갔습니다.", rec[1]))
            case .Change: user[rec[1]] = rec[2]
            }
        }
    }
    
    let answer: [String] = result.compactMap { "\(user[$0.uid]!)\($0.message)" }
    return answer
}