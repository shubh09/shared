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

class TopFox {
	public:
	int possibleHandles(string f, string g)
	{
            set<string> st;
            int l1=sz(f),l2=sz(g);
            int i,j;
            FOR(i,1,l1+1)
            {
                FOR(j,1,l2+1)
                {
                    string str1=f.substr(0,i);
                    string str2=g.substr(0,j);
                    str1.append(str2);
                    st.insert(str1);
                }
            }
            return sz(st);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; string Arg1 = "cd"; int Arg2 = 4; verify_case(0, Arg2, possibleHandles(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abb"; string Arg1 = "bbc"; int Arg2 = 7; verify_case(1, Arg2, possibleHandles(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "fox"; string Arg1 = "ciel"; int Arg2 = 12; verify_case(2, Arg2, possibleHandles(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abbbb"; string Arg1 = "bbbbbbbc"; int Arg2 = 16; verify_case(3, Arg2, possibleHandles(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "abxy"; string Arg1 = "xyxyxc"; int Arg2 = 21; verify_case(4, Arg2, possibleHandles(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "ababababab"; string Arg1 = "bababababa"; int Arg2 = 68; verify_case(5, Arg2, possibleHandles(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
        {
        TopFox ___test; 
        ___test.run_test(-1); 
        } 
// END CUT HERE
