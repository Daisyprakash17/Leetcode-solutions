struct Node {
   Node *links[26];
    bool flag=false;
    bool containNode(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void putNode(char ch,Node * node){
        links[ch-'a']=node;
    }
    Node * getNode(char ch){
        return links[ch-'a'];
    }
};
class Trie {
public:
    Node * root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
       Node * node=root;
        for(auto i:word)
        {
            if(!node->containNode(i))
                node->putNode(i,new Node());
            node=node->getNode(i);
                
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Node * node=root;
        for(auto i:word)
        {
            if(node->containNode(i)==false)
                return false;
            node=node->getNode(i);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node * node=root;
        for(auto i:prefix)
        {
            if(node->containNode(i)==false)
                return false;
            node=node->getNode(i);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */