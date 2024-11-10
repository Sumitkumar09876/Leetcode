class Solution {
public:
    bool isNumber(string s) {
        unsigned char state = 0;  // Using bits to store flags
        const int n = s.length();
        int i = 0;
        
        // Skip leading sign if present
        if(i < n && (s[i] == '+' || s[i] == '-')) i++;
        
        // Process digits before dot/exponent
        while(i < n && isdigit(s[i])) {
            state |= 1;  // Set digit flag
            i++;
        }
        
        // Process decimal point and following digits
        if(i < n && s[i] == '.') {
            i++;
            while(i < n && isdigit(s[i])) {
                state |= 1;  // Set digit flag
                i++;
            }
        }
        
        // Must have at least one digit before exponent
        if(!(state & 1)) return false;
        
        // Process exponent if present
        if(i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            if(i < n && (s[i] == '+' || s[i] == '-')) i++;
            
            // Must have at least one digit after exponent
            if(i == n) return false;
            while(i < n && isdigit(s[i])) i++;
        }
        
        return i == n;
    }
};