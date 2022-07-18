#include<iostream>
#include<vector>
using namespace std;
  
vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1=0; // index of nums1 to iterate 
        int i2=0; // index of nums2 to iterate till end  
        vector<int> ans;

        //rather than using for loop use while loop
        while(i1<m && i2<n)
        {
            //while loop breaks when the smaller array's index goes out of range
            if(nums1[i1]>nums2[i2])
            {    
                ans.push_back(nums2[i2]);
                i2++;
            }
            else if( nums1[i1] == nums2[i2] )
            {
                ans.push_back(nums2[i2]);
                ans.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else
            {
                ans.push_back(nums1[i1]);
                i1++;
            }     
        }
        
        for(;i1<m ;i1++)
        {
            ans.push_back(nums1[i1]);
        }
        
        for(;i2<n ;i2++)
        {
            ans.push_back(nums2[i2]);
        }
        
        return ans;       
}
  
// Driver code
int main()
{
    vector<int> arr1 = {1, 3, 5, 7};
    int n1 = 4;
  
    vector<int> arr2 = {2, 4, 6, 8};
    int n2 = 4;
  
    vector<int> arr3;
    arr3= merge(arr1, n1, arr2, n2);
  
    cout << "Array after merging" <<endl;
    for (int i : arr3)
        cout << i << " ";

    return 0;
}