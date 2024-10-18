class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int sLen = s.length(), pLen = p.length();

        if (sLen < pLen) return res;

        unordered_map<char, int> pCount, sCount;
        for (char c : p) {
            pCount[c]++;
        }

        for (int i = 0; i < sLen; i++) {
            sCount[s[i]]++;
            
            if (i >= pLen) {
                if (sCount[s[i - pLen]] == 1) {
                    sCount.erase(s[i - pLen]);
                } else {
                    sCount[s[i - pLen]]--;
                }
            }
            
            if (pCount == sCount) {
                res.push_back(i - pLen + 1);
            }
        }
        return res;
    }
};