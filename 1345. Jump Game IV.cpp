class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, vector<int>> mp;
        vector<bool> visited(n, false);
        
        for(int i = 0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        
        queue<int> que;
        que.push(0);
        visited[0] = true;
        
        int step = 0;
        
        while(!que.empty()){
            int size = que.size();
            
            while(size--){
                int curr = que.front();
                que.pop();
                
                int left = curr-1;
                int right = curr+1;
                
                if(curr == n-1)
                    return step;
                 
                if(left >=0 && !visited[left]){
                    que.push(left);
                    visited[left] = true;
                }
                 if(right >=0 && !visited[right]){
                    que.push(right);
                    visited[right] = true;
                }
                
                for(int &idx : mp[arr[curr]]){
                    if(!visited[idx]){
                        que.push(idx);
                        visited[idx] = true;
                    }
                }
                mp.erase(arr[curr]);
            }
            step++;
        }
        return -1; 
    }
};

//first we find sixe in n variable
//taking unorder map vector to store no and index of that no
//and vector name visited size n and mark false every path
//for loop to push all the number index in map
//making queue 
//strating from 0 index push in que and mark visited true and increment step bcoz we take 1 step

//BFS

//While queue not get empty taking variable size and find size 
//another loop till size get empty 
//we assign que front in current and pop that (becoz after again we come and take the value again)
//now from current we move 2step whether left right or same value
//if current is equal to last element so we return step (bcoz the value is same and we directly move there )

//example{7,4,5,2,7,8,7} in this we easily reach end at 1 jump only

//now for moving left the value should be grater than 0 and it should not be mark visited then only we move so we push left in que and mark visitied
//same for right
//and another if indx of mp and current indx of arr are equal and also they are not visitedvso we push and mark visited
//we erase current no
//and every time we add step
//if we ddt find any path so we return -1
