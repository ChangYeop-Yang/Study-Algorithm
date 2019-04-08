import Foundation

typealias Jop = (progress: Int, speed: Int)

let MAX_P = 100

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {

    // MARK: - 각 기능은 진도가 100%일 때 서비스에 반영할 수 있습니다.
    var completeJop = Array<Jop>()
    for index in 0..<progresses.count {
        let jop = Jop(progresses[index], speeds[index])
        completeJop.append(jop)
    }
    
    /*
        ⌘ CAPTION ⌘
        각 기능의 개발속도는 모두 다르기 때문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고, 이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.
    */
    var answer = Array<Int>()
    while !completeJop.isEmpty {
        
        var begins = Array<Int>()
        let length = completeJop.count
        
        for index in 0..<length {
            completeJop[index].progress += completeJop[index].speed
        }
        
        // MARK: - 배포는 하루에 한 번만 할 수 있으며, 하루의 끝에 이루어진다고 가정합니다.
        for index in 0..<length {
            if MAX_P <= completeJop[index].progress { begins.append(index); continue }
            break;
        }
        
        // MARK: - 각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하세요.
        if begins.isEmpty == false {
            answer.append(begins.count)
            for _ in 0..<begins.count { completeJop.removeFirst() }
        }
    }
    
    return answer
}
