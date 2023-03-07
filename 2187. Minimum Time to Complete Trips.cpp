
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long start = 1;
        long long end = 1e14;
        
        while(start <= end){
            
            long long trip = 0;
            long long mid = start + (end - start)/2;
            
            for(int i=0;i<time.size();i++)
                trip += mid / time[i];
            
            if(trip < totalTrips){
                start = mid + 1;
            }
            else 
                end = mid - 1;
        }
        return start;
    }
};


//simply doing binary search 
//at line 14 we iterate in time array and adding the value in trip 
//example!!!! {1,2,3}   =>   mid = 2   =>   2/1 + 2/2 + 2/3 = 2 + 1 + 0  now the trip is 3 which is less 

//if trip is smaller thant total trips  so we move our start from mid + 1
//In this case our start at 3 end at 3 and mid is also at 3  => 3/1 + 3/2 + 3/3 = 3+2+1 = 5 
//now we return start bcoz we get our total trips 
