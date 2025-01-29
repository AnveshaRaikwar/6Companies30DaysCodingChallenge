class Solution {
public:

    TreeNode* createParentMapping(TreeNode* root, int target, map<TreeNode*,TreeNode*> &nodeToParent){
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root]=NULL;

        TreeNode* result = NULL;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front->val == target){
                result=front;
            }

            if(front->left){
                nodeToParent[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right]=front;
                q.push(front->right);
            }

        }

        return result;
    }

    int burnTree(TreeNode* target, map<TreeNode*,TreeNode*> &nodeToParent){
        map<TreeNode*,bool> visited;
        visited[target] = true;

        queue<TreeNode*> q;
        q.push(target);

        int ans =0;
        
        while(!q.empty()){
            bool flag = 0;
            int size = q.size();

            for(int i=0; i<size; i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    flag=1;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && !visited[front->right]){
                    flag=1;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag=1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            if(flag){
                ans++;
            }
            
        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        
        //create map for node to parent 
        //find target node
        // burn tree
        map<TreeNode*,TreeNode*> nodeToParent;
        TreeNode* target = createParentMapping(root, start, nodeToParent);
        int ans = burnTree(target, nodeToParent);

        return ans;
    }
};