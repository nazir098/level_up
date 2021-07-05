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
