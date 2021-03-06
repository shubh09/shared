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

int digsum(int a)
{
    int ans=0;
    while (a>0)
    {
        ans+=(a%10);
        a/=10;
    }
    return ans;
}

class MinimalDifference {
	public:
	int findNumber(int A, int B, int C) 
	{
            int i;
            int ans;
            int diff=1000000000;
            int tar=digsum(C);
            FOR(i,A,B+1)
            {
                if (abs(digsum(i)-tar)<diff)
                {
                    diff=abs(digsum(i)-tar);
                    ans=i;
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
	void test_case_0() { int Arg0 = 1; int Arg1 = 9; int Arg2 = 10; int Arg3 = 1; verify_case(0, Arg3, findNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 11; int Arg1 = 20; int Arg2 = 20; int Arg3 = 11; verify_case(1, Arg3, findNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 999; int Arg3 = 1; verify_case(2, Arg3, findNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 1000; int Arg2 = 99; int Arg3 = 189; verify_case(3, Arg3, findNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1987; int Arg1 = 9123; int Arg2 = 1; int Arg3 = 2000; verify_case(4, Arg3, findNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        MinimalDifference ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
