class Trie {
public:
    vector<Trie*> children;
    bool isEnd;
    Trie() {
        children = vector<Trie*>(26,nullptr);
        isEnd = false;
    }
};

class Solution {
public:
    void insert(Trie* root,string& s,int index) {
        if(index == s.size()) {
            root->isEnd = true;
            return;
        }
        if(root->children[s[index] - 'a'] == nullptr) {
            Trie* newnode = new Trie();
            root->children[s[index] - 'a']  = newnode;
        } 
        insert(root->children[s[index] - 'a'],s,index+1);
    }
    vector<vector<string>> ans;
    string no = "";
    void search(Trie* root,int index) {
        if(ans[index].size() == 3 || root == NULL) return;
        if(root->isEnd == true) {
            ans[index].push_back(no);
        } 
        for(int i = 0;i<26;i++) {
            no.push_back(i+'a');
            search(root->children[i],index);
            no.pop_back();
        }
    }
    void search2(Trie* root,string& s,int index) {
        if(root == NULL|| index == s.size()) return;
        root = root->children[s[index] - 'a'];
        no.push_back(s[index]);
        search(root,index);
        search2(root,s,index+1);
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root = new Trie();
        ans = vector<vector<string>>(searchWord.size());
        for(string& x:products) insert(root,x,0);
        search2(root,searchWord,0);
        return ans;
    }
};