/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        BST_Preorder(root, data);
        return data;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0){
            return NULL;
        }
        vector<TreeNode*> node_vec;
        int val = 0;
        for(int i = 0; i < data.length(); i++){
            if(data[i] == '#'){
                node_vec.push_back(new TreeNode(val));
                val = 0;
            }
            else{
                val = 10 * val + data[i] - '0';
            }
        }
        for(int i = 1; i < node_vec.size() ; i++){
            BST_insert(node_vec[0], node_vec[i]);
        }
        return node_vec[0];
        
        
    }

private:
    //coder
    void BST_Preorder(TreeNode* node, string& data){
        if(node == NULL){
            return;
        }
        std::string str_val;
        change_int_to_string(node -> val, str_val);
        data += str_val;

        BST_Preorder(node -> left, data);
        BST_Preorder(node -> right, data);
    }
    
    void change_int_to_string(int val, string& str_val){
        string tmp;
        while(val){
            tmp += val % 10 + '0';
            val = val / 10;
        }
        for(int i = tmp.size() - 1; i >=0; i--){
            str_val += tmp[i];
        }
        str_val += '#';
    }
    
    //decoder
    void BST_insert(TreeNode* node, TreeNode* insert_node){
        if(insert_node -> val < node -> val){
            if(node -> left){
                BST_insert(node -> left, insert_node);
            }
            else{
                node -> left = insert_node;
            }
        }
        else{
            if(node -> right){
                BST_insert(node -> right, insert_node);
            }
            else{
                node -> right = insert_node;
            }
            
        }
    }
};