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
typedef vector<ll> vll;
typedef vector<vll> vvll;

int M,N;

vector<string> &split(string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(string &s, char delim) {
    vector<string> elems;
    return split(s, delim, elems);
}

int str2int(string s)
{
    istringstream buffer(s);
    int ans;
    buffer>>ans;
    return ans;
}

ll MOD=(ll) 1e9+7;

int addmod(int a,int b)
{
	ll t=(ll)a+b;
	if (t>=MOD) t=t%MOD;
	return t;
}

int submod(int a,int b)
{
    //assuming both a and b are positive and <MOD
    int t=a-b;
    t=t<0?t+MOD:t;
    return t;
}

int mulmod(int a,int b)
{
	ll t=(ll)a*b;
	if (t>=MOD) t=t%MOD;
	return t;
}


int epowmod(int a,int p)
{
	if (p==0) return 1;
	int t=epowmod(a,p/2);
	t=mulmod(t,t);
	if (p&1) t=mulmod(t,a);
	return t;
}

const int MX=2000;
//int dp1[MX+1][MX+1],dp2[MX+1][MX+1];
int dp1[MX+1][MX+1],dp2[MX+1][MX+1];

//stress free; m,n - current score
int solve1(int m,int n){
    int ans=0;
    if (dp1[m][n]>=0) return dp1[m][n];
    if (m==M||n==N) return (dp1[m][n]=1);
    if (m<=n+1){
        ans=solve1(m+1,n);
        dp1[m][n]=ans;
        return ans;
    }else{
        ans=solve1(m+1,n);
        ans=addmod(ans,solve1(m,n+1));
        return (dp1[m][n]=ans);
    }
}

//stressful; m,n - current score
int solve2(int m,int n){
    if (dp2[m][n]>=0) return dp2[m][n];
    if (m==M||n==N) return (dp2[m][n]=1);
    int ans=0;
    if (m==n){
        ans=solve2(m,n+1);
        return (dp2[m][n]=ans);
    }else{
        ans=solve2(m+1,n);
        ans=addmod(ans,solve2(m,n+1));
        return (dp2[m][n]=ans);
    }
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
        string str;
        cin>>str;
        vstr inp=split(str,'-');
        M=str2int(inp[0]);N=str2int(inp[1]);
//        dp1=new int[MX+1][MX+1]; //error if no casting is done
//        dp2=new int[MX+1][MX+1];
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));

        cout<<"Case #"<<t+1<<": "<<solve1(0,0)<<' '<<solve2(0,0)<<'\n';
//        FOR(i,0,4){
//            FOR(j,0,4) cout<<dp1[i][j]<<' ';
//            cout<<'\n';
//        }
//        cout<<M<<' '<<N<<'\n';
    }
}
