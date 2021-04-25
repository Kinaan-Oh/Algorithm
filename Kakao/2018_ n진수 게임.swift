// swift는 진법변환을 직접 구현할 필요가 없음. 

func solution(_ n:Int, _ t:Int, _ m:Int, _ p:Int) -> String {
    var numArray: [Character] = []
    var answer: String = ""
    var num: Int = 0
    while numArray.count < m*t {
        numArray += String(num, radix: n, uppercase: true).map({$0})
        num += 1
    }
    for i in 0..<t {
        answer += String(numArray[m*i+p-1])
    }
    return answer
}
