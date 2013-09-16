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

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)
#define pb(n)                                   push_back(n)
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define clr(a)                                  memset(a,0,sizeof(a))

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;

int ceil(int a,int b)
{
	int ans=a/b;
	if (a%b==0) return ans;
	ans++;
	return ans;
}

class DeerInZooDivTwo {
	public:
	vector <int> getminmax(int N, int K) {
		int maxn=N-ceil(K,2);
		int minn=max(0,N-K);
		vector<int> ans;
		ans.pb(minn);
		ans.pb(maxn);
		return ans;
	}
};
