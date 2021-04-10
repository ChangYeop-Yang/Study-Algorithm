class Solution {

func vaildIPv4(_ ipAddress: String) -> Bool {
    
    let expression = "^(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$"
    
    // MARK: - A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros
    guard let reg = try? NSRegularExpression(pattern: expression, options: [.caseInsensitive]) else { return false }
    
    let range = NSRange(location: Int.zero, length: ipAddress.count)
    guard let _ = reg.firstMatch(in: ipAddress, range: range) else { return false }
    
    return true
}
    
func vaildIPv6(_ ipAddress: String) -> Bool {
    // MARK: - A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where 1 <= xi.length <= 4, Leading zeros are allowed in xi, xi is a hexadecimal string which may contain digits, lower-case English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
    let expression = "^(([0-9]|[A-F]|[a-f]){1,4}\\:){7}([0-9]|[a-f]|[A-F]){1,4}$"
    
    // MARK: - A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros
    guard let reg = try? NSRegularExpression(pattern: expression, options: [.caseInsensitive]) else { return false }
    
    let range = NSRange(location: Int.zero, length: ipAddress.count)
    guard let _ = reg.firstMatch(in: ipAddress, range: range) else { return false }
    
    return true
}
    
func validIPAddress(_ IP: String) -> String {
        
        if vaildIPv4(IP) {
            return "IPv4"
        } else if vaildIPv6(IP) {
            return "IPv6"
        } else {
            return "Neither"
        }
}
}
