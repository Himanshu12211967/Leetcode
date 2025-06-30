class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int allxor = 0;

        for(auto num : nums){
            allxor ^= num;
        }

        unsigned int diffbit = static_cast<unsigned int>(allxor) & (~static_cast<unsigned int>(allxor) + 1);


        int a=0,b=0;

        for(auto num : nums){
            if(num & diffbit){
                a ^= num;
            }
            else b ^= num;
        }

        return {a,b};

    }
};