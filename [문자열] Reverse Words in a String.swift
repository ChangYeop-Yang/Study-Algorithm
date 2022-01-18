import Foundation

class Solution {
    
    // REMARK: that s may contain leading or trailing spaces or multiple spaces between two words.
    func reverseWords(_ s: String) -> String {
        
        let split = s.split(separator: " ").reversed()
        return split.joined(separator: " ")
    }
}
