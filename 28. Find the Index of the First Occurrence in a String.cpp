class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        
        for(int i = 0; i <= m-n; i++) { //haystack
            
            for(int j = 0; j < n; j++) { //needle
                
                if(haystack[i+j] != needle[j])
                    break;
                
                if(j == n-1)
                    return i;
                
            }
            
        }
        
        return -1;
    }
};

//2 for loop and checking condition 
// if if current i and j value is not equal then break and increment
//else check the string needle till end
//if it reach till end that means we got the string
//return the first index of the string
//otherwise return -1
