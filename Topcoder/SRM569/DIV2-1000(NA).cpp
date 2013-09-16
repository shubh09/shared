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

int arr[100001];

void solve(int n,int k)
{
    if (n==0) return;
    int tn=n;
    if (k==0)
    {
        int i;
        int s=(int)sqrt(n);
        FOR(i,2,s+1)
        {
            while (n%i==0)
            {
                arr[i]++;
//                printf("here %d\n",i);
                n/=i;
            }
        }
        if (n>1) arr[n]++;
//        printf("here %d\n",n);
    }
    else
    {
        solve(n-1,k);
        solve(n,k-1);
    }
}

int MOD=1000000009;

int mulmod(int a,int b)
{
	ll t=(ll)a*b;
	if (t>=MOD) t=t%MOD;
	return t;
}


class MegaFactorialDiv2 {
	public:
	int countDivisors(int N, int K) 
	{
            clr(arr);
            solve(N,K);
            int ans=1;
            int i;
//            FOR(i,2,10) printf("%d %d\n",i,arr[i]);
            FOR(i,0,100001)
            {
                ans=mulmod(ans,arr[i]+1);
            }
            return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 6; verify_case(1, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 18; verify_case(2, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 1392; verify_case(3, Arg2, countDivisors(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 2; int Arg2 = 321266186; verify_case(4, Arg2, countDivisors(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        MegaFactorialDiv2 ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
