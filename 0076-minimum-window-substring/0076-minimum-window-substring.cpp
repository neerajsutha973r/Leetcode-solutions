class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(256,0);
        vector<int> window(256,0);
        int ml=INT_MAX;
        for(char c:t) need[c]++;
        int count=0;
        int l=0;
        int n=s.size();
        int start;
        for(int r=0;r<n;r++){
            window[s[r]]++;
            if(window[s[r]]<=need[s[r]]) count++;
            while(count==t.size()){
                if(r-l+1<ml){
                    ml=r-l+1;
                    start=l;
                }
                window[s[l]]--;
                if(window[s[l]]<need[s[l]]) count--;
                l++;
            }
        }
        if(ml==INT_MAX) return "";
        return s.substr(start,ml);
    }
};