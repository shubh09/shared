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


class MyVeryLongCake {
	public:
	int cut(int n)
	{
		int i,j;
                int N=n;
                int s=sqrt(n);
                int ans=1;
                vi arr;
                for(i=2;i<=s;i++)
                {
                    if (n%i==0)
                    {
                        while (n%i==0) n/=i;
//                        ans+=(N/i)-1;
                        arr.pb(i);
                    }
                }
                if (n>1) arr.pb(n);
                s=sz(arr);
//                cout<<"arr=";
//                FOR(i,0,s) cout<<arr[i]<<' ';
//                cout<<endl;
                FOR(i,1,1<<s)
                {
                    int mul=1;
//                    cout<<"i="<<i<<endl;
                    FOR(j,0,s)
                    {
                        if (i&(1<<j))
                        {
                            mul*=arr[j];
//                            cout<<"multiplying "<<arr[j]<<endl;
                        }
                    }
                    int nd=__builtin_popcount(i);
                    int q=(N/mul)-1;
//                    cout<<"mul="<<mul<<' '<<"q="<<q<<endl;
                    if (nd&1) ans+=q;
                    else ans-=q;
                }
                return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 4; verify_case(0, Arg1, cut(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; verify_case(1, Arg1, cut(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 7; verify_case(2, Arg1, cut(Arg0)); }
	void test_case_3() { int Arg0 = 1000000000; int Arg1 = 600000000; verify_case(3, Arg1, cut(Arg0)); }
	void test_case_4() { int Arg0 = 577007436; int Arg1 = 384671628; verify_case(4, Arg1, cut(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	MyVeryLongCake ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE

