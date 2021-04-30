import Foundation

func substitue(chord: String)->String {
    var encoded = chord;
    let list = [("C#","c"),("D#","d"),("F#","f"),("G#","g"),("A#","a")]
    for i in 0..<list.count {
        encoded=encoded.replacingOccurrences(of: list[i].0, with: list[i].1)
    }
    return encoded
}

func getPlayTime(begin: String, end: String)->Int {
    let dateformatter = DateFormatter()
    dateformatter.dateFormat = "HH:mm"
    let beginTime = dateformatter.date(from: begin)!
    let endTime = dateformatter.date(from: end)!
    return Int(endTime.timeIntervalSince(beginTime))/60
}

func getOriginalChord(chord: String, playtime: Int)->String {
    let chord = chord.map({String($0)})
    var originalChord: String = ""
    for i in 0..<playtime {
        originalChord += chord[i%chord.count]
    }
    return originalChord
}

func solution(_ m:String, _ musicinfos:[String]) -> String {
    var answer = "(None)"
    var playTimeOfAnswer: Int = -1
    let chordListened = substitue(chord: m)
    
    for musicinfo in musicinfos {
        let musicinfo_parsed = musicinfo.split(separator: ",").map({String($0)})
        let playTime = getPlayTime(begin: musicinfo_parsed[0], end: musicinfo_parsed[1])
        let title = musicinfo_parsed[2]
        let chord = getOriginalChord(chord: substitue(chord: musicinfo_parsed[3]), playtime: playTime)
        if chord.contains(chordListened) && playTimeOfAnswer<playTime {
            answer = title
            playTimeOfAnswer = playTime
        }
    }
    return answer
}
