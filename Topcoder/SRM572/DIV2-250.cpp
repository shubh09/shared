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
#define mp(a,b)                                 make_pair(a,b)

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;

class SkiResortsEasy {
	public:
	int minCost(vector <int> arr) 
	{
            int s=sz(arr);
            int i;
            int ans=0;
            FOR(i,1,s)
            {
                if (arr[i]>arr[i-1])
                {
                    ans+=(arr[i]-arr[i-1]);
                    arr[i]=arr[i-1];
                }
            }
            return ans;
            
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {30, 20, 20, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minCost(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minCost(Arg0)); }
	void test_case_2() { int Arr0[] = {6, 8, 5, 4, 7, 4, 2, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, minCost(Arg0)); }
	void test_case_3() { int Arr0[] = {749, 560, 921, 166, 757, 818, 228, 584, 366, 88}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2284; verify_case(3, Arg1, minCost(Arg0)); }
	void test_case_4() { int Arr0[] = {712, 745, 230, 200, 648, 440, 115, 913, 627, 621, 186, 222, 741, 954, 581, 193, 266, 320, 798, 745}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6393; verify_case(4, Arg1, minCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        SkiResortsEasy ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
