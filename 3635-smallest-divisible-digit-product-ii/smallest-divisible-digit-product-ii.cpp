class Solution {
public:
    int twos[10]={0}, threes[10]={0}, fives[10]={0}, sevens[10]={0};
    vector<vector<int>> dist23;

    void buildDist(int a,int b){
        dist23.assign(a+1, vector<int>(b+1, -1));
        dist23[0][0]=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<pair<int,int>> moves = {{1,0},{0,1},{2,0},{1,1},{3,0},{0,2}};
        while(!q.empty()){
            auto [i,j]=q.front(); q.pop();
            for(auto &mv:moves){
                int ni=min(a,i+mv.first), nj=min(b,j+mv.second);
                if(dist23[ni][nj]==-1){
                    dist23[ni][nj]=dist23[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }
    }

    inline int minDigitsNeeded(int la,int lb,int lc,int ld){
        return dist23[la][lb]+lc+ld;
    }

    string smallestArrangement(int len,int la,int lb,int lc,int ld){
        string res; res.reserve(len);
        int slots=len;
        for(int pos=0; pos<len; pos++){
            for(int v=1; v<=9; v++){
                int nla=max(0,la-twos[v]), nlb=max(0,lb-threes[v]);
                int nlc=max(0,lc-fives[v]), nld=max(0,ld-sevens[v]);
                if(minDigitsNeeded(nla,nlb,nlc,nld) <= slots-1){
                    res.push_back('0'+v);
                    la=nla; lb=nlb; lc=nlc; ld=nld;
                    slots--;
                    break;
                }
            }
        }
        return res;
    }

    string smallestNumber(string num, long long t) {
        twos[2]=1; twos[4]=2; twos[6]=1; twos[8]=3;
        threes[3]=1; threes[6]=1; threes[9]=2;
        fives[5]=1;
        sevens[7]=1;

        int a=0,b=0,c=0,d=0;
        while(t%2==0){a++;t/=2;}
        while(t%3==0){b++;t/=3;}
        while(t%5==0){c++;t/=5;}
        while(t%7==0){d++;t/=7;}
        if(t!=1) return "-1";

        buildDist(a,b);

        int L=num.size();
        vector<int> PA(L+1,0),PB(L+1,0),PC(L+1,0),PD(L+1,0);
        int z=L;
        for(int i=0;i<L;i++){
            int v=num[i]-'0';
            if(v==0 && z==L) z=i;
            PA[i+1]=min(a,PA[i]+twos[v]);
            PB[i+1]=min(b,PB[i]+threes[v]);
            PC[i+1]=min(c,PC[i]+fives[v]);
            PD[i+1]=min(d,PD[i]+sevens[v]);
        }

        if(z==L && PA[L]==a && PB[L]==b && PC[L]==c && PD[L]==d) return num;

        int top=min(z,L-1);
        int foundI=-1, foundV=-1;
        for(int i=top;i>=0;i--){
            int remaining=L-1-i;
            int base=num[i]-'0';
            for(int v=base+1; v<=9; v++){
                int na=min(a,PA[i]+twos[v]), nb=min(b,PB[i]+threes[v]);
                int nc=min(c,PC[i]+fives[v]), nd=min(d,PD[i]+sevens[v]);
                int la=a-na, lb=b-nb, lc=c-nc, ld=d-nd;
                if(minDigitsNeeded(la,lb,lc,ld)<=remaining){
                    foundI=i; foundV=v; break;
                }
            }
            if(foundI!=-1) break;
        }

        if(foundI!=-1){
            string ans=num.substr(0,foundI);
            ans.push_back('0'+foundV);
            int na=min(a,PA[foundI]+twos[foundV]), nb=min(b,PB[foundI]+threes[foundV]);
            int nc=min(c,PC[foundI]+fives[foundV]), nd=min(d,PD[foundI]+sevens[foundV]);
            int la=a-na, lb=b-nb, lc=c-nc, ld=d-nd;
            int remaining=L-1-foundI;
            ans += smallestArrangement(remaining, la,lb,lc,ld);
            return ans;
        }

        int minLenTotal = dist23[a][b] + c + d;
        int L2 = max(L+1, minLenTotal);
        return smallestArrangement(L2, a,b,c,d);
    }
};