import Foundation

private typealias Attribute = (percentage: Float, upperWin: Int, weight: Int, win: Int)

/**
    - MARK:
        - 전체 승률이 높은 복서의 번호가 앞쪽으로 갑니다. 아직 다른 복서랑 붙어본 적이 없는 복서의 승률은 0%로 취급합니다.
        - 승률이 동일한 복서의 번호들 중에서는 자신보다 몸무게가 무거운 복서를 이긴 횟수가 많은 복서의 번호가 앞쪽으로 갑니다.
        - 자신보다 무거운 복서를 이긴 횟수까지 동일한 복서의 번호들 중에서는 자기 몸무게가 무거운 복서의 번호가 앞쪽으로 갑니다.
        - 자기 몸무게까지 동일한 복서의 번호들 중에서는 작은 번호가 앞쪽으로 갑니다.
*/
func solution(_ weights: [Int], _ head2head: [String]) -> [Int] {
    
    var player: [Int: Attribute] = [:]
    
    for (index, weight) in weights.enumerated() {
        player[index] = Attribute(Float.zero, Int.zero, weight, Int.zero)
    }
    
    // 임의의 i에 대해서 head2head[i][i] 는 항상 'N'입니다. 자기 자신과 싸울 수는 없기 때문입니다.
    for (number, weight) in weights.enumerated() {
        
        var total: Int = Int.zero
        for index in head2head[number].indices where head2head[number][index] != "N" {
            
            total += 1
            
            // 플레이어가 게임에서 승리한 경우
            if head2head[number][index] == "W" {
                player[number]?.win += 1
                
                // 자신보다 무거운 복서를 이긴 경우
                let position = head2head[number].distance(from: head2head[number].startIndex, to: index)
                if weight < player[position]!.weight { player[number]?.upperWin += 1 }
            }
        }
        
        // 승률은 (플레이어 승리 횟수 / 총 게임 횟수) * 100
        let winCount: Int = player[number]?.win ?? Int.zero
        player[number]?.percentage = Float(winCount) / Float(total) * 100
    }
    
    return player.sorted {
        // 전체 승률이 높은 복서의 번호가 앞쪽으로 갑니다.
        if $0.value.percentage > $1.value.percentage { return true }
        else if $0.value.percentage < $1.value.percentage { return false }
        // 승률이 동일한 복서의 번호들 중에서는 자신보다 몸무게가 무거운 복서를 이긴 횟수가 많은 복서의 번호가 앞쪽으로 갑니다.
        else if $0.value.percentage == $1.value.percentage && $0.value.upperWin != $1.value.upperWin {
            return $0.value.upperWin > $1.value.upperWin
        }
        // 자신보다 무거운 복서를 이긴 횟수까지 동일한 복서의 번호들 중에서는 자기 몸무게가 무거운 복서의 번호가 앞쪽으로 갑니다.
        else if $0.value.upperWin == $1.value.upperWin && $0.value.weight != $1.value.weight {
            return $0.value.weight > $1.value.weight
        }
        // 자기 몸무게까지 동일한 복서의 번호들 중에서는 작은 번호가 앞쪽으로 갑니다.
        else if $0.value.weight == $1.value.weight {
            return $0.key > $1.key
        } else { return false }
    }.compactMap { $0.key + 1 }
}
