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


class Inventory {
	public:
	int monthlyOrder(vector <int> sales, vector <int> daysAvailable)
	{
		int i,j;
                int n=sz(sales);
                int n_eff=0;
                double ans=0;
                FOR(i,0,n)
                {
                    if (daysAvailable[i]>0)
                    {
                        ans+=(double)(sales[i]*30)/daysAvailable[i];
                        n_eff++;
                    }
                }
                ans/=(double)n_eff;
                ans-=1e-9;
                int ians=(int)ceil(ans);
                return ians;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(0, Arg2, monthlyOrder(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {75,120,0,93}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {24,30,0,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 103; verify_case(1, Arg2, monthlyOrder(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {8773}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {16}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16450; verify_case(2, Arg2, monthlyOrder(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1115,7264,3206,6868,7301}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,9,4,18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 36091; verify_case(3, Arg2, monthlyOrder(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Inventory ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE

//FLOATING POINT ARITHMETIC - DO