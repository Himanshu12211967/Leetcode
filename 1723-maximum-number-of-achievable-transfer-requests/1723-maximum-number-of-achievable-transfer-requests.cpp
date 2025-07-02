class Solution {
public:

    int solve(int idx, int count, int n, vector<vector<int>>& requests, vector<int> migrate){

        if(idx == requests.size()){
            for(int i=0; i<n; i++){
                if(migrate[i] != 0) return 0;
            }
            return count;
        }

        // taken request
        int a = requests[idx][0];
        int b = requests[idx][1];
        migrate[a]--;
        migrate[b]++;
        int opt1 = solve(idx+1,count+1,n,requests,migrate);
        migrate[a]++;
        migrate[b]--;
        int opt2 = solve(idx+1,count,n,requests,migrate);
        return max(opt1,opt2);

    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> migrate(n,0);
        return solve(0,0,n,requests,migrate);
    }
};