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

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;

class PenguinPals {
	public:
	int findMaximumMatching(string str) 
	{
            int s=sz(str);
            vector<bool> elig(s,true);
            vvi numelig(s,vi(s,0));
            int i,j;
            int mi,mj;
            int ans=0;
            cout<<str<<endl;
            FOR(i,0,s)
            {
                FOR(j,0,s)
                {
                    numelig[i][j]=min(abs(i-j)+1,s-abs(i-j)+1);
                    printf("%d ",numelig[i][j]);
                }
                printf("\n");
            }
            while(1)
            {
                //finding the closest matching pairs among the remaining eligible people
                int d=100;
                FOR(i,0,s)
                {
                    //finding the closest possible match for i
                    //ensuring the j is not equal to i
                    if (elig[i])
                    {
                        FOR(j,0,s)
                        {
                            if (elig[j]&&i!=j)
                            {
                                if (str[i]==str[j])
                                {
                                    int td=numelig[i][j];
                                    if (td<d)
                                    {
                                        mj=j;mi=i;
                                        d=td;
                                    }
                                }
                            }
                        }
                    }
                }
                if (d==100)
                {
                    //no eligible pair left
                    return ans;
                }
                else
                {
                    printf("%d %d\n",mi,mj);
                    ans++;
                    int td1=0;
                    if (mi<mj)
                    {
                        FOR(i,mi,mj+1) td1+=elig[i];
                    }
                    else
                    {
                        FOR(i,mj,mi+1) td1+=elig[i];
                    }
                    int td2=0;
                    if (mi<mj)
                    {
                        FOR(i,0,mi+1) td1+=elig[i];
                        FOR(i,mj,s) td1+=elig[i];
                    }
                    else
                    {
                        FOR(i,0,mj+1) td1+=elig[i];
                        FOR(i,mi,s) td1+=elig[i];
                    }
                    if (td1<td2)
                    {
                        if (mi<mj)
                        {
                            FOR(i,mi,mj+1) elig[i]=false;
                        }
                        else
                        {
                            //mi>mj
                            FOR(i,mj,mi+1) elig[i]=false;
                        }
                    }
                    else
                    {
                        //s-abs(mj-mi) = d
                        if (mi<mj)
                        {
                            FOR(i,0,mi+1) elig[i]=false;
                            FOR(i,mj,s) elig[i]=false;
                        }
                        else
                        {
                            //mi>mj
                            FOR(i,0,mj+1) elig[i]=false;
                            FOR(i,mi,s) elig[i]=false;
                        }
                    }
                    //updating numelig
                    int k;
                    FOR(i,0,s)
                    {
                        FOR(j,0,s)
                        {
                            int td1=0;
                            if (i<j)
                            {
                                FOR(k,i,j+1) td1+=(int)elig[k];
                            }
                            else
                            {
                                FOR(k,j,i+1) td1+=(int)elig[k];
                            }
                            int td2=0;
                            if (i<j)
                            {
                                FOR(k,0,i+1) td2+=(int)elig[k];
                                FOR(k,j,s) td2+=(int)elig[k];
                            }
                            else
                            {
                                FOR(k,0,j+1) td2+=(int)elig[k];
                                FOR(k,i,s) td2+=(int)elig[k];
                            }
                            numelig[i][j]=min(td1,td2);
                        }
                    }
                    FOR(i,0,s) printf("%d ",(int)elig[i]);
                    printf("\n");
//                    FOR(i,0,s)
//                    {
//                        FOR(j,0,s)
//                        {
//                            printf("%d ",numelig[i][j]);
//                        }
//                        printf("\n");
//                    }
                }
            }
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRBRBRBB"; int Arg1 = 3; verify_case(0, Arg1, findMaximumMatching(Arg0)); }
	void test_case_1() { string Arg0 = "RRRR"; int Arg1 = 2; verify_case(1, Arg1, findMaximumMatching(Arg0)); }
	void test_case_2() { string Arg0 = "BBBBB"; int Arg1 = 2; verify_case(2, Arg1, findMaximumMatching(Arg0)); }
	void test_case_3() { string Arg0 = "RBRBRBRBR"; int Arg1 = 4; verify_case(3, Arg1, findMaximumMatching(Arg0)); }
	void test_case_4() { string Arg0 = "RRRBRBRBRBRB"; int Arg1 = 5; verify_case(4, Arg1, findMaximumMatching(Arg0)); }
	void test_case_5() { string Arg0 = "R"; int Arg1 = 0; verify_case(5, Arg1, findMaximumMatching(Arg0)); }
	void test_case_6() { string Arg0 = "RBRRBBRB"; int Arg1 = 3; verify_case(6, Arg1, findMaximumMatching(Arg0)); }
	void test_case_7() { string Arg0 = "RBRBBRBRB"; int Arg1 = 4; verify_case(7, Arg1, findMaximumMatching(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        PenguinPals ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
