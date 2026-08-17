class Solution {
public:
    long long total_trips(vector<int>&time, long long timetaken){
        long long trips_pertime=0;
        for(int i=0;i<time.size();i++){
            if(time[i]>timetaken) trips_pertime+=0;
            else{
                trips_pertime+= (timetaken/time[i]);
            }   
        }
        return trips_pertime;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        //int low=*min_element(time.begin(),time.end());
        long long low=1;
        long long high= *min_element(time.begin(),time.end())*(long long)totalTrips;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long res_trips= total_trips(time,mid);
            if(res_trips>=totalTrips) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
/*class Solution {
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
};*/