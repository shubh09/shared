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


class ConvertibleStrings {
	public:
	int leastRemovals(string A, string B)
	{
		int i,j;
                string str="ABCDEFGHI";
                int n=sz(A);
                int ans=n;
                do
                {
                    int tans=0;
                    FOR(i,0,n) if (str[A[i]-'A']!=B[i]) tans++;
                    ans=min(ans,tans);
                }while (next_permutation(all(str)));
                return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "DD"; string Arg1 = "FF"; int Arg2 = 0; verify_case(0, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAAA"; string Arg1 = "ABCD"; int Arg2 = 3; verify_case(1, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AAIAIA"; string Arg1 = "BCDBEE"; int Arg2 = 3; verify_case(2, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABACDCECDCDAAABBFBEHBDFDDHHD"; string Arg1 = "GBGCDCECDCHAAIBBFHEBBDFHHHHE"; int Arg2 = 9; verify_case(3, Arg2, leastRemovals(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	ConvertibleStrings ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
