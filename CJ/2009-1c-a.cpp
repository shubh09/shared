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
#define pans(t,ans)                             do{cout<<"Case #"<<t<<": "<<ans<<endl;}while(0)

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
        string str;
        cin>>str;
        int n=sz(str);
        set<char> st;
        FOR(i,0,n) st.insert(str[i]);
        int base=max(2,sz(st));
        map<char,int> val;
        val[str[0]]=1;
        int cur=1;
        ll ans=0;
        FOR(i,1,n)
        {
            char c=str[i];
            if (val.find(c)!=val.end()) continue;
            if (cur==1) val[c]=0;
            else val[c]=cur;
            cur++;
        }
        ll p=1;
        for(i=n-1;i>=0;i--)
        {
            ans+=((ll)val[str[i]]*p);
            p*=(ll)base;
        }
        pans(t+1,ans);
    }
}
