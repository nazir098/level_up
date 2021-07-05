whenever use morris traversal then dont return in between of the loop 
instead take a variable and store the ans otherwise our tree will remained
modified

morris traversal: left ka rightmost node
using stack: all left node into the stack
    void allright(Node* root,stack<Node*>&st)
    {
        while(root!=nullptr)
        {
            st.push(root);
            root=root->right;
        }
    }
    int kthLargest(Node *root, int K)
    {
        stack<Node*>st;
        allright(root,st);
        while(K-->1)
        {
            Node* curr=st.top();
            st.pop();
            allright(curr->left,st);
            
        }
         Node* curr=st.top();
        return curr->data;
    }
=======================================================
//637. Average of Levels in Binary Tree
        vector<double> levels(TreeNode* root)
    {
        vector<double>ans;
        if(root==nullptr)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.size()!=0)
        {
            double res=0;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
            TreeNode* node=q.front();
            q.pop();
            res+=node->val; 
            if(node->left!=nullptr)
                q.push(node->left);
                
            if(node->right!=nullptr)
                q.push(node->right);
                
            }
            ans.push_back(1.0*res/n);
        }
        return ans;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        
        return levels(root);
    }
========================================================
    1325. Delete Leaves With a Given Value
this question requires post order opn coz when we deletr the leaf
then their parent may again leef which need to be delete again

though we can do it in pre order if we have to just deletr leaf node and 
 not keep deleting leaf node
 
 TreeNode* removeLeafNodes(TreeNode* root, int target) 
{
        
if(root==nullptr)return nullptr;
root->left=removeLeafNodes(root->left, target);
root->right=removeLeafNodes(root->right, target);
return (root->left==root->right&&root->val==target)?nullptr:root;
    }
