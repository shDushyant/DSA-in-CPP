class Solution {
public:
    int minInsertions(string s) {
        int insert = 0;
        int need = 0;

        for(char c : s) {
            if(c == '(') {
                if(need % 2 == 1) {
                    insert++;
                    need--;
                }
                need += 2;
            }
            else {
                need--;

                if(need < 0) {
                    insert++;
                    need = 1;
                }
            }
        }

        return insert + need;
    }
};