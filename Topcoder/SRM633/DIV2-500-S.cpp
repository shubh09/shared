#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cassert>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define mp(a,b)                                 make_pair(a,b)
#define ps(str)                                 printf("%s\n",str)

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

template<typename Head>
void myprint(Head a)
{
    cout<<a<<'\n';
}

template<typename Head, typename... Tail>
void myprint(Head a,Tail... t)
{
    cout<<a<<' ';
    myprint(t...);
}


double eps=1e-9;
class Jumping {
	public:
	string ableToGet(int x, int y, vector <int> arr2)
	{
		int i,j;
                double dist=sqrt(x*x+y*y);
                int a=arr2[0],b=arr2[0];
                int n=sz(arr2);
                FOR(i,1,n){
                    int c=arr2[i];
                    if (c<=a){
                        a-=c;
                        b+=c;
                    }
                    else if (c<=b) {
                        a=0;
                        b+=c;
                    }
                    else{
                        a=c-b;
                        b+=c;
                    }
                }
                if (dist>=(double)a-eps&&dist<=(double)b+eps) return "Able";
                else return "Not able";
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
