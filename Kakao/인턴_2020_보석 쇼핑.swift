// 출제의도: "Two-Pointer", Time Complexity: O(n), Space Complexity: O(n) (n: gems.size)

import Foundation

func solution(_ gems:[String]) -> [Int] {
    var ans = (0, gems.count)
    var window: (left: Int, right: Int) = (0, 0)
    let typeOfGems = Set(gems).count
    var gemsInWindow = [String: Int]()
    
    while window.right<gems.count {
        gemsInWindow[gems[window.right], default:0] += 1
        window.right += 1

        guard gemsInWindow.count == typeOfGems else { continue }

        while gemsInWindow[gems[window.left]]! > 1 {
            gemsInWindow[gems[window.left]]! -= 1
            window.left += 1
        }
        ans = window.right-window.left<ans.1-ans.0 ? window : ans
    }
    
    return [ans.0+1, ans.1]
}
