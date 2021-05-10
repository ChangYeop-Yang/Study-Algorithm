import Foundation

typealias PlayElement = (count: Int, number: Int)
typealias PlayList = [String: PlayAttribute]

struct PlayAttribute {
    var elements: [PlayElement]
    var frequency: Int = Int.zero
    
    init(count: Int, number: Int) {
        self.elements = [PlayElement(count, number)]
    }
}

/**
    노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

    1. 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
    2. 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
    3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
*/
func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    
    // MARK: - genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
    var result: [Int] = []
    var playlist: PlayList = [:]
    
    let count: Int = genres.count
    for index in Int.zero..<count {
        let key: String = genres[index]
        let value: Int = plays[index]
        
        if playlist[key] == nil {
            playlist.updateValue(PlayAttribute(count: value, number: index), forKey: key)
        } else {
            let temp = PlayElement(value, index)
            playlist[key]?.elements.append(temp)
        }
        
        playlist[key]?.frequency += value
    }
    
    for key in playlist.keys {
        playlist[key]?.elements.sort {
            if $0.count > $1.count { return true }
            else if $0.count == $1.count && $0.number < $1.number { return true }
            return false
        }
    }
    
    var list = playlist.values.sorted { $0.frequency > $1.frequency }
    for index in list.indices {
        list[index].elements.sort {
            if $0.count > $1.count { return true }
            else if $0.count == $1.count && $0.number < $1.number { return true }
            return false
        }
    }
    
    // MARK: - 장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
    for item in list {
        if item.elements.count > 1 { result += [item.elements[0].number, item.elements[1].number] }
        else { result += [item.elements[0].number] }
    }
    
    // MARK: - 노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return.
    return result
}
