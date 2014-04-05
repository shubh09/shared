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

ll epow(ll a,int p)
{
	if (p==0) return 1;
	ll t=epow(a,p/2);
	t*=t;
	if (p&1) t*=a;
	return t;
}

string solve2(ll n,ll l,string &str)
{
    int num=sz(str);
    n--;        //would be better if n is 0-indexed
    int i;
    ll n2=epow(num,l-1);
    string ans;
    for(i=l-1;i>=0;i--)
    {
        ll d=n/n2;
        //guaranteed that d<num, since n<(num^l)
        ans.pb(str[d]);
        n-=(n2*d);
        n2/=(ll)num;
    }
    return ans;
}

string solve(string &str, ll n)
{
    int len=sz(str);
    ll n2=(ll)len;
    int l=1;
    while (n2<n)
    {
        l++;
        n-=n2;
        n2*=(ll)len;
    }
    return solve2(n,l,str);
}

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    sd(T);
    int i,j,t;
    string str;
    ll n;
    FOR(t,0,T)
    {
        cin>>str;
        cin>>n;
        cout<<solve(str,n)<<endl;
    }
}
