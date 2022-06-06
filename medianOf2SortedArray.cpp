class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);
        
        int size1 = nums1.size();
        int size2 = nums2.size();
        int low = 0;
        int high = size1;
        
        while(low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (size1 + size2 + 1) / 2 - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            
            int right1 = cut1 == size1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == size2 ? INT_MAX : nums2[cut2];
            
            if(left1 <= right2 && left2 <= right1) {
                if((size1 + size2) % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else
                    return max(left1, left2);
            } else if(left1 > right2) 
                high = cut1 - 1;
            else 
                low = cut1 + 1;
        }
        
        return 0.0;
    }
};
