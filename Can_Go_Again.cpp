#include <bits/stdc++.h>

using namespace std;

class Edge
{

public:
    int u;
    int v;
    int wt;

    Edge(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

int main()
{

    int v, e;
    cin >> v >> e;
    vector<Edge> adj;
    long long dis[1005];
    long long INF = LLONG_MAX;

    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;

        adj.push_back(Edge(a, b, w));
    }

    for (int i = 1; i <= v; i++)
    {
        dis[i] = INF;
    }

    int src;
    cin >> src;
    dis[src] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        for (Edge ed : adj)
        {

            if (dis[ed.u] < INF && (dis[ed.u] + ed.wt < dis[ed.v]))
            {
                dis[ed.v] = dis[ed.u] + ed.wt;
            }
        }
    }

    bool isCycle = false;

    for (Edge ed : adj)
    {

        if (dis[ed.u] < INF && (dis[ed.u] + ed.wt < dis[ed.v]))
        {
            isCycle = true;
            break;
        }
    }

    if (isCycle)
        cout << "Negative Cycle Detected\n";
    else
    {
        int q;
        cin >> q;
        while (q--)
        {
            int d;
            cin >> d;

            if (src == d)
                cout << "0\n";
            else
            {
                if (dis[d] == INF)
                    cout << "Not Possible\n";
                else
                {
                    cout << dis[d] << endl;
                }
            }
        }
    }

    return 0;
}