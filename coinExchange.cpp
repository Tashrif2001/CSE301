#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
int coinChange(vector<int>&coins, int coin, int amount)
{
    if(!coin)
    return amount;

    if(!amount)
    return 0;

    if(dp[coin][amount]!=INT_MAX)
    return dp[coin][amount];

    else if(coins[coin-1]>amount)
    {
        dp[coin][amount]=coinChange(coins, coin-1, amount);
    }
    else
    {
        dp[coin][amount]=min(coinChange(coins, coin-1, amount), 1+coinChange(coins, coin, amount-coins[coin-1]));
    }
    
    return dp[coin][amount];
}
int main()
{
    vector<int>coins={1,2,5};
    int amount=11, coin=coins.size();
    dp.assign(coin+1, vector<int>(amount+1, INT_MAX));
    cout<<coinChange(coins, coin, amount)<<endl;
    return 0;
}
