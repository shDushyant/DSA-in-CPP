class Solution {
public:
    bool isvowel(char c){
        if( c=='a'|| c=='e'||c=='i'||c=='o'|| c=='u' || c=='A'|| c=='E'||c=='I'|| c=='O'|| c=='U') return true;
        else return false;
    }
    string reverseVowels(string s) {
        int l=0, r=s.size()-1;
        while(l<r){
            if(isvowel(s[l]) && isvowel(s[r])){
                swap(s[l],s[r]);
                l++;
                r--;
            }
            if(!isvowel(s[l])){
                l++;
                continue;
            }
            if(!isvowel(s[r])){
                r--;
                continue;
            }
        }
        return s;
        
    }
};