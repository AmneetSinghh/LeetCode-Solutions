class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r)
        {
            int mid = (l+r)/2;
            if (nums[mid] == target)
                return true;
			// with duplicates we can have this contdition, just update left & right
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
            else if(nums[l] <= nums[mid])
            {
                if (nums[mid]>=target and nums[l]<=target)
                    r=mid-1;
                else
                    l=mid+1;
            }
            else
            {
                if(target>=nums[mid] and target<=nums[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        return false;
    }
};