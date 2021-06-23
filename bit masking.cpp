concepts:
1<<k==2^k
y=n & n-1 => remove the first one from left side 
p=n & -n => it makes the first 1 to 1 and rest of the thing will be zero
n= y|p =>we will get the same no.

bits as boolean array
kth index, arr[k]           ==1<<k
arr[k]=true                 == arr|= mask
arr[k]=false                == arr &= (~mask)
set and reset from same exp
                               arr^=mask
//191. Number of 1 Bits
int hammingWeight(uint32_t n) {
        int i=0;
        int cnt=0;
        while(n!=0)
        {
            if(n&(1))
                cnt++;
            n=n>>1;
       
        }
        return cnt;
    }
    ////////////////
 int hammingWeight(uint32_t n) {
         int count = 0;
        while (n != 0) 
        {
            count++;
            n &= (n - 1);
        }

        return count;
    }
    //////////////////////////////////////////////////////////
    338. Counting Bits
  vector<int> countBits(int n) 
  {      
        vector<int>ans(n+1,0);
        for(int i=0;i<=n;i++)
        {
            int div=i/2;
            int rem=i%2;
            ans[i]=ans[div]+rem;
        }
        return ans;
    }
    /////////
    using bitwise opn
    we know n & n-1 reduces no. of 1 bit by one from n
    so a[n]=a[n & n-1];
    countBits(int num) 
    {    vector<int>(num + 1,0);
        for (int i = 1; i <= num; i++) 
        {
            ans[i] = ans[i & (i - 1)] + 1;
        }

        return ans;
    }
    ///////////////////////////////////////////
    136. Single Number
     int singleNumber(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            ans=ans^nums[i];
        }
        return ans;
    }
    /////////////////////////////////////////
    342. Power of Four
       bool isPowerOfFour(int n) {
        if(n<1)return false;
        
        if((n &(n-1))==0)
        {
             int mask=1;
            for(int i=0;i<32;i++)
            {
                 
                if(((mask<<i) & n))
                {
                    if(i%2==0)
                    return true;
                }
            }
        }
        return false;
    }
    ///////////////////////////////////////////
    78. Subsets
        vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        int possible_set=1<<n;
        
        for(int i=0;i<possible_set;i++)
        {
            vector<int>tem;
            for(int j=0;j<n;j++)
            {
                if((1<<j)&i)
                    tem.push_back(nums[j]);
            }
            ans.push_back(tem);
        }
        return ans;
    }
