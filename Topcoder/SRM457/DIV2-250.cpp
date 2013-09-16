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
#include <assert.h>

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

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;

class TheSquareDivTwo {
	public:
	vector <string> solve(vector <string> b) 
	{
            int s1=sz(b),s2=sz(b[0]);
            assert(s1==s2);
            vi arr(s1,0);
            int i,j;
            FOR(i,0,s1)
            {
                FOR(j,0,s2)
                {
                    if (b[i][j]=='C') arr[i]++;
                }
            }
            vstr ans(s2,string(s1,'C'));
            FOR(j,0,s2)
            {
                int numdot=s2-arr[j];
                FOR(i,0,numdot)
                {
                    ans[i][j]='.';
                }
            }
            return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"..",
 "C."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..", ".C" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {"CC",
 ".C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"C.", "CC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {".C..",
 "CC.C",
 "..C.",
 "CCCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"...C", ".C.C", ".C.C", "CCCC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"...CCC",
 "...CCC",
 "...CCC",
 "CCC...",
 "CCC...",
 "CCC..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"......", "......", "......", "CCCCCC", "CCCCCC", "CCCCCC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { string Arr0[] = {".....C",
 "....CC",
 "...CCC",
 "..CCCC",
 ".CCCCC",
 "CCCCCC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".....C", "....CC", "...CCC", "..CCCC", ".CCCCC", "CCCCCC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, solve(Arg0)); }
	void test_case_5() { string Arr0[] = {"C.C..C.C..C..C.",
 "CCC...C..CCC.C.",
 "......CC...CCCC",
 ".C..CC.C.C.C.C.",
 "C....C.C......C",
 ".....C..CCCCC.C",
 "CCC.......CCCCC",
 "..C.C..C.C...C.",
 "CCC....CCC.CC..",
 "CC.CCCC.CCCC...",
 ".C..C.CC.C.CC.C",
 "C.CCCC..CC..C.C",
 ".CCCC.CCCCCC...",
 "..C...C.CCC.CC.",
 "CCCC..CCC.C...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"...............", "...............", "...............", "...............", "...............", ".........C..C..", ".........C.CC..", ".C....C.CCCCC.C", ".C.C.CC.CCCCCCC", "CCCC.CC.CCCCCCC", "CCCC.CCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TheSquareDivTwo ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
