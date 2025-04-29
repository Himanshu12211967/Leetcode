class Solution {
public:

    long long int just_near_on_left(vector<int> &heaters, int val){

        long long int ans = INT_MAX;
        int st = 0;
        int end = heaters.size()-1;

        while(st <= end){

            int mid = st + (end-st)/2;
            if(heaters[mid] <= val){
                ans = heaters[mid];
                st = mid+1;
            }
            else{
                end = mid-1;
            }

        }

        return ans;
    }

    long long int just_near_on_right(vector<int> &heaters, int val){

        long long int ans = INT_MAX;
        int st = 0;
        int end = heaters.size()-1;

        while(st <= end){

            int mid = st + (end-st)/2;
            if(heaters[mid] >= val){
                ans = heaters[mid];
                end = mid-1;
            }
            else{
                st = mid+1;
            }

        }

        return ans;

    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        long long int ans = INT_MIN;
        sort(heaters.begin(),heaters.end());

        for(int i=0; i<houses.size(); i++){

            long long int val = houses[i];
            long long int nearonleft = just_near_on_left(heaters,val);
            long long int nearonright = just_near_on_right(heaters,val);
            if(nearonleft != INT_MAX) nearonleft = abs(nearonleft-val);
            if(nearonright != INT_MAX) nearonright = abs(nearonright-val);
            long long int newdist = min(nearonleft,nearonright);
            ans = max(ans,newdist);
        }

        return ans;
    }

};