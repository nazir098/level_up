
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


























