import Foundation

func findTarget(array: [Int], left: Int, right: Int, index: Int) -> Int {
    
    var copyArray = Array(array[left...right])
    copyArray.sort()
    
    return copyArray[index - 1]
}

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    
    var answer = Array<Int>()
    
    for value in commands {
        let command: (left: Int, right: Int, index: Int) = (value[0] - 1, value[1] - 1, value[2])
        let target = findTarget(array: array, left: command.left, right: command.right, index: command.index)
        
        answer.append(target)
    }
    
    return answer
}
