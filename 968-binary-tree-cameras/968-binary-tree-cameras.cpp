class Solution {
  map<pair<TreeNode*, int>, int> dp;
  int vcover(TreeNode* root, bool pvisited, bool force) {
    if (root==NULL)
      return force ? INT_MAX : 0;
    pair<TreeNode*, int> state = make_pair(root,pvisited * 2 +force);
    if (dp.find(state) != dp.end()) 
      return dp[state];
    
    int incl=vcover(root->left, true, false)+vcover(root->right, true, false) + 1;
    if (force) {
      dp[state]=incl;
      return incl;
    }
    
    int excl=INT_MAX;
    if (pvisited)
      excl=vcover(root->left, false, false)+vcover(root->right, false, false);
    else {
      if (root->left)
        excl=min(excl,vcover(root->left, false, true) +vcover(root->right, false, false));
      if (root->right)
        excl=min(excl,vcover(root->left, false, false) +vcover(root->right, false, true));
    }
    int result=min(incl, excl);
    dp[state]=result;
    return result;
  }
  
public:
  int minCameraCover(TreeNode* root) {
    return vcover(root, false, false);
  }
};