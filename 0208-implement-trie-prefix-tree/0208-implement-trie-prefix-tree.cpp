class Node{
    public:
    bool flag;
    vector<Node *>next;
    void setval(char ch,Node* node){
        next[ch-'a']=node;
    }
    Node* getval(char ch){
        return next[ch-'a'];
    }
    bool checkval(char ch){
        return next[ch-'a']!=nullptr;
    }
    Node(){
        flag=false;
        next.resize(26,nullptr);
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node * temp=root;
        
        for(auto i:word){
            if(temp->checkval(i)==false){
             temp->setval(i,new Node());   
            }
            temp=temp->getval(i);
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        Node * temp=root;
        for(auto i :word){
            if(temp->checkval(i)==false)
                return false;
            temp=temp->getval(i);
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node * temp=root;
        for(auto i :prefix){
            if(temp->checkval(i)==false)
                return false;
            temp=temp->getval(i);
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