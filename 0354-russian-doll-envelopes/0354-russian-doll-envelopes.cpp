class Solution {
public:

    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int LIS(vector<int> &nums){

        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++){
            if(temp.back() < nums[i]){
                temp.push_back(nums[i]);
            }
            else{
                int index = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[index] = nums[i];
            }
        }
        return temp.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),cmp);

        vector<int> heights;
        for (auto env : envelopes) {
            heights.push_back(env[1]);  // extract only the heights
        }

        for(int i=0; i<envelopes.size(); i++){
            cout<<envelopes[i][0]<<" "<<envelopes[i][1]<<endl;
        }

        return LIS(heights);
    }
};