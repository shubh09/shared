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

class PenguinPals {
	public:
	int findMaximumMatching(string str) 
	{
            
            int l=sz(str);
            if (l<2) return 0;
            if (str[0]==str[l-1]) return 1+findMaximumMatching(str.substr(1,l-2));
            int i;
            FOR(i,1,l)
            {
                if (str[i-1]==str[i])
                {
                    return 1+findMaximumMatching(str.substr(0,i-1)+str.substr(i+1));
                }
            }
            return l/2-1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRBRBRBB"; int Arg1 = 3; verify_case(0, Arg1, findMaximumMatching(Arg0)); }
	void test_case_1() { string Arg0 = "RRRR"; int Arg1 = 2; verify_case(1, Arg1, findMaximumMatching(Arg0)); }
	void test_case_2() { string Arg0 = "BBBBB"; int Arg1 = 2; verify_case(2, Arg1, findMaximumMatching(Arg0)); }
	void test_case_3() { string Arg0 = "RBRBRBRBR"; int Arg1 = 4; verify_case(3, Arg1, findMaximumMatching(Arg0)); }
	void test_case_4() { string Arg0 = "RRRBRBRBRBRB"; int Arg1 = 5; verify_case(4, Arg1, findMaximumMatching(Arg0)); }
	void test_case_5() { string Arg0 = "R"; int Arg1 = 0; verify_case(5, Arg1, findMaximumMatching(Arg0)); }
	void test_case_6() { string Arg0 = "RBRRBBRB"; int Arg1 = 3; verify_case(6, Arg1, findMaximumMatching(Arg0)); }
	void test_case_7() { string Arg0 = "RBRBBRBRB"; int Arg1 = 4; verify_case(7, Arg1, findMaximumMatching(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        PenguinPals ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
