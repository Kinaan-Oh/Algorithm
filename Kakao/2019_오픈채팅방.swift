// 출제의도: "Hash Table(Dictionary)", Time Complexity: O(L), Space Complexity: O(n). (L: record 모든 문자열 길이의 합)

import Foundation

func solution(_ record:[String]) -> [String] {
    var nickname = [String: String]()

    record.forEach {
        let seperated = $0.components(separatedBy: " ")
        if seperated.count==3 {
            nickname[seperated[1]] = seperated[2]
        }
    }

    return record.filter({!$0.contains("Change")})
        .map({ (log:String) -> String in
            let seperated = log.components(separatedBy: " ")
            var message = nickname[seperated[1]]!

            switch(seperated[0]) {
                case "Enter":
                    message += "님이 들어왔습니다."
                case "Leave":
                    message += "님이 나갔습니다."
                default:
                    break
            }
              
            return message
      })
}
