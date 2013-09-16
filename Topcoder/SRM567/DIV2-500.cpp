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

class TheSquareRootDilemma {
	public:
	int countPairs(int N, int M) 
	{
            int a;
            int ans=0;
            FOR(a,1,N+1)
            {
                int s=(int)sqrt(a);
                if (s*s==a)
                {
                    ans+=(int)sqrt(M);
                }
                else
                {
                    int j;
                    for (j=s+1;j>0;j--)
                    {
                        if (a%(j*j)==0) break;
                    }
                    int r=a/(j*j);
                    ans+=(int)sqrt(M/r);
                }
            }
            return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 3; verify_case(1, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 8; int Arg2 = 5; verify_case(2, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 310; verify_case(3, Arg2, countPairs(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TheSquareRootDilemma ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
