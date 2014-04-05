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

vector<ll> p3;

bool solve(ll x,ll y,int k)//
{
//    cout<<x<<' '<<y<<' '<<k<<endl;
    if (k==0)
    {
        if (abs(x-y)==1&&(x==0||y==0)) return true;
        return false;
    }
    bool ans1=false,ans2=false;
    int num=(p3[k]+1)/2;
    if (x<=-num) ans1=solve(x+p3[k],y,k-1);
    else if (x>=num) ans1=solve(x-p3[k],y,k-1);
    if (y<=-num) ans2=solve(x,y+p3[k],k-1);
    else if (y>=num) ans2=solve(x,y-p3[k],k-1);
    return (ans1||ans2);
}

class PowerOfThree {
	public:
	string ableToGet(ll x, ll y)
	{
		int i,j;
                ll p=1;
                string yes="Possible",no="Impossible";
                FOR(i,0,21)
                {
                    p3.pb(p);
                    p*=(ll)3;
                }
                if (x==0&&y==0) return yes;
                int k;
                FOR(k,0,21) if (solve(x,y,k)) return yes;
                return no;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 2; string Arg2 = "Possible"; verify_case(1, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 9; string Arg2 = "Impossible"; verify_case(2, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 0; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "Impossible"; verify_case(4, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = -6890; int Arg1 = 18252; string Arg2 = "Possible"; verify_case(5, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 1000000000; int Arg1 = -1000000000; string Arg2 = "Impossible"; verify_case(6, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = -5; int Arg1 = 0; string Arg2 = "Possible"; verify_case(7, Arg2, ableToGet(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	PowerOfThree ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
