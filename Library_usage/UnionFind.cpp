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

class UF {
    int *p,*rank,cnt;
public:
    UF(int n){
        cnt=n;
        p=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++) p[i]=i,rank[i]=1;
    }
    ~UF(){
        delete [] rank;
        delete [] p;
    }
    int find(int x){
        if (x!=p[x]) p[x]=find(p[x]);
        return p[x];
    }
    void link(int x,int y){
        x=find(x),y=find(y);
        if (rank[x]>rank[y]) p[y]=x;
        else p[x]=y;
        if (rank[x]==rank[y]) rank[y]++;
    }
    
    
};

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    UF U(10);
//    sd(n);
    int n=100;
    int i,j;
    FOR(i,0,n)
    {
        sd(t);
        if (t==1){
            sd(x);
            p(U.find(x));
        }
        else{
            sd(x);sd(y);
            U.link(x,y);
        }
    }
}
