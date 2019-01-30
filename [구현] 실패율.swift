import Foundation

func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    
    var value: [Int: Int] = [:]
    for stage in stages {
        if !value.isEmpty && value.keys.contains(stage) { value[stage]! += 1; continue }
        value[stage] = 1
    }
    
    var result: [(stage: Int, value: Double)] = []
    
    var success: Int = stages.count
    
    for stage in 1...N {
        if !value.keys.contains(stage) { result.append((stage, 0)); continue }
        result.append((stage, Double(value[stage]!) / Double(success)))
        
        success -= value[stage]!
    }
    
    result.sort { return $0.value == $1.value ? $0.stage < $1.stage : $0.value > $1.value }
    return result.compactMap { $0.stage }
    
}
