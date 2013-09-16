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

ll solve(int emp,int n)
{
    if (n>emp) return 0;
    ll ans=1LL;
    int i;
    FOR(i,0,n)
    {
        ans*=emp;
        emp--;
    }
    return ans;
}


class MovieSeating {
	public:
	long long getSeatings(int n, vector <string> hall)
	{
            int s1=sz(hall);
            int s2=sz(hall[0]);
            int i,j;
            vi row(s1,0),col(s2,0);
            ll ansif1=0,ans=0;
            FOR(i,0,s1)
            {
                FOR(j,0,s2)
                {
                    row[i]+=(hall[i][j]=='.');
                }
                ansif1+=(ll)(row[i]);
            }
            FOR(j,0,s2) FOR(i,0,s1) col[j]+=(hall[i][j]=='.');
            if (n==1) return ansif1;
            FOR(i,0,s1)
            {
                int emp=row[i];
                ans+=solve(emp,n);
            }
            FOR(i,0,s2)
            {
                int emp=col[i];
                ans+=solve(emp,n);
            }
            return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arr1[] = { ".#..",
  ".##.",
  "...." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 34LL; verify_case(0, Arg2, getSeatings(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = { "..#",
  ".##",
  "..." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 16LL; verify_case(1, Arg2, getSeatings(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; string Arr1[] = { "..####..", 
  ".###.##.",
  ".######.",
  "#.#.#.#." }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(2, Arg2, getSeatings(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; string Arr1[] = { "........" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 40320LL; verify_case(3, Arg2, getSeatings(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
        {
        MovieSeating ___test; 
        ___test.run_test(-1); 
        } 
// END CUT HERE
