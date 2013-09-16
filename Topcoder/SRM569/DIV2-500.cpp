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

class TheDeviceDiv2 {
	public:
	string identify(vector <string> v) 
	{
            bool ispossible=true;
            int n=sz(v),m=sz(v[0]);
            int i,j;
            FOR(j,0,m)
            {
                //jth bit
                bool diff=false,bothone=false;
                FOR(i,0,n)
                {
                    int k;
                    FOR(k,0,n)
                    {
                        if (k!=i)
                        {
                            if (v[i][j]=='1'&&v[k][j]=='1') bothone=true;
                            if (v[i][j]!=v[k][j]) diff=true;
                            if (bothone&&diff) break;
                        }
                    }
                    if (bothone&&diff) break;
                }
                ispossible=bothone&&diff;
                if (ispossible==false) break;
            }
            if (ispossible) return "YES";
            else return "NO";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"010",
 "011",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(0, Arg1, identify(Arg0)); }
	void test_case_1() { string Arr0[] = {"1",
 "0",
 "1",
 "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, identify(Arg0)); }
	void test_case_2() { string Arr0[] = {"11111"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(2, Arg1, identify(Arg0)); }
	void test_case_3() { string Arr0[] = {"0110011",
 "0101001",
 "1111010",
 "1010010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, identify(Arg0)); }
	void test_case_4() { string Arr0[] = {"101001011",
 "011011010",
 "010110010",
 "111010100",
 "111111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(4, Arg1, identify(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TheDeviceDiv2 ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
