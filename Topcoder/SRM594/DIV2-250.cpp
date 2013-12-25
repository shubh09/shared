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


class FoxAndClassroom {
	public:
	string ableTo(int n, int m)
	{
		int i,j;
                string yes="Possible";
                string no="Impossible";
                if (__gcd(m,n)==1) return yes;
                else return no;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, ableTo(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; string Arg2 = "Impossible"; verify_case(1, Arg2, ableTo(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 6; string Arg2 = "Impossible"; verify_case(2, Arg2, ableTo(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 6; string Arg2 = "Impossible"; verify_case(3, Arg2, ableTo(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 7; string Arg2 = "Possible"; verify_case(4, Arg2, ableTo(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 10; int Arg1 = 10; string Arg2 = "Impossible"; verify_case(5, Arg2, ableTo(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	FoxAndClassroom ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
