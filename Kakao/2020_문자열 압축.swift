// 출제의도: "문자열", Time Complexity: O(n), Space Complexity: O(n) (n: s.length)
// c++에서 제공하는 string.substr(a,b)를 제공하지 않음.(정수 범위) 편의를 위해 String 클래스를 확장(extension)함.

import Foundation

extension String {
    subscript(r: Range<Int>) -> String {
        let begin = self.index(self.startIndex, offsetBy: r.lowerBound)
        let end = self.index(self.startIndex, offsetBy: r.upperBound, limitedBy: self.endIndex)
        return String(self[begin..<(end ?? self.endIndex)])
    }
}

func solution(_ s:String) -> Int {
    var answer: Int = Int.max
    
    for i in 1...s.count {
        var components = [String]()
        var begin = 0

        while begin<s.count {
            components += [s[begin..<begin+i]]
            begin += i
        }

        var ht = [String: Int]()
        var compression = ""
        var last = components[0]

        for component in components {
            if component == last {
                ht[component, default: 0] += 1
                continue
            }

            compression += (ht[last, default: 0]>1 ? String(ht[last, default: 0])+last : last)
            ht[last] = 0
            ht[component, default: 0] += 1
            last = component
        }
        compression += (ht[last, default: 0]>1 ? String(ht[last, default: 0])+last : last)
        answer = min(answer, compression.count)
    }
    
    return answer
}
