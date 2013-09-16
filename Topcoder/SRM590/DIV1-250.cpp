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


class FoxAndChess {
	public:
	string ableToMove(string str, string str2) 
  { 
            string np="Impossible",pp="Possible"; 
    int i,j; 
    string sstr,sstr2;
                int n=sz(str); 
                FOR(i,0,n) if (str[i]!='.') sstr.pb(str[i]);
                FOR(i,0,n) if (str2[i]!='.') sstr2.pb(str2[i]);
                if (sstr.compare(sstr2)!=0) return np;
                vi arr1(500,0); 
                vi arr2(500,0); 
                FOR(i,0,n) arr1[str[i]]++; 
                FOR(i,0,n) arr2[str2[i]]++; 
                FOR(i,0,500) if (arr1[i]!=arr2[i]) return np; 
                vi dp11(n,0),dp12(n,0); 
                dp11[0]=(str[0]=='R');dp12[0]=(str2[0]=='R'); 
                FOR(i,1,n) dp11[i]=dp11[i-1]+(str[i]=='R'); 
                FOR(i,1,n) dp12[i]=dp12[i-1]+(str2[i]=='R'); 
                FOR(i,0,n) if (dp11[i]<dp12[i]) return np; 
//                FOR(i,0,sz(dp11)) printf("%d ",dp11[i]); printf("\n"); 
//                FOR(i,0,sz(dp12)) printf("%d ",dp12[i]); printf("\n"); 
                vi dp21(n,0),dp22(n,0); 
                dp21[n-1]=(str[n-1]=='L');dp22[n-1]=(str2[n-1]=='L'); 
                for (i=n-2;i>=0;i--) dp21[i]=dp21[i+1]+(str[i]=='L'); 
                for (i=n-2;i>=0;i--) dp22[i]=dp22[i+1]+(str2[i]=='L'); 
//                FOR(i,0,sz(dp21)) printf("%d ",dp21[i]); printf("\n"); 
//                FOR(i,0,sz(dp22)) printf("%d ",dp22[i]); printf("\n"); 
                FOR(i,0,n) if (dp21[i]<dp22[i]) return np; 
                 
                return pp; 
  }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "R..."; string Arg1 = "..R."; string Arg2 = "Possible"; verify_case(0, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "..R."; string Arg1 = "R..."; string Arg2 = "Impossible"; verify_case(1, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = ".L.R.R."; string Arg1 = "L...R.R"; string Arg2 = "Possible"; verify_case(2, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = ".L.R."; string Arg1 = ".R.L."; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "LRLLRLRLLRLLRLRLRL"; string Arg1 = "LRLLRLRLLRLLRLRLRL"; string Arg2 = "Possible"; verify_case(4, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "L"; string Arg1 = "."; string Arg2 = "Impossible"; verify_case(5, Arg2, ableToMove(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	FoxAndChess ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE

//the accepted solution
//just had to check that no L,R crossed each other - i.e. their relative ordering had to remain same in the source and the target. The dp thing does the rest.