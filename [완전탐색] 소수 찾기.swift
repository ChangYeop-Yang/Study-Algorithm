import Foundation

var result: Set<Int> = Set.init()
var isPrime: [Bool] = Array.init()

func isPrimeNumber(value: Int) {
    // 만일 주어진 수가 1보다 작거나 같을 경우에는 소수가 아니다.
    if value <= 1 { return }
    
    isPrime = Array(repeating: true, count: value + 1)
    isPrime[Int.zero] = false
    isPrime[1] = false
    
    var index: Int = 2
    while (index * index) <= value {
        for number in stride(from: index * index, to: value, by: +index) where isPrime[index] {
            isPrime[number] = false
        }
        index += 1
    }
}

func permutation(numbers: String, value: String, start: Int, end: Int) {

    if let intValue = Int(value), start == end && isPrime[intValue] {
        result.insert(intValue)
        return
    }

    for index in numbers.indices {
        var copyArray = numbers
        let last = copyArray.remove(at: index)

        permutation(numbers: copyArray, value: "\(value)\(last)", start: start + 1, end: end)
    }
}

/**
    - NOTE:
        - numbers는 길이 1 이상 7 이하인 문자열입니다.
        - numbers는 0~9까지 숫자만으로 이루어져 있습니다.
        - "013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
*/
func solution(_ numbers: String) -> Int {
    
    isPrimeNumber(value: 9999999)
            
    for index in Int.zero..<numbers.count {
        permutation(numbers: numbers, value: String.init(), start: Int.zero, end: index + 1)
    }
    
    // MARK: 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.
    return result.count
}
