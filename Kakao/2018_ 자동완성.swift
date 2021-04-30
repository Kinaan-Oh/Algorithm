// Trie 자료구조. 포인터 배열을 Dictionary 자료구조로 구현. Time Complexity: O(L)

class Trie {
    var children: [String:Trie]
    var numOfTail: Int
    
    init() {
        self.children = [:]
        self.numOfTail = 0
    }
    
    func insert(_ word: [String],_ index: Int) {
        self.numOfTail += 1
        if index == word.count {
            return
        }
        if self.children[word[index]] == nil {
            self.children[word[index]] = Trie()
        }
        return self.children[word[index]]!.insert(word, index+1)
    }
    
    func find(_ word: [String],_ index: Int) -> Int {
        if self.numOfTail == 1 || index == word.count {
            return index
        }
        return self.children[word[index]]!.find(word, index+1)
    }
}

func solution(_ words:[String]) -> Int {
    var answer: Int = 0
    var trie = Trie()
    for word in words {
        trie.insert(word.map({String($0)}), 0)
    }
    for word in words {
        answer += trie.find(word.map({String($0)}), 0)
    }
    return answer
}
