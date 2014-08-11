//maximum sum path in two arrays

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

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    sd(n);sd(m);
    int i,j;
    vi arr1(n),arr2(m);
    FOR(i,0,n) s(arr1[i]);
    FOR(i,0,m) s(arr2[i]);
    int ans=0,sum1=0,sum2=0;
    i=0;j=0;
    while(i<n&&j<m)
    {
        if (arr1[i]==arr2[j])
        {
            ans+=(max(sum1,sum2))+arr1[i];
            sum1=sum2=0;
            i++;
            j++;
        }
        else if (arr1[i]<arr2[j])
        {
            sum1+=arr1[i];
            i++;
        }
        else
        {
            sum2+=arr2[j];
            j++;
        }
    }
    while(i<n) sum1+=arr1[i++];
    while(j<m) sum2+=arr2[j++];
    ans+=max(sum1,sum2);
    p(ans);
}
