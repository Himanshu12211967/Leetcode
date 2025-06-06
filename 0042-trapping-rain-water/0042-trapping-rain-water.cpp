class Solution {
public:

    void left_side(vector<int> &height,vector<int> &left_boundary){

        int maxi = height[0];
        left_boundary[0] = height[0];

        for(int i=1; i<height.size(); i++){
            left_boundary[i] = max(height[i],maxi);
            maxi = max(maxi,height[i]);
        }
       
    }

    void right_side(vector<int> &height,vector<int> &right_boundary){

        int maxi = height[height.size()-1];
        right_boundary[height.size()-1] = height[height.size()-1];

        for(int i=height.size()-2; i>=0; i--){
            right_boundary[i] = max(height[i],maxi);
            maxi = max(maxi,height[i]);
        }

    }

    int trap(vector<int>& height) {
        
        int total_water = 0;
        vector<int> left_boundary(height.size());
        vector<int> right_boundary(height.size());

        left_side(height,left_boundary);
        right_side(height,right_boundary);

        for(int i=0; i<height.size(); i++){

            cout<<left_boundary[i] << " "<<right_boundary[i];
            int water = min(left_boundary[i],right_boundary[i])-height[i];
            total_water += water;

        }

        return total_water;

    }
};