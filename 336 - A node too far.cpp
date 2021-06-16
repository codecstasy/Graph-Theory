#include <bits/stdc++.h>
#define ll long long
using namespace std;
int cs;
const ll inf=1000005;

class graph {
public:
    unordered_map <ll, vector <ll> > g;
    vector <ll> lev;
    vector <ll> vis;
    void add_edge(ll u, ll v);
    void clear();
    void size();
    ll bfs(ll s, ll ttl);
};

void graph::add_edge(ll u, ll v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

void graph::clear() {g.clear();}

ll graph::bfs(ll source, ll ttl) {
    ll ans=0;
    ll nodes=1;
    lev.resize(100005, inf);
    vis.resize(100005, 0);
    vis[source]=1;
    lev[source]=0;
    queue <ll> q;
    q.push(source);
    while(!q.empty()) {
        ll u=q.front(); q.pop();
        for(auto v: g[u]) {
            if(vis[v]==0) {
                nodes++;
                vis[v]=1;
                lev[v]=lev[u]+1;
                if(lev[v]>ttl) ans++;
                q.push(v);
            }
        }
    }
    ans+=g.size()-nodes;
    //cout << g.size() << endl << vis.size() << endl;
    //cout << nodes << endl;
    vis.clear();
    lev.clear();
    return ans;
}

int main() {
    cs=1;
    while(1) {
        ll e;
        cin >> e;
        if(e==0) break;
        graph g;
        for(ll i=1 ; i<=e ; i++) {
            ll u,v;
            cin >> u >> v;
            g.add_edge(u,v);
        }
        while(1) {
            ll src,ttl;
            cin >> src >> ttl;
            if(src==0 && ttl==0) break;
            ll ans=g.bfs(src,ttl);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",(int)cs,(int)ans,(int)src,(int)ttl);
            cs++;
        }
        g.clear();
    }
    return 0;;
}
