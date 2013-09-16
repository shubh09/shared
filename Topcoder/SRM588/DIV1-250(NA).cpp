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


class GUMIAndSongsDiv1 {
	public:
	int maxSongs(vector <int> dur, vector <int> tone, int T)
	{
		int i,j;
                vector<pii> vp;
                int s=sz(tone);
                FOR(i,0,s) vp.pb(mp(tone[i],dur[i]));
                sort(all(vp));
                vvi dp(s,vi(2,0));
                //dp[i][0]=max number of songs which can be played, such that the sequence ends with the ith song (i refers to the index in the sorted list)
                //dp[i][1]=the minimum duration of the dp[i][1] songs scheduled
                FOR(i,0,s)
                {
                    //the initialization
                    if (vp[i].second<=T)
                    {
                        dp[i][0]=1;
                        dp[i][1]=vp[i].second;
                    }
                    //finding the optimal solution
                    FOR(j,0,i)
                    {
                        int tdur=dp[j][1]-vp[j].first+vp[i].first+vp[i].second;
                        if (tdur<=T)
                        {
                            if (dp[i][0]<dp[j][0]+1)
                            {
                                dp[i][0]=dp[j][0]+1;
                                dp[i][1]=tdur;
                            }
                            else if (dp[i][0]==dp[j][0]+1)
                            {
                                if (tdur<dp[i][1])
                                {
                                    dp[i][1]=tdur;
                                }
                            }
                        }
                    }
                }
                int ans=0;
                FOR(i,0,s) ans=max(ans,dp[i][0]);
                return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 5, 4, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 17; int Arg3 = 3; verify_case(0, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100, 200, 300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 99; int Arg3 = 0; verify_case(1, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 4; verify_case(2, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {9, 11, 13, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 1; verify_case(3, Arg3, maxSongs(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {87,21,20,73,97,57,12,80,86,97,98,85,41,12,89,15,41,17,68,37,21,1,9,65,4,
 67,38,91,46,82,7,98,21,70,99,41,21,65,11,1,8,12,77,62,52,69,56,33,98,97}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {88,27,89,2,96,32,4,93,89,50,58,70,15,48,31,2,27,20,31,3,23,86,69,12,59,
 61,85,67,77,34,29,3,75,42,50,37,56,45,51,68,89,17,4,47,9,14,29,59,43,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 212; int Arg3 = 12; verify_case(4, Arg3, maxSongs(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	GUMIAndSongsDiv1 ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
