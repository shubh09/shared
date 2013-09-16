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
typedef vector<vector<pair<int,int> > > TG;

void dfs(TG &G,int s,vi &vis)
{
    //assumes that vis[s]=0
    vis[s]=1;
    int deg=sz(G[s]);
    int i;
    FOR(i,0,deg)
    {
        int v=G[s][i].first;
        if (vis[v]==0)
        {
            dfs(G,v,vis);
        }
    }
}

int s1,s2;

pair<int,int> vertNumber(int i,int j)
{
    return mp(i*s2+j,0);
}

class ArcadeManao {
	public:
	int shortestLadder(vector <string> level, int coinRow, int coinColumn)
	{
		int i,j,l;
                s1=sz(level);s2=sz(level[0]);
                FOR(l,0,50)
                {
                    //l is the length of the ladder
                    
                    //constructing the graph
                    TG G(s1*s2);
                    FOR(i,0,s1)
                    {
                        FOR(j,0,s2)
                        {
                            int cur=vertNumber(i,j).first;
                            if (level[i][j]=='X')
                            {
                                //horizontal
                                if (j<s2-1&&level[i][j+1]=='X') G[cur].pb(vertNumber(i,j+1));
                                if (j>0&&level[i][j-1]=='X') G[cur].pb(vertNumber(i,j-1));
                                //vertical
                                int k;
                                FOR(k,1,l+1)
                                {
                                    if (i+k<s1&&level[i+k][j]=='X') G[cur].pb(vertNumber(i+k,j));
                                    if (i-k>=0&&level[i-k][j]=='X') G[cur].pb(vertNumber(i-k,j));
                                }
                            }
                        }
                    }
                    vi vis(s1*s2,0);
                    dfs(G,vertNumber(s1-1,0).first,vis);
                    if (vis[vertNumber(coinRow-1,coinColumn-1).first]==1) return l;
                }
                return -1;      //won't ever reach here. a ladder of length 49 is enough no matter where the coin is.
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; int Arg3 = 2; verify_case(0, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"XXXX",
 "...X",
 "XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; int Arg3 = 4; verify_case(2, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; verify_case(3, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; verify_case(4, Arg3, shortestLadder(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
        {
        ArcadeManao ___test; 
        ___test.run_test(-1); 
        } 
// END CUT HERE
