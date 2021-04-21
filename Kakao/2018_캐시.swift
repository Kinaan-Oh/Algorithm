// LRU를 구현하기 위해서 자료구조 큐를 선택해야 하는 문제. cacheSize가 0인 경우를 따로 처리해야 함. Time Complexity : O(cities.size()*cacheSize)

func solution(_ cacheSize:Int, _ cities:[String]) -> Int {
    if cacheSize == 0 {
        return cities.count * 5
    }

    var cache: [String] = []
    var totalExecutionTime: Int = 0

    cities.forEach { (city) in
        // cache hit
        if let index = cache.firstIndex(of: city.lowercased()) {
            totalExecutionTime += 1
            cache.append(cache.remove(at: index))
            return
        }
    
        // cache miss
        totalExecutionTime += 5
        if cache.count == cacheSize {
            cache.removeFirst()
        }
        cache.append(city.lowercased())
    }
    
    return totalExecutionTime
}
