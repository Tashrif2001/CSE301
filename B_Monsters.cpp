#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{   
    ll n,k,t,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vector<pair<ll,ll>>p;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            p.push_back({x,i+1});
        }
        for(int i=0; i<n; i++)
        {
            sort(p.begin(), p.end(), greater<>());
            if(p[0].first>0)
            p[0].first-=k;
            if(p[0].first<=0)
            {
                cout<<p[0].second<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}