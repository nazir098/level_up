combination and subsequence is same 
permutation is all combination
P>C
In combination element is clubbed from the right side only
but in permutation all element is taken except the  used element 
collection of some element from a bunch is combination

//top to bottom
int firstidx(vector<int>arr,int idx,int data)
{
	if(idx==arr.size())
	return -1;
	else if(arr[idx]==data)
	return idx;
  
	int next=0;                       //last 3 line can be written in one like 
  next=firstidx(arr,idx+1,data);   //return firstidx(arr,idx+1,data);
	return next;
}

int lastidx(vector<int>arr,int idx,int data)
{
	if(idx==arr.size())       //you can iterate from last
	return -1;
  
	int idx_from_top=lastidx(arr,idx+1,data);
	if(idx_from_top!=-1)
	return index;
  
	if(arr[idx]==data)
	return idx;

	return idx_from_top;
}

vector<int> allIndex(vector<int> &arr, int idx, int data, int count)
{
	if(idx==arr.size())
	{
		vector<int>base(count,0);
		return base;
	}
		if(arr[idx]==data)
	count++;
	auto ans=allIndex(arr,idx+1,data,count);
	if(arr[idx]==data)
	ans[count-1]=idx;
	
	return ans;
	
}
//bottom to top
//you will have to pass the array in argument to store the result
int subseq(string &str, int idx, string ans, vector<string> &res)
{
	if(idx==str.size())
	{
		res.push_back(ans);
		return 1;
	}
	int count=0;
	count=subseq(str, idx+1,  ans+str[idx],  res);
	count+=subseq(str, idx+1,  ans,  res);
	return count;
}
//coin change method to find subsequence
int Subsequence_coin(string str,string ans,int ind)
{
	cout<<ans<<endl;
	if(ind==str.size())
	{
          return 1;
	}

	int count=0;
	for(int i=ind;i<str.size();i++)
	{ 
		count+=Subsequence_coin(str,ans+str[i],i+1);
	}

return count;
}
///////////////
//78. Subsets: make a tree diagram analyze the need of pop_back in it
//coin change method
void subseq(vector<int>arr,vector<int>asf,vector<vector<int>>&ans,int ind)
    {
        ans.push_back(asf);
        if(ind==arr.size())
        {
            return;
        }
        for(int i=ind;i<arr.size();i++)
        {
            asf.push_back(arr[i]);
            subseq(arr,asf,ans,i+1);
            asf.pop_back();
        }
    }
   //subsequence method
void subseq(vector<int>arr,vector<int>asf,vector<vector<int>>&ans,int i)
{
        
      if(i==arr.size())
    {
    ans.push_back(asf);
    return;
   }
         
    asf.push_back(arr[i]);
    subseq(arr,asf,ans,i+1);
    asf.pop_back();
    subseq(arr,asf,ans,i+1);     
    }
//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
//simple version of flood fill
//no need of visited array we can use given matrix as visited array
//visited array is only and only for marking of travlled path means where there is block element you will never go there
//thats why you will mark only the path and unmark only the path
int fun(vector<vector<int>>&mat,int sr,int sc,int er,int ec,vector<string >&ans,string psf)
{
	if(sr==er&&sc==ec)
	{
		ans.push_back(psf);
		return 1;
	}
	int count=0;
	mat[sr][sc]=0;
	
	if(sr+1<=er&&mat[sr+1][sc]==1)
	count+=fun(mat,sr+1,sc,er,ec,ans,psf+"D");
	
	if(sc-1>=0&&mat[sr][sc-1]==1)
	count+=fun(mat,sr,sc-1,er,ec,ans,psf+"L");
	
	if(sc+1<=ec&&mat[sr][sc+1]==1)
	count+=fun(mat,sr,sc+1,er,ec,ans,psf+"R");
	
	if(sr-1>=0&&mat[sr-1][sc]==1)
	count+=fun(mat,sr-1,sc,er,ec,ans,psf+"U");
	

	mat[sr][sc]=1;
	
	return count;
}
    vector<string> findPath(vector<vector<int>> &mat, int n) {
    int sr=0,sc=0,er=n-1,ec=n-1;
	vector<string>ans;
    if(mat[0][0]==0||mat[n-1][n-1]==0)
    return ans;
	string psf="";
	int t=fun(mat,sr,sc,er,ec,ans,psf);
	return ans;
    }
/////////////////////////////////////////////////////////////////////////////////////
complex version of flood fill
https://www.geeksforgeeks.org/rat-in-a-maze-with-multiple-steps-jump-allowed/
matrix element will tail u how large u can make jump
first loop should of direction coz of that we can stop our extra call
second loop radius so that we increment in one direcn again and again whenever encounter out of bound just break from there


////////////////////////////////////////////////////////////////////////////////////////
int permutationUnique2(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    char prev = '$';
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (prev != ch)
        {
            string ros = str.substr(0, i) + str.substr(i + 1);
            count += permutationUnique2(ros, ans + ch);
        }
        prev = ch;
    }

    return count;
}
//////////////
//40. Combination Sum II
void combin(vector<int>& arr, vector<int> ansf,vector<vector<int>>&ans,int target,int ind)
    {
        if(target==0)
        {
            ans.push_back(ansf);
            
            return;
        }
       int pre=-1;
        for(int i=ind;i<arr.size();i++)
        {
        if(target-arr[i]>=0&&pre!=arr[i])
        { 
            ansf.push_back(arr[i]);
            combin(arr,ansf ,ans, target-arr[i],i+1);
            ansf.pop_back();
        
        }
            pre=arr[i];
                
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr,int target) 
    {
        vector<vector<int>>ans;
        vector<int>v;
        sort(arr.begin(),arr.end());
        combin(arr, v,ans, target,0); 
        return ans;
    }


class pair_
{
public:
    string psf = "";
    int len = 0;

    pair_(string psf, int len)
    {
        this->len = len;
        this->psf = psf;
    }
};

pair_ longestPath(int sr, int sc, vector<vector<bool>> &vis, vector<vector<int>> &dir, vector<string> &dirS)
{
    int n = vis.size(), m = vis[0].size();
    if (sr == n - 1 && sc == m - 1)
    {
        pair_ base("", 0);
        return base;
    }

    vis[sr][sc] = true; // blocked
    pair_ myAns("", -1);
    for (int d = 0; d < dir.size(); d++)
    {
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];

        if (r >= 0 && c >= 0 && r < n && c < m)
        {
            if (!vis[r][c])
            {
                pair_ recAns = longestPath(r, c, vis, dir, dirS);
                if (recAns.len != -1 && recAns.len + 1 > myAns.len)
                {
                    myAns.len = recAns.len + 1;
                    myAns.psf = dirS[d] + recAns.psf;
                }
            }
        }
    }

    vis[sr][sc] = false; // unblocked
    return myAns;
}

////////////////////////////
322. Coin Change
//min no. of coin required to achieve a target
//very important question
//use either permutation or combination ans will be same(dynamic p)
//here you will learn how to find combination or permutation using top to bottom approach
int change(vector<int>arr,int amt,int ind)//i did using combination it could also be done in permutation
    {
        if(amt==0)
        {
                return 0;   
        }
        int ans=1e9;
        for(int i=ind;i<arr.size();i++)
        {
             int myrec;
            if(amt-arr[i]>=0)
            {
                myrec = change(arr,amt-arr[i],i);
                if(myrec!=1e9&&ans>(myrec+1))
                ans=myrec+1;
            }    
	}
        return ans;   
    }

    int coinChange(vector<int>& coins, int amt) {
         int n=   change(coins,amt,0);
        return n!=1e9?n:-1;
        
    }

//////////////////////////////
 int PermutationSingleCoins_subsequence(int[] arr, int tar, int idx, string ans) {
        if (tar == 0 || idx == arr.size()) //size check is not required in case of using for loop as for loop condition is suff
	{
            if (tar == 0) {
                cout<<ans<<endl;
                return 1;
            }
            return 0;
        }

        int count = 0;

        if (arr[idx] > 0 && tar - arr[idx] >= 0) 
	{
            int val = arr[idx];
            arr[idx] = -val;
            count += PermutationSingleCoins_subsequence(arr, tar - val, 0, ans + val);
            arr[idx] = val;
        }
        count += PermutationSingleCoins_subsequence(arr, tar, idx + 1, ans);//if coint doesnt take part in ans then ind+1;

        return count;
    }




















