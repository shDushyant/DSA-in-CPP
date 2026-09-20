class Node{
    public:
    string val;
    Node* next;
    Node*prev;
    Node(string x){
        val= x;
        next=nullptr;
        prev=nullptr;
    }
};
class BrowserHistory {
    Node* currpage;
public:
    BrowserHistory(string homepage) {
        currpage= new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode= new Node(url);
        currpage->next= newNode;
        newNode->prev= currpage;
        currpage= newNode;
    }
    
    string back(int steps) {
        while(steps>0){
            if(currpage->prev) currpage= currpage->prev;
            else break;
            steps--;
        }
        return currpage->val; 
    }
    
    string forward(int steps) {
        while(steps>0){
            if(currpage->next) currpage=currpage->next;
            else break;
            steps--;
        }
        return currpage->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */