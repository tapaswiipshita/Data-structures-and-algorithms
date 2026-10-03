class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int>cnt1(52,0);
        vector<int>cnt2(52,0);
        for(int i=0;i<jewels.size();i++){
            if((int)jewels[i]>96){
                cnt1[jewels[i]-'a']++;
            }
            else{
                cnt1[jewels[i]-'A'+26]++;
            }
        }
        for(int i=0;i<stones.size();i++){
            if((int)stones[i]>96){
                cnt2[stones[i]-'a']++;
            }
            else{
                cnt2[stones[i]-'A'+26]++;
            }
        }
        int ans=0;
        for(int i=0;i<jewels.size();i++){
            if((int)jewels[i]>96){
                int a=jewels[i]-'a';
                ans+=cnt2[a];
            }
            else{
                int a=jewels[i]-'A'+26;
                ans+=cnt2[a];
            }
        }
        return ans;
    }
};