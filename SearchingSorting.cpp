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
     int StartingIndx(vector<int> nums,int tar)
    {
        int si=0,ei=nums.size()-1,mid=0;
        while(si<=ei)
        {
            mid=(si+ei)/2;
            
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
            mid=(si+ei)/2;
            
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


















/////////////////////////////////////////////////////////////////////////