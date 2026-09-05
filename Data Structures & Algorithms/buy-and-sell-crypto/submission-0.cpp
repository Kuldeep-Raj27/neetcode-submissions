class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int x=0;
        int y=prices.size() - 1;
        int buyLess = prices[0];
        int sellMore = prices[y];
        x++;
        y--;
        while(x<=y){
            if(prices[x]<buyLess){
                buyLess = prices[x];
            }
            else if(profit<(prices[x]-buyLess)){
                profit = prices[x]-buyLess;
            }                        
            x++;
            if(prices[y]>sellMore){
                sellMore = prices[y];
            }
            else if(profit<(sellMore - prices[y])){
                profit = sellMore - prices[y];
            }
            y--;
        }
        if((sellMore - buyLess)>profit){
            profit = sellMore - buyLess;
        }
        return profit;

    }
};
