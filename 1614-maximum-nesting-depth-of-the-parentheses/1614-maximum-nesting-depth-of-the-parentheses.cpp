class Solution {
public:
    int maxDepth(string s) {
        int ans=0,Max=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') ans++;
            Max=max(ans,Max);
            if(s[i]==')') ans--;
        }
        return Max;
    }
};