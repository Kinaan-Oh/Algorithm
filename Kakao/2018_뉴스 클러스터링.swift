// multiset의 union, intersect 개념.

func solution(_ st1:String, _ st2:String) -> Int {
    let str1 = st1.lowercased()
    let str2 = st2.lowercased()

    var arrOfStr1: [String] = []
    var arrOfStr2: [String] = []

    for i in 0..<str1.count-1 {
        arrOfStr1.append(String(str1[str1.index(str1.startIndex, offsetBy: i)..<str1.index(str1.startIndex, offsetBy: i+2)]))
    }
    for i in 0..<str2.count-1 {
        arrOfStr2.append(String(str2[str2.index(str2.startIndex, offsetBy: i)..<str2.index(str2.startIndex, offsetBy: i+2)]))
    }

    arrOfStr1 = arrOfStr1.filter({$0[$0.startIndex]>="a" && $0[$0.startIndex]<="z" && $0[$0.index($0.endIndex, offsetBy: -1)]>="a" && $0[$0.index($0.endIndex, offsetBy: -1)]<="z"})
    arrOfStr2 = arrOfStr2.filter{$0[$0.startIndex]>="a" && $0[$0.startIndex]<="z" && $0[$0.index($0.endIndex, offsetBy: -1)]>="a" && $0[$0.index($0.endIndex, offsetBy: -1)]<="z"}

    var mapOfStr1: [String:Int] = [:]
    var mapOfStr2: [String:Int] = [:]

    for elem in arrOfStr1 {
        mapOfStr1[elem] = (mapOfStr1[elem] ?? 0) + 1
    }
    for elem in arrOfStr2 {
        mapOfStr2[elem] = (mapOfStr2[elem] ?? 0) + 1
    }

    let setOfStr1 = Set(arrOfStr1)
    let setOfStr2 = Set(arrOfStr2)

    let intersection = setOfStr1.intersection(setOfStr2)
    var numOfIntersection: Int = 0
    for elem in intersection {
        numOfIntersection += min(mapOfStr1[elem]!,mapOfStr2[elem]!)
    }

    let union = setOfStr1.union(setOfStr2)
    var numOfUnion: Int = 0
    for elem in union {
        numOfUnion += max(mapOfStr1[elem] ?? 0,mapOfStr2[elem] ?? 0)
    }

    let jaccardSimilarity: Double = numOfUnion==0 ? 1 : Double(numOfIntersection)/Double(numOfUnion)
    return Int(jaccardSimilarity*65536)
}
