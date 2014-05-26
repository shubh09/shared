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
#define pans(t,ans)                             do{cout<<"Case #"<<t<<": "<<ans<<endl;} while(0)

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

ll dp[31][2][2][2];

int a,b,k;
ll go(int p, int a1, int a2, int a3) {
	if(p==-1) return 1;
	if(dp[p][a1][a2][a3]>=0) return dp[p][a1][a2][a3];
	dp[p][a1][a2][a3] = 0;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			int k2 = i&&j;
			if(((!a1) || i<=((a>>p)&1)) && ((!a2) || j<=((b>>p)&1)) && ((!a3) || k2<=((k>>p)&1))) {
				dp[p][a1][a2][a3]+=go(p-1,a1&&(i==((a>>p)&1)),a2&&(j==((b>>p)&1)),a3&&(k2==((k>>p)&1)));
			}
		}
	}
	return dp[p][a1][a2][a3];
}

ll solve(int p,int a1,int b1,int k1)
{
    if (p<0) return 1;
    if (dp[p][a1][b1][k1]>=0) return dp[p][a1][b1][k1];
    int i,j;
    dp[p][a1][b1][k1]=0;
    FOR(i,0,2) FOR(j,0,2)
    {
        int k2=i&j;
        if(((!a1) || i<=((a>>p)&1)) && ((!b1) || j<=((b>>p)&1)) && ((!k1) || k2<=((k>>p)&1))) {
				dp[p][a1][b1][k1]+=solve(p-1,a1&&(i==((a>>p)&1)),b1&&(j==((b>>p)&1)),k1&&(k2==((k>>p)&1)));}
//        if (((!a1)||(a&(1<<p)>=(i<<p)))&&((!b1)||(b&(1<<p)>=(j<<p)))&&((!k1)||(k&(1<<p)>=(k2<<p))))
//            dp[p][a1][b1][k1]+=solve(p-1,a1&&(a&(1<<p)==(i<<p)),b1&&(b&(1<<p)==(j<<p)),k1&&(k&(1<<p)==(k2<<p)));
    }
    return dp[p][a1][b1][k1];
}

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    
    sd(T);
    int i,j,t;
    FOR(t,0,T)
    {
        s(a);s(b);s(k);
        a--;b--;k--;
        memset(dp,-1,sizeof(dp));
        pans(t+1,solve(30,1,1,1));
    }
}

//go works, solve doesn't - figure out why