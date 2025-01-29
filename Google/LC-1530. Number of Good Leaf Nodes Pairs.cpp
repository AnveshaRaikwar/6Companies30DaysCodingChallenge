class Solution {
public:
    int ans =0;
    vector<int> helper(TreeNode* root, int d){
        if(!root) return{0};

        if(root->left == NULL && root->right == NULL) return {1};

        auto l = helper(root->left, d);
        auto r = helper(root->right, d);

        for(auto a:l){
            for(auto b:r){
                if(a && b && a+b<=d) ans++;
            }
        }

        //to return vector store values

        vector<int> temp;

        for(auto a:l){
            if(a && a+1<d) temp.push_back(a+1);
        }
        for(auto b:r){
            if(b && b+1<d) temp.push_back(b+1);
        }

        return temp;
    }

    int countPairs(TreeNode* root, int distance) {
        helper(root,distance);
        return ans;
    }
};