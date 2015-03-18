#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					cin>>n
#define p(n)					cout<<n<<'\n'
#define sd(n)					int n;cin>>n;
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define mp(a,b)                                 make_pair(a,b)
#define ps(str)                                 cout<<str<<'\n'

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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef unsigned int uint;
typedef unsigned long long ull;

class PeacefulLine {
    public:
        int findMajority(vi &arr){
            int n=sz(arr),x=arr[0],cnt=1,i;
            FOR(i,1,n){
                if (arr[i]==x) cnt++;
                else cnt--;
                if (cnt==0){
                    x=arr[i];
                    cnt=1;
                }
            }
            cnt=0;
            FOR(i,0,n) if (x==arr[i]) cnt++;
            if (n&1){
                if (cnt>(n+1)/2) return x;
                else return -1;
            }
            else{
                if (cnt>n/2) return x;
                else return -1;
            }
        }
    string makeLine(vector <int> arr){
            int i,j;
            string yes="possible",no="impossible";
            int x=findMajority(arr);
            if (x==-1) return yes;
            else return no;
	}
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(0, Arg1, makeLine(Arg0)); }
	void test_case_1() { int Arr0[] = {1,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "impossible"; verify_case(1, Arg1, makeLine(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,2,2,3,3,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(2, Arg1, makeLine(Arg0)); }
	void test_case_3() { int Arr0[] = {3,3,3,3,13,13,13,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(3, Arg1, makeLine(Arg0)); }
	void test_case_4() { int Arr0[] = {3,7,7,7,3,7,7,7,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "impossible"; verify_case(4, Arg1, makeLine(Arg0)); }
	void test_case_5() { int Arr0[] = {25,12,3,25,25,12,12,12,12,3,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(5, Arg1, makeLine(Arg0)); }
	void test_case_6() { int Arr0[] = {3,3,3,3,13,13,13,13,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "possible"; verify_case(6, Arg1, makeLine(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PeacefulLine ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE

//unnecessarily complex approach