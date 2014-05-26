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
        sd(n);sd(m);
        vvi mat(n,vi(m));
        FOR(i,0,n) FOR(j,0,m) s(mat[i][j]);
        vi rmax(n,0),cmax(m,0);
        FOR(i,0,n) FOR(j,0,m) rmax[i]=max(rmax[i],mat[i][j]);
        FOR(j,0,m) FOR(i,0,n) cmax[j]=max(cmax[j],mat[i][j]);
        int succ=true;
        FOR(i,0,n) FOR(j,0,m) succ&=((mat[i][j]==rmax[i])||(mat[i][j]==cmax[j]));
        if (succ) pans(t+1,"YES");
        else pans(t+1,"NO");
    }
}
