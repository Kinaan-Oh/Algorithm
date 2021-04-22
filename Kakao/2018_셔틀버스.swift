// O(nm). String(format:"",) 이용해봄.

func solution(_ n:Int, _ t:Int, _ m:Int, _ timetable:[String]) -> String {
    let ealiestShuttleArrivalTime: Int = 540
    var shuttleArrivalTime: Int
    let crewTimeTable = timetable.map { (time) -> Int in
        return Int(time.prefix(2))!*60 + Int(time.suffix(2))!
    }.sorted()
    var nextCrewWaitingForShuttle: Int = 0
    var numOfPassengersInLatestShuttle: Int = 0

    for i in 0..<n-1 {
        shuttleArrivalTime = ealiestShuttleArrivalTime + t*i
        for _ in 0..<m {
            if nextCrewWaitingForShuttle==crewTimeTable.count || crewTimeTable[nextCrewWaitingForShuttle] > shuttleArrivalTime {
                break
            }
            nextCrewWaitingForShuttle += 1
        }
    }

    shuttleArrivalTime = ealiestShuttleArrivalTime + t*(n-1)
    for _ in 0..<m {
        if nextCrewWaitingForShuttle==crewTimeTable.count || crewTimeTable[nextCrewWaitingForShuttle] > shuttleArrivalTime {
            break
        }
        nextCrewWaitingForShuttle += 1
        numOfPassengersInLatestShuttle += 1
    }

    if numOfPassengersInLatestShuttle == m {
        return  String(format: "%02d:%02d", (crewTimeTable[nextCrewWaitingForShuttle-1]-1)/60, (crewTimeTable[nextCrewWaitingForShuttle-1]-1)%60)
    }
    return  String(format: "%02d:%02d", shuttleArrivalTime/60, shuttleArrivalTime%60)
}
