// 출제의도: "문자열처리 or 정규표현식", Time Complexity: 정규식 엔진 성능에 좌우됨, Space Complexity: O(n). (n: pages.size)
// 실질적인 출제의도는 html에 대한 이해, 정규 표현식 이라 판단됨. html에 대한 이해가 없으면 문제 이해가 오래 걸려서 시간 내에 풀 수 없음. url, 문자열 검색은 전형적인 정규표현식 이용 사례임.
// 정규 표현식에 대한 개념을 "손에 잡히는 10분 정규표현식"으로 정리. swift 언어는 C++보다 정규표현식 처리에 유리하다 판단함.
// 이 문제로 든 생각은, 카카오는 애초에 웹 개발자를 타깃을 두고 이들에게 유리한 문제를 출제를 한 것은 아닌가 함.
// 어쨌든, 이 문제를 통해 정규 표현식을 이용한 url, 문자열 검색을 경험해보았음.

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
    case word = "[A-Z]+"
    case url = #"(?<=<meta property="og:url" content="https://)([^"]*)"#
    case link = #"(?<=<a href="https://)([^"]*)"#
}

func solution(_ word:String, _ pages:[String]) -> Int {
    var basicScore = [String: Double]()
    var linkScore = [String: Double]()
    
    pages.forEach {
        let url = $0.matches(pattern: RegExType.url.rawValue, option: .dotMatchesLineSeparators)
        let links = $0.matches(pattern: RegExType.link.rawValue, option: .dotMatchesLineSeparators)
        let score = $0.matches(pattern: RegExType.word.rawValue, option: .caseInsensitive)
            .filter({$0.lowercased() == word.lowercased()})
            .count

        basicScore[url[0]] = Double(score)
        links.forEach {
            linkScore[$0] = (linkScore[$0] ?? 0) + Double(score)/Double(links.count)
        }
    }
    
    var maximumMatchingScore: Double = -1
    return pages.enumerated().reduce(into: Int()) { ans, page in
        let url = page.element.matches(pattern: RegExType.url.rawValue, option: .dotMatchesLineSeparators)
        let matchingScore = (basicScore[url[0]] ?? 0)+(linkScore[url[0]] ?? 0)

        if matchingScore > maximumMatchingScore {
            maximumMatchingScore = matchingScore
            ans = page.offset
        }
    }
}
