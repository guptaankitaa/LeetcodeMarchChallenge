// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         stack<int>st;
        
//         int n = pushed.size();
        
//         int i = 0, j = 0;
        
//         while(i < n && j < n){
            
//             st.push(pushed[i]);
            
//             while(st.size() != 0 && j < n && st.top() == popped[j]){
//                 st.pop();
//                 j++;
//             }
//             i++;
//         }
        
//         return st.empty();
//     }
// };

//Approch 1  Using Stack           Time = O(n)  Space = O(n)

//taking stack first we push 
//then we check if stack is empty or not and j is not greater then size and the top of stack is equal to j (if all these condition satisfy then only)
//we pop the elemnt or increment j 
//and i will increment in every case and in last only check that st is empty return true else false

class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        for (int x : pushed) {
            pushed[i] = x;
            i++;
            while (i > 0 && pushed[i - 1] == popped[j])
                --i, ++j;
        }
        return i == 0;
    } 
  };  


//Approch 2             Time = O(n)  Space = O(1)

