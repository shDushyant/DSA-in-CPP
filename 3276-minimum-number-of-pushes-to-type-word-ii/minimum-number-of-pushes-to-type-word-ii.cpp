class Solution {
public:
    int minimumPushes(string word) {
        int cnt=0;
        int cnt2=1;
        // TO CALCULATE THE FREQUENCIES SO THAT MAXIMUM FREQUNCY ELEMENT       GETS MINIMUM PUSH
        unordered_map<char,int>mpp;  
        for(char c:word){
            mpp[c]++;
        }
        // MAKING A VECTOR TO STORE THE FREQUNCIES AND THEN SORTING IT SEPERATELY IN DEC ORDER AND THEN CALCULATING THE MINIMUM TOTAL PUSHES 
        vector<int>pushes;
        for(auto p:mpp){
            pushes.push_back(p.second);
        }
        sort(pushes.rbegin(),pushes.rend()); // DECREASING ORDER SORTING 
        int totalpushes=0;
        for(int i=0;i<pushes.size();i++){
           int pushes_perkey= (i/8)+1;
           totalpushes+= pushes[i]*(pushes_perkey);
        }
        return totalpushes;
       // SORTING IN HASHMAP BASED ON FREQUENCIES AND THEN CALCULATING MIN PUSHES
       /* vector<pair<char, int>> vec(mpp.begin(), mpp.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {return a.second > b.second;});

       for(auto &x: vec){
        if(cnt2<=8 ) cnt+= x.second;
        else if( cnt2<=16) cnt+= 2*(x.second);
        else if( cnt2<=24) cnt+= 3*(x.second);
        else cnt+= 4*(x.second);
          cnt2++;
       }
        return cnt;*/  
    }
};