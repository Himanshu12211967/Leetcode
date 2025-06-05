class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int start = 0;
        int balance = 0;

        for(int i=0; i<gas.size(); i++){
            balance += gas[i];
            if(balance >= cost[i]){
                balance -= cost[i];
            }
            else{
                start = i+1;
                balance = 0;
            }
        }

        int need = 0;
        for(int i=0; i<start; i++){
            balance += gas[i];
            need += cost[i];
        }

        if(need > balance) return -1;
        return start;

    }
};