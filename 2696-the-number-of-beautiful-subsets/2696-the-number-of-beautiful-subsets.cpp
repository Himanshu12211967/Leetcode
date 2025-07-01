class Solution {
public:

    int solve(vector<int>& nums, int idx, int k,map<int,int> &st){

        if(idx == nums.size()) return 1;

        int way1 = 0;
        if(st[nums[idx]-k] == 0 && st[nums[idx]+k] == 0){
            st[nums[idx]]++;
            way1 = solve(nums,idx+1,k,st);
            st[nums[idx]]--;
        }
        int way2 = solve(nums,idx+1,k,st);
        return way1 + way2;

    }

    int beautifulSubsets(vector<int>& nums, int k) {
        map<int,int>st;
        return solve(nums,0,k,st)-1;
    }
};