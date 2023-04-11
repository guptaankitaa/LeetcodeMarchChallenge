class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '*')
                st.pop();
            else
                st.push(s[i]);
          }   
            
            string result = "";
            
            while(!st.empty()){
                result.push_back(st.top());
                st.pop();
            }
            
            reverse(begin(result), end(result));
            return result;
        
    }
};

//1st Approch   Time= O(n)   Space= O(n)
//we use stack push al the char in st and if we find * then we pop the (last) element of stack 
//and if we dont find * we simply push char in stack
//make a empty string and then while st not  become empty push the top and pop tha element from stack
//and the reverse the result and return it

class Solution {
public:
    string removeStars(string s) {
         string result = "";
        
        for(int i = 0; i<s.length(); i++){
            if(s[i] != '*')
               result.push_back(s[i]);
            else
                result.pop_back();
          }   
            return result;
        
    }
};

//2nd approch     Time= O(n)   Space= O(n)
//we use empty string 
//if we dont find * till then keep pushing char 
//else we pop the char and return result


class Solution{
    public: 
    string removeStars(string s){
        int n = s.length() ;
        int i = 0;
        int j = 0;
        while(i<n){
            if(s[i] == '*'){
                 j--;
            }
            else {
                 s[j] = s[i];
                
                j++;
            }
               i++; 
        }
        
        return s.substr(0,j);
        
    }
};

//3rd Approch  Time= O(n)   Space= O(1)
//here we use simple 2 pointer  both are in 0th position 
//if we find * we decrese j  and move forward
//else we gonna assign the value of i in j and increment both i and j 
//and last return and from 0 to j
