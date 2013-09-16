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

int inf=1000000000;

string int2str(int n)
{
    stringstream ss;
    string ans;
    ss<<n;
    ss>>ans;
    return ans;
}

set<string> st;

int solve(string a,string b,int num)
{
    if (a.empty()) return inf;
    if (a.compare(b)==0) return num;
    if (st.find(a)!=st.end()) return inf;
    st.insert(a);
    string a2=a;
    reverse(all(a2));
    return min(solve(a2,b,num+1),solve(a.substr(0,sz(a)-1),b,num+1));
}


int solve2(string a,string b)
{
    int l1=sz(a),l2=sz(b);
    int ans=inf;
    size_t pos=a.find(b);
    while (pos!=string::npos)
    {
        int temp_ans=l1-(pos+l2);
        temp_ans+=(pos>0?pos+2:0);
        ans=min(ans,temp_ans);
        pos=a.find(b,pos+1);
    }
    reverse(all(b));
    pos=a.find(b);
    while (pos!=string::npos)
    {
        int temp_ans=l1-(pos+l2);
        temp_ans+=(pos>0?pos+1:1);
        ans=min(ans,temp_ans);
        pos=a.find(b,pos+1);
    }
    if (ans==inf) return -1;
    return ans;
}

class TheNumberGameDiv2 {
	public:
	int minimumMoves(int A, int B) 
	{
            string sa=int2str(A),sb=int2str(B);
            return solve2(sa,sb);
	}
	

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 761252168; int Arg1 = 612; int Arg2 = 7; verify_case(0, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5162; int Arg1 = 16; int Arg2 = 4; verify_case(1, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 334; int Arg1 = 12; int Arg2 = -1; verify_case(2, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 218181918; int Arg1 = 9181; int Arg2 = 6; verify_case(3, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9798147; int Arg1 = 79817; int Arg2 = -1; verify_case(4, Arg2, minimumMoves(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TheNumberGameDiv2 ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
