import Foundation

let input = readLine()?.split(separator: " ").compactMap { String($0) }

if let convert = input?.last, let clearTime = Int64(convert) {
    var addTime = Int64((input?.first)!)
    var minusTime = Int64(input![1])
    
    print((clearTime - minusTime! - 1) / (addTime! - minusTime!) + 1)
}
