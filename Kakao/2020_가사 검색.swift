// 출제의도: "Trie", Time Complexity: O(L+M), Space Complexity: O(L) (L: 모든 word 길이의 합, M: 모든 query 길이의 합)
// 처음엔 Trie의 배열을 Array(repeating: Trie(), count: 100001) 으로 만들었지만, 이와 같은 배열의 생성은 1개의 Trie을 공유하는 형태로 생성이 됨.(100001개의 Trie가 아닌 1개의 Trie를 공유)
// Array(repeating: ,count: )의 내부 동작 원리를 몰랐기 때문에 많은 시간을 낭비. (0...100001).map { _ in Trie() } 으로 문제 해결.(100001개의 트라이 배열 생성)

import Foundation

extension String {
    func prefix() -> [String] {
        return self.map({String($0)}).filter { ("a"..."z").contains($0) }
    }
}

class Trie {
    var children: [String: Trie]
    var numOfTail: Int
    
    init() {
        self.children = [:]
        self.numOfTail = 0
    }
    
    func insert(_ word: [String], _ index: Int) -> Void {
        self.numOfTail += 1
        if index == word.count {
            return
        }
        self.children[word[index]] = self.children[word[index]] ?? Trie()
        self.children[word[index]]!.insert(word, index+1)
    }
    
    func find(_ word: [String], _ index: Int) -> Int {
        if index == word.count {
            return self.numOfTail
        }
        guard let child = self.children[word[index]] else { return 0 }
        return self.children[word[index]]!.find(word, index+1)
    }
}

func solution(_ words:[String], _ queries:[String]) -> [Int] {
    var answer = [Int]()
    var prefixOfWord = (0...100001).map { _ in Trie() }
    var prefixOfReversedWord = (0...100001).map { _ in Trie() }
    
    for word in words {
        prefixOfWord[word.count].insert(word.prefix(), 0)
        prefixOfReversedWord[word.count].insert(String(word.reversed()).prefix(), 0)
    }
    
    for query in queries {
        if query.first == "?" {
            let reversed = String(query.reversed())
            answer.append(prefixOfReversedWord[query.count].find(reversed.prefix(), 0))
        }
        else {
            answer.append(prefixOfWord[query.count].find(query.prefix(), 0))
        }
    }
    
    return answer
}
