class Trie {
    public : 
        struct TrieNode {
            TrieNode* child[26];
            int cnt;
            TrieNode() {
                cnt = 0;
                for(int i = 0 ; i < 26 ; i++)
                    child[i] = NULL;
            }
        };
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        void insert(string s) {
            TrieNode* cur = root;
            for(int i = 0 ; i < s.length() ; i++) {
                int c = s[i] - 'a';
                if(cur->child[c] != NULL) cur = cur->child[c];
                else {
                    cur->child[c] = new TrieNode();
                    cur = cur->child[c];
                }
            }
            cur->cnt++;
        }
        void insert(string s, int key) {
            TrieNode* cur = root;
            for(int i = 0 ; i < s.length() ; i++) {
                int c = s[i] - 'a';
                if(cur->child[c] != NULL) cur = cur->child[c];
                else {
                    cur->child[c] = new TrieNode();
                    cur = cur->child[c];
                }
            }
            cur->cnt = key;
        }
        bool search(string word) {
            TrieNode* cur = root;
            for(int i = 0 ; i < word.length() ; i++) {
                int c = word[i] - 'a';
                if(cur->child[c] == NULL) return false;
                cur = cur->child[c];
            }
            return (cur->cnt > 0);
        }
        bool startsWith(string prefix) {
            TrieNode* cur = root;
            for(int i = 0 ; i < prefix.length() ; i++) {
                int c = prefix[i] - 'a';
                if(cur->child[c] == NULL) return false;
                cur = cur->child[c];
            }
            return true;
        }
        int sum(string prefix) {
            TrieNode* cur = root;
            int ans = 0;
            for(int i = 0 ; i < prefix.length() ; i++) {
                int c = prefix[i] - 'a';
                if(cur->child[c] == NULL) return 0;
                cur = cur->child[c];
            }
            auto dfs = [&](auto &f , TrieNode* curr) -> void {
                if(curr == NULL) return;  
                ans += curr -> cnt;
                for(int i = 0 ; i < 26 ; i++) {
                    if(curr->child[i] != NULL) f(f , curr->child[i]);
                }
            };
            dfs(dfs , cur);
            return ans;
        }
};