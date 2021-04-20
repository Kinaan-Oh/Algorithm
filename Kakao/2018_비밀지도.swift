// bitwise 유형. O(n^2)

func solution(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] 
{
    var map: [String] = []
    for i in 0..<n
    {
        let dataInRow: Int = arr1[i] | arr2[i]
        var mapInRow: String = ""
        for j in 0..<n
        {
            if dataInRow & (1<<j) != 0
            {
                mapInRow = "#" + mapInRow
            }
            else
            {
                mapInRow = " " + mapInRow
            }
        }
        map.append(mapInRow)
    }
    return map
}
