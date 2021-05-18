/*Q. rotate by k?

a[]= 3 5 1 6 7 4; k=2-> k can be negative
o/p: 1 6 7 4 3 5
 */ 
#include <iostream>
#include <vector>

using namespace std;
void rotateByK(vector<int> &arr, int r)
{
    int n = arr.size();
    // r %= n;
    // if (r < 0)
    // r += n;

    r = (r % n + n) % n; //it handles negative case also means the effect of k=-2 & a.size=5 === (-2 % 5 + 5)%5 == 3 i.e k=3

    reverse(arr, 0, n - 1);
    reverse(arr, n - r, n - 1);
    reverse(arr, 0, n - r - 1);
}
/////////////////////////////////////////////////////////////////////////////////////////////
/* Q. segrigate negative and positive no.
 -> it can be done using two pointers one at initial point and one at final pooint. but this is not a genreal method
 ->thatswhy we will use quick sort approach
 */

 vector<int> Segrigate(vector<int>& A)
 {
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
    }
///////////////////////////////////////////////////////////
// C++ program to rotate an array by
// d elements using juggling method
#include <bits/stdc++.h>
using namespace std;

//Fuction to get gcd of a and b
int gcd(int a, int b)
{
	if (b == 0)
		return a;

	else
		return gcd(b, a % b);
}

//Function to left rotate arr[] of siz n by d
void leftRotate(int arr[], int d, int n)
{
	/* To handle if d >= n */
	d = d % n;
	int g_c_d = gcd(d, n);
	for (int i = 0; i < g_c_d; i++) {
		/* move i-th values of blocks */
		int temp = arr[i];
		int j = i;

		while (1) {
			int k = j + d;
			if (k >= n)
				k = k - n;

			if (k == i)
				break;

			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
}

// Function to print an array
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function calling
	leftRotate(arr, 2, n);
	printArray(arr, n);

	return 0;
}

//////////////////////////////////////////////////////////
void segregateZeroOne(vector<int> &arr)
{
	int zp=-1,op=0,n=arr.size();
	while(op<n)
	{
		if(arr[op]==0)
			swap(arr[++zp],arr[op]);
		op++;
	}
}
///////////////////////////////////////////////////////////////

    vector<int> segregateZeroOnetwo(vector<int> &arr)
{
	int zp=-1,op=0,n=arr.size(),tw=n;
	while(op<tw)
	{
		if(arr[op]==0)
		{
			swap(arr[++zp],arr[op++]);// op++ is tricky here
			//divide into four regions 000 1111 012010 2222 using 3 pointers i.e zero pointer(zp)
			                             ^    ^        ^
			//whenever we are getting zero than swapping is only occouring with 1 so we must inc op as it will necessarily be 1				     
		}
		else if(arr[op]==2)
		{
		 swap(arr[--tw],arr[op]);// we dont know what comes after swapping like it could be 0/1/2 as coming from undefined region so we need to check again
		}
		else	
		op++;
	}
	return arr;
}

int max_sum(int A[],int N)
{int res=0,sum=0,maxval=0;

 for(int i=0;i<N;i++)
{
    sum+=A[i];//14
    res+=A[i]*i;//11
}

 for(int i=0;i<N;i++)
{ 
    int isum=res-sum + (N*A[i]);//this formula comes by taking example of arr{a, b, c, d}=>0a+ 1b+ 2c +3d so think how it can be converted in 0b+ 1c +2d +3a 
	 
	 //isum: result of each summation
	 //res: sum of previous array

    maxval=max(maxval ,max(isum,res));
    res=isum;
}
return maxval;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//11 container with most water
// it is diff from trap water proble in the sense that while calculating area we are neglecting all the b/w members
// assuming such as they are not present but in case of stack prblm the height of the building was factor
  int maxArea(vector<int>& height) {
        
        int n=height.size();
        int left=0,right=n-1;//this is max range 
	  //after each iteration the range will be shrinking in the search of higher no.
        int res=0;
        while(left<right)
        {
            int width=right-left;
            int area;
            if(height[left]< height[right])
            {
                
               area= width* min(height[left++],height[right]);
            }
            else
            {
                  area= width* min(height[left],height[right--]);
            }
            res=max(res,area);
        }
        return res;
    }
/////////////////////////////////////////////////////////////////////////////////////
//Q. finding kth smallest element in average O(n) time using quickselect
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int findpivot(int arr[],int l,int r)
{
    int piv=r;
    int itr=r-1;
    while(itr>=l)
    {
        if(arr[piv]<arr[itr])
        {
            swap(&arr[itr],&arr[piv-1]);
            swap(&arr[piv],&arr[piv-1]);
            piv--;
        }
        itr--;
    }
    return piv;
}
int kthSmallest(int arr[], int l, int r, int k)
    {
        //k=k-1;
     
        int piv=findpivot(arr,l,r);
           
        if(k-1==piv)
        return arr[k-1];
        
        else if(piv>k)
        return kthSmallest(arr,l,piv-1,k);
        else
        return kthSmallest(arr,piv+1,r,k);
        
        }
/////////////////////////////////////////////////////////////////////////
//Q.3 Longest substring 
//using two pointer method in just 2 pass
//make one variable as indicator if it voilates the condition then shrink the length
//for example cnt here
int lengthOfLongestSubstring(string s) {
        int si=0,ei=0,ans=0,cnt=0;
        int freq[128]={0};
        if(s.size()<1)return s.size();
        while(ei<s.size())
        {
       
            if(freq[s[ei++]]++>0) cnt++;
               
            while(cnt>0)
            {
                if(freq[s[si++]]-->1)cnt--;
            
            }
             ans=max(ans,ei-si);
        }
           return ans;
    }
////////////////////////////////////////////////////////////////////////////
//comprihensible version of above code
int lengthOfLongestSubstring(string s) {
        int si=0,ei=0,ans=0,cnt=0;
        int freq[128]={0};
        if(s.size()<1)return s.size();
        while(ei<s.size())
        {
       
            if(freq[s[ei]]==1) cnt++;
              
            freq[s[ei]]++;
            ei++;
            
            while(cnt>0)
            {
                if(freq[s[si]]==2)cnt--;
                
                freq[s[si]]--;
                si++;
            
            }
             ans=max(ans,ei-si);
        }
           return ans;
    }
////////////////////////////////////////////////////////////
//https://www.lintcode.com/problem/longest-substring-with-at-most-two-distinct-characters/description
//Q. Longest substring with atmost 2 distinct charachter  
 int lengthOfLongestSubstring(string s) {
        int si=0,ei=0,ans=0,cnt=0;
        int freq[128]={0};
        if(s.size()<1)return s.size();
        while(ei<s.size())
        {
       
            if(freq[s[ei]]==1) cnt++;
              
            freq[s[ei]]++;
            ei++;
            
            while(cnt>0)
            {
                if(freq[s[si]]==2)cnt--;
                
                freq[s[si]]--;
                si++;
            
            }
             ans=max(ans,ei-si);
        }
           return ans;
    }
/////////////////////////////////////////////////////
//Q. 76
//substr() parameters are 1.starting index(included) 2. length of required string
//EX: string s1 = "Geeks";
//string r = s1.substr(3, 2);
//cout << "String is: " << r;
//O/P: ks
string minWindow(string s, string t) {
        int sn=s.length();
        int tn=t.length();
        if(sn<tn)
        {return "";}
        int freq[128]={0};
        int si=0;
        int ei=0;
        for(char ch:t)
        {
            freq[ch]--;
            
        }
        int count=tn;
        int len=INT_MAX;
        int gsi=0;
        
        while(ei<sn)
        {
            if(freq[s[ei++]]++<0)
            {count--;}
           
            
            while(count==0)
            {
                if(ei-si<len)
                {   gsi=si;
                    len=ei-si;
                    
                }
                
                if(freq[s[si++]]--==0)
                {
                    count++;
                }
                
            }
            
        }
      
        return len==(INT_MAX)?"":s.substr(gsi,len);
    }
////////////////////////////////////////////////////////////////////////
https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
1456

https://www.lintcode.com/en/old/problem/longest-substring-with-at-most-k-distinct-characters/

https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
340
1456
//////////
1. https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
2. 340
3. 1456
4. 992
5. 1248
6. https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
