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

set<string> dict;
int ans;

void solve(vstr &v,int k,string &cur)
{
    int n=sz(v);
    if (k==n)
    {
        if (dict.find(cur)!=dict.end()) ans++;
        return;
    }
    n=sz(v[k]);
    int i;
    FOR(i,0,n)
    {
        char c=v[k][i];
        cur.pb(c);
        solve(v,k+1,cur);
        cur.resize(k);
    }
}

vector<string> parse(string &str,int l)
{
    int i,j=0;
    vstr ans;
    FOR(i,0,l)
    {
        if (str[j]!='(')
        {
            string temp(1,str[j]);
            ans.pb(temp);
            j++;
        }
        else
        {
            string temp;
            while (str[j]!=')')
            {
                j++;
                temp.pb(str[j]);
            }
            ans.pb(temp);
            j++;
        }
    }
    return ans;
}

vvi parse2(string &str,int l)
{
    int i,j=0;
    vvi ans(l,vi(26,0));
    FOR(i,0,l)
    {
        if (str[j]!='(')
        {
            ans[i][str[j]-'a']=1;
            j++;
        }
        else
        {
            while (1)
            {
                j++;
                if (str[j]==')') break;
                ans[i][str[j]-'a']=1;
            }
            j++;
        }
    }
    return ans;
}

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int i,j;
    sd(l);sd(d);sd(n);
    string str;
    vstr dict;
    FOR(i,0,d)
    {
        cin>>str;
        dict.pb(str);
    }
    FOR(i,0,n)
    {
        string str2;     //if str not declared here (and simply the previous declaration is used) - doesn't work for the small input!!!!!!
        ans=0;
        cin>>str2;
//        p("ehre");
//        cout<<"Processing "<<str2<<endl;
        
//        vstr v2=parse(str,l);
        vvi mat=parse2(str2,l);
        
        FOR(j,0,d)
        {
            string cur=dict[j];
            int k;
            FOR(k,0,l)
            {
                if (!mat[k][cur[k]-'a']) break;
            }
            if (k==l)
            {
//                cout<<cur<<endl;
                ans++;
            }
        }
        
//        string temp;
//        solve(v,0,temp);
//        cout<<i<<' '<<n<<endl;
        pans(i+1,ans);
    }
    
}
//line 122
//possible recursive solution too - but too inefficient (the solve function)