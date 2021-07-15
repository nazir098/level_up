19. Remove Nth Node From End of List
    // when head itself is potential ans then its hint that we
    // can take a dummy node
    
    ListNode* getlength(ListNode* head,int n)
    {
        if(head==nullptr||head->next==nullptr)return nullptr;
        
        ListNode* dummy=new ListNode(-1);
       
        ListNode* curr=dummy;
        ListNode* forw=dummy;
        dummy->next=head;
  
        while(n-->0)
        {
            
            forw=forw->next;
        }
     
       
        while(forw!=nullptr&&forw->next!=nullptr)
        {
           
            forw=forw->next;
            curr=curr->next;
        }
    
        if(forw==nullptr)return dummy->next;
        curr->next=curr->next->next;
        return dummy->next;
    }
2. Add Two Numbers
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1==nullptr||l2==nullptr)
            return l1==nullptr?l2:l1;
        
        int carry=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* head=dummy;
        while(l1!=nullptr||l2!=nullptr||carry!=0)
        {
            int val1=l1!=nullptr?l1->val:0;
            int val2=l2!=nullptr?l2->val:0;
            int sum=(val1 +val2 + carry);
            carry=sum/10;
            cout<<sum<<" ";
            head->next=new ListNode(sum%10);
            
            head=head->next;
            if(l1!=nullptr)
            l1=l1->next;
            if(l2!=nullptr)
            l2=l2->next;
            
        }
        l1==nullptr?head->next=l2:head->next=l1;
        return dummy->next;
    }
