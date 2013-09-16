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
#define sd(n)					int n;scanf("%d",&n)
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;

class NinjaTurtles {
	public:
	int countOpponents(int p, int k) 
	{
            int n=0;
            int tp=0;
            while (tp<p)
            {
                n++;
                tp=3*(n/k)+(n/3);
            }
            if (tp==p) return n;
            return -1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 6; verify_case(0, Arg2, countOpponents(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 4; int Arg2 = 3; verify_case(1, Arg2, countOpponents(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 13; int Arg1 = 6; int Arg2 = -1; verify_case(2, Arg2, countOpponents(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 13; int Arg1 = 17; int Arg2 = 30; verify_case(3, Arg2, countOpponents(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 122; int Arg1 = 21; int Arg2 = 258; verify_case(4, Arg2, countOpponents(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        NinjaTurtles ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
