class Node{
public:
    bool flag;
    vector<Node *>nextnode;
    void setnode(char ch,Node *newnode){
        nextnode[ch-'a']=newnode;
    }
    bool hasnode(char ch){
        return nextnode[ch-'a']!=nullptr;
    }
    Node* getnode(char ch){
        return nextnode[ch-'a'];
    }
    Node(){
        flag=false;
        nextnode.resize(26,nullptr);
    }
};
class Trie {
public:
    Node * root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node * temp=root;
        for(auto i:word){
            if(temp->hasnode(i)){
                temp=temp->getnode(i);
            }
            else{
                Node * newnode=new Node();
                temp->setnode(i,newnode);
                temp=temp->getnode(i);
            }
        }
        temp->flag=true; // this means that this string is completed this this point
    }
    
    bool search(string word) {
        
        Node * temp=root;
        
        for(auto i:word){
            if(temp->hasnode(i)==false)
                return false;
            temp=temp->getnode(i);
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node * temp=root;
        for(auto i:prefix){
            if(temp->hasnode(i)==false)
                return false;
            temp=temp->getnode(i);
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