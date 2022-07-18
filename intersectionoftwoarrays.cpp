 /* map_name.find() ==> 
            The function returns an iterator or a constant iterator which refers to the position where the key is present in the map. If the key is not present in the map container, it returns an iterator or a constant iterator which refers to map.end()
            if element is found map_name.find() == map_name.end() will return 0/false
            */
/* this whole approach is my own creation without any refrence
   it uses maps and vectors*/

#include <bits/stdc++.h>
using namespace std;


vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map< int ,int > all_elements_count;
        vector<int> ans;
        
        for(int i1: nums1)
        {
            if( !(all_elements_count.find(i1)==all_elements_count.end()) )
            {
                all_elements_count[i1]+=1;
            }
            
            all_elements_count.insert({i1,1});
        }
        
        for(int i2: nums2)
        {
            if( !(all_elements_count.find(i2)==all_elements_count.end()) )
            {
                if(all_elements_count[i2] >=1 )
                {
                    ans.push_back(i2);
                    all_elements_count[i2]-=1;
                }
            }
            
            //all_elements_count.insert({i2,1}); //this in not needed as we are concerned only about matching pairs
        }
        
        return ans; 
}

int main()
{
    vector<int> a = { 1, 3, 2, 3, 3, 4, 5, 5, 6 };
    vector<int> b = { 3, 3, 5 };
    vector<int> ans =intersect(a,b);
    for(int i :ans){
        cout<<i<<" ";
    }
    return 0;
}