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
