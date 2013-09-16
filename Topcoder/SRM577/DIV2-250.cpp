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

class EllysNewNickname {
	public:
	int getLength(string str) {
            int l=sz(str);
            vi arr(26,0);
            arr[0]=arr['e'-'a']=arr['i'-'a']=arr['o'-'a']=arr['u'-'a']=arr['y'-'a']=1;
            int i;
            int ans=l,cnt=0;
            FOR(i,0,l)
            {
                if (arr[str[i]-'a']==1)
                {
                    cnt++;
                }
                else
                {
                    ans-=(cnt>0?cnt-1:0);
                    cnt=0;
                }
            }
            ans-=(cnt>0?cnt-1:0);
            return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "tourist"; int Arg1 = 6; verify_case(0, Arg1, getLength(Arg0)); }
	void test_case_1() { string Arg0 = "eagaeoppooaaa"; int Arg1 = 6; verify_case(1, Arg1, getLength(Arg0)); }
	void test_case_2() { string Arg0 = "esprit"; int Arg1 = 6; verify_case(2, Arg1, getLength(Arg0)); }
	void test_case_3() { string Arg0 = "ayayayayayaya"; int Arg1 = 1; verify_case(3, Arg1, getLength(Arg0)); }
	void test_case_4() { string Arg0 = "wuuut"; int Arg1 = 3; verify_case(4, Arg1, getLength(Arg0)); }
	void test_case_5() { string Arg0 = "naaaaaaaanaaaanaananaaaaabaaaaaaaatmaaaaan"; int Arg1 = 16; verify_case(5, Arg1, getLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
    int main()
        {
        EllysNewNickname ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 

