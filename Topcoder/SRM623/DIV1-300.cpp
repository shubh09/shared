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
#define ps(str)                                 printf("%s\n",str)

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX
#define PI 3.14159265358979323846

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<pair<int,int> > > TG;

template<typename T>
void print_mat(vector<vector<T> > &mat)
{
    int s1=sz(mat),s2;
    int i,j;
    FOR(i,0,s1)
    {
        s2=sz(mat[i]);
        FOR(j,0,s2) cout<<mat[i][j]<<' ';
        cout<<'\n';
    }
}
template<typename Head>
void myprint(Head a)
{
    cout<<a<<'\n';
}

template<typename Head, typename... Tail>
void myprint(Head a,Tail... t)
{
    cout<<a<<' ';
    myprint(t...);
}

class UniformBoard {
	public:
	int getBoard(vector <string> board, int K)
	{
		int i,j;
                int n=sz(board);
                vvi mat_apples(n,vi(n,0)),mat_pears(n,vi(n,0)),mat_empty(n,vi(n,0));
                FOR(i,0,n) FOR(j,0,n){
                    if (board[i][j]=='.') mat_empty[i][j]++;
                    else if (board[i][j]=='A') mat_apples[i][j]++;
                    else mat_pears[i][j]++;
                    if (i>0){
                        mat_empty[i][j]+=mat_empty[i-1][j];
                        mat_apples[i][j]+=mat_apples[i-1][j];
                        mat_pears[i][j]+=mat_pears[i-1][j];
                    }
                    if (j>0){
                        mat_empty[i][j]+=mat_empty[i][j-1];
                        mat_apples[i][j]+=mat_apples[i][j-1];
                        mat_pears[i][j]+=mat_pears[i][j-1];
                    }
                    if (i>0&&j>0){
                        mat_empty[i][j]-=mat_empty[i-1][j-1];
                        mat_apples[i][j]-=mat_apples[i-1][j-1];
                        mat_pears[i][j]-=mat_pears[i-1][j-1];
                    }
                }
                int i2,j2;
                int num_empty=mat_empty[n-1][n-1];
                int num_apples=mat_apples[n-1][n-1];
                int ans=0;
//                print_mat(mat_empty);
                FOR(i,0,n) FOR(j,0,n) FOR(i2,0,i+1) FOR(j2,0,j+1){
                    int area=(i-i2+1)*(j-j2+1);
                    if (num_apples<area) continue;
                    int cur_apples=mat_apples[i][j]-(i2>0?mat_apples[i2-1][j]:0)-(j2>0?mat_apples[i][j2-1]:0)+(i2>0&&j2>0?mat_apples[i2-1][j2-1]:0);
                    int cur_pears=mat_pears[i][j]-(i2>0?mat_pears[i2-1][j]:0)-(j2>0?mat_pears[i][j2-1]:0)+(i2>0&&j2>0?mat_pears[i2-1][j2-1]:0);
                    int cur_empty=mat_empty[i][j]-(i2>0?mat_empty[i2-1][j]:0)-(j2>0?mat_empty[i][j2-1]:0)+(i2>0&&j2>0?mat_empty[i2-1][j2-1]:0);
                    if (num_empty==0){
                        if (cur_apples==area) ans=max(ans,area);
                        continue;
                    }
                    int moves=cur_empty+2*cur_pears;
//                    myprint(num_apples,area,cur_empty,cur_pears);
                    if (moves<=K) {
                        ans=max(ans,area);
//                        if (area==2) ps("ans set to 2");
                    }
//                    myprint(i,j,i2,j2,cur_apples);
                }
                return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"PPP",
 "APA",
 "A.P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAA",
 "PPP",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(3, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 0; verify_case(4, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"PPAAPA..AP",
 "PPA.APAP..",
 "..P.AA.PPP",
 "P.P..APAA.",
 "P.P..P.APA",
 "PPA..AP.AA",
 "APP..AAPAA",
 "P.P.AP...P",
 ".P.A.PAPPA",
 "..PAPAP..P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; verify_case(5, Arg2, getBoard(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	UniformBoard ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
