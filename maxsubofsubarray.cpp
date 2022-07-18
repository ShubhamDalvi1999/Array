#include<bits/stdc++.h>
using namespace std;

/*This is the 1st attempt on 4th June 2022
  Solving using brute force method
*/

int maxSubArraySum(int a[], int n)
{
    //considering the min valid subarray size is 1 
    /*for [2,4,5,0,9]
      for eg we take size as 2 to iterate
      we need to iterate over each index of array ,like [2,4] for 0th index [4,5] for 1st index so we need a loop for that
      inside this loop we need a loop to add the elements of that subarray, that will be loop no 2
      and to go beyond ur assumption of suarray of size 2 we need a loop over these two loops , so that will be loop 3
    */
    //TODO : always put a array out of bound condition to avoid overflow like inside loop 2 

    int ans=INT_MIN;
    for(int size_of_subarray=1; size_of_subarray<=n; size_of_subarray++)
    {
        for(int start_index=0; start_index<n; start_index++)
        {
            if(start_index+size_of_subarray > n)
                break; //if size_of_subarray is 2 and start_index is 4 for ur eg, that subarray is invalid 

            int sum=0;
            for(int i=start_index ; i< (start_index+size_of_subarray);i++)
            {
                sum+=a[i];
            }
            ans=max(ans,sum);
        }
    }
    return ans;
}




int main () {
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}