// O(nlgn)

import Foundation

func solution(_ lines:[String]) -> Int 
{
    var idx_req: Int = 0
    var idx_res: Int = 0
    var throuputInLastSecond: Int = 0
    var maxThroughputPerSecond: Int = 0
    var requestQueue = [Int]()
    var responseQueue = [Int]()
    parseLog(of: lines).forEach { (requestTime: Int, responseTime: Int) in
        requestQueue.append(requestTime)
        responseQueue.append(responseTime)
    }

    requestQueue.sort()
    responseQueue.sort()

    while idx_req < requestQueue.count
    {
        let Include = requestQueue[idx_req] < responseQueue[idx_res]+1000 ? true : false
        if Include
        {
            idx_req += 1
            throuputInLastSecond += 1
        }
        else
        {
            idx_res += 1
            throuputInLastSecond -= 1
        }
        maxThroughputPerSecond = max(maxThroughputPerSecond, throuputInLastSecond)
    }
    
    return maxThroughputPerSecond
}

func parseLog(of lines: [String]) -> [(requestTime: Int, responseTime: Int)]
{
    let dateFormatter = DateFormatter()
    dateFormatter.timeZone = TimeZone(abbreviation: "UTC")
    dateFormatter.dateFormat = "yyyy-MM-dd HH:mm:ss.SSS"
    
    return lines.map { (log: String) -> (requestTime: Int, responseTime: Int) in
        let responseTimeString = log[..<log.index(log.startIndex, offsetBy: 23)]
        let processingTimeString = log[log.index(log.startIndex, offsetBy: 24)..<log.index(log.endIndex, offsetBy: -1)]
        
        let reseponseTime = Int(dateFormatter.date(from: String(responseTimeString))!.timeIntervalSince1970*1000)
        let processingTime = Int(Double(processingTimeString)!*1000)
        let requestTime = reseponseTime - processingTime + 1
        return (requestTime, reseponseTime)
    }
}
