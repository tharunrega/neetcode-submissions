class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        map<char,int> mps,mpt;
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            mps[s[i]]++;
            mpt[t[i]]++;
        }
        if(mps.size()!=mpt.size()) return false;
        for(auto const& [key, val] : mps){
            if(mps[key] != mpt[key]) return false;
        }
        return true;
    }
};