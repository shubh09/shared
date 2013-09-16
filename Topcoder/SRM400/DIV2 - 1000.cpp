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

void swtch2(char &c)
{
    if (c=='*') c='.';
    else c='*';
}

void swtch(vstr &v,int i,int j)
{
    //the switch at (i,j) was pressed (0-indexed)
    int s1=sz(v),s2=sz(v[0]);
    swtch2(v[i][j]);
    if (i<s1-1) swtch2(v[i+1][j]);
    if (j<s2-1) swtch2(v[i][j+1]);
    if (i>0) swtch2(v[i-1][j]);
    if (j>0) swtch2(v[i][j-1]);
    if (i>0&&j>0) swtch2(v[i-1][j-1]);
    if (i<s1-1&&j<s2-1) swtch2(v[i+1][j+1]);
    if (i>0&&j<s2-1) swtch2(v[i-1][j+1]);
    if (i<s1-1&&j>0) swtch2(v[i+1][j-1]);
}

class LightedPanels {
	public:
	int minTouch(vector <string> v) 
	{
            int s1=sz(v),s2=sz(v[0]);
            int boundary_length=s1+s2-1;
            int num=1<<boundary_length;
            int i,j,k;
            int ans=100;
            FOR(k,0,num)
            {
                int tans=0;
                bitset <15> bs(k);
                vstr v2(v);
                //the first row
                FOR(j,0,s2)
                {
                    if (bs[j])
                    {
                        //press the corresponding switch
                        swtch(v2,0,j);
                        tans++;
                    }
                }
                //the first column
                FOR(j,s2,s1+s2-1)
                {
                    if (bs[j])
                    {
                        //press the corresponding switch
                        swtch(v2,j-s2+1,0);
                        tans++;
                    }
                }
                FOR(i,1,s1)
                {
                    FOR(j,1,s2)
                    {
                        if (v2[i-1][j-1]=='.')
                        {
                            //press the switch; (i-1,j-1) needs to be lighted
                            swtch(v2,i,j);
                            tans++;
                        }
                    }
                }
                //check if all the lights are on
                FOR(i,0,s1)
                {
                    FOR(j,0,s2)
                    {
                        if (v2[i][j]=='.') break;
                    }
                    if (j!=s2) break;
                }
                if (i==s1) ans=min(ans,tans);
            }
            if (ans==100) ans=-1;
            return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"*****",
 "*...*",
 "*...*",
 "*...*",
 "*****"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minTouch(Arg0)); }
	void test_case_1() { string Arr0[] = {".*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, minTouch(Arg0)); }
	void test_case_2() { string Arr0[] = {"**.",
 "**.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minTouch(Arg0)); }
	void test_case_3() { string Arr0[] = {"*...",
 "**..",
 "..**",
 "...*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, minTouch(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        LightedPanels ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
