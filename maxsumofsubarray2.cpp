#include<bits/stdc++.h>
using namespace std;

/*This is the 1st attempt on 4th June 2022
  Solving using brute force method
  In this optimized solution, use index for your advantage and add the values using logical order 
  This method uses the sum of pervious subarray starting from one index, this reduces redundant computations
*/

int maxSubArraySum(int a[], int n)
{
    //considering the min valid subarray size is 1 
    
    //TODO : always put a array out of bound condition to avoid overflow like inside loop 2 

    int ans=INT_MIN;
    for(int start_index=0; start_index<n; start_index++)
    {   
        int sum=0;
        for(int size_of_subarray=1; size_of_subarray<=n; size_of_subarray++)
        {
            if(start_index+size_of_subarray > n)
                break; //if size_of_subarray is 2 and start_index is 4 for ur eg, that subarray is invalid 

            sum+=a[start_index+size_of_subarray-1];
            ans=max(ans,sum);
        }
    }
    return ans;
}




int main () {
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum; //ans is 7
    return 0;
}