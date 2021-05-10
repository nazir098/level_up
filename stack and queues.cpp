//394
string decodeString(string s) {
      /*  stack<string>sstk;
	stack<int>nstk;
	string res="";
	int num=0;
	
	for(int i=0;i<s.size();i++)
	{
		char ch=s[i];
        
		if(ch>='0'&&ch<='9')
		{
			while(i<s.size()&&(s[i]>='0'&&s[i]<='9'))
			{
				num=num*10+ s[i]-'0';
				i++;
			}
			i--;//while loop increses it by one
		}
		else if(ch>='a'&&ch<='z')
		res+=ch;
		else if(ch=='[')
		{
			sstk.push(res);
			nstk.push(num);
			res="";
			num=0;
		}
		else if(ch==']')
		{
            num=nstk.top()-1;// we have allready one string in your so reduce iteration by 1 
          
          nstk.pop();
	      	string temp=res;
			while(num--){
                res+=temp;
    
            }
			res= sstk.top()+res;
			sstk.pop();
              
           num=0;// this assignment is necessary so that if num becomes -1 then in while loop it will be -1*10+ ch -'0'
		}
		
	}
	return res;
    }
    
    
    //295 my sln ->always pushing to the left side 1 condn to move from left to right and 1 condn to swap-> expecting result from left side 
    priority_queue<int>maxPQ;
    priority_queue<int,vector<int>,greater<int>>minPQ;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
    left.push(num);
        if((left.size()-right.size())>1)
        {//left to right
            int t=left.top();
            left.pop();
            right.push(t);
        }
        else if((left.size()-right.size())==1&&right.size()>0)
        {
            if(left.top()>right.top()){//swap
            right.push(left.top());left.pop();
            left.push(right.top());right.pop();
            }
           
                
        }
    }
    
    double findMedian() {
  if(left.size()==right.size())
      return (double) (left.top()+right.top())/2;
        
        
            return left.top();
    }
    // sir's soln
     void addNum(int num) {
            if (maxPQ.size() == 0 || num <= maxPQ.top())
                maxPQ.push(num);
            else
                minPQ.push(num);

            if (maxPQ.size() - minPQ.size() == 2)
            {minPQ.push(maxPQ.top()); maxPQ.pop();}
            if (maxPQ.size() - minPQ.size() == -1)
            {maxPQ.push(minPQ.top());minPQ.pop();}
        }

        double findMedian() {
            if (maxPQ.size() == minPQ.size())
                return ((maxPQ.top() + minPQ.top()) / 2.0);
            else
                return maxPQ.top() * 1.0;
        }
	
	
	//23 merge k sort list
	will be doing after linked class
	//632
	will have to do
