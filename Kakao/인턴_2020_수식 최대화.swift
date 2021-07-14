// "Divide and Conquer", Time Complexity: O(n), Space Complexity: O(n) (n: expression.size)

import Foundation

var precedence: [Character] = ["*", "+", "-"]

extension Array where Element == Character {
    mutating func next_permutation() -> Bool {
        var first: Index = 0, last: Index = self.count, i: Index = last-1
        
        while true {
            var i1: Index, i2: Index
            
            i1 = i
            i -= 1
            if self[i] < self[i1] {
                i2 = last
                repeat {
                    i2 -= 1
                } while !(self[i] < self[i2])
                
                self.swapAt(i, i2)
                
                let r = self[i1..<last].reversed()
                self.removeSubrange(i1..<last)
                self += r
                
                return true
            }
            
            guard i != first else { return false }
        }
    }
}

extension String {
    subscript(r: Range<Int>) -> String {
            let begin = self.index(self.startIndex, offsetBy: r.lowerBound)
            let end = self.index(self.startIndex, offsetBy: r.upperBound)
            return String(self[begin..<end])
    }
}

func calc(_ expression: String) -> Int64 {
    var result = Int64()
    var fnd = false

    for op in precedence.reversed() {
        guard !fnd else { break }

        for c in expression.enumerated().reversed() {
            guard !fnd && c.element == op else { continue }
            
            fnd.toggle()
            switch op {
                case "*":
                    result = calc(expression[0..<c.offset])*calc(expression[c.offset+1..<expression.count])
                case "+":
                    result = calc(expression[0..<c.offset])+calc(expression[c.offset+1..<expression.count])
                default:
                    result = calc(expression[0..<c.offset])-calc(expression[c.offset+1..<expression.count])
            }
        }
    }

    guard fnd else { return Int64(expression) ?? -1 }
    return result
}

func solution(_ expression:String) -> Int64 {
    var answer = Int64.min
    repeat {
        answer = max(answer, abs(calc(expression)))
    } while precedence.next_permutation()
    return answer
}
