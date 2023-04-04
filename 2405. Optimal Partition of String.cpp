class Solution {
public:
    int partitionString(string s) {
        vector<int> lastSeen(26, -1);      //size and initialize
        
        int count = 0;
        
        int substrStart = 0;          //starting of substrg
         
        for(int i = 0; i<s.length(); i++){
                       
            
            if(lastSeen[s[i]-'a'] >= substrStart){     //mtlb same ch hai
                
                count++;                                 //increment cnt
                substrStart = i;                      //new substrg start krna hoga from i
            }
            lastSeen[s[i]-'a'] = i;                        //update
        }
        return count+1;                                      //last bach rha hai thst why +1
    }
};
