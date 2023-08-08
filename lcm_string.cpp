#include<iostream>
using namespace std;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
int lcm(int x, int y)
{
    return (x*y)/gcd(x,y);
}
int main()
{
    int t;
    cin>>t;
    string a,b;
    while(t--)
    {
        cin>>a>>b;
        int lc = lcm(a.size(), b.size()); 
        int x=(lc/a.size())-1, y=(lc/b.size())-1;
        for(int i=0; i<x; i++)
        a+=a;
        for(int i=0; i<y; i++)
        b+=b;
        (a==b)?cout<<a<<endl:cout<<-1<<endl;
    }
    return 0;
}
