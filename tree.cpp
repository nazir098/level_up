 MOST imp question 
 binary tree to BST
 ->sort the inorder traversal and then SDLL->BST
   ->this method is not inplace and it wont give exact structure of tree
->BT->DLL->SDLL->BST
  ->this is how we can do inplace  

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
99. Recover Binary Search Tree
       TreeNode* rightmost(TreeNode* left,TreeNode* curr)
    {
        while(left->right!=nullptr&&left->right!=curr)
        {
            left=left->right;
        }
        return left;
    }
void fun(TreeNode* root)
  {
      TreeNode* firsterror=nullptr;
      TreeNode* seconderror=nullptr;
    
      
      TreeNode* pre=new TreeNode(INT_MIN);
     
      TreeNode *curr=root;
    
        while(curr!=nullptr)
            {
                auto left=curr->left;
               
                if(left==nullptr)
                {   
                     if(pre->val>curr->val)
                     {
                         if(firsterror==nullptr)
                             firsterror=pre;
                         seconderror=curr;
                     }
                    pre=curr;
                    curr=curr->right;
                }
                else
                {
                    auto rmn=rightmost(left,curr);
                    if(rmn->right==nullptr)
                    { rmn->right=curr;
                      curr=curr->left;
                    }
                    else
                    {
                       if(pre->val>curr->val)
                        {
                         if(firsterror==nullptr)
                             firsterror=pre;
                         seconderror=curr;
                        }
                     
                        pre= curr;
                        rmn->right=nullptr;
                        curr=curr->right;                      
                    }

                }
            }
    int t=firsterror->val;
    firsterror->val=seconderror->val;
    seconderror->val=t;
        
    }
    void recoverTree(TreeNode* root) {
       
 fun(root);

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
==============================================================
->construction set
===================================
Construct Binary Search Tree from Preorder Traversal
    TreeNode* fun(vector<int>& pre,int &ind,int lr,int rr)
    {
        if(ind>=pre.size()||pre[ind]>rr||pre[ind]<lr)
            return nullptr;
        TreeNode* root=new TreeNode(pre[ind]); 
        ind++;
        
        root->left=fun(pre,ind,lr,root->val);
        root->right=fun(pre,ind,root->val,rr);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       int ind=0;
 
       return fun(preorder,ind,-1e9,1e9);
        
==============================================================
Construct Tree from Inorder & Preorder
     int pi=0;
    int getind(int in[],int n,int ins,int ine)
    {
        for(int i=ins;i<=ine;i++)
        {
            if(in[i]==n)
            return i;
        }
        return -1;
    }
    
    
    Node* fun(int in[],int pre[],int n,int &pi,int ins,int ine)
    {
        if(ins>ine||pi>=n)
        return nullptr;
        
       int ind=getind(in,pre[pi],ins,ine);
       
       Node* root=new Node(pre[pi]);
       pi++;
       root->left=fun(in,pre,n,pi,ins,ind-1);
       root->right=fun(in,pre,n,pi,ind+1,ine);
       
       return root;
       
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        if(n==0)return nullptr;
       
       return fun(in,pre,n,pi,0,n-1);

==============================================================
Tree from Postorder and Inorder
  int getind(int in[],int n,int ins,int ine)
    {
        for(int i=ins;i<=ine;i++)
        {
            if(in[i]==n)
            return i;
        }
        return -1;
    }
    
    
    Node* fun(int in[],int post[],int n,int &pi,int ins,int ine)
    {
        if(ins>ine||pi<0)
        return nullptr;
        
       int ind=getind(in,post[pi],ins,ine);
       
       Node* root=new Node(post[pi]);
       pi--;
       root->right=fun(in,post,n,pi,ind+1,ine);
       root->left=fun(in,post,n,pi,ins,ind-1);
       
       
       return root;
       
    }
Node *buildTree(int in[], int post[], int n) {
    int ind=n-1;
    return  fun(in,post,n,ind,0,n-1);
}
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
===================================================================
987. Vertical Order Traversal of a Binary Tree
use of priority queue
    void width(TreeNode* root,int hl,vector<int>&ans)
    {
        if(root==nullptr)return;
        
        ans[0]=min(ans[0],hl);
        ans[1]=max(ans[1],hl);
        
        width(root->left,hl-1,ans);
        width(root->right,hl+1,ans);
    }
    
   class vpair{
       public:
       int vl;
       int hl;
       TreeNode* node;
       
       vpair(int hl,int level,TreeNode* nod)
       {
          this->hl=hl;
           vl=level;
           node=nod;
       }
   };
    
    class comp{
        public:
        bool operator()(vpair &el1, vpair &el2)
        {
            int hl1=el1.hl;
            int vl1=el1.vl;
            int val1=el1.node->val;
            
            int hl2=el2.hl;
            int vl2=el2.vl;
            int val2=el2.node->val;
            
            if(hl1==hl2)
            {
                if(vl1==vl2)
                {
                    return val1>val2;
                }
                else
                    return vl1>vl2;
            }
            else
                return hl1>hl2;
            
        }
    };
    //hl: horizontal level
    //vl: vertical level
    vector<vector<int>> vertical(TreeNode* root)
    {
        vector<int>ans(2,0);
        width(root,0,ans);
        vector<vector<int>>res(ans[1]-ans[0]+1);
        
        priority_queue<vpair,vector<vpair>,comp>que;
      
        que.push(vpair(0,abs(ans[0]),root));
        
        while(que.size()!=0)
        {
          int size= que.size();
            
            while(size-->0)
            {
                auto rn=que.top();que.pop();
                auto rnvl=rn.vl;
                auto rnn=rn.node;
                auto rnhl=rn.hl;
                
                res[rnvl].push_back(rnn->val);
                
                 if(rnn->left!=nullptr)
                    que.push(vpair(rnhl+1,rnvl-1,rnn->left));
                
                  if(rnn->right!=nullptr)
                    que.push(vpair(rnhl+1,rnvl+1,rnn->right));
                
               
                              
        
            }
         
        }
 return res;
        
    }
