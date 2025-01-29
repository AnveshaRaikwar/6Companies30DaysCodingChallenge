class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //using level order traversal [Can use anyone preorder,postorder ,etc]
        if(!root) return "";

        string s="";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL) s.append("#,"); //using # in string if in tree it is NULL
            else{
                s.append(to_string(front->val) + ",");
            }

            if(front!=NULL){
                q.push(front->left);
                q.push(front->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        stringstream s(data);  // stringstream allows string to be iterated over as object
        string str; // it will be used to iterate on string

        getline(s,str,','); // str iterates over string s and consider single object on basis of comma ','
        // str now contains 1st object of string

        // first object is always root
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            getline(s,str,','); // contains next object

            if(str == "#"){
                front->left = NULL;
            }
            else{
                TreeNode* leftnode = new TreeNode(stoi(str));
                front->left = leftnode;
                q.push(leftnode);
            }

            getline(s,str,',');
            if(str == "#"){
                front->right = NULL;
            }
            else{
                TreeNode* rightnode = new TreeNode(stoi(str));
                front->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};
