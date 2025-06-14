class Solution {
public:
    int mySqrt(int x) {
        
        int st = 0;
        int end = x;
        long long int mid = (st+end)/2;

        while(st <= end){

            if(mid*mid == x) return mid;
            else if(mid*mid > x) end=mid-1;
            else st=mid+1;
            mid = (st+end)/2;
        }

        return mid;
    }
};