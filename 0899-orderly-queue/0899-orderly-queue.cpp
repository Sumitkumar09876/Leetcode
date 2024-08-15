class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.length();
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string result = s;
        for (int i = 1; i < n; i++) {
            string t = s.substr(i) + s.substr(0, i);
            if (t < result) {
                result = t;
            }
        }
        return result;
    }
};
