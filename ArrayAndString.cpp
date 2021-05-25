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
                if(ei-si<len)        //why inside loop? coz min is req and we cant find min at all iteration, ans would be wrong
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
///////////////////////////////////////////////////////////////////////
// Q. https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
//smallest window of itself return a substring
string findSubString(string str)
    {
        int fre[128]={0};
        int si=0,ei=0,len=INT_MAX,cnt=0;
        int gsi=0;
        for(int i=0;i<str.size();i++)
        {
            if(fre[str[i]]==0){
                fre[str[i]]=1;
                cnt++;
            }
        }
        while(ei<str.size())
        {
            if(fre[str[ei++]]-->0)
            cnt--;
            while(cnt==0)
            {
                if(len>ei-si)
                {
                    len=ei-si;
                    gsi=si;
                }
                if(fre[str[si++]]++==0)
                cnt++;
            }
            
        }
        return len==INT_MAX?"":str.substr(gsi,len);
    }
////////////////////////////////////////////////////////////////////////
//Q.1456. Maximum Number of Vowels in a Substring of Given Length

bool isvowel(char c)
    {
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    
    int maxVowels(string s, int k) {
        if(k==0)return 0;
        int ei=0,si=0,len=0,vowel=0;
        while(ei<s.size()){
        if(isvowel(s[ei++]))
        {
            vowel++;
            
        }
        while(ei-si>k)
        {
            if(isvowel(s[si++]))
                vowel--;
        }
        len=max(len,vowel);
    }
        return len;
    }
////////////////////////////////////////////////////////////////////////
//Q. 340. Longest Substring with At Most K Distinct Characters

int lengthOfLongestSubstringKDistinct(String s, int k)
{
	if(s.size()<=k)return s.size();
	int ei=0 , si=0, len=0,cnt=0;
	int fre[128]={0};
	int n=s.size();
	
	while(ei<n)
	{
		if(fre[s[ei++]]++==0)
			cnt++;
		
		while(cnt>k)
		{
			if(fre[s[si++]]--==1)
				cnt--;
		}
		
		len=max(len,ei-si);
	}
	return len;
		
}

////////////////////////////////////////////////////////////////////////
//Q. Count all subarrays with atMost k Different Integers.
// It is trickier one coz we are adding not replacing the value of cnt
// one line change from above code
int CntAtMostKDistinct(vector<int>&s, int k)
{
	int ei=0, si=0, cnt=0, n=s.size();
	unordered_map<int , int>fre;
	
	while(ei<n)
	{
		                          /*if(fre[s[ei++]]++==0) it works also fine 
			                            cnt++;*/
		fre[s[ei++]]++;
		
		while(fre.size()>k)
		{
			if(fre[s[si++]]--==1)
				fre.erase(si-1);  //mind it (si-1)
		}
		
	//n(n+1)/2 =1+2+3+4+5	
		
		len=len +(ei-si);  //only here chnges from above code
	}
	return len;
}

//////////////////////////////////////////////////////////////////////
Q.904. Fruit Into Baskets
//length of longest substring having exact 2 distinct elements 
//Input: [0,1,2,2]
//Output: 3
//Explanation: We can collect [1,2,2].
//If we started at the first tree, we would only collect [0, 1].

int totalFruit(vector<int>& tree)
  {
        int n=tree.size();
        if(n<=2)return n;
        
        int si=0,ei=0,cnt=0,ans=0;
        unordered_map<int ,int>fre;
        
        while(ei<n)
        {
            fre[tree[ei++]]++;
            
            while(fre.size()>2)
            {
                if(fre[tree[si++]]--==1)
                    fre.erase(tree[si-1]);
            }
            ans=max(ans,ei-si);
        }
        return ans;
    }

///////////////////////////////////////////////////////////////////////
// why we cant find directly k distinct element ??why atmost(K)-atmost(k-1)??
//we know that n no. will have n(n+1)/2 substring but there is condition applied that you can select only k distinct/exact  elements
//For getting soln we can make a window which have only k distinct/exact elements 
//how you are adding the count is subjected to the condition in given question

//Q. Count of subarrays having exactly K distinct elements
//make a window that have exact k distinct ele in mean time if some elements are repeating you can drop it (with storing cnt of drop)
//then no. of dropped elements tells current window can have that much extra combination of sub string
//eg : 1 1  2 1
            ^ ^this is our window then CntofDrop=2 => CntofDrop + 1(window itself)
//this CntofDrop will only reset when there is break in string means Nodistinct>k

int CntExactKDistinct(vector<int>&s, int k)
{
	int ei=0, si=0, cnt=0, n=s.size(),dropped=0,ans=0;
	unordered_map<int , int>fre;
	
	while(ei<n)
	{
		                        
		fre[s[ei++]]++;
		
		if(fre.size()>k)   //it has having only distict character like =>1 2 3 for k=2 not =>1 1 2 3
		{
			if(fre[s[si++]]--==1);//it will always be true
				fre.erase(s[si-1]);
			dropped=0;
	         }
		
                  while(fre[s[si]]>1)
		{
		    fre[s[si++]]--;
		    dropped++;
		 
		}
		if(fre.size()==k)  //if our window have k distinct element but it contains more repeated elements then we add always dropped +1 => 1 2 1 1 1
			ans+=dropped+1;                                                                                                            ^ ^  _____>in this scenario we are adding
	}
	return ans;
}
///////////////////////////////////////////////////////////////////////
// 1248. Count Number of Nice Subarrays
// 1st approach is to use atMostOdd(k)-atMostOdd(k-1)
// 2nd approach is sliding window for exact distinct

public int atMostOdd(vector<int>&arr, int k)
{
        int n = arr.size(), si = 0, ei = 0, count = 0, ans = 0;
        while (ei < n) {
            if ((arr[ei++] & 1) != 0)
                count++;

            while (count > k)
	    {
                if ((arr[si++] & 1) != 0)
                    count--;
            }

            ans += ei - si;
        }

        return ans;
 }
int numberOfSubarrays(vector<int>& nums, int k) 
{
	return atMostOdd(nums,k) - atMostOdd(nums,k-1);
}
////////
int numberOfSubarrays(vector<int>& nums, int k) {
        int si=0,ei=0,cnt=0,ans=0,dropped=0;
        
        
        while(ei<nums.size())
        {
          
            if(nums[ei++]&1)
                cnt++;
            if(cnt>k)  //you can use while loop also but its sure that it will excute only once
            {
                 
                if((nums[si]&1)==0) //you can use while loop also but its sure that it will excute only once
                    si++;
                si++;
                cnt--;                //this block is same when we find atmost k distinct
                dropped=0;
            }
		
           while((nums[si]&1)==0 and si<ei) //please put bit operation in bracket
            {
                si++;
                dropped++;          //this block, storage of dropped elements
            }
            
            if(cnt==k)
            { ans+=dropped+1;      //this block is like adding extra repeated elements that can result as a combination of windowed substring
             
            }
            
        }
        return ans;
    }
////////////////////////////////////////////////////////////////////////
//Q.930. Binary Subarrays With Sum
// it is based on the principle of prefix sum, agr ek indx pe prefix sum x h ar ek jgh pe prefix y h
// sath m ek condition satisfy ho rhi h=> x+k=y iska mtlb x ar y k bich m ek asa subarray exist krta h jiska 
// sum k h
// 1.aprroach using hashmap prefix sum
// 2.using sliding window , for exact k distinct
// 3.atmost(arr,goal)-atmost(arr,goal-1)
    int numSubarraysWithSum(vector<int>arr, int goal) {
  
	int ei=0, si=0, cnt=0, n=arr.size() ,ans=0,sum=0;
    unordered_map<int,int>fre;
	fre[0]=1;
	while(ei<n)
	{
		 sum=sum+arr[ei++];
            ans+=fre[sum-goal];
            fre[sum]++;
	}
	return ans;

    }
   ///////////////// 
  int numSubarraysWithSum(vector<int>& nums, int goal)
  {
        int start=0,end=0,pre=0,sum=0,ans=0;
        
        while(end<nums.size())
        {
            if(nums[end]==1)
            {
                sum++;
            }
            
            if(sum>goal)
            {
                while(nums[start]!=1)
                {
                    start++;
                }
                start++;
                pre=0;
                sum--;
            }
            
            while(start<end&&nums[start]==0)
            {
                pre++;
                start++;
            } 
            
            if(sum==goal&&start<=end)
               ans+=pre+1;
            end++;
        }
        
        
        return ans;
        
    }
////////////////////////////////////////////////////////////////////////
485. Max Consecutive Ones

int findMaxConsecutiveOnes(vector<int> &nums)
{
        int n = nums.size(), si = 0, ei = 0, len = 0, count = 0;
        while (ei < n) 
	{
            if (nums[ei++] == 0)
                count++;

            while (count == 1) {      //jse hi zero aya hme shrink krna basically si ar ei ek pas aa jayenge
                if (nums[si++] == 0)
                    count--;
            }

            len = max(len, ei - si);
        }
        return len;
    }
//////////////
int findMaxConsecutiveOnes(vector<int>& nums)
{
        int ei=0,cnt=0,ans=0;
        
        while(ei<nums.size() )
        {
            if(nums[ei++]==1)
                cnt++;
            else
                cnt=0;
            
            ans=max(ans,cnt);
        }
        return ans;
  }
////////////////////////////////////////////////////////////////////////
//Q.930. Subarrays With Sum==target
// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: 
// The 4 subarrays are bolded below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// brute force approach is to find all sum substring and compare with goal
//another approach is atmostsum(target-1)-atmostsum(target)
// another approach is sliding window as used in exact distinct element

////////////////////////////////////////////////////////////////////////

340
1456
//////////
1. https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
2. 340
3. 1456
4. 992
5. 1248
6. https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
