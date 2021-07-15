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
