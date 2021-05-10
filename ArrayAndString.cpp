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
