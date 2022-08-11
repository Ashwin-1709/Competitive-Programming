struct node {
    node* ma[2];
    int cnt;
    node() {
        cnt = 0;
        ma[0] = ma[1] = NULL;
    }
};
void insert(int x , node* cur) {
    for(int i = 30 ; i >= 0 ; i--) {
        int b = (x >> i) & 1;
        if(!cur->ma[b]) cur->ma[b] = new node();
        cur = cur->ma[b];
        cur->cnt++;
    } 
}
void remove(int x , node* cur) {
    for(int i = 30 ; i >= 0 ; i--) {
        int b = (x >> i) & 1;
        cur = cur->ma[b];
        cur->cnt--;
    }
}
int query(int x , node* cur) {
    int mask = 0;
    for(int i = 30 ; i >= 0 ; i--) {
        int b = (x >> i) & 1;
        if(cur->ma[b] and cur->ma[b]->cnt > 0) 
            cur = cur->ma[b];
        else {
            cur = cur->ma[b ^ 1];
            mask |= (1LL << i);
        }
    }
    return mask;
}
bool present(int x , node* cur) {
    for(int i = 30 ; i >= 0 ; i--) {
        int b = (x >> i) & 1;
        if(!cur->ma[b] or cur->ma[b]->cnt <= 0) return false;
        cur = cur->ma[b]; 
    }
    return true;
}