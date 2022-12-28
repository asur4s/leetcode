class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxPrice = INT_MIN;
        int ans = 0;
        for(int price: prices){
            if(price < minPrice){
                minPrice = price;
                maxPrice = price;
            }
            if(price - minPrice > ans){
                ans = price - minPrice;
            }
        }
        return ans;
    }
};