 struct Node{
     Node *links[26];
     bool flag=false;
     bool containkey(char ch) {
         return (links[ch-'a']!=NULL);
         // return true if there is the value
         // and will return false if it is not there
     }
     void putkey(char ch,Node * node){
         links[ch-'a']=node;
     }

     Node* getnode(char ch){
         return links[ch-'a'];
     } 
 };
class Trie {
    private :
    Node * root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node * node =root;
        for(auto i:word)
        {
            if(node->containkey(i)==false)
            {
                // if new node is not there 
                // then we will create a new node
                // and will put the current char in current node 
                // and will point the link to the new node with flag false
                
                node->putkey(i,new Node());
            }
            node=node->getnode(i);
            
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Node * node=root;
        
        for(auto i:word)
        {
            if(node->containkey(i)==false)
                return false;
            node=node->getnode(i);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node * node=root;
        for(auto i:prefix)
        {
            if(node->containkey(i)==false)
                return false;
            node=node->getnode(i);
            
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