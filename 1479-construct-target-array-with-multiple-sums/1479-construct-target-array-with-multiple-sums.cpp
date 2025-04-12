class Solution {
public:

    bool isPossible(vector<int>& target) {
        
        priority_queue<int> pq;
        long long sum = 0;

        for(int i=0; i<target.size(); i++){
            pq.push(target[i]);
            sum += target[i];
        }

        while(pq.top() != 1){

            long long val = pq.top();
            pq.pop();

            long long remaining_sum = sum - val;
            if(remaining_sum <= 0 || remaining_sum >= val) return false;
            int element = val % remaining_sum;
            if(element == 0 && remaining_sum != 1) return false;
            sum = remaining_sum + element;
            pq.push(element);

        }

        return true;
    }
};