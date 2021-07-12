// 출제의도: "DFS, Bitmask"
// 작은 입력으로 효율성은 무시하고 구현하는 것이 출제 의도. 
// swift는 c++과는 다르게 순열 라이브러리(next_permutation)을 제공하지 않음. 따라서, dfs로 순열을 구현.
// dfs로 순열 구현시 bitmask를 통해 지금까지 선택한 user_id의 인덱스를 기록.(굳이 배열을 따로 만들 필요없음)

import Foundation

var ans = Set<Int>()
var user_id = [String]()
var banned_id = [String]()

func match(_ selected_id: String, _ banned_id: String) -> Bool {
    guard selected_id.count == banned_id.count else { return false }
    
    for (s, b) in zip(selected_id, banned_id) {
        guard b == "*" || s == b else { return false }
    }
    return true
}

func match(_ selected_id: [String], _ banned_id: [String]) -> Bool {
    for (s, b) in zip(selected_id, banned_id) {
        guard match(s, b) else { return false }
    }
    return true
}

func dfs(_ count: Int, _ visited: Int, _ selected_id: [String]) -> Void {
    guard count<banned_id.count else {
        ans = match(selected_id, banned_id) ? ans.union([visited]) : ans
        return
    }
    
    for i in 0..<user_id.count {
        guard visited&(1<<i) == 0 else { continue }
        
        dfs(count+1, visited|(1<<i), selected_id+[user_id[i]])
    }
}

func solution(_ param0:[String], _ param1:[String]) -> Int {
    user_id = param0
    banned_id = param1
    dfs(0, 0, [])
    return ans.count
}
