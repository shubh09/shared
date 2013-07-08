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

pair<vi,vi> dijkstras(TG G,int s)
{
    int n=sz(G);        //the number of vertices
    set<pair<int,int> > q;       //the queue
    //initialization
    vi d(n,INF);
    vi pi(n,-1);
    d[s]=0;
    q.insert(mp(0,s));
    while (!q.empty())
    {
        pair<int,int> temp=*q.begin();
        q.erase(q.begin());
        int u=temp.second;
        printf("Took out %d\n",u);
        int d2=temp.first;
        assert(d[u]==d2);
        int deg=sz(G[u]);
        p(deg);
        int i=0;
        FOR(i,0,deg)
        {
            int v=G[u][i].first;
            int w_uv=G[u][i].second;
            printf("here");
            if (d[v]>d[u]+w_uv)
            {
                //the condition is important!
                if (d[v]!=INF)
                        q.erase(q.find(mp(d[v],v)));
                d[v]=d[u]+w_uv;
                pi[v]=u;
                q.insert(mp(d[v],v));
            }
        }
    }
    return mp(d,pi);
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
    sd(s);
    vi d,pi;
    pair<vi,vi> ans=dijkstras(G,s);
    d=ans.first;
    pi=ans.second;
    FOR(i,0,n) printf("%d ",d[i]);
    printf("\n");
    FOR(i,0,n) printf("%d ",pi[i]);
    printf("\n");
}
