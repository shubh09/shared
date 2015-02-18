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

vector<bool> sieve(int n)		//O(nloglogn)
{
    //ans[i]=true if i is prime
    vector<bool> ans(n+1,true);
    ans[0]=ans[1]=false;
    int i;
    int hi=(int)sqrt(n);
    FOR(i,2,hi+1)
    {
        if (ans[i]==true)
        {
            //i is prime
            int t=i*i;
            while (t<=n)
            {
                ans[t]=false;
                t+=i;
            }
        }
    }
    return ans;
}

template<typename T>
void print_arr(vector<T> &arr)
{
    int s=sz(arr),i;
    FOR(i,0,s) cout<<arr[i]<<' ';
    cout<<'\n';
}

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    
    int MX=1e7;
    int i,j,t;
    vector<bool> isPrime=sieve(MX);
    vi primes,primacity(MX+1,0);
    FOR(i,2,MX+1){
        if (isPrime[i]){
            primes.pb(i);
            primacity[i]=1;
        }else{
            int s=sqrt(i);
            FOR(j,2,s+1){
                if (i%j==0){
                    int k=i/j;
                    if (k%j==0) primacity[i]=primacity[k];
                    else primacity[i]=primacity[k]+1;
                    break;
                }
            }
            assert(j<=s);
        }
    }
    vvi mat(10);
    FOR(i,0,MX+1){
        mat[primacity[i]].pb(i);
    }
    for(i=0;i<10;i++) cout<<mat[1][i]<<' ';
    sd(T);
    FOR(t,0,T)
    {
        sd(a);sd(b);sd(k);
        if (k>=10){
            pans(t+1,0);
            continue;
        }
        int ind1=lower_bound(all(mat[k]),a)-mat[k].begin();
        int ind2=upper_bound(all(mat[k]),b)-mat[k].begin()-1;
        pans(t+1,ind2-ind1+1);
    }
}
