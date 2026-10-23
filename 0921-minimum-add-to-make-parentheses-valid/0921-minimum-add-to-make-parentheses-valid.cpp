class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>x;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') x.push(s[i]);
            else{
                if(x.empty()) cnt++;
                else x.pop();
            }
        }
        cnt+=x.size();
        return cnt;
    }
};