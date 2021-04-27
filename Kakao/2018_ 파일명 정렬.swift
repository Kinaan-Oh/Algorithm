// enumerated()를 이용한 stable sort 구현.

import Foundation

extension String {
    var head: String {
        return self.prefix { $0.isNumber == false }.uppercased()
    }
    var number: Int {
        return Int( self.drop   { $0.isNumber == false }
                        .prefix { $0.isNumber })!
    }
}

func solution(_ files:[String]) -> [String] {

    return files.enumerated().sorted { (lhs, rhs) in
        let l = lhs.element
        let r = rhs.element
        if l.head == r.head {
            if l.number == r.number {
                return lhs.offset < rhs.offset
            }
            return l.number < r.number
        }
        return l.head < r.head
    }.map{ $0.element }
}
