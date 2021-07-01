// 출제의도: "구현(모듈화)"
// Swift의 enum을 이용한 옵션의 구현, tuple 속성을 이용한 정렬의 간소화를 학습.

import Foundation

var beams = [[Bool]](repeating: [Bool](repeating: false, count: 101), count: 101)
var pillars = [[Bool]](repeating: [Bool](repeating: false, count: 101), count: 101)
var frames = Set<[Int]>()
var n: Int = 0

enum FrameType: Int {
    case pillar, beam
}

enum Action: Int {
    case remove, build
}

func isBeamStable(at pos: [Int]) -> Bool {
    if pos[1]-1>=0 && pillars[pos[0]][pos[1]-1] {
        return true
    }
    if pos[1]-1>=0 && pos[0]+1<=n && pillars[pos[0]+1][pos[1]-1] {
        return true
    }
    if pos[0]-1>=0 && pos[0]+1<=n && beams[pos[0]-1][pos[1]] && beams[pos[0]+1][pos[1]] {
        return true
    }
    return false
}

func isPillarStable(at pos: [Int]) -> Bool {
    if pos[1]==0  {
        return true
    }
    if beams[pos[0]][pos[1]] || (pos[0]-1>=0 && beams[pos[0]-1][pos[1]]) {
        return true
    }
    if pos[1]-1>=0 && pillars[pos[0]][pos[1]-1] {
        return true
    }
    return false
}

func isFrameStable(at pos: [Int], of frame: FrameType) -> Bool {
    switch frame {
        case .beam:
            if isBeamStable(at: pos) {
               return true
            }
        case .pillar:
            if isPillarStable(at: pos) {
                return true
            }
    }
    return false
}

func areFramesStable() -> Bool {
    for frame in frames {
        if !isFrameStable(at: frame[0...1].map{ Int($0) }, of: (frame[2]==0 ? .pillar : .beam)) {
            return false
        }
    }
    return true
}

func isFrameRemovable(at pos: [Int], of frame: FrameType) -> Bool {
    var removable = false
    switch frame {
        case .beam:
            beams[pos[0]][pos[1]].toggle()
            if areFramesStable() {
                removable = true
            }
            beams[pos[0]][pos[1]].toggle()
            
        case .pillar:
            pillars[pos[0]][pos[1]].toggle()
            if areFramesStable() {
                removable = true
            }
            pillars[pos[0]][pos[1]].toggle()
    }
    return removable
}

func buildBeam(at pos: [Int]) -> Void {
    if !isFrameStable(at: pos, of: .beam) {
        return
    }
    frames.insert(pos+[FrameType.beam.rawValue])
    beams[pos[0]][pos[1]].toggle()
}

func buildPillar(at pos: [Int]) -> Void {
    if !isFrameStable(at: pos, of: .pillar) {
        return
    }
    frames.insert(pos+[FrameType.pillar.rawValue])
    pillars[pos[0]][pos[1]].toggle()
}

func removeBeam(at pos: [Int]) -> Void {
    if isFrameRemovable(at: pos, of: .beam) {
        frames.remove(pos+[FrameType.beam.rawValue])
        beams[pos[0]][pos[1]].toggle()
    }
}

func removePillar(at pos: [Int]) -> Void {
    if isFrameRemovable(at: pos, of: .pillar) {
        frames.remove(pos+[FrameType.pillar.rawValue])
        pillars[pos[0]][pos[1]].toggle()
    }
}

func buildFrame(at pos: [Int], of frame: FrameType) {
    switch frame {
        case .beam:
            buildBeam(at: pos)
        case .pillar:
            buildPillar(at: pos)
    }
}

func removeFrame(at pos: [Int], of frame: FrameType) {
    switch frame {
        case .beam:
            removeBeam(at: pos)
        case .pillar:
            removePillar(at: pos)
    }
}

func solution(_ sz:Int, _ command:[[Int]]) -> [[Int]] {
    n = sz
    command.forEach {
        let pos = $0[0...1].map { Int($0) }
        let frame = ($0[2] == 0) ? FrameType.pillar : FrameType.beam
        let action = ($0[3] == 0) ? Action.remove : Action.build

        switch action {
            case .build:
                buildFrame(at: pos, of: frame)
            case .remove:
                removeFrame(at: pos, of: frame)
        }
    }
    
    return frames.map({($0[0],$0[1],$0[2])}).sorted(by: <).map {[$0.0,$0.1,$0.2]}
}
