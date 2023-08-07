#include<iostream>
using namespace std;

struct item{
    int value;
    int weight;
    double val_per_weight;
}items[100];

bool compare(struct item item1, struct item item2)
{
    return item1.value_per_weight>item2.value_per_weight;
}
int benefit()
{

}
int main()
{
    freopen("test.txt", "r", stdin);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>items[i].value>>items[i].weight;
        items[i].value_per_weight = (items[i].value/items[i].weight);
    }
    int res = benefit();
    return 0;
}
