class Solution {
public:

    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        int timer = 0;
        queue<pair<int,int>> q;

        for(int i=0; i<tickets.size(); i++){
            q.push({tickets[i],i});
        }

        while(!q.empty()){

            int ticket = q.front().first;
            int index = q.front().second;
            q.pop();
            timer++;

            if(ticket > 1) q.push({ticket-1,index});
            if(index == k && ticket == 1) return timer;


        }
        

        return timer;

    }
};