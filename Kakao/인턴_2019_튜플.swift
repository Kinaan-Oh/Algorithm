// "정규 표현식 or 문자열 처리", Time Complexity: O(n), Space Complexity: O(n) (n: s.length)
// String의 split 이나 components를 이용하여 간단하게 구현 가능하나, 정규 표현식 학습을 목표로 구현.

// [7/17 리뷰] : swift는 # # 을 제공. \를 중복해서 적어줘야되는 불편함을 해소할 수 있음.
//     case set = "\\{.*?\\}"
//     case elem = "\\d+"
// 을 
//     case set = #"\{.*?\}"#
//     case elem = #"\d+"#
// 로 변경.



import Foundation

extension String {
    func matches(pattern: String, option: NSRegularExpression.Options) -> [String] {
        do {
            let regex = try NSRegularExpression(pattern: pattern, options: option)
            let range = NSRange(self.startIndex..<self.endIndex, in: self)
            
            return regex.matches(in: self, options: [], range: range)
                .map { String(self[Range($0.range, in: self)!]) }
        } catch let error {
            print("regular expression pattern is invalid")
            return []
        }
    }
}

enum RegExType: String {
    case set = #"\{.*?\}"#
    case elem = #"\d+"#
}

func solution(_ param0:String) -> [Int] {
    var answer = [Int]()
    var s = param0
    s.removeFirst()
    s.removeLast()
    
    s.matches(pattern: RegExType.set.rawValue, option: .caseInsensitive)
     .map({ $0.matches(pattern: RegExType.elem.rawValue, option: .caseInsensitive) })
     .sorted { $0.count < $1.count }
     .reduce(into: Set<String>()) { ans, set in
         let newElem = set.reduce(into: String()) { newElem, elem in
             if ans.contains(elem) {
                 return
             }
             newElem = elem
         }
         ans.insert(newElem)
         answer.append(Int(newElem)!)
    }
    
    return answer
}
