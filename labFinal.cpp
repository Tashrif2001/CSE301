#include<bits/stdc++.h>
using namespace std;

int bfs(int n, vector<int>choco, vector<vector<int>>graph)
{
    vector<bool> visited(n, false);
    int totalChocolates = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int minCost = INT_MAX;
            queue<int>Q;
            Q.push(i);

            while (!Q.empty()) {
                int curr = Q.front();
                Q.pop();
                visited[curr] = true;
                minCost = min(minCost, choco[curr]);

                for (int adj : graph[curr]) {
                    if (!visited[adj]) {
                        Q.push(adj);
                    }
                }
            }
            totalChocolates+=minCost;
        }
    }
    return totalChocolates;
}

int main() {
    //freopen("lab2.txt", "r", stdin);

    int n,m,x,y;
    cin>>n>>m;

    vector<int> choco(n);
    for (int i=0; i<n; i++) 
        cin>>choco[i];

    vector<vector<int>>graph(n);

    for (int i=0; i<m; i++) 
    {
        cin>>x>>y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }

    cout<<bfs(n, choco, graph)<<endl;

    return 0;
}