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

void print_mat(vvi &mat)
{
    int s1=sz(mat),s2=sz(mat[0]);
    int i,j;
    FOR(i,0,s1)
    {
        FOR(j,0,s2) cout<<mat[i][j]<<' ';
        cout<<'\n';
    }
}

class ElephantDrinkingEasy {
	public:
	int maxElephants(vector <string> v)
	{
		int i,j,k;
                int n=sz(v);
                int N=4*n;
                int ans=0;
                FOR(i,0,1<<N)
                {
                    vvi mat(n+2,vi(n+2,0));
                    FOR(j,0,n) if (i&(1<<j)) mat[0][j+1]=1;
                    FOR(j,0,n) if (i&(1<<(j+(n)))) mat[j+1][0]=1;
                    FOR(j,0,n) if (i&(1<<(j+2*(n)))) mat[j+1][n+1]=1;
                    FOR(j,0,n) if (i&(1<<(j+3*(n)))) mat[n+1][j+1]=1;
                    bool succ=true;
                    FOR(j,0,n)
                    {
                        if (mat[0][j+1]==1)
                        {
                            FOR(k,1,n+1)
                            {
                                if (mat[k][j+1]==1) succ=false;
                                mat[k][j+1]=1;
                                if (v[k-1][j]=='Y') break;
                            }
                            if (k==n+1) succ=false;
                        }
                        if (!succ) break;
                    }
                    FOR(j,0,n)
                    {
                        if (mat[j+1][0]==1)
                        {
                            FOR(k,1,n+1)
                            {
                                if (mat[j+1][k]==1) succ=false;
                                mat[j+1][k]=1;
                                if (v[j][k-1]=='Y') break;
                            }
                            if (k==n+1) succ=false;
                        }
                        if (!succ) break;
                    }
                    FOR(j,0,n)
                    {
                        if (mat[j+1][n+1]==1)
                        {
                            for(k=n;k>0;k--)
                            {
                                if (mat[j+1][k]==1) succ=false;
                                mat[j+1][k]=1;
                                if (v[j][k-1]=='Y') break;
                            }
                            if (k==0) succ=false;
                        }
                        if (!succ) break;
                    }
                    FOR(j,0,n)
                    {
                        if (mat[n+1][j+1]==1)
                        {
                            for(k=n;k>0;k--)
                            {
                                if (mat[k][j+1]==1) succ=false;
                                mat[k][j+1]=1;
                                if (v[k-1][j]=='Y') break;
                            }
                            if (k==0) succ=false;
                        }
                        if (!succ) break;
                    }
                    if (succ)
                    {
//                        if (__builtin_popcount(i)==6) print_mat(mat),cout<<endl;
                        ans=max(ans,__builtin_popcount(i));
                    }
                }
                return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NNNNN",
 "NNYYN",
 "NYNNN",
 "NNYNN",
 "NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, maxElephants(Arg0)); }
	void test_case_1() { string Arr0[] = {"YYY",
 "YYY",
 "YYY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, maxElephants(Arg0)); }
	void test_case_2() { string Arr0[] =  {"YNYN",
  "NNYY",
  "YYNN",
  "YYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, maxElephants(Arg0)); }
	void test_case_3() { string Arr0[] =  {"YNYN",
  "YNYY",
  "YYNN",
  "YYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, maxElephants(Arg0)); }
	void test_case_4() { string Arr0[] = {"YYNYN",
 "NYNNY",
 "YNYNN",
 "YYNYY",
 "YYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, maxElephants(Arg0)); }
	void test_case_5() { string Arr0[] = {"YYNYN",
 "NYNYY",
 "YNYYN",
 "YYNYY",
 "YYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(5, Arg1, maxElephants(Arg0)); }
	void test_case_6() { string Arr0[] = {"NN",
 "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, maxElephants(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	ElephantDrinkingEasy ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
