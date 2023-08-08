#include <bits/stdc++.h>
using namespace std;

int rod_cut(vector<int>&price, int n)
{
    vector<int>dp(n+1);
    dp[0]=0;
    int q;
    for(int j=1; j<=n; j++)
    {
        q=INT_MIN;
        for(int i=0; i<j; i++)
        {
            q = max(q, price[i]+dp[j-i-1]);
        }
        dp[j]=q;
    }
    return dp[n];
}
int main() {
    //freopen("rod.txt", "r", stdin);
    int n,num;
    cin>>num;
    vector<int>price(num);
    for(int i=0; i<num; i++)
    {
        cin>>price[i];
    }
    cin>>n;
    int res=rod_cut(price, n);
    cout<<res;
    return 0;
}
