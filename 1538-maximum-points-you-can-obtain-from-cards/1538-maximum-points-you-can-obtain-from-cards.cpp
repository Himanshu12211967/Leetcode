class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {
        
        int size = cardPoints.size() - k;
        int sum = 0;
        int left_delete = 0;
        int minimum_contigous_sum = INT_MAX;

        for(int i=0; i<size; i++){
            sum += cardPoints[i];
        }

        minimum_contigous_sum = min(minimum_contigous_sum,sum);

        for(int i=size; i<cardPoints.size(); i++){
            sum = sum + cardPoints[i] - cardPoints[left_delete++];
            minimum_contigous_sum = min(minimum_contigous_sum,sum);
        }

        int total_sum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        return total_sum - minimum_contigous_sum;
    }


};