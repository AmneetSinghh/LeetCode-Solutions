class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        
        long long totSum = 0;
        
        // calculate sum of all positive numbers, i.e maxSubseqSum (2^nth sum)
        for(auto &num : nums)
        {
            if(num > 0)
                totSum += num;
            
            num = abs(num);// we only have to decrease at each step, thats why we take every element as positive.
        }
        
        // sort ascending order
        sort(nums.begin(), nums.end());
        
        // maintain {subseqSum, index which we taken to reduce the sum}
        priority_queue<pair<long long, int>> pq;
        
        // push totSum - first num, num pos is 0
        pq.push({totSum - nums[0], 0});
        // delete largest at every step.
        
        long long res = totSum, n = nums.size();
        
        while(--k)
        {
            auto cur = pq.top(); pq.pop();// always cut the largest, because that sum is the kth largest.
            
            res = cur.first;// current kth total sum.
            
            int idx = cur.second;// index of the element which we substracted.
            
            if(idx <=n - 2)
            {
                // generate next possible sum
                // pick curIdx and try with the next idx
                pq.push({res + nums[idx] - nums[idx + 1], idx + 1});
                // notPick curIdx and try with the next idx
                pq.push({res - nums[idx + 1], idx + 1});
            }
        }
        
        return res;
    }
};