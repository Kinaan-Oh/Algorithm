// Time Complexity: O((msg.length)^2). swift는 UnicodeScalar를 통해 아스키코드로 문자열/문자를 생성 가능.

func solution(_ msg:String) -> [Int] {
    var answer: [Int] = []
    var start: Int = 0
    var dic: [String:Int] = [:]
    var nextKey: Int = 27
    var key: [String] = (65...90).map({String(UnicodeScalar($0))})
    for i in 0..<key.count {
        dic[key[i]] = i+1
    }
    
    while start<msg.count {
        var end = msg.count
        while end<=msg.count {
            if dic[String(msg[msg.index(msg.startIndex, offsetBy: start)..<msg.index(msg.startIndex, offsetBy: end)])] != nil {
                answer.append(dic[String(msg[msg.index(msg.startIndex, offsetBy: start)..<msg.index(msg.startIndex, offsetBy: end)])]!)
                break
            }
            end -= 1
        }
        if end==msg.count {
            break
        }
        dic[String(msg[msg.index(msg.startIndex, offsetBy: start)...msg.index(msg.startIndex, offsetBy: end)])] = nextKey
        nextKey += 1
        start = end
    }
    
    return answer
}
