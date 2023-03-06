class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        
        int n = arr.size();
        int i = 0;
        
        while(i < n && k > 0){
            
            if(arr[i] == num){
                i++;
            }
            else {
                k--;
            }
            num++;
        }
        
        while(k--){
            num++;
        }
        return num-1;
    }
};

//Naive Approch O(n)
//in this we are taking num start it with 1 (it tell counting)
//find size and a i variable which is at 0
//whlie our i reach till n and k should be greater than 0 
//if array and num both value are equal that means no elemnt is missing we simply increment i 
//else missing!!!!!! so we decrement k 
//and in every condion we increment num
//edge case:: if the array become empty and we didnt find the elemnt  so we just loop till k become 0 and every tym we increment num to check next value
//return num-1



class Solution {
public:
   int findKthPositive(vector<int>& arr, int k)  {
        
        int n = arr.size();
        int start = 0, end = n-1;
        
        while (start <= end) {
            
            int mid = start + (end - start) / 2;
            
            if (arr[mid] - (mid + 1) < k)
                start = mid + 1;
            
            else
                end = mid - 1;
        }
        return start + k;
    }
};

//Optimize Approch O
//simple taking 2 variable start and end start at 0 end at last index
//if missing no is smaller than k that means we have to search in right 
//else go left
