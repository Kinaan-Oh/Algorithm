// 출제의도: "구현", Time Complexity: O(n), Space Complexity: O(n). (n: numbers.size)

import Foundation

struct Point {
    var x: Int
    var y: Int
    
    init(_ x: Int,_ y: Int) {
        self.x = x
        self.y = y
    }
    
    func manhattanDistance(_ target: Point) -> Int {
        return abs(self.x - target.x) + abs(self.y - target.y)
    }
}

var button = [1: Point(0,0), 2: Point(1,0), 3: Point(2,0),
              4: Point(0,1), 5: Point(1,1), 6: Point(2,1),
              7: Point(0,2), 8: Point(1,2), 9: Point(2,2),
                             0: Point(1,3)]

func solution(_ numbers:[Int], _ param1:String) -> String {
    var hand = param1 == "left" ? "L" : "R"
    var leftThumb = Point(0,3)
    var rightThumb = Point(2,3)
    var ans = ""
    
    for number in numbers {
    switch number {
            case 1, 4, 7:
                leftThumb = button[number]!
                ans += "L"

            case 3, 6, 9:
                rightThumb = button[number]!
                ans += "R"

            default:
                let leftThumbDist = leftThumb.manhattanDistance(button[number]!)
                let rightThumbDist = rightThumb.manhattanDistance(button[number]!)

                ans += leftThumbDist<rightThumbDist ? "L" : (leftThumbDist>rightThumbDist ? "R" : hand)
                leftThumb = ans.last! == "L" ? button[number]! : leftThumb
                rightThumb = ans.last! == "R" ? button[number]! : rightThumb
        }
    }
    
    return ans
}
