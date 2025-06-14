class Solution {
public:

    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second < b.second;
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();
        vector<pair<int,int>> v;

        for(int i=0; i<n; i++){
            v.push_back({profits[i],capital[i]});
        }

        sort(v.begin(),v.end(),cmp);

        priority_queue<int> pq;
        int i = 0;

        while(k--){

            while(i < n && v[i].second <= w){
                pq.push(v[i].first);
                i++;
            }

            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }

        }

        return w;
        
    }
};