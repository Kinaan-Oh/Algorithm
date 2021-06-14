// "Binary Tree, Preorder, Postorder", Time Complexity: O(n*h), Space Complexity: O(n). (h: Binary Tree의 깊이, n: nodeinfo.size)

import Foundation

class BinaryTree {
    let val: Int
    let pos: [Int]
    var leftChild: BinaryTree? = nil
    var rightChild: BinaryTree? = nil
    
    init(val: Int, pos: [Int]) {
        self.val = val
        self.pos = pos
    }
    
    func insert(node: BinaryTree) {
        if self.pos[0]<node.pos[0] {
            if let rightChild = self.rightChild {
                rightChild.insert(node: node)
            }
            else {
                self.rightChild = node
            }
        }
        else {
            if let leftChild = self.leftChild {
                leftChild.insert(node: node)
            }
            else {
                self.leftChild = node
            }
        }
    }
    
    func VLR() -> [Int] {
        return [self.val] + (self.leftChild?.VLR() ?? []) + (self.rightChild?.VLR() ?? [])
    }
    
    func LRV() -> [Int] {
        return (self.leftChild?.LRV() ?? []) + (self.rightChild?.LRV() ?? []) + [self.val]
    }
}

func solution(_ nodeinfo:[[Int]]) -> [[Int]] {
    var root: BinaryTree? = nil

    nodeinfo.enumerated()
        .map {($0.offset+1,$0.element[0],$0.element[1])}
        .sorted(by: {$0.2>$1.2})
        .forEach({
            guard let r = root else {
                root = BinaryTree(val: $0.0, pos: [$0.1,$0.2])
                return
            }
            r.insert(node: BinaryTree(val: $0.0, pos: [$0.1,$0.2]))
        })
    
    return [root?.VLR() ?? [], root?.LRV() ?? []]
}
