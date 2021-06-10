// 출제의도: "해시 테이블(Dictionary)", Time Complexity: O(nlgn), Space Complexity: O(n). (n: stages.size)
// 정렬(nlgn)이 병목.

import Foundation

func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    var numOfUsers = stages.count
    var numOfUsersInStage = stages.reduce(into: [Int: Int]()) { numOfUsersInStage, stage in
        numOfUsersInStage[stage, default:0] += 1
    }

    var failRate = [Float]()
    for i in 1...N {
        guard numOfUsers>0 else {
            failRate.append(0)
            continue
        }
        
        failRate.append(Float(numOfUsersInStage[i] ?? 0)/Float(numOfUsers))
        numOfUsers -= numOfUsersInStage[i] ?? 0
    }

    return failRate.enumerated()
        .sorted(by: {$0.element==$1.element ? $0.offset<$1.offset : $0.element>$1.element})
        .map{$0.offset+1}
}
