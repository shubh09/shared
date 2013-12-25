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

int dx[]={-1,1,0,0,-1,1};
int dy[]={0,0,-1,1,1,-1};

bool is2colorable=true;

bool isInRange(int x,int y,int n)
{
    if (x>=0&&y>=0&&x<n&&y<n) return true;
    return false;
}

void dfs(int x,int y,vvi &vis,int prev_color,vector<string> v)
{
    if (!is2colorable) return;
    cout<<"visiting "<<x<<" "<<y;
    int n=sz(v);
    if (prev_color==-1) vis[x][y]=0;
    else vis[x][y]=1-prev_color;
    int cur_color=vis[x][y];
    cout<<" colored "<<cur_color<<endl;
    int i,j;
    FOR(i,0,6)
    {
        int x2=x+dx[i],y2=y+dy[i];
        if (isInRange(x2,y2,n)&&v[x2][y2]=='X')
        {
            if (vis[x2][y2]==cur_color)
            {
                is2colorable=false;
                return;
            }
            if (vis[x2][y2]==-1)
            {
                dfs(x2,y2,vis,cur_color,v);
            }
        }
    }
}

//int dx[]={1,1};
//int dy[]={-1,0};
class HexagonalBoard {
	public:
	int minColors(vector <string> v)
	{
		int i,j;
                bool n1,n2,n3;
                n1=n2=n3=false;
                int n=sz(v);
                vvi vis(n,vi(n,-1));
                is2colorable=true;
                FOR(i,0,n)
                {
                    FOR(j,0,n)
                    {
                        if (v[i][j]=='X')
                        {
                            n1=true;
                            int k;

                            FOR(k,0,6)
                            {
                                int x=i+dx[k],y=j+dy[k];
                                if (x>=0&&y>=0&&x<n&&y<n) if (v[x][y]=='X') n2=true;
                            }
                            
                            int x2=i+1,y2=j-1,x3=i+1,y3=j;
                            if (x2>=0&&x3>=0&&y2>=0&&y3>=0&&x2<n&&x3<n&&y2<n&&y3<n&&v[x2][y2]=='X'&&v[x3][y3]=='X') n3=true;
                            x2=i-1;y2=j;x3=i-1;y3=j+1;
                            if (x2>=0&&x3>=0&&y2>=0&&y3>=0&&x2<n&&x3<n&&y2<n&&y3<n&&v[x2][y2]=='X'&&v[x3][y3]=='X') n3=true;
                            if (vis[i][j]==-1) dfs(i,j,vis,-1,v);
                        }
                    }
                }
                if (!is2colorable) n3=true;
                if (n3) return 3;
                if (n2) return 2;
                if (n1) return 1;
                return 0;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"---",
 "---",
 "---"}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, minColors(Arg0)); }
	void test_case_1() { string Arr0[] = {"-X--",
 "---X",
 "----",
 "-X--"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minColors(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXXX",
 "---X",
 "---X",
 "---X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minColors(Arg0)); }
	void test_case_3() { string Arr0[] = {"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minColors(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	HexagonalBoard ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
	