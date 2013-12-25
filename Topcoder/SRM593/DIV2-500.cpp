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


class WolfDelaymaster {
	public:
	string check(string str)
	{
            string yes="VALID";
            string no="INVALID";
            int i,j;
            int n=sz(str);
            i=0;j=0;
            int pi;
            while (i<n)
            {
                pi=i;
                int c1=0,c2=0,c3=0,c4=0;
                while (i<n&&str[i]=='w') i++;
                c1=i-pi;;
                while (i<n&&str[i]=='o') i++;
                c2=i-c1-pi;
                while (i<n&&str[i]=='l') i++;
                c3=i-c2-c1-pi;
                while (i<n&&str[i]=='f') i++;
                c4=i-c3-c2-c1-pi;
                printf("%d %d %d %d\n",c1,c2,c3,c4);
                if (c1!=c2||c2!=c3||c3!=c4) return no;
            }
            return yes;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "wolf"; string Arg1 = "VALID"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { string Arg0 = "wwolfolf"; string Arg1 = "INVALID"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { string Arg0 = "wolfwwoollffwwwooolllfffwwwwoooollllffff"; string Arg1 = "VALID"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { string Arg0 = "flowolf"; string Arg1 = "INVALID"; verify_case(3, Arg1, check(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	WolfDelaymaster ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
