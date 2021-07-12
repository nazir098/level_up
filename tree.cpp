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
void fun(Node* root,vector<int>asf,vector<vector<int>>&res)
{
    if(root==nullptr)
    return;
    if(root->left==root->right)
    {
        
        asf.push_back(root->data);
        res.push_back(asf);
        return ;
    }
    
    asf.push_back(root->data);
    fun(root->left,asf,res);
    fun(root->right,asf,res);
    
    
}    
==========================    
    mind the usecase of & while passing any vector if not use then complexity of only
    this will be o(n)
    void allRootLeafPath(Node* root,vector<int>&asf,vector<vector<int>>&res)
{
    if(root==nullptr)
    return;
    if(root->left==root->right)
    {
        vector<int>base(asf);     //copying vector once
        base.push_back(root->data);
        res.push_back(base);
    }
    
    asf.push_back(root->data);
    fun(root->left,asf,res);
    fun(root->right,asf,res);
    asf.pop_back();
    
}
=============================================================
    ->exactly one child
when the required case encounter still we go for search another
exactly one child node

-> in counting the nodes u will have to do it in post order coz
there are multiple ans possible in a path 
==============================================================     
 fire a node tell how much time will took to fire whole tree   
     void printalldown(TreeNode* root,TreeNode* block,vector<vector<int>>&ans,int dist)
 {
       if(root==NULL||root==block)
       {
           return;
       }
       if(dist==ans.size())
       {
           ans.push_back({});
           
       }
         ans[dist].push_back(root->val);
       printalldown(root->left,block,ans,dist+1);
       printalldown(root->right,block,ans,dist+1);
 }

 int find(TreeNode* root,int key,vector<vector<int>>&ans)
 {
     if(root==NULL)
     {
         return -1;
     }

     if(root->val==key)
     {
         printalldown(root,NULL,ans,0);
         return 1;
     }
     int left=find(root->left,key,ans);
     int right=find(root->right,key,ans);
     
     if(left!=-1)
     {
         printalldown(root,root->left,ans,left);
         return left+1;
     }
       if(right!=-1)
     {
         printalldown(root,root->right,ans,right);
         return right+1;
     }
     return -1;
 }    
========================================================
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
