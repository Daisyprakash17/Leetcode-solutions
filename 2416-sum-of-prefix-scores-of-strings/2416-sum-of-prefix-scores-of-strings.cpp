struct Node{
  Node * links[26];
    int count=0;
    bool  containNode(char ch){
        return links[ch-'a']!=NULL;
    }
    void putNode(char ch,Node * node){
        links[ch-'a']=node;
    }
    Node * getNode(char ch){
        return links[ch-'a'];
    }
};
class Solution {
public:
    Node *root;
    void insertString(string &s)
    {
        Node * node=root;
        for(auto i:s)
        {
            if(node->containNode(i)==false)
                node->putNode(i,new Node());
            node=node->getNode(i);
            node->count++;
        }
    }
    int getVal(string & s)
    {
        Node * node=root;
        int count=0;
        for(auto i:s)
        {
            node=node->getNode(i);
            count+=node->count;
        }
        return count;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
            root=new Node();
        for(auto i:words)
            insertString(i);
        vector<int>ans;
        for(auto i:words)
            ans.push_back(getVal(i));
        return ans;
    }
};