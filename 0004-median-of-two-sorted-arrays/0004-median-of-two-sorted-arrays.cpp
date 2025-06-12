class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.empty() && nums2.empty()) return 0;

        int i = nums1.size()-1;
        int j = 0;

        while(i >= 0 && j < nums2.size()){
            if(nums1[i] > nums2[j]){
                swap(nums1[i],nums2[j]);
            }
            i--;
            j++;
        }

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        for(int i=0; i<nums1.size(); i++){
            cout<<nums1[i]<<" ";
        }cout<<endl;

        for(int k=0; k<nums2.size(); k++){
            cout<<nums2[k]<<" ";
        }

        if(nums1.size() == nums2.size()) return (double)(nums2[0]+nums1[nums1.size()-1])/2;
        
        int total = nums1.size() + nums2.size();
        int mid = total/2;

        if(nums1.size() > nums2.size()){

            if(nums1.size() == nums2.size()+1) return (double)nums1[nums1.size()-1];
            if(total%2 == 0) return (double)(nums1[mid]+nums1[mid-1])/2;
            return (double)nums1[mid];
        }

        if(nums1.size()+1 == nums2.size()) return (double)nums2[0];
        if(total%2 == 0) return (double)(nums2[mid-nums1.size()]+nums2[mid-1-nums1.size()])/2;
        return (double)nums2[mid-nums1.size()];
    }
};