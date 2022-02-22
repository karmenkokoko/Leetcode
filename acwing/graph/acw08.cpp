#include <bits/stdc++.h>

using namespace std;

// dijkstra求最短路径

const int N = 510;
int g[N][N], dist[N];
bool st[N];

int n, m;

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // update n-1次最短路径
    for (int i = 0; i < n - 1; i++)
    {
        int t = -1;
        // 找最短的路径
        for (int j = 1; j <= n; j++)
        {
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
            {
                t = j;
            }
        }
        // 更新路径
        st[t] = true;
        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }

    if(dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    cout << dijkstra() << endl;
    return 0;
}