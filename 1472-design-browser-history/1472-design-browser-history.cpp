class ListNod{
        public: 
    string x;
    ListNod *prev, *next;

        ListNod(string x){
            this->x = x;
            prev = NULL, next = NULL;
        }
        ListNod(){
            prev = next = NULL;
        }
};
class BrowserHistory {
public:
    ListNod *head;
    ListNod *curr, *prev = NULL;
    BrowserHistory(string homepage) {
        head = new ListNod(homepage);
        curr = head;
        prev = head;
    }
    void visit(string url) {
        curr->next = new ListNod(url);
        curr = curr->next;
        curr->prev = prev;
        prev = curr;
    }
    string back(int steps) {
        while(steps-- && prev->prev){
            prev = prev->prev;
        }
        curr = prev;
        return prev->x;
    }
    
    string forward(int steps) {
        while(steps-- && curr->next){
            curr = curr->next;
        }
        prev = curr;
        return curr->x;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */