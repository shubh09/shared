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

int blank,cnt;
int bx,by;      //the identity of the black cell is also important
int vis2[51][51];

int dx[]={0,-1,0,1};//RULD
int dy[]={1,0,-1,0};

void dfs(int x,int y,vstr &v,vvi &vis)     //vis2 can't be passes as an argument
{
    cnt++;
    vis[x][y]=1;
    int s1=sz(v),s2=sz(v[0]);
    int i;
    FOR(i,0,4)
    {
        int x2=x+dx[i],y2=y+dy[i];
        if (x2>=0&&y2>=0&&x2<s1&&y2<s2)
        {
            if (v[x2][y2]=='.'&&vis2[x2][y2]==0)
            {
                blank++;
                vis2[x2][y2]=1;
                bx=x2;by=y2;
            }
            if (v[x2][y2]=='o'&&vis[x2][y2]==0) dfs(x2,y2,v,vis);
        }
    }
}

class FoxAndGo {
	public:
	int maxKill(vector <string> v)
	{
		int i,j;
                int s1=sz(v),s2=sz(v[0]);
                vvi vis(s1,vi(s2,0));
                int add=0;
                vvi ans_mat(s1,vi(s2,0));
                FOR(i,0,s1)
                {
                    FOR(j,0,s2)
                    {
                        if (v[i][j]=='o'&&vis[i][j]==0)
                        {
                            blank=0;cnt=0;clr(vis2);
                            dfs(i,j,v,vis);
                            if (blank==0) add+=cnt;
                            if (blank==1) ans_mat[bx][by]+=cnt;
                        }
                    }
                }
                int ans=0;
                FOR(i,0,s1) FOR(j,0,s2) ans=max(ans,ans_mat[i][j]);
                return ans+add;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 "..x..",
 ".xox.",
 ".....",
 "....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maxKill(Arg0)); }
	void test_case_1() { string Arr0[] = {"ooooo",
 "xxxxo",
 "xxxx.",
 "xxxx.",
 "ooooo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, maxKill(Arg0)); }
	void test_case_2() { string Arr0[] = {".xoxo",
 "ooxox",
 "oooxx",
 "xoxox",
 "oxoox"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(2, Arg1, maxKill(Arg0)); }
	void test_case_3() { string Arr0[] = {".......",
 ".......",
 ".......",
 "xxxx...",
 "ooox...",
 "ooox...",
 "ooox..."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, maxKill(Arg0)); }
	void test_case_4() { string Arr0[] = {".......",
 ".xxxxx.",
 ".xooox.",
 ".xo.ox.",
 ".xooox.",
 ".xxxxx.",
 "......."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, maxKill(Arg0)); }
	void test_case_5() { string Arr0[] = {"o.xox.o",
 "..xox..",
 "xxxoxxx",
 "ooo.ooo",
 "xxxoxxx",
 "..xox..",
 "o.xox.o"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(5, Arg1, maxKill(Arg0)); }
	void test_case_6() { string Arr0[] = {".......",
 "..xx...",
 ".xooox.",
 ".oxxox.",
 ".oxxxo.",
 "...oo..",
 "......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(6, Arg1, maxKill(Arg0)); }
	void test_case_7() { string Arr0[] = {".ox....",
 "xxox...",
 "..xoox.",
 "..xoox.",
 "...xx..",
 ".......",
 "......."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(7, Arg1, maxKill(Arg0)); }
	void test_case_8() { string Arr0[] = {"...................",
 "...................",
 "...o..........o....",
 "................x..",
 "...............x...",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "................o..",
 "..x................",
 "...............x...",
 "...................",
 "..................."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(8, Arg1, maxKill(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	FoxAndGo ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE

//don't name a variable 'count'
//having issues with case 5, because the white cells aren't already connected 