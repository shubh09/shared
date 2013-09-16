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


class FoxAndGomoku {
	public:
	string win(vector <string> v)
	{
		int i,j;
                string yes="found",no="not found";
                int n=sz(v);
                vvi mat(n,vi(n,0));
                FOR(i,0,n) mat[i][0]=(v[i][0]=='o');
                FOR(j,1,n)
                {
                    FOR(i,0,n)
                    {
                        mat[i][j]=mat[i][j-1]+(v[i][j]=='o');
                        if (mat[i][j]==mat[i][j-1]) mat[i][j]=0;
                        if (mat[i][j]>=5) return yes;
                    }
                }
                vi tmp(n,0);
                fill(all(mat),tmp);
                FOR(j,0,n) mat[0][j]=(v[0][j]=='o');
                FOR(i,1,n)
                {
                    FOR(j,0,n)
                    {
                        mat[i][j]=mat[i-1][j]+(v[i][j]=='o');
                        if (mat[i][j]==mat[i-1][j]) mat[i][j]=0;
                        if (mat[i][j]>=5) return yes;
                    }
                }
                int s;
                FOR(s,0,n+n-1)
                {
                    int curr=0;
                    FOR(i,0,s+1)
                    {
                        j=s-i;
                        if (j<n&&i<n)
                        {
                            int pcurr=curr;
                            curr+=(v[i][j]=='o');
                            if (pcurr==curr) curr=0;
                            if (curr>=5) return yes;
                        }
                    }
                }
                FOR(s,-n,n+1)
                {
                    int curr=0;
                    FOR(i,0,n)
                    {
                        j=s+i;
                        if (j>=0&&j<n)
                        {
                            int pcurr=curr;
                            curr+=(v[i][j]=='o');
                            if (pcurr==curr) curr=0;
                            if (curr>=5) return yes;
                        }
                    }
                }
                return no;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"....o.",
 "...o..",
 "..o...",
 ".o....",
 "o.....",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "found"; verify_case(0, Arg1, win(Arg0)); }
	void test_case_1() { string Arr0[] = {"oooo.",
 ".oooo",
 "oooo.",
 ".oooo",
 "....."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "not found"; verify_case(1, Arg1, win(Arg0)); }
	void test_case_2() { string Arr0[] = {"oooo.",
 ".oooo",
 "oooo.",
 ".oooo",
 "....o"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "found"; verify_case(2, Arg1, win(Arg0)); }
	void test_case_3() { string Arr0[] = {"o.....",
 ".o....",
 "..o...",
 "...o..",
 "....o.",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "found"; verify_case(3, Arg1, win(Arg0)); }
	void test_case_4() { string Arr0[] = {"o....",
 "o.o..",
 "o.o.o",
 "o.o..",
 "o...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "found"; verify_case(4, Arg1, win(Arg0)); }
	void test_case_5() { string Arr0[] = {"..........",
 "..........",
 "..oooooo..",
 "..o.......",
 "..o.......",
 "..oooooo..",
 ".......o..",
 ".......o..",
 "..oooooo..",
 ".........."}
 
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "found"; verify_case(5, Arg1, win(Arg0)); }
	void test_case_6() { string Arr0[] = {"..........",
 "..........",
 "..oooo.o..",
 "..o.......",
 "..o.......",
 "..o.oooo..",
 ".......o..",
 ".......o..",
 "..oooo.o..",
 ".........."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "not found"; verify_case(6, Arg1, win(Arg0)); }
	void test_case_7() { string Arr0[] = {"ooooo",
 "ooooo",
 "ooooo",
 "ooooo",
 "ooooo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "found"; verify_case(7, Arg1, win(Arg0)); }
	void test_case_8() { string Arr0[] = {".....",
 ".....",
 ".....",
 ".....",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "not found"; verify_case(8, Arg1, win(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	FoxAndGomoku ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE

//made a few errors with indices. good practice problem for practicing traversing the array diagonally; harder than the usual DIV2-250's. There must exist a simpler solution