#include <bits/stdc++.h>

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


class AlienAndPassword {
	public:
	int getNumber(string S)
	{
		int i,j;
                set<string> st;
                int n=sz(S);
                FOR(i,0,n)
                {
                    string str;
                    FOR(j,0,i) str.pb(S[j]);
                    FOR(j,i+1,n) str.pb(S[j]);
                    st.insert(str);
                }
                return sz(st);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "A"; int Arg1 = 1; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arg0 = "ABA"; int Arg1 = 3; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arg0 = "AABACCCCABAA"; int Arg1 = 7; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arg0 = "AGAAGAHHHHFTQLLAPUURQQRRRUFJJSBSZVJZZZ"; int Arg1 = 26; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arg0 = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"; int Arg1 = 1; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	AlienAndPassword ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE

