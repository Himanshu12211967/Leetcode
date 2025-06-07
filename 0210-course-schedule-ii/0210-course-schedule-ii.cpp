class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        map<int,vector<int>> m;
        vector<int> inorder(numCourses,0);

        for(int i=0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            m[a].push_back(b);
            inorder[b]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(inorder[i] == 0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto neigh : m[node]){
                inorder[neigh]--;
                if(inorder[neigh] == 0) q.push(neigh);
            }

        }

        reverse(ans.begin(),ans.end());
        if(ans.size() != numCourses) return {};
        return ans;

    }
};