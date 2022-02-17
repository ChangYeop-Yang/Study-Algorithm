import Foundation

func findIndex(ranked: [Int], score: Int, first: Int, last: Int) -> Int {
    
    let halfIndex = (first + last) / 2
    
    if first > last { return halfIndex }
    
    if ranked[halfIndex] == score {
        return halfIndex
    }
    else if ranked[halfIndex] < score {
        return findIndex(ranked: ranked, score: score, first: first, last: halfIndex - 1)
    }
    else {
        return findIndex(ranked: ranked, score: score, first: halfIndex + 1, last: last)
    }
}

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

func climbingLeaderboard(ranked: [Int], player: [Int]) -> [Int] {

    var answer: [Int] = []
    
    var rank: Int = Int.zero
    var leaderboard: [Int: Int] = [:]
    for score in ranked {
        if leaderboard.keys.contains(score) == false { rank = rank + 1 }
        
        leaderboard.updateValue(rank, forKey: score)
    }
    
    let length: Int = ranked.count
    for score in player {
        if let rank = leaderboard[score] {
            answer.append(rank)
            continue
        }
        
        let index = findIndex(ranked: ranked, score: score, first: Int.zero, last: length - 1)
        
        let approach = ranked[index]
        if let rank = leaderboard[approach] {
            answer.append(approach > score ? rank + 1 : rank)
        }
    }
    
    return answer
}

let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: stdout)!

guard let rankedCount = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

guard let rankedTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }

let ranked: [Int] = rankedTemp.split(separator: " ").map {
    if let rankedItem = Int($0) {
        return rankedItem
    } else { fatalError("Bad input") }
}

guard ranked.count == rankedCount else { fatalError("Bad input") }

guard let playerCount = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

guard let playerTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }

let player: [Int] = playerTemp.split(separator: " ").map {
    if let playerItem = Int($0) {
        return playerItem
    } else { fatalError("Bad input") }
}

guard player.count == playerCount else { fatalError("Bad input") }

let result = climbingLeaderboard(ranked: ranked, player: player)

fileHandle.write(result.map{ String($0) }.joined(separator: "\n").data(using: .utf8)!)
fileHandle.write("\n".data(using: .utf8)!)
