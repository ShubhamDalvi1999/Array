#include<bits/stdc++.h>
using namespace std;

/*This is the 1st attempt on 4th June 2022
  Solving using brute force method
  In this optimized solution, use index for your advantage and add the values using logical order 
  This method uses dynamic programming , memebering the previous max sum of subarray ( including indvidual ele or a subarry of size >2)
  the concept used here is => reducing the size of the array and finding the max sum of subarray then comparing it with 
  the increased size subarray by the logic that new maxsum will be maximum of 
   (previous subarray OR  the sum of prev subarray+currently added element OR current element alone)
    for last two condition we use line no 21
    and for the whole we use line no 22
*/

int maxSubArray(int nums[], int n) {
        
    int max_till_here = nums[0];
    int current_max   = nums[0];
        
    for(int i=1; i<n ;i++)    
    {
        current_max= max(nums[i], current_max+nums[i] );
        
        max_till_here = max( current_max, max_till_here);        
    }  
    
    return max_till_here;
        
}


int main () {
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArray(a,n);
    cout << "Maximum contiguous sum is " << max_sum; //ans is 7
    return 0;
}