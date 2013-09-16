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

int comp(string s1,string s2)   //returns 1 if s1 is greater; assumes no leading zeroes
{
    int len=sz(s1);
    int i;
    FOR(i,0,len)
    {
        if (s1[i]>s2[i]) return 1;
        if (s1[i]<s2[i]) return -1;
    }
    return 0;
}

class SwappingDigits {
	public:
	string minNumber(string num)
	{
            int i,j;
            int n=sz(num);
            string ans=num;
            FOR(i,0,n)
            {
                FOR(j,i+1,n)
                {
                    string temp_str=num;
                    if (i>0||temp_str[j]!='0') swap(temp_str[i],temp_str[j]);
                    if (comp(temp_str,ans)<0) ans=temp_str;
                }
            }
            return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "596"; string Arg1 = "569"; verify_case(0, Arg1, minNumber(Arg0)); }
	void test_case_1() { string Arg0 = "93561"; string Arg1 = "13569"; verify_case(1, Arg1, minNumber(Arg0)); }
	void test_case_2() { string Arg0 = "5491727514"; string Arg1 = "1491727554"; verify_case(2, Arg1, minNumber(Arg0)); }
	void test_case_3() { string Arg0 = "10234"; string Arg1 = "10234"; verify_case(3, Arg1, minNumber(Arg0)); }
	void test_case_4() { string Arg0 = "93218910471211292416"; string Arg1 = "13218910471211292496"; verify_case(4, Arg1, minNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
        {
        SwappingDigits ___test; 
        ___test.run_test(-1); 
        } 
// END CUT HERE
