class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int i = 0;
        bool hasNum = false;
        bool hasDot = false;
        bool hasE = false;
        
        // Skip leading whitespace (if any)
        while(i < n && s[i] == ' ') i++;
        
        // Check first character for sign
        if(i < n && (s[i] == '+' || s[i] == '-')) i++;
        
        // Process digits before E/e and possible decimal point
        while(i < n) {
            if(isdigit(s[i])) {
                hasNum = true;
                i++;
            }
            else if(s[i] == '.') {
                if(hasDot || hasE) return false;
                hasDot = true;
                i++;
            }
            else if(s[i] == 'e' || s[i] == 'E') {
                if(hasE || !hasNum) return false;
                hasE = true;
                hasNum = false; // Reset hasNum for checking digits after E
                i++;
                // Handle sign after E
                if(i < n && (s[i] == '+' || s[i] == '-')) i++;
            }
            else break;
        }
        
        // Skip trailing whitespace (if any)
        while(i < n && s[i] == ' ') i++;
        
        // Valid if we've seen at least one number and reached end of string
        return hasNum && i == n;
    }
};