class Solution {
public:

    bool ispossible(vector<int>& time, int totalTrips, long long int mid){

        long long int completed_trips = 0;

        for(int i=0; i<time.size(); i++){
            completed_trips = completed_trips + mid/time[i];
        }

        return (completed_trips >= totalTrips);
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long int st = 1;
        long long int end = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;
        long long int ans = end;

        while(st <= end){

            long long int mid = st + (end - st)/2;
            if(ispossible(time,totalTrips,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                st = mid+1;
            }

        }

        return ans;
    }
};