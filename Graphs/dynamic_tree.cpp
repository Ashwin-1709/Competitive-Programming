// https://github.com/yosupo06/library-checker-problems/blob/master/datastructure/dynamic_tree_subtree_add_subtree_sum/sol/correct.cpp
struct Node;
extern Node *NONE;
struct Node {
  #define l ch[0]
  #define r ch[1]
	Node *p = NONE;
	Node *ch[2] = {NONE, NONE};
	int64_t val = 0;
	int size = 0;
	int size_light = 0; // LIGHT
	int64_t sum = 0;
	int64_t sum_light = 0; // LIGHT
	int64_t added = 0;
	int64_t cancel = 0;
	bool rev = false;
	void flush() {
		if (p != NONE) {
			add(p->added - cancel);
			cancel = p->added;
		}
		if (rev) {
			l->rev ^= 1;
			r->rev ^= 1;
			std::swap(l, r);
			rev = false;
		}
	}
	void fetch() {
		if (l != NONE) l->flush();
		if (r != NONE) r->flush();
		size = 1 + l->size + r->size + size_light;
		sum = val + l->sum + r->sum + sum_light;
	}
	void add(int64_t add_val) {
		val += add_val;
		sum += (int64_t) size * add_val;
		sum_light += (int64_t) size_light * add_val;
		added += add_val;
	}
	void rotate(int dir) {
		Node *new_root = ch[!dir];
		if (new_root->ch[dir] != NONE) new_root->ch[dir]->flush();
		ch[!dir] = new_root->ch[dir];
		ch[!dir]->p = this;
		ch[!dir]->cancel = added;
		new_root->ch[dir] = this;
		new_root->p = p;
		new_root->cancel = p->added;
		if (p->l == this) p->l = new_root;
		if (p->r == this) p->r = new_root;
		p = new_root;
		cancel = new_root->added;
		return fetch(), new_root->fetch();
	}
	bool is_root() { return p == NONE || (p->l != this && p->r != this); }
	void splay() {
		while (!is_root()) {
			if (p->is_root()) {
				p->flush(), flush();
				p->rotate(p->l == this);
			} else {
				Node *pp = p->p;
				pp->flush(), p->flush(), flush();
				bool flag0 = pp->l == p;
				bool flag1 = p->l == this;
				if (flag0 == flag1) pp->rotate(flag0);
				p->rotate(flag1);
				if (flag0 != flag1) pp->rotate(flag0);
			}
		}
		flush();
	}
	Node *expose() {
		Node *prev = NONE;
		for (Node *cur = this; cur != NONE; cur = cur->p) {
			cur->splay();
			if (cur->r != NONE) { // add
				cur->r->flush();
				cur->size_light += cur->r->size;
				cur->sum_light += cur->r->sum;
			}
			cur->r = prev;
			if (cur->r != NONE) { // remove
				cur->r->flush();
				cur->size_light -= cur->r->size;
				cur->sum_light -= cur->r->sum;
			}
			cur->fetch();
			prev = cur;
		}
		splay();
		return prev;
	}
	void link(Node *parent) {
		expose();
		parent->expose();
		parent->r = this;
		p = parent;
		cancel = parent->added;
		parent->fetch();
	}
	void cut() {
		expose();
		l->flush();
		l->p = NONE;
		l = NONE;
		fetch();
	}
	void evert() {
		expose();
		rev ^= 1;
		flush();
	}
  #undef l
  #undef r
};

Node *NONE = new Node;

vector<Node>nodes;
vector<int>par;

// helper functions: can be used as black box as understanding the underlying implementation of the data stucture is complex.
auto init = [&](vector<int>a){
  vector<Node>nodes(sz(a));
  for(int i = 0; i < sz(a); i++) {
    nodes[i].val = a[i];
    nodes[i].fetch();
  }
  return nodes;
};

// add edge to parent
auto add_edge = [&](int par, int c) -> void {
  nodes[par].evert();
  nodes[par].link(&nodes[c]);
};

// subtree add query
auto add_subt = [&](int v, int x) -> void {
  nodes[par[v]].evert();
  nodes[v].cut();
  nodes[v].add(x);
  nodes[v].link(&nodes[par[v]]);
};

// subtree sum query
auto query_subt = [&](int v) -> int {
  nodes[par[v]].evert();
  nodes[v].cut();
  int val = nodes[v].sum;
  nodes[v].link(&nodes[par[v]]);
  return val;
};

// node relocation query (cut and link)
auto relocate = [&](int v, int cut_from, int cut_to) -> void {
  nodes[cut_from].evert();
  nodes[v].cut();
  nodes[cut_to].evert();
  nodes[cut_to].link(&nodes[v]);
  par[v] = cut_to;
};
