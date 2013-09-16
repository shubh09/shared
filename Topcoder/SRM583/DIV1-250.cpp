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

int norm(int num,int n)
{
    num%=n;
    if (num<0) num+=n;
    return num;
}

int bfs(int sc,int ec,vvi &G)
{
    if (sc==ec) return 0;
    int n=sz(G);
    vi vis(n,0);
    queue<pair<int,int> > q;
    vis[sc]=1;
    q.push(mp(sc,0));
    while (!q.empty())
    {
        pair<int,int> temp=q.front();
        q.pop();
        int v=temp.first;
        int num=temp.second;
        //v can't be ec because we check while pushing
        int deg=sz(G[v]);
        int i;
        FOR(i,0,deg)
        {
            int u=G[v][i];
            if (u==ec) return num+1;
            if (vis[u]==0)
            {
                vis[u]=1;
                q.push(mp(u,num+1));
            }
        }
    }
    return -1;
}

class TravelOnMars {
	public:
	int minTimes(vector <int> arr, int sc, int ec)
	{
		int i,j;
                int n=sz(arr);
                vvi G(n);
                FOR(i,0,n)
                {
                    int d=arr[i];
                    FOR(j,1,d+1)
                    {
                        G[i].pb(norm(i+j,n));
                        G[i].pb(norm(i-j,n));
                    }
                }
                return bfs(sc,ec,G);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; int Arg3 = 2; verify_case(0, Arg3, minTimes(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {2,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; int Arg3 = 3; verify_case(1, Arg3, minTimes(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2,1,1,2,1,2,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 6; int Arg3 = 3; verify_case(2, Arg3, minTimes(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {3,2,1,1,3,1,2,2,1,1,2,2,2,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 13; int Arg3 = 4; verify_case(3, Arg3, minTimes(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
        {
        TravelOnMars ___test; 
        ___test.run_test(-1); 
        } 
// END CUT HERE
