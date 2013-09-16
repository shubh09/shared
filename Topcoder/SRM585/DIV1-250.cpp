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

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<pair<int,int> > > TG;

#define MAXN 1000001

int res[MAXN];

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


void solve()
{
    int i;
    vi sum(MAXN);
    res[0]=1;
    res[1]=1;
    res[2]=3;
    sum[0]=1;
    sum[1]=2;sum[2]=5;
    FOR(i,3,MAXN)
    {
        res[i]=addmod(addmod(sum[i-2],sum[i-2]),1);
        sum[i]=addmod(sum[i-1],res[i]);
    }
}


class TrafficCongestion {
	public:
	int theMinCars(int treeHeight)
	{
		int i,j;
                solve();
                return res[treeHeight];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, theMinCars(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; verify_case(1, Arg1, theMinCars(Arg0)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; verify_case(2, Arg1, theMinCars(Arg0)); }
	void test_case_3() { int Arg0 = 585858; int Arg1 = 548973404; verify_case(3, Arg1, theMinCars(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	TrafficCongestion ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
        