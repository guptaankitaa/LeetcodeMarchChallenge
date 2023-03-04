class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        
        int minkposition = -1;
        int maxkposition = -1;
        int culpritIndx  = -1;
        
        for(int i = 0; i<nums.size(); i++){
            
            if(nums[i] < minK || nums[i] > maxK)
                culpritIndx = i;
            
            if(nums[i] == minK)
                minkposition =  i;
            
            if(nums[i] == maxK)
                maxkposition =  i;
            
            long long smaller = min(minkposition, maxkposition);
            
            long long temp = smaller - culpritIndx;
            
            ans += (temp <= 0) ? 0 : temp;
        }    
        
        return ans;
    }
};

//making long long ans variable because in this we store the count of sub array

//then making 3 variable 1store min positon 2store max position 3store culprit(means the value which not lies btw fixed bound) all the 3 varibale mark initialy -1
//simply iterate in array and find

// the value which not lies btw fixed bound (meas greater or smaller than given val) so we upate culprit

//if nums of i is small so updae minposition

//if nums of i is greater so updae maxposition

//then we find minimum from minposition or maxposition and store in smaller variable

//and in temp we store smaller - culpritIndx

//ans in ans if temp is less than 0 so we add 0 in ans else we add temp value

//return ans
