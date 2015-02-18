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
#define ps(str)                                 printf("%s\n",str)

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX
#define PI 3.14159265358979323846

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<pair<int,int> > > TG;


class IdentifyingWood {
    public:
    string check(string s, string t){
            int i=0,j=0;
            int n1=sz(s),n2=sz(t);
            FOR(i,0,n1){
                if (s[i]==t[j]){
                    j++;
                }
                if (j==n2) break;
            }
            if (j==n2) return "Yep, it's wood.";
            else return "Nope.";
	}
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "absdefgh"; string Arg1 = "asdf"; string Arg2 = "Yep, it's wood."; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "oxoxoxox"; string Arg1 = "ooxxoo"; string Arg2 = "Nope."; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "oxoxoxox"; string Arg1 = "xxx"; string Arg2 = "Yep, it's wood."; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "qwerty"; string Arg1 = "qwerty"; string Arg2 = "Yep, it's wood."; verify_case(3, Arg2, check(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "string"; string Arg1 = "longstring"; string Arg2 = "Nope."; verify_case(4, Arg2, check(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    IdentifyingWood ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
