#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					cin>>n
#define p(n)					cout<<n<<'\n'
#define sd(n)					int n;cin>>n;
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define mp(a,b)                                 make_pair(a,b)
#define ps(str)                                 cout<<str<<'\n'

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX
#define PI 3.14159265358979323846

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<pair<int,int> > > TG;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef unsigned int uint;
typedef unsigned long long ull;

int getBit(uint n,int p)
{
    return (n>>p)&1;
}

int dp[32][2];

int f(int p,bool isEqual,uint M)
{
    int isEq=isEqual?1:0;
    if (dp[p][isEq]>=0) return dp[p][isEq];
    int ans;
    if (p==0)
    {
        if (isEqual) ans=getBit(M,0);
        else ans=2;
    }
    else if (isEqual)
    {
        if (getBit(M,p)==0) ans=f(p-1,true,M);
        else ans=f(p-1,true,M)+f(p-1,false,M);
    }
    else
    {
        ans= 2*f(p-1,false,M);
    }
    dp[p][isEq]=ans;
    return ans;
}

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    sd(n);
    int i,j;
    FOR(i,0,n)
    {
        memset(dp,-1,sizeof(dp));
        uint M;
        s(M);
        p(f(31,true,M));
    }
}
