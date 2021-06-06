34. Find First and Last Position of Element in Sorted Array
dry run on corner cases of 
-first position 
-last position of a num in array of repeated ele
-index for inserting in non repeating array
-index for inseerting in repeating array
array are sorted
//what should be keep in mind while writing binary search code?
// hmare pas ei,si,mid h to hme is baat ka hmesha dhyan rkhna h k 
// kisi bhi corner case pe wo variable invalid na ho jo array m as
//a index lia ja rha h, baki ki chije upar wala while loop sambhal lega
//usko hm dry run se solve krenge
//jse startind function m hm si variable as a index le rhe h ar ye bhi dikh rha h k si sirf bdh skta h to 
//ye possible h k ye kbhi bhi size k bahr chale jaye is liye ek check lgana pdega
//jb bhi dry run kro si<=ei tk kia kro 
     int StartingIndx(vector<int> nums,int tar)
    {
        int si=0,ei=nums.size()-1,mid=0;
        while(si<=ei)
        {
            mid=(si+ei)/2;     // si + (ei - si) / 2;
            
            if(tar>nums[mid])
                si=mid+1;
            else
                ei=mid-1;
            
            
        }
      
       return si<nums.size()&&nums[si]==tar?si:-1;
    
    }
    
        int EndingInd(vector<int> nums,int tar)
    {
        int si=0,ei=nums.size()-1,mid=0;
        while(si<=ei)
        {
            mid=(si+ei)/2;          // si + (ei - si) / 2;
            
            if(tar<nums[mid])
                ei=mid-1;
            else
                si=mid+1;
            
           
        }
     return si>0 && nums[si-1]==tar?si-1:-1;
    }
int StartingIndx(vector<int> nums,int tar)
{
            int si=0,ei=nums.size()-1,mid=0;
            while(si<=ei)
            {
              mid=(si+ei)/2;
                if(nums[mid]==tar)
                {
                    while(mid>=0&&nums[mid]==tar)
                    {
                        mid--;
                    }
                    return mid+1;
                }
                else if(nums[mid]<tar)
                    si=mid+1;
                else
                    ei=mid-1;


            }
        return -1;
}

    int EndingInd(vector<int> nums,int tar)
        {
            int si=0,ei=nums.size()-1,mid=0;
            while(si<=ei)
            {
              mid=(si+ei)/2;
                if(nums[mid]==tar)
                {
                    while(mid<nums.size()&&nums[mid]==tar)
                    {
                        mid++;
                    }
                    return mid-1;
                }
                else if(nums[mid]<tar)
                    si=mid+1;
                else
                    ei=mid-1;


            }
        return -1;

        }
///////////////////////////////////////////////////////////////////////////
//Q.35. Search Insert Position
int searchInsert(vector<int>& nums, int target) {
        int ei=nums.size()-1,si=0,mid=0;
        while(si<=ei)
        {
            mid=(si+ei)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                si=mid+1;
            else
                ei=mid-1;
        }
        return si<0?0:si;
    }

///////////////////////////////////////////////////////////////////////////

int insertLocation(vector<int> &arr, int data)  //same as finding EndingInd +1 
{
    int n = arr.size(), si = 0, ei = n - 1;
    while (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (arr[mid] <= data)
            si = mid + 1;
        else
            ei = mid - 1;
    }

    return si;
}

int perfectPosOfElement(vector<int> &arr, int data)
{
    int insertPos = insertLocation(arr, data);
    int lastIndex = insertPos - 1;

    return (lastIndex >= 0 && arr[lastIndex] == data) ? lastIndex : insertPos;
}
///////////////////////////////////////////////////////////////////////
//Q.Find closest number in array
int nearestElement(vector<int> &arr, int data)
{
    if (arr.size() == 0)
        return 0;

    int n = arr.size();
    if (data <= arr[0] || data >= arr[n - 1])
        return data <= arr[0] ? arr[0] : arr[n - 1];

    int si = 0, ei = n - 1;
    while (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (arr[mid] <= data)
            si = mid + 1;
        else
            ei = mid - 1;
    }

    return data - arr[ei] <= arr[si] - data ? arr[ei] : arr[si];
}
////////////////////////////////////////////////////////////////////////
//Quick sort
//average time: NlogN +N
//wrost case: N^2
// two swap method is not genric it cant work in linked list
//we will go by dividing the region which is more genric to find the exact location of pivot
//what if someone says k tum pivot 3rd ind ko lo. to dry run m asa dekha h k jo value last ind pe hoti h
//arr k wo exact position pe ati h agr usko pivot mana gya ho to
int PivotInd(vector<int >&arr,int si, int ei,int pivot)
{
     swap(arr[pivot],arr[ei]);
     while(si<=ei)
}
//////////////////////////////////////////////////////////////////////////
    int search(vector<int>& nums, int target) {
        
        int n=nums.size(),si=0,ei=n-1,mid;
        while(si<=ei)
        {
            mid=(si+ei)/2;
            if(nums[mid]==target)
                return mid;
            
            else if(nums[si]<=nums[mid])
            {
                if(nums[si]<=target && target<nums[mid])
                    ei=mid-1;
                else
                    si=mid+1;
                
            }
            else
            {
                  if(nums[ei]>=target && target>nums[mid])
                    si=mid+1;
                else
                    ei=mid-1;
                
            }
        
        }
        return -1;
    }
////////////
    int search(vector<int>& nums, int target)
    {
         int n=nums.size(),si=0,ei=n-1,mid;
        
        if(n==1&&nums[0]==target)return 0;
        else if(n==1&&nums[0]!=target)return -1;
        
        int pivot=min(nums,target);
        int left= bs(nums,target,si,pivot-1);
        int right=bs(nums,target,pivot,ei);
        
        if(left!=-1)return left;
        return right;    

    }
////////////////////////////////////////////////////////////////////////////
    bool search(vector<int>& nums, int target)
    {
         int n=nums.size(),si=0,ei=n-1,mid;
        
        if(nums[0]==target)return true;
    
        while(si<=ei)
        {
            mid=(si+ei)/2;
            if(nums[mid]==target||nums[si]==target)
                    return true;
            else if(nums[si]<nums[mid])
            {
               
                if(target<nums[mid] && target>=nums[si])
                    ei=mid-1;
                else
                    si=mid+1;
                
            }
            else if(nums[mid]<nums[ei])
            {
                if(target>nums[mid]&&target<=nums[ei])
                    si=mid+1;
                else
                    ei=mid-1;
            }
            else
                si++;
            
        }

        return false;


    }
/////////////////////////////////////////////////////////////////////////////
Q.154. Find Minimum in Rotated Sorted Array II

         int findMin(vector<int>& nums) {
        int n=nums.size(),si=0,ei=n-1,mid;
        
        while(si<ei)
        {
            mid=(si+ei)/2;
            
            if(nums[si]<nums[mid])  //array is sorted from si to mid
            {
                if(nums[si]<nums[ei])  //in ideal case when array have no rotation or no rotation in range of si to ei =>array will always be the starting ele
                    ei=si;
                else
                 si=mid+1;
            }
            else if(nums[mid]<nums[ei])  //array is sorted from mid to ei
            {
                 if(nums[mid]<nums[ei])  //in ideal case when there is no rotation or no rotation in range of mid to ei =>array will always be the starting element i.e mid ele
                     ei=mid;
                else
                    si=mid+1;
            }
            else                   //when both element get equal just try to make conditon false by increasing si or dec ei
                si++;
        }
        return nums[si];
    }
    
///////////////////////////////////////////////////////////////////////////
// Q. Union of Two Sorted Arrays
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
       vector<int>res;
       int i=0,j=0;
       while(i<n&&j<m)
       {
           while(i<n-1&&arr1[i]==arr1[i+1])i++; //see carfully these two lines
           while(j <m-1&&arr2[j]==arr2[j+1])j++;
           if(arr1[i]<arr2[j])
           res.push_back(arr1[i++]);
           else if(arr1[i]>arr2[j])
           res.push_back(arr2[j++]);
           else{
               res.push_back(arr1[i++]);
               j++;
           }
       }
      
       
          while(i<n){
              if(i<n-1 && arr1[i]==arr1[i+1])i++;//see carfully these two lines
              else
              res.push_back(arr1[i++]);
          }
          while(j<m)
          {
           if(j<m-1 && arr2[j]==arr2[j+1])j++;
              else
              res.push_back(arr2[j++]);
          }
          
       return res;
    }
////////////////////////////////////////////////////////////////////////////












/////////////////////////////////////////////////////////////////////////
