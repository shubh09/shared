#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					cin>>n
#define p(n)					cout<<n<<'\n'
#define sd(n)					int n;cin>>n
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define mp(a,b)                                 make_pair(a,b)
#define ps(str)                                 cout<<str<<'\n'
#define pans(t,ans)                             cout<<"Case #"<<t<<": "<<ans<<endl;

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
        sd(n);sd(k);
        vstr v(n);
        FOR(i,0,n)
        {
            cin>>v[i];
            j=n-1;
            int k=n-1;
            for(j=n-1;j>=0;j--)
            {
                if (v[i][j]!='.') v[i][k--]=v[i][j];
            }
            while (k>=0) v[i][k--]='.';
        }
//        FOR(i,0,n) p(v[i]);
        bool red=false,blue=false;
        //horizontal
        FOR(i,0,n)
        {
            vi dp(n,0);
            char c=v[i][0];
            if (c=='.') dp[0]=0;
            else dp[0]=1;
            FOR(j,1,n)
            {
                c=v[i][j];
                if (c=='.') dp[j]=0;
                else if (c==v[i][j-1]) dp[j]=dp[j-1]+1;
                else dp[j]=1;
            }
            FOR(j,0,n)
            {
                if (dp[j]==k)
                {
                    if (v[i][j]=='B') blue=true;
                    else if (v[i][j]=='R') red=true;
                }
            }
                
        }
        //vertical
        FOR(j,0,n)
        {
            vi dp(n,0);
            char c=v[0][j];
            if (c=='.') dp[0]=0;
            else dp[0]=1;
            FOR(i,1,n)
            {
                c=v[i][j];
                if (c=='.') dp[i]=0;
                else if (c==v[i-1][j]) dp[i]=dp[i-1]+1;
                else dp[i]=1;
            }
            FOR(i,0,n)
            {
                if (dp[i]==k)
                {
                    if (v[i][j]=='B') blue=true;
                    else if (v[i][j]=='R') red=true;
                }
            }
        }
        //diagonal
        vvi dp1(n,vi(n,0)),dp2(n,vi(n,0));
//        FOR(i,0,n) if (v[i][0]!='.') dp1[i][0]=dp2[i][0]=1;
        FOR(j,0,n) if (v[0][j]!='.') dp1[0][j]=dp2[0][j]=1;
        FOR(i,1,n)
        {
            FOR(j,0,n)
            {
                if (v[i][j]!='.') dp1[i][j]=dp2[i][j]=1;
                else continue;
                int x[]={i-1,i-1};
                int y[]={j-1,j+1};
                int k;
                FOR(k,0,2)
                {
                  int x2=x[k],y2=y[k];
                  if (y2<0||y2>=n) continue;
                  if (k==0&&v[i][j]==v[x2][y2]) dp1[i][j]=dp1[x2][y2]+1;
                  if (k==1&&v[i][j]==v[x2][y2]) dp2[i][j]=dp2[x2][y2]+1;
                }
            }
        }
//        p("dp1:");
//        FOR(i,0,n)
//        {
//            FOR(j,0,n) cout<<dp1[i][j]<<' ';
//            cout<<endl;
//        }
//        p("dp2:");
//        FOR(i,0,n)
//        {
//            FOR(j,0,n) cout<<dp2[i][j]<<' ';
//            cout<<endl;
//        }
        FOR(i,0,n)
        {
            FOR(j,0,n)
            {
                if (dp1[i][j]==k||dp2[i][j]==k)
                {
                    if (v[i][j]=='B') blue=true;
                    else if (v[i][j]=='R') red=true;
                }
            }
        }
        if (red&&blue)
        {
            pans(t+1,"Both");
        }
        else if (red)
        {
            pans(t+1,"Red");
        }
        else if (blue)
        {
            pans(t+1,"Blue");
        }
        else
        {
            pans(t+1,"Neither");
        }
    }
}

//mistake - commented line 106