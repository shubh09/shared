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

class FIELDDiagrams {
    ll arr[40][40];
	public:
	long long countDiagrams(int f) 
	{
            if (f==1) return 1;
            clr(arr);
            arr[f][0]=arr[f][1]=1;      //base case; the last row
            int i;
            for (i=f-1;i>1;i--) //for all except the first row
            {
                int mx=f-i+1;   //the max number of colored squares ith row can contain
                for (int j=0;j<=mx;j++)
                {
                    //to fill arr[i][j]
                    for (int k=0;k<=j;k++)
                    {
                        arr[i][j]+=arr[i+1][k];
                    }
                }
            }
            //the first row needs to be tackled separately because it can't contain 0 colored squares
            ll ans=0;
            for (i=1;i<=f;i++)
            {
                for (int j=0;j<=i;j++)
                {
                    ans+=arr[2][j];
                }
            }
            return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 4LL; verify_case(0, Arg1, countDiagrams(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 13LL; verify_case(1, Arg1, countDiagrams(Arg0)); }
	void test_case_2() { int Arg0 = 5; long long Arg1 = 131LL; verify_case(2, Arg1, countDiagrams(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        FIELDDiagrams ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
