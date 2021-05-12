#include <iostream>
#include <queue>
#include <uonorderd_map>
using namespace std;

//215
//Given an integer array nums and an integer k, return the kth largest element in the array.
ANS
//all element in this pool will be greater than the top element(min heap) and there are k element so the toppest element will be min ele in all k i.e kth largest element

   int findKthLargest(vector<int>& nums, int k)
   {
     priority_queue<int,vector<int>,greater<int>>pq;
       for(auto el:nums)
       {
         pq.push(el);
         
         if(pq.size()>k)
             pq.pop();
       }
 return pq.top();
 }


Q. kth smallest
ANS
//same concept this time make max heap
//all element in this pool will be smaller than the top element(max heap) and there are k element so the toppest element will be max ele in all k i.e kth smaller element  
//e
//b
//c   => e is the 5th largest el
//d
//a

 int findKthSmallest(vector<int>& nums, int k)
   {
     priority_queue<int>pq;
       for(auto el:nums)
       {
         pq.push(el);
         
         if(pq.size()>k)
             pq.pop();
       }
 return pq.top();
 }



//350 Q.Intersection of two arrays ->Each element in the result must appear as many times as it shows in both array
//mine soln
   vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         unordered_map<int, int> map;
          vector<int>v;
        
        for(auto el:nums1)
            map[el]++;
        
        for(auto el:nums2)
        {
            if(map[el]-- > 0)
            {v.push_back(el);
     
            }
        }
        return v;
//sir's soln
    unordered_map<int, int> map;
    for (int ele : nums1)
        map[ele]++;

    vector<int> ans;
    for (int ele : nums2)
    {
        if (map.find(ele) != map.end())
        {
            ans.push_back(ele);
            map[ele]--;
            if (map[ele] == 0)
                map.erase(ele);
        }
    }

    return ans;
}
//347  top frequent elements
//mine soln
   vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>vec;
   priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        unordered_map<int,int>map;
        for(auto el:nums)
            map[el]++;
        
        for(auto el:nums){
           if(map[el]) 
           {pq.push({map[el],el});
            map[el]=0;
            
            if(pq.size()>k)pq.pop();
                        
            }
        }
            
            while(pq.size())
            {
                vec.push_back(pq.top()[1]);
                pq.pop();
            }
        return vec;
    }
//sir's soln
vector<int> topKFrequent(vector<int> &nums, int k)
{

    unordered_map<int, int> map;
    for (int ele : nums)
        map[ele]++;

    //{freq,val}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    for (pair<int, int> key : map)
    {
        int val = key.first;
        int freq = key.second;

        pq.push({freq, val});
        if (pq.size() > k)
            pq.pop();
    }

    vector<int> ans;
    while (pq.size() != 0)
    {
        vector<int> p = pq.top();
        pq.pop();

        int freq = p[0];
        int val = p[1];

        ans.push_back(val);
    }

    return ans;
}

//973 k closest point to origin
 vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>vec;
        priority_queue<vector<int>>pq;//max heap
        for(auto el:points)
        {
            int fir=el[0];
            int sec=el[1];
            int dis=(fir*fir)+(sec*sec);
            
            pq.push({dis,fir,sec});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        while(pq.size()!=0)
        {
            vec.push_back({pq.top()[1],pq.top()[2]});
            pq.pop();
        }
        return vec;
    }

//sir's soln
class comp
{
public:
    bool operator()(const vector<int> &a, const vector<int> &b) const
    {
        int d1 = a[0] * a[0] + a[1] * a[1]; // x1^2 + y1^2
        int d2 = b[0] * b[0] + b[1] * b[1]; // x2^2 + y2^2

        return d2 > d1;
    }
};

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;

    for (vector<int> &p : points)
    {
        pq.push(p);
        if (pq.size() > k)
            pq.pop();
    }

    vector<vector<int>> ans;
    while (pq.size() != 0)
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}
//378. Kth Smallest Element in a Sorted Matrix
int kthSmallest(vector<vector<int>> &matrix, int k)
{
   //build a min heap, top element would be the first smallest.we will k times pop then to get kth smallest 
   //as the array is sorted we are taking element just next to the smallest no

    int n = matrix.size(), m = matrix[0].size();
    //{val,x,y};
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push({matrix[i][0], i, 0});
    }

    int ans = 0;
    while (k-- > 0)
    {
        vector<int> rv = pq.top();
        pq.pop();
        int val = rv[0];
        int x = rv[1];
        int y = rv[2];

        ans = val;
        y++;
        if (y < m)
            pq.push({matrix[x][y], x, y});
    }

    return ans;
}

//////////////////////////////////////////////////////////////////////////////
//380
//complexity matters
class RandomizedSet {
public:
    
    unordered_map<int,int>map;
    vector<int>vec;
    RandomizedSet() {
        //vec.push_back(0);
        //map[0]=0;
    }
    
    
    bool insert(int val) {
        if(map.find(val)==map.end())
        {
            vec.push_back(val);
            map[val]=vec.size()-1;
         return true;
        }
            return false;
    }
    

    bool remove(int val) {
        
        if(map.find(val)!=map.end())
        {int ind=map[val];
         int lind=vec.size()-1;
         
         vec[ind]=vec[lind];
         map[vec[ind]]=ind;
         
         vec.pop_back();
         map.erase(val);
         
////////////////////////////////////////////////////////////////////////////////////
//895
class FreqStack {

public:
    class comp{
        public:
        bool operator()(const vector<int>&a, const vector<int>&b)const
        { 
            if(a[0]==b[0])
                return a[2]<b[2];
            
        return a[0]<b[0];
        }            
    };
    
    priority_queue<vector<int>,vector<vector<int>>,comp>pq;
    unordered_map<int,int>map;
    int i=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        map[val]++;
       
        pq.push({map[val],val,i++});
     
        
    }
    
    int pop() {
       
        auto ans=pq.top();
        pq.pop();
       
        int value=ans[1];
        map[value]--;
        if(ans[0]==0)
            map.erase(value);
        
        return value;
    }         
            return true;
        }
            return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int t=(rand()%vec.size());
      
        return vec[t];
    }
/////////////////////////////////////////////////////////////////////////////
//380
//we hve to do everything in O(1)
class RandomizedSet {
public:
   
    unordered_map<int,int>map;
    vector<int>vec;
    RandomizedSet() {
    }
    

    bool insert(int val) {
        if(map.find(val)==map.end())
        {
            vec.push_back(val);
            map[val]=vec.size()-1;
         return true;
        }
            return false;
    }
    
    
    bool remove(int val) {
        
        if(map.find(val)!=map.end())
        {int ind=map[val];
         int lind=vec.size()-1;
         
         vec[ind]=vec[lind];
         map[vec[ind]]=ind;
         
         vec.pop_back();
         map.erase(val);
         
         
            return true;
        }
            return false;
    }
    
    
    int getRandom() {
        int t=(rand()%vec.size());
      
        return vec[t];
    }
