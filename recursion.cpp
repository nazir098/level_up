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

























