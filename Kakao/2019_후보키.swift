// 출제의도: "Bitmask, 완전탐색"
// (1) HashSet -> 중복성 검사 (2) BitMask -> 유일성 검사
// "a&b == a" or "a|b == b" : a가 b에 포함된다.

import Foundation

func solution(_ relation:[[String]]) -> Int {
    let rowSize = relation.count
    let colSize = relation[0].count
    var candidateKeys = Set<Int>()

    for select in 1..<(1<<colSize) {
        var relationSelected = Set<String>()

        for i in 0..<rowSize {
            var tuple = ""
            for j in 0..<colSize where (select & (1<<(colSize-1-j))) != 0 {
                if j>0 {
                    tuple += " "
                }
                tuple += relation[i][j]
            }
            relationSelected.insert(tuple)
        }

        if relationSelected.count==relation.count && candidateKeys.filter({(select|$0)==select}).isEmpty {
            candidateKeys.insert(select)
        }
    }
    
    return candidateKeys.count
}
