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

int ndigits(int a)
{
    int ans=0;
    while (a>0)
    {
        a/=10;
        ans++;
    }
    return ans;
}

string int2str(int n)
{
    stringstream ss;
    string ans;
    ss<<n;
    ss>>ans;
    return ans;
}

int dxor(int a,int b)
{
    string as=int2str(a),bs=int2str(b);
    if (sz(as)<sz(bs)) while (sz(as)!=sz(bs)) as="0"+as;
    else while (sz(as)!=sz(bs)) bs="0"+bs;
    int l=sz(as);
    int i,ans=0;
    FOR(i,0,l)
    {
        int cn=(as[i]-'0')^(bs[i]-'0');
        cn%=10;
        ans=ans*10+cn;
    }
    return ans;
}

int dxor2(int a,int b)
{
    int ans=0,p10=1;
    
    while (a>0||b>0)
    {
        int x=a%10,y=b%10;
        int z=(x^y)%10;
        ans+=(z*p10);
        p10*=10;
        a/=10;
        b/=10;
    }
    return ans;
}

class DoubleXor {
	public:
	int calculate(int N) 
	{
            int ans=N;
            for(int i=N-1;i>0;i--)
            {
//                printf("%d ",i);
               ans=dxor2(i,ans); 
               //dxor gave tle
            }
            return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, calculate(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; verify_case(1, Arg1, calculate(Arg0)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 0; verify_case(2, Arg1, calculate(Arg0)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 11; verify_case(3, Arg1, calculate(Arg0)); }
	void test_case_4() { int Arg0 = 102; int Arg1 = 103; verify_case(4, Arg1, calculate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        DoubleXor ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
