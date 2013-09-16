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

class SpidersOnTheGrid {
	public:
	int find(vector <string> v) 
	{
            int s1=sz(v);
            int s2=sz(v[0]);
            vvi arr(s1,vi(s2,0));
            int i,j;
            FOR(i,0,s1)
            {
                FOR(j,0,s2)
                {
                    if (j==0&&v[i][j]=='W') continue;
                    if (i==0&&v[i][j]=='N') continue;
                    if (i==s1-1&&v[i][j]=='S') continue;
                    if (j==s2-1&&v[i][j]=='E') continue;
                    char c=v[i][j];
                    if (c=='W') arr[i][j-1]++;
                    if (c=='S') arr[i+1][j]++;
                    if (c=='N') arr[i-1][j]++;
                    if (c=='E') arr[i][j+1]++;
                }
            }
            int ans=0;
            FOR(i,0,s1)
            {
                FOR(j,0,s2)
                {
                    if (arr[i][j]==0) ans++;
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
	void test_case_0() { string Arr0[] = {"EW","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arr0[] = {"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arr0[] = {"EW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arr0[] = {"ESW","ENW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arr0[] = {"E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        SpidersOnTheGrid ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
