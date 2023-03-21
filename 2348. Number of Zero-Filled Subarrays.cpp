class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        
        int n = nums.size();
        int i = 0;
        
       while(i<n){
           int l = 0;
            if(nums[i] == 0){
                while(i<n && nums[i] == 0){
                    i++;
                    l++;
                }
            } else {
                i++;
            }
           result += (l) * (l+1) /2;
        }
        return result;
    }
};

//making a variable result n for size i for iterate from zero 
//while loop till n 
//taking variable length initialize with zero
//if value of i is equal to zero
//checking this condition i<n && nums[i] == 0 increment both i and l 
//else i++
//using formula = length * length+1 /2
//return result

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        
        int n = nums.size();
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                count++;
            }else{
                count = 0;
            }
            result = result + count;
        }
        return result;
    }
};

//making a variable result n for size and count initialize with 0
//for loop till n 
//if value of i is equal to zero increment count else count = 0 
//in result add the count
//return result
