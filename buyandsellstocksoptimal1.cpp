class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max_till_here[prices.size()];
        int max_profit=INT_MIN;
        int max=prices[prices.size()-1];
        
        for(int i=prices.size()-1; i>=0; i--)
        {
            if(max< prices[i])
            {
                max=prices[i];
                max_till_here[i]=max;
            }
             max_till_here[i]=max;            
            
        }
        
        for(int i=0;i<prices.size();i++)
        {
            if(max_profit< (max_till_here[i]-prices[i]))
                max_profit = max_till_here[i]-prices[i];
            
        }
        return max_profit;
    }
};

int main()
{
    
    return 0;
}