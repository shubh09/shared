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


class GearsDiv2 {
	public:
	int getmin(string str)
	{
		int i,j,k;
                int len=sz(str);
                
                //misunderstood the question
                //need to remove the annoying cyclicity of the problem
                char prev=str[0];
                int ans=0;
                //assuming that the first character is present in the solution
                bool lastChosen=true;   //whether or not the last char of str is chosen to make up the desired ring
                FOR(i,1,len)
                {
                    if (str[i]==prev)
                    {
                        ans++;
                        prev='-';
                        if (i==len-1) lastChosen=false;
                    }
                    else prev=str[i];
                }
                if (lastChosen&&str[0]==str[len-1]) ans++;
                int ans2=0;
                //assuming that the first character is not present in the solution
                prev=str[1];
                FOR(i,1,len)
                {
                    if (str[i]==prev)
                    {
                        ans2++;
                        prev='-';
                    }
                    else prev=str[i];
                }
                return max(ans,ans2);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LRRR"; int Arg1 = 1; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "RRR"; int Arg1 = 2; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "LRLR"; int Arg1 = 0; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "LRLLRRLLLRRRLLLL"; int Arg1 = 6; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR"; int Arg1 = 14; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	GearsDiv2 ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
