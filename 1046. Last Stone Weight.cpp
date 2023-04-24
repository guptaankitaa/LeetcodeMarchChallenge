// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
        
//         while(stones.size() > 1){
            
//             sort(begin(stones),end(stones));
            
//             int a =  stones.back(); 
//               stones.pop_back();
//             int b =  stones.back(); 
//               stones.pop_back();
            
//             stones.push_back(abs(a-b));
//         }
        
//            return stones[0];
//     }
// };

// Approch 1    Time = O(n*n logn) Space = O(n)

//simple jb tk size greater than 1 hai 
//tb tk sort kro or last 2 element uthao or pop krdo  or minus kr do  or push krdo result vapis
//lastly return stones position 0 (kuki 1 element left hoga) 

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        
        for(int &stone : stones){
            
            pq.push(stone);
        }
        
        while(pq.size() > 1){
            
            
            int a =  pq.top(); 
              pq.pop();
            int b =  pq.top(); 
              pq.pop();
            
            pq.push(abs(a-b));
        }
        
           return pq.top();
    }
};

// Approch 2    using Heap    Time = O(n log n) Space = O(n)
// using sorting again and again or we need max ele. or min ele. then we use HEAP
