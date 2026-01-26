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
        string res;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* top=st.top();
            if(!top){
                res.append("#,");
            }else{
                string temp=to_string(top->val);
                res.append(temp);
                res.push_back(',');
            }
            st.pop();
            if(top)st.push(top->right);
            if(top)st.push(top->left);
        }
        return res;
    }
    //build tree
    TreeNode* buildTree(stringstream & ss){
        string token;
        getline(ss,token,',');
        if(token=="#")return nullptr;
        int value=stoi(token);
        TreeNode* root=new TreeNode(value);
        root->left=buildTree(ss);
        root->right=buildTree(ss);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.size();
        stringstream ss(data);
        return buildTree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));