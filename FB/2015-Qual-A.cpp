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

string getMin(string str){
    int n=sz(str);
    char mn='9'+1,ind=-1;
    for(int i=n-1;i>=0;i--){
        if (str[i]!='0'&&str[i]<mn){
            mn=str[i];
            ind=i;
        }
    }
    if (ind==-1||ind==0) return str;
    swap(str[0],str[ind]);
    return str;
}

string getMax(string str){
    int n=sz(str);
    char mx='0'-1,ind=-1;
    for(int i=n-1;i>=0;i--){
        if (str[i]!='0'&&str[i]>mx){
            mx=str[i];
            ind=i;
        }
    }
    if (ind==-1||ind==0) return str;
    swap(str[0],str[ind]);
    return str;
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
        int n=sz(str);
        string mn=str,mx=str;
        FOR(i,1,n)FOR(j,0,i){
            swap(str[i],str[j]);
            if (str[0]!='0'){
                mn=min(mn,str);
                mx=max(mx,str);
            }
            swap(str[i],str[j]);
        }
        pans(t+1,mn+" "+mx);
    }
    //counterexample with using the above defined functions - when the first digit itself is the max/min digit in the number; would have had to make further modifications to account for such cases
}
