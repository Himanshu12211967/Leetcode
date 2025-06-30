class Solution {
public:

    int solve(int n, int k){

        if(n == 2){
            if(k & 1) return 1;
            return 0;
        }

        int ans = solve(n-1,k);
        return (ans+k)%n;

    }

    int findTheWinner(int n, int k) {
        if(n == 1) return 1;
        
        return solve(n,k)+1;
    }
};