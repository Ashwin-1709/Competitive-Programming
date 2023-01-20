template<typename T>
struct segment_tree {
    struct node {
        node *l , *r;
        T val;
        node(T c) : l(nullptr) , r(nullptr) , val(c) {}
        node(node* l, node* r, int c) {
            this->l = l;
            this->r = r;
            val = c;
        }
    };

    node *root;
    T NEUTRAL;
    int sz;
    function<T(T , T)>merge;
    segment_tree(vector<T>&a , int NEUTRAL , function<T(T , T)>merge) {
        sz = (int)a.size();
        this->NEUTRAL = NEUTRAL;
        this->merge = merge;
        root = build(a , 0 , sz - 1);
    }

    node* build(vector<T> &a , int tl , int tr) {
        if(tl == tr) 
            return new node(a[tl]);
        int mid = (tl + tr) >> 1;
        node* l = build(a , tl , mid);
        node* r = build(a , mid + 1, tr);
        return new node(l, r, merge(l->val , r->val));
    }

    T query(node *cur , int tl , int tr , int l , int r) {
        if(l > r or !cur)
            return NEUTRAL;
        if(l == tl and r == tr)
            return cur ? cur->val : NEUTRAL;
        int mid = (tl + tr) >> 1;
        return merge(query(cur->l , tl , mid , l , min(r , mid)) , 
                        query(cur->r , mid + 1 ,tr , max(l , mid + 1) , r));
    }

    inline T query(int l , int r) { return query(root , 0 , sz - 1 , l , r); }
    
    void set(node* cur , int tl , int tr , int pos , T new_val) {
        if(tl == tr) {
            cur->val = new_val;
            return;
        }
        int mid = (tl + tr) >> 1;
        if(pos <= mid) 
            set(cur->l , tl , mid , pos , new_val);
        else
            set(cur->r , mid + 1 , tr , pos , new_val);

        cur->val = merge(cur->l ? cur->l->val : NEUTRAL, cur->r ? cur->r->val : NEUTRAL);
    }

    inline void set(int pos , T val) {set(root , 0 , sz - 1 , pos , val);}
}; 
