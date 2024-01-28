import Foundation

enum CacheMode: Int {
    
    case hit = 1
    case miss = 5
}

// 캐시 교체 알고리즘은 LRU(Least Recently Used)를 사용한다. (LRU 알고리즘 : 가장 오랫동안 참조되지 않은 페이지를 교체하는 기법)
func solution(_ cacheSize: Int, _ cities: [String]) -> Int {
    
    var answer = Int.zero
    
    var cache: Set<String> = Set.init()
    var cacheQueue: Array<String> = Array.init()
    
    // 캐시의 크기가 존재하지 않는 경우에는 모든 경우에 저장되지 않는 것으로 간주하므로 예외 처리를 수행합니다.
    if cacheSize == Int.zero { return cities.count * CacheMode.miss.rawValue }
    
    for item in cities {
        
        // 대소문자 구분을 하지 않는다.
        let forKey = item.uppercased()
                
        // cache hit일 경우 실행시간은 1이고, cache miss일 경우 실행시간은 5이다.
        if cache.contains(forKey) == true {
            answer += CacheMode.hit.rawValue
            
            let index = cacheQueue.firstIndex { key in key == forKey } ?? Int.init()
            cacheQueue.remove(at: index)
            cacheQueue.append(forKey)
            continue
        }
        
        // 지정 된 캐시의 크기를 넘어선 경우에는 가장 오랫동안 참조하지 않은 항목을 삭제합니다.
        answer += CacheMode.miss.rawValue
        
        if cache.count == cacheSize {
            let first = cacheQueue.removeFirst()
            cache.remove(first)
        }
        
        cacheQueue.append(forKey)
        cache.insert(forKey)
    }
    
    return answer
}
