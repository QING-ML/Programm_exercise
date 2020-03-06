/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        int path_value = 0;
        preorder(root, path_value, sum, path, result);
        return result;
        
    }
private:
    void preorder(TreeNode* &root, int &path_value, const int sum,
                  vector<int> &path, vector<vector<int>> &result){
        if(root == NULL){
            return;
        }
        path.push_back(root-> val);
        path_value += root->val;
        
        if(root -> left == NULL && root ->right == NULL && path_value == sum){
            result.push_back(path);
        }
        
        preorder(root -> left, path_value, sum, path, result);
        preorder(root -> right, path_value, sum, path, result);
        
        path.pop_back();
        path_value -= root -> val;
        
        
    }
};