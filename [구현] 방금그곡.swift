 import Foundation

fileprivate struct MelodyInfo {

    let index: Int
    let playTime: Int
    
    let melody: String
    let musicName: String
    
    var melodyTime: String
    
    init(target: String, index: Int) {
        
        let split = target.split(separator: ",").compactMap { String($0) }
        
        self.index = index
        self.playTime = MelodyInfo.calculatePlayTime(start: split[0], end: split[1])
        self.musicName = split[2]
        self.melody = replacingOccurrences(target: split[3])
        
        self.melodyTime = MelodyInfo.playMelody(time: self.playTime, length: self.melody.count, melody: self.melody)
    }
    
    static func playMelody(time: Int, length: Int, melody: String) -> String {
        
        var answer = String.init()
        var index = Int.zero
        for _ in (Int.zero..<time) {
            
            let indexString = String.Index(utf16Offset: index, in: melody)

            answer.append(melody[indexString])
            
            index = (index + 1) % length
        }
        
        return answer
    }
    
    static func calculatePlayTime(start: String, end: String) -> Int {
        
        let startTime = start.split(separator: ":").compactMap { Int($0) }
        let endTime = end.split(separator: ":").compactMap { Int($0) }
        
        return ((endTime.first! - startTime.first!) * 60) + (endTime.last! - startTime.last!)
    }
}

func replacingOccurrences(target: String) -> String {
    
    let dict: [String: String] = ["C#": "c", "D#": "d", "F#": "f", "G#": "g", "A#": "a"]
    
    var result = target
    for (key, value) in dict {
        result = result.replacingOccurrences(of: key, with: value)
    }
    
    return result
}

/**
    - 네오가 기억한 멜로디와 악보에 사용되는 음은 C, C#, D, D#, E, F, F#, G, G#, A, A#, B 12개이다.
    - 각 음은 1분에 1개씩 재생된다. 음악은 반드시 처음부터 재생되며 음악 길이보다 재생된 시간이 길 때는 음악이 끊김 없이 처음부터 반복해서 재생된다. 음악 길이보다 재생된 시간이 짧을 때는 처음부터 재생 시간만큼만 재생된다.
    - 음악이 00:00를 넘겨서까지 재생되는 일은 없다.
    - 조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다. 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다.
    - 조건이 일치하는 음악이 없을 때에는 “(None)”을 반환한다.
*/
func solution(_ m: String, _ musicinfos: [String]) -> String {
    
    var answer: [MelodyInfo] = Array.init()
    
    let melody = replacingOccurrences(target: m)
    
    for index in musicinfos.indices {
        let info = MelodyInfo(target: musicinfos[index], index: index)
        
        if info.melodyTime.contains(melody) {
            answer.append(info)
        }
    }
    
    // 조건이 일치하는 음악이 없는 경우
    let none = "(None)"
    if answer.count == Int.zero { return none }
    
    return answer.sorted { $0.playTime > $1.playTime && $0.index > $1.index }.first?.musicName ?? none
}

let result = solution("CC#BCC#BCC#BCC#B", ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"])
print(result)
