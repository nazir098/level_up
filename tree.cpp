 MOST imp question 
 binary tree to BST

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

-> lca   236. Lowest Common Ancestor of a Binary Tree  
if one present in left side and another is in right side or 2 more cases are 
possible try to impliment those two case then u will be done
   bool lca( TreeNode* root,TreeNode* first,TreeNode* second,TreeNode* &ans)
    {
        if(root==nullptr)
            return false;
        bool self=false;
        if(root==first||root==second)
            self=true;
        
        bool left=lca(root->left,first,second,ans);
        bool right=lca(root->right,first,second,ans);
        
        if(left && right){
             ans=root;
            return true;
        }
        if(self&&right){
            ans=root;
            return true;
        }
        
        if(self&&left){
            ans=root;
            return true;
        }
           
        
        return self||left||right;
            
        
    }
========================================================
   ->LCA in binary search tree
 bool llca(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans)
    {
        
        while(root!=nullptr)
        {
            if(root->val<p->val&&root->val<q->val)
                root=root->right;
            else if(root->val>p->val&&root->val>q->val)
                root=root->left;
            else
                break;
                
        }
        ans=root;
        return true;
        
    }
==============================================================
98. Validate Binary Search Tree
//if you do without flag you will get error

    bool isValidBST(TreeNode* root) {
        TreeNode* curr=root;
        long prev=-(long)1e13;
        bool flag=true;
        while(curr!=nullptr)
        {
            TreeNode* le=curr->left;
         
               
            if(le==nullptr)
            {
                if(prev>=curr->val)
                    {flag=false;}
                prev=curr->val;
                curr=curr->right;
                
            }
            else
            {
                TreeNode* rmn=rightmost(le,curr);
                if(rmn->right==nullptr)
                {
                    rmn->right=curr;
                    curr=le;
                    
                }
                else
                {
                     rmn->right=nullptr;
                    if(prev>=curr->val)
                        flag=false;
                    prev=curr->val;
                    curr=curr->right;
                 
                }
            }
            
        }
        return flag;
        
==============================================================
->Binary Tree to DLL
only three lines need to add , think what that could be
it is just a track of prev node :)

if u see carefully then at the end prev is pointing to the last node
of the tree

    Node * bToDLL(Node *root)
    {
        
       stack<Node*>st;
       allleft(root,st);
       
       Node* dummy=new Node;
       dummy->right=dummy->left=nullptr;
       Node* prev=dummy;
       while(st.size()!=0)
       {
           Node* curr = st.top();
           st.pop();
           
           prev->right=curr;
           curr->left=prev;
           
           prev=curr;
           
           allleft(curr->right,st);
           
       }
       Node* head=dummy->right;
       dummy->right=dummy->right->left=nullptr;
        return head;
 ===========================     
 // using morrison traversal method      
        Node* curr=root;
        Node* dummy= new Node;
         dummy->data=-1;
        dummy->right=dummy->left=nullptr;
       
      
Node* prev=dummy;
while(curr!=nullptr)
{
    Node* le= curr->left;
    if(le==nullptr)
    {
        prev->right=curr;
        curr->left=prev;
        prev=curr;
        curr=curr->right;
    }
        else
        {
            Node* rmn=rightmost(le,curr);
            if(rmn->right==nullptr)
            {
                rmn->right=curr;
                curr=curr->left;
            }
                else
                {
                    rmn->right=nullptr;   //link break
                    
                    prev->right=curr;     //link create
                    curr->left=prev;
                    
                    prev=prev->right;      //shifting of pointers
                    curr=curr->right;
                }
                
            }
 }
    Node* head=dummy->right;
    dummy->right=head->left=nullptr;
    return head;
===============================================================      
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
