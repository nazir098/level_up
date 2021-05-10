#include<bits/stdc++.h>
using namespace std;
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int>map;
    vector<int>vec;
    RandomizedSet() {
        vec.push_back(0);
        map[0]=0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map[val]!=0)
        {
            vec.push_back(val);
            map[val]=vec.size()-1;
         return true;
        }
            return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        
        if(map[val]!=0)
        {int ind=map[val];
         int lind=vec.size()-1;
         vec[ind]=vec[lind];        
        vec.pop_back();
         map.erase(val);
         map[vec[ind]]=ind;
         
            return true;
        }
            return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int t=rand()%vec.size()-1;
        
        return vec[t];
    }
};



int solve(string s)
{
	int sign=1;
	int res=0;
	for(int j=0;j<s.size();j++)
	{char ch=s[j];
		if(ch==' ')continue;
		else if(ch=='+')sign=1;
		else if(ch=='-')sign=-1;
		else{
				int num=0;
			while(s[j]>='0'&&s[j]<='9')
			{
				num=num*10+s[j]-'0';
				j++;
			}
			res+=sign*num;
		}
		
	}
	return res;
}


string decode(string s)
{
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
				num=num*10+ ch-'0';
				i++;
				
			}
			i--;
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
		{num=nstk.top()-1;
		string temp=res;
			while(num--)
			res+=temp;
			nstk.pop();
			res= sstk.top()+res;
			sstk.pop();
		}
		
	}
	return res;
}
/*
     string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        string res;
        int num = 0;
        for(char c : s) {
            if(isdigit(c)) {
                num = num*10 + (c-'0');                              
            }
            else if(isalpha(c)) {
                res.push_back(c);                
            }
            else if(c == '[') {
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            }
            else if(c == ']') {
                string tmp = res;
                for(int i = 0; i < nums.top()-1; ++i) {
                    res += tmp;
                }
                res = chars.top() + res;
                chars.pop(); nums.pop();
            }
        }
        return res;
     }*/
     vector<int> Segrigate(vector<int>& A) {
        int ni=-1,pi=0; 
        while(pi<A.size())
        {
            if(A[pi]<0)
                {
				swap(A[++ni],A[pi]);
		
                }
          pi++;
          
           
        }
       
        return A;
    }
   /*  vector<int> Segrigate(vector<int>& A) {
        int ni=-1,pi=0,n=A.size(); 
        while(ni<n&&pi<n)
        {
        	cout<<A.size()<<" ";
            if(A[pi]<0)
                {
				swap(A[++ni],A[pi]);
			
                }
          pi++;
          
           
        }
       
        return A;
    }*/

int main()
{
	 vector<int> a={-1, 2, 3, -4, 5, 6, -7, 8,-9};
	 auto b=Segrigate(a);
	 for(auto el:b)
	 cout<<el<<" ";
}
