class Solution {
public:

    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.first > b.first;
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<pair<int,int>> duplicate;

        for(int i=0; i<score.size(); i++){
            duplicate.push_back({score[i],i});
        }
        sort(duplicate.begin(),duplicate.end(),cmp);

        vector<string> ans(score.size());

        int i = 0;
        if(i < score.size()){
            int pos = duplicate[i].second;
            ans[pos] = "Gold Medal";
            i++;
        }
        if(i < score.size()){
            int pos = duplicate[i].second;
            ans[pos] = "Silver Medal";
            i++;
        }
        if(i < score.size()){
            int pos = duplicate[i].second;
            ans[pos] = "Bronze Medal";
            i++;
        }

        int nextmedal = 4;

        while(i < score.size()){
            int pos = duplicate[i].second;
            ans[pos] = to_string(nextmedal);
            nextmedal++;
            i++;
        }

        return ans;

    }
};