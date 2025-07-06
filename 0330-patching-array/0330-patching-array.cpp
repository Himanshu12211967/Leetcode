class Solution {
public:

    int minPatches(vector<int>& nums, int n) {
        
        long long int next = 1;
        int patch = 0,i = 0;

        while(next <= n){

            if(i < nums.size() && next >= nums[i]){
                next += nums[i];
                i++;
            }
            else{
                patch++;
                next += next;
            }
        }

        return patch;
    }
};