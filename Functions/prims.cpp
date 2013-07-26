#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cassert>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)
#define pb(n)                                   push_back(n)
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define clr(a)                                  memset(a,0,sizeof(a))
#define mp(a,b)                                 make_pair(a,b)

#define INF                                     INT_MAX
#define UINF                                    ULONG_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef vector<vector<pair<int,int> > > TG;

pair<int,vi> prims(TG G,int r)
{
    int n=sz(G);        //number of vertices
    //initialize
    vi pi(n,-1);
    vi key(n,INF);
    key[r]=0;
    set<pair<int,int> > q;
    q.insert(mp(0,r));
    int cost=0;
    while (!q.empty())
    {
        pair<int,int> temp=*q.begin();
        q.erase(q.begin());
        int d=temp.first;
        int u=temp.second;
        cost+=d;
        assert(d==key[u]);
        int deg=sz(G[u]);
        int i;
        FOR(i,0,deg)
        {
            int v=G[u][i].first;
            int w_uv=G[u][i].second;
            if (key[v]>w_uv)
            {
                if (key[v]!=INF)
                    q.erase(q.find(mp(key[v],v)));
                key[v]=w_uv;
                pi[v]=u;
                q.insert(mp(key[v],v));
            }
        }
    }
    return mp(cost,pi);
}

int main()
{
    sd(n);sd(m);
    int i,j;
    TG G(n);
    FOR(i,0,m)
    {
        sd(a);sd(b);sd(w);
        //assuming directed graph
        G[a].pb(mp(b,w));
        //if undirected uncomment the following
        //G[b].pb(mp(a,w));
    }
    int cost;
    vi pi;
    pair<int,vi> ans=prims(G,0);
    cost=ans.first;
    pi=ans.second;
    p(cost);
    FOR(i,0,n) printf("%d ",pi[i]);
    //if an element in pi other than the rth element is -1, it means that that vertex is unreachable from r, and a MST isn't possible
    printf("\n");
}

