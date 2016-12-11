/*
In this problem, your job to write a function to check whether a input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, you need to keep in mind that leading zeros in the IPv4 is illegal. For example, the address 172.16.254.01 is illegal.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a legal one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, you need to keep in mind that extra leading zeros in the IPv6 is also illegal. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is also illegal.

Note: You could assume there is no extra space in the test cases and there may some special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
*/
class Solution {
public:
    const string validIPv6Chars = "0123456789abcdefABCDEF";
    bool isValidIPv4Block(string& block) {
    	int num = 0;
    	if (block.size() > 0 && block.size() <= 3) {
    	    for (int i = 0; i < block.size(); i++) {
    	        char c = block[i];
    	        // special case: if c is a leading zero and there are characters left
    	        if (!isalnum(c) || (i == 0 && c == '0' && block.size() > 1))
    		    return false;
    	        else {
    		    num *= 10;
    		    num += c - '0';
    	        }
    	    }
    	    return num <= 255;
    	}
    	return false;
    }
    bool isValidIPv6Block(string& block) {
    	if (block.size() > 0 && block.size() <= 4) {
    	    for (int i = 0; i < block.size(); i++) {
    	        char c = block[i];
    	        if (validIPv6Chars.find(c) == string::npos)
    	    	    return false;
    	    }
    	    return true;
    	}
    	return false;
    }
    string validIPAddress(string IP) {
    	string ans[3] = {"IPv4", "IPv6", "Neither"};
    	stringstream ss(IP);
    	string block;
    	// ipv4 candidate
    	if (IP.substr(0, 4).find('.') != string::npos) {
    	    for (int i = 0; i < 4; i++) {
    		if (!getline(ss, block, '.') || !isValidIPv4Block(block))
    	   	    return ans[2];
    	    }
    	    return ss.eof() ? ans[0] : ans[2];
    	}
    	// ipv6 candidate
    	else if (IP.substr(0, 5).find(':') != string::npos) {
    	    for (int i = 0; i < 8; i++) {
    		if (!getline(ss, block, ':') || !isValidIPv6Block(block))
    		    return ans[2];
    	    }
    	    return ss.eof() ? ans[1] : ans[2];
    	}

    	return ans[2];
    }
};
