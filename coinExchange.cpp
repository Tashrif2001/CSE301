#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
int coinChange(vector<int>&coins, int amount)
{
    if(!amount)
    return 0;

    if(dp[amount]!=INT_MAX)
    return dp[amount];

    int q = INT_MAX;
    for(int i=0; i<coins.size(); i++)
    {
        if(amount>=coins[i])
        {
            int temp = coinChange(coins, amount-coins[i]);
            if(temp!=INT_MAX)
            q = min(q, temp+1);
        }
    }
    dp[amount]=q;
    return dp[amount];
}
int main()
{
    vector<int>coins={1,2,5,6};
    int amount=11;
    dp.assign(amount+1, INT_MAX);
    cout<<coinChange(coins, amount)<<endl;
    return 0;
}
