/*class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        vector<int>ans;                            //this is brute force 
        for(int i=0;i<queryIndices.size();i++){
            s[queryIndices[i]]=queryCharacters[i];    //update the string
            int k=0,j=1; 
            int windsize=1;
            int max_leng=1;
            while(j<s.size()){                        //using sliding window to check for max-leng for ith query
                if(s[k]==s[j]){
                    windsize++;
                    j++;
                }
                else {
                    max_leng= max(windsize,max_leng);
                    windsize=1;
                    k=j;
                    j++;
                }
            }
            if(windsize>max_leng) ans.push_back(windsize);  // test case 2 , windsize=2 and max_leng update nhi hua
            else if(max_leng==1) ans.push_back(max_leng);
            //if(max_leng==1) ans.push_back(0);
            else ans.push_back(max_leng);
        }
        return ans;
    }
};  */
 // time for optimal apprach : segment trees
 class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;

        Node() {
            leftChar = rightChar = '#';
            prefix = suffix = best = len = 0;
        }
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;
        res.suffix = b.suffix;

        if (a.leftChar == b.leftChar && a.prefix == a.len)
            res.prefix = a.len + b.prefix;

        if (a.rightChar == b.rightChar && b.suffix == b.len)
            res.suffix = b.len + a.suffix;

        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar)
            res.best = max(res.best, a.suffix + b.prefix);

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            seg[node].leftChar = s[l];
            seg[node].rightChar = s[l];
            seg[node].prefix = 1;
            seg[node].suffix = 1;
            seg[node].best = 1;
            seg[node].len = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            seg[node].leftChar = c;
            seg[node].rightChar = c;
            seg[node].prefix = 1;
            seg[node].suffix = 1;
            seg[node].best = 1;
            seg[node].len = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, c);
        else
            update(2 * node + 1, mid + 1, r, idx, c);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};