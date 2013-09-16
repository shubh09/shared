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

int holes[]={1,0,0,0,1,0,1,0,2,1};

class DigitHoles {
	public:
	int numHoles(int n)
	{
            int ans=0;
            while (n>0)
            {
                int digit=n%10;
                ans+=(holes[digit]);
                n/=10;
            }
            return ans;
	}
	

	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 42; int Arg1 = 1; verify_case(0, Arg1, numHoles(Arg0)); }
	void test_case_1() { int Arg0 = 669; int Arg1 = 3; verify_case(1, Arg1, numHoles(Arg0)); }
	void test_case_2() { int Arg0 = 688; int Arg1 = 5; verify_case(2, Arg1, numHoles(Arg0)); }
	void test_case_3() { int Arg0 = 123; int Arg1 = 0; verify_case(3, Arg1, numHoles(Arg0)); }
	void test_case_4() { int Arg0 = 456; int Arg1 = 2; verify_case(4, Arg1, numHoles(Arg0)); }
	void test_case_5() { int Arg0 = 789; int Arg1 = 3; verify_case(5, Arg1, numHoles(Arg0)); }



};
// BEGIN CUT HERE
int main()
        {
        DigitHoles ___test; 
        ___test.run_test(-1); 
        } 
// END CUT HERE