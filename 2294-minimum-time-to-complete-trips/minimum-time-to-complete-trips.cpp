/*class Solution {
public:
    int sum(vector<int>&time){
        int sum_total=0;
        for(int x:time){
            sum_total+=x;
        }
        return sum_total;
    }
    int total_trips(vector<int>&time, int timetaken){
        int trips_pertime=0;
        for(int i=0;i<time.size();i++){
            if(time[i]>timetaken) trips_pertime+=0;
            else{
                trips_pertime+= (timetaken/time[i]);
            }   
        }
        return trips_pertime;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        if(time.size()==1){
          if(time[0]>totalTrips) return time[0];
          else return totalTrips/time[0];
        } 
        //int low=*min_element(time.begin(),time.end());
        int low=1;
        int high=sum(time);
        while(low<=high){
            int mid=low+(high-low)/2;
            int res_trips= total_trips(time,mid);
            if(res_trips>=totalTrips) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};*/
class Solution {
public:

    long long totalTrips(vector<int>& time, long long t) {
        long long trips = 0;

        for (long long x : time) {
            trips += t / x;

            // Avoid unnecessary calculations
            if (trips >= t) {
                // Don't actually use this condition here
            }
        }

        return trips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {

        long long low = 1;

        long long mn = *min_element(time.begin(), time.end());

        long long high = mn * (long long)totalTrips;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            long long trips = 0;

            for (long long x : time) {
                trips += mid / x;

                // We only care whether trips >= totalTrips
                if (trips >= totalTrips)
                    break;
            }

            if (trips >= totalTrips) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};