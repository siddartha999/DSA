/**
* Link: https://leetcode.com/problems/construct-string-from-binary-tree/description/
*/

// Approach 1: TC: O(N^2), SC: O(N).  O(N^2) due to new string creation at every step which potentially (worst-case in theory) 
// spans the entire tree length!

class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root) return "";
        if(!root->left && !root->right) return to_string(root->val);
        string leftStr = tree2str(root->left);
        string rightStr = tree2str(root->right);
        string res = to_string(root->val) + "(" + leftStr + ")";
        if(rightStr != "") res += "(" + rightStr + ")";
        return res;
    }
};



// Approach 2: TC: O(N), SC: O(N)
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root) return "";
        if(!root->left && !root->right) return to_string(root->val);
        string res = "";
        helper(root, res);
        return res;
    }
private:
    void helper(TreeNode* root, string& res) {
        if(!root) return;
        res += to_string(root->val);
        if(!root->left && !root->right) {
            return;
        }
        res += "(";
        helper(root->left, res);
        res += ")";
        if(root->right) {
            res += "(";
            helper(root->right, res);
            res += ")";
        }
    }
};
