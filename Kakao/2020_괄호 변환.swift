// 출제의도: "구현, 재귀, 스택"
// 올바른 괄호임을 판단하기 위해 스택 자료구조 이용.(swift에선 Array로 대체)

import Foundation

extension String {
    subscript(i: Int) -> String {
        return String(self[self.index(self.startIndex, offsetBy: i)])
    }
    
    subscript(r: Range<Int>) -> String {
        let begin = self.index(self.startIndex, offsetBy: r.lowerBound)
        let end = self.index(self.startIndex, offsetBy: r.upperBound)
        return String(self[begin..<end])
    }
}

func solution(_ p:String) -> String {
    if p.count == 0 {
        return ""
    }
    
    var u = "", v = ""
    var cnt = 0
    var stack = [Character]()
    var isCorrect = true
    
    for i in 0..<p.count {
        cnt = p[i] == "(" ? cnt+1 : cnt-1
        if cnt == 0 {
            u = p[0..<i+1]
            v = p[i+1..<p.count]
            break
        }
    }
    
    for p in u {
        if p == "(" {
            stack.append(p)
            continue
        }

        if stack.isEmpty {
            isCorrect = false
            break
        }
        stack.removeLast()
    }
    
    if isCorrect {
        return u + solution(v)
    }
    else {
        u.removeFirst()
        u.removeLast()
        u = u.map({$0=="(" ? ")" : "("}).joined()
        return "(" + solution(v) + ")" + u
    }
}
