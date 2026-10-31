class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // queue<int>q;
        // int time=0;
        // for(int i=0;i<tickets.size();i++){
        //     q.push(i);
        // }
        // while(tickets[k]!=0){
        //     time++;
        //     tickets[q.front()]--;
        //     if(tickets[q.front()]==0) q.pop();
        //     else{
        //         q.push(q.front());
        //         q.pop();
        //     }
        // }

        int time=0;
        for(int i=0;i<tickets.size();i++){
            if(i<=k){
                time+=min(tickets[k],tickets[i]);
            }
            else{
                time+=min(tickets[k]-1,tickets[i]);
            }
        }
        return time;
    }
};