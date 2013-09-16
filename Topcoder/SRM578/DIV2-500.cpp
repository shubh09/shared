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
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)
#define pb(n)                                   push_back(n)
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define clr(a)                                  memset(a,0,sizeof(a))

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;

int vis[50][50];

ll MOD=(ll) 1e9+7;

int addmod(int a,int b)
{
	ll t=(ll)a+b;
	if (t>=MOD) t=t%MOD;
	return t;
}

int submod(int a,int b)
{
    //assuming both a and b are positive and <MOD
    int t=a-b;
    t=t<0?t+MOD:t;
    return t;
}

int mulmod(int a,int b)
{
	ll t=(ll)a*b;
	if (t>=MOD) t=t%MOD;
	return t;
}


int epowmod(int a,int p)
{
	if (p==0) return 1;
	int t=epowmod(a,p/2);
	t=mulmod(t,t);
	if (p&1) t=mulmod(t,a);
	return t;
}


void dfs(vstr &v,int x,int y,int d)
{
    int s1=sz(v),s2=sz(v[0]);
    if (x<0||y<0||x>s1-1||y>s2-1) return;
    if (vis[x][y]==1) return;
    if (v[x][y]=='.') return;
    vis[x][y]=1;
    int dis,i,j;
    FOR(dis,1,d+1)
    {
        FOR(i,0,dis+1)
        {
            j=dis-i;
            dfs(v,x+i,y+j,d);
            dfs(v,x-i,y+j,d);
            dfs(v,x+i,y-j,d);
            dfs(v,x-i,y-j,d);
        }
    }
}

int solve(vstr v,int d)
{
    int s1=sz(v),s2=sz(v[0]);
    int i,j;
    int ans=0;
    clr(vis);
    FOR(i,0,s1)
    {
        FOR(j,0,s2)
        {
            if (vis[i][j]==0&&v[i][j]!='.') 
            {
                dfs(v,i,j,d);
                ans++;
            }
        }
    }
    return ans;
}


class GooseInZooDivTwo {
	public:
	int count(vector <string> field, int dist) {
            int numConnectedComponents=solve(field,dist);
            return submod(epowmod(2,numConnectedComponents),1);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"vvv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 7; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"vvv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"v.v..................v............................"
,".v......v..................v.....................v"
,"..v.....v....v.........v...............v......v..."
,".........vvv...vv.v.........v.v..................v"
,".....v..........v......v..v...v.......v..........."
,"...................vv...............v.v..v.v..v..."
,".v.vv.................v..............v............"
,"..vv.......v...vv.v............vv.....v.....v....."
,"....v..........v....v........v.......v.v.v........"
,".v.......v.............v.v..........vv......v....."
,"....v.v.......v........v.....v.................v.."
,"....v..v..v.v..............v.v.v....v..........v.."
,"..........v...v...................v..............v"
,"..v........v..........................v....v..v..."
,"....................v..v.........vv........v......"
,"..v......v...............................v.v......"
,"..v.v..............v........v...............vv.vv."
,"...vv......v...............v.v..............v....."
,"............................v..v.................v"
,".v.............v.......v.........................."
,"......v...v........................v.............."
,".........v.....v..............vv.................."
,"................v..v..v.........v....v.......v...."
,"........v.....v.............v......v.v............"
,"...........v....................v.v....v.v.v...v.."
,"...........v......................v...v..........."
,"..........vv...........v.v.....................v.."
,".....................v......v............v...v...."
,".....vv..........................vv.v.....v.v....."
,".vv.......v...............v.......v..v.....v......"
,"............v................v..........v....v...."
,"................vv...v............................"
,"................v...........v........v...v....v..."
,"..v...v...v.............v...v........v....v..v...."
,"......v..v.......v........v..v....vv.............."
,"...........v..........v........v.v................"
,"v.v......v................v....................v.."
,".v........v................................v......"
,"............................v...v.......v........."
,"........................vv.v..............v...vv.."
,".......................vv........v.............v.."
,"...v.............v.........................v......"
,"....v......vv...........................v........."
,"....vv....v................v...vv..............v.."
,".................................................."
,"vv........v...v..v.....v..v..................v...."
,".........v..............v.vv.v.............v......"
,".......v.....v......v...............v............."
,"..v..................v................v....v......"
,".....v.....v.....................v.v......v......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 797922654; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
    int main()
        {
        GooseInZooDivTwo ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 

