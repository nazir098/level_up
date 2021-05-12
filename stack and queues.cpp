//394
string decodeString(string s) {
        stack<string>sstk;
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
    
  /////////////////////////////////////////////////////////////////////////////////////////  
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
	
///////////////////////////////////////////////////////////////////////////	
	//23 merge k sort list
	will be doing after linked class
	//632
	will have to do
////////////////////////////////////////////////////////////////////////////		
//895
//sir has used pair we can use vector also and write own comp class
//another method is using frquency as index and on that index make a stack
//this question has been moved to hasmap		

//Infix to Postfix
 int prec(char c)
        {
            if(c=='+'||c=='-')
            return 1;
            else if(c=='*'||c=='/')
            return 2;
            else if(c=='^')
            return 3;
            else 
            return 0;
        }
    string infixToPostfix(string s)
    {
        
        stack<char>st;
        string str ="";
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
            str+=s[i];
            else if(s[i]=='(')
            st.push(s[i]);
            else if(st.size()!=0&&s[i]==')')
            {
                while(st.size()!=0&&st.top()!='(')
                {str+=st.top();
                
                    st.pop();
                }
                
                st.pop();
            }
            
            else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
            {
              while(st.size()!=0&&prec(s[i])<=prec(st.top()))
                    {str+=st.top();;st.pop();}
                    st.push(s[i]);
                
            }
        }
        
        while(st.size()!=0)
        {
           str+=st.top();
            st.pop();
        }
       
/////////////////////////////////////////////////////////////////////
//227 basic calc 2	 
//this question is based on infix to postfix diff only here we are evaluting no. at the same time
//catch is using long to num variable	    
int eval(int a,int b,char c)
    {
        if(c=='+')return a+b;
        else  if(c=='-')return a-b;  
        else  if(c=='*')return a*b;  
        else  if(c=='/')return (a/b);  
        else return -1;  
 
    }
    int pre(char c)
    {
        if(c=='+'||c=='-')return 1;
        else if(c=='*'||c=='/')return 2;
        else 
            return 0;
    }
    int calculate(string s) {
        long num=0;
        stack<int>st;
        stack<int>op;
        long res=0;
        for(int i=0;i<s.size();i++)
        {
            
            char ch=s[i];
            if(ch==' ')continue;
            if(ch>='0'&&ch<='9')
            {num=0;
                while(i<s.size()&&s[i]>='0'&&s[i]<='9')
                {
                    num=num*10+s[i]-'0';
                    i++;
                }
                i--;
                st.push((int)num);
            }
            else{
                
                  while(op.size()!=0&&pre(ch)<=pre(op.top()))
                    {cout<<"res"<<res;
                    int b=st.top();st.pop();
                    int a=st.top();st.pop();
                    char c=op.top();op.pop();
                    res=eval(a,b,c);
                      
                    st.push(res);
                    }
               
                  op.push(ch);
                }
          
              
        }
          while(op.size()!=0)
                {
                    int b=st.top();st.pop();
                    int a=st.top();st.pop();
                    char c=op.top();op.pop();
                    res=eval(a,b,c);
                    st.push(res);
                }
    return st.top();
    }	    
///////////////////////////////////////////////////////////
//636 exclusive time function
 vector<int> breaked(string s)
    {  vector<int>vec(3,0);
     int id=0;
     int  type;
     int ctime=0;
     int i=0;
        while(i<s.size())
    {
              
             while(s[i]!=':')              //loop for getting id
            {
                id=id*10+s[i]-'0';
                i++;
            }
            i++;
            
            s[i]=='s'?type=0:type=1;      //its starting point or not
         
            while(s[i]!=':')i++;          // moving towards current time      
            
            i++;
             while(i<s.size())            //getting current time
                {
                    ctime=ctime*10 +s[i]-'0';
                    i++;
                }
        
    }  
     vec[0]=id;
     vec[1]=type;
     vec[2]=ctime;
       return vec;     
            
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int>st;
        vector<int>vec(n,0);
        int ltime=0;
        for(string el:logs)
        {
            auto info=breaked(el);
            int id=info[0];
            int ctime=info[2];
            int type=info[1];
            
            if(type==0)
            {
                if(!st.empty())
                {
                     vec[st.top()]=vec[st.top()]+ctime-ltime;
                }
                st.push(id);
                ltime=ctime;                       //starting point is inclusive
            }
            else
            {
                vec[id]=vec[id]+ctime-ltime+1;
                ltime=ctime+1;                     //ending point is exclusive
                st.pop();
            }
        }
        return vec;
    }
//////////////////////////////////////////////////////
//84 largest rectangle in a histogram
//in stack for an element the downwarth element is there lower limit and coming smaller no. is their expansion limit
 int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    st.push(-1);
    int maxArea = 0;

    int i = 0;
    while (i < n)
    {
        while (st.top() != -1 && heights[st.top()] >= heights[i])
        {
            int idx = st.top();
            st.pop();

            int h = heights[idx];
            int w = i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }

        st.push(i++);
    }

    while (st.top() != -1)
    {
        int idx = st.top();
        st.pop();

        int h = heights[idx];
        int w = n - st.top() - 1;
        maxArea = max(maxArea, h * w);
    }

    return maxArea;
}
////////////////////////////////////////////////////////////////
//85 maximal rectangle
 int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0)return 0;
        int n=matrix[0].size();
        vector<int>vec(n,0);
        int maxval=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                    vec[j]+=1;
                else
                    vec[j]=0;
            }
            maxval=max(largestRectangleArea(vec),maxval);
        }
        return maxval;
    }	    
