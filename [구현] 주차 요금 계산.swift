import Foundation

public struct CostTime {
    public let basicTime: Int
    public let basicCost: Int
    public let unitTime: Int
    public let unitCost: Int
}

public struct CarInfo {
    public var inputTime: DateComponents
    public var outputTime: DateComponents = DateComponents(hour: 23, minute: 59)
}

func createDateComponents(time: String) -> DateComponents {
   
    let split = time.split(separator: ":").compactMap { String($0) }
    
    return DateComponents(hour: Int(split[Int.zero]), minute: Int(split[1]))
}

func calculateDate(first: DateComponents, second: DateComponents) -> Int {
    
    let outHour = second.hour ?? Int.zero, inHour = first.hour ?? Int.zero
    let outMinute = second.minute ?? Int.zero, inMinute = first.minute ?? Int.zero
    
    return ((outHour * 60) + outMinute) - ((inHour * 60) + inMinute)
}

/**
    - NOTE:
        - 어떤 차량이 입차된 후에 출차된 내역이 없다면, 23:59에 출차된 것으로 간주합니다.
            - 0000번 차량은 18:59에 입차된 이후, 출차된 내역이 없습니다. 따라서, 23:59에 출차된 것으로 간주합니다.
        - 00:00부터 23:59까지의 입/출차 내역을 바탕으로 차량별 누적 주차 시간을 계산하여 요금을 일괄로 정산합니다.
        - 누적 주차 시간이 기본 시간이하라면, 기본 요금을 청구합니다.
        - 누적 주차 시간이 기본 시간을 초과하면, 기본 요금에 더해서, 초과한 시간에 대해서 단위 시간 마다 단위 요금을 청구합니다.
            - 초과한 시간이 단위 시간으로 나누어 떨어지지 않으면, 올림합니다.
            - ⌈a⌉ : a보다 작지 않은 최소의 정수를 의미합니다. 즉, 올림을 의미합니다.
*/
func solution(_ fees: [Int], _ records: [String]) -> [Int] {

    var tower: [String: Array<CarInfo>] = [:]
    let time = CostTime(basicTime: fees[Int.zero], basicCost: fees[1], unitTime: fees[2], unitCost: fees[3])
    
    for index in records.indices {
        let split = records[index].split(separator: " ").compactMap { String($0) }
        
        let carNumber = split[1]
        let carState = split[2]
        let dateComponents = createDateComponents(time: split[Int.zero])
        
        if !tower.keys.contains(carNumber) { tower[carNumber] = .init() }
        
        if carState == "IN" {
            let info = CarInfo(inputTime: dateComponents)
            tower[carNumber]?.append(info)
        } else if carState == "OUT" {
            var last = tower[carNumber]?.removeLast()
            last?.outputTime = dateComponents
            tower[carNumber]?.append(last!)
        }
    }
    
    var answer: [(String, Int)] = .init()
    
    for (key, value) in tower {
        var totalTime = Int.zero
        value.forEach { totalTime += calculateDate(first: $0.inputTime, second: $0.outputTime) }
        
        // 누적 주차 시간이 기본 시간이하라면, 기본 요금을 청구합니다.
        if totalTime <= time.basicTime {
            let result: (String, Int) = (key, time.basicCost)
            answer.append(result)
        }
        // 누적 주차 시간이 기본 시간을 초과하면, 기본 요금에 더해서, 초과한 시간에 대해서 단위 시간 마다 단위 요금을 청구합니다.
        else if totalTime > time.basicTime {
            let unitCost = Double(totalTime - time.basicTime) / Double(time.unitTime)
            let resultCost = time.basicCost + Int(unitCost.rounded(.awayFromZero)) * time.unitCost
            
            let result: (String, Int) = (key, resultCost)
            answer.append(result)
        }
    }
    
    // 차량 번호가 작은 자동차부터 청구할 주차 요금을 차례대로 정수 배열에 담아서 반환합니다.
    return answer.sorted { $0.0 < $1.0 }.compactMap { $0.1 }
}
