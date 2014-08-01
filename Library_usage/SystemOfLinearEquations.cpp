//http://codeforces.com/contest/451/problem/C


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

typedef vector<int> VI;
typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;

// Gauss-Jordan elimination with full pivoting.
//
// Uses:
//   (1) solving systems of linear equations (AX=B)
//   (2) inverting matrices (AX=I)
//   (3) computing determinants of square matrices
//
// Running time: O(n^3)
//
// INPUT:    a[][] = an nxn matrix
//           b[][] = an nxm matrix
//
// OUTPUT:   X      = an nxm matrix (stored in b[][])
//           A^{-1} = an nxn matrix (stored in a[][])
//           returns determinant of a[][]

double EPS=1e-9;

T GaussJordan(VVT &a, VVT &b) {
  const int n = a.size();
  const int m = b[0].size();
  VI irow(n), icol(n), ipiv(n);
  T det = 1;

  for (int i = 0; i < n; i++) {
    int pj = -1, pk = -1;
    for (int j = 0; j < n; j++) if (!ipiv[j])
      for (int k = 0; k < n; k++) if (!ipiv[k])
	if (pj == -1 || fabs(a[j][k]) > fabs(a[pj][pk])) { pj = j; pk = k; }
    if (fabs(a[pj][pk]) < EPS) { return 0; }
    ipiv[pk]++;
    swap(a[pj], a[pk]);
    swap(b[pj], b[pk]);
    if (pj != pk) det *= -1;
    irow[i] = pj;
    icol[i] = pk;

    T c = 1.0 / a[pk][pk];
    det *= a[pk][pk];
    a[pk][pk] = 1.0;
    for (int p = 0; p < n; p++) a[pk][p] *= c;
    for (int p = 0; p < m; p++) b[pk][p] *= c;
    for (int p = 0; p < n; p++) if (p != pk) {
      c = a[p][pk];
      a[p][pk] = 0;
      for (int q = 0; q < n; q++) a[p][q] -= a[pk][q] * c;
      for (int q = 0; q < m; q++) b[p][q] -= b[pk][q] * c;      
    }
  }

  for (int p = n-1; p >= 0; p--) if (irow[p] != icol[p]) {
    for (int k = 0; k < n; k++) swap(a[k][irow[p]], a[k][icol[p]]);
  }

  return det;
}

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

bool check(vvll &a,vvll &x,vvll &b)
{
    //check whether ax=b holds
    int n=sz(a),m=sz(a[0]);
    assert(sz(x)==m);
    int k=sz(x[0]);
    assert(sz(b)==n);
    assert(sz(b[0])==k);
    vvll c(n,vll(k,0));
    for(int i=0;i<n;i++) for(int j=0;j<k;j++)
    {
        for(int kk=0;kk<m;kk++) c[i][j]+=(a[i][kk]*x[kk][j]);
    }
    return (b==c);
}

vvll copy_mat(vector<vector<double> > &src)
{
    int n=sz(src),m=sz(src[0]);
    vvll dest(n,vll(m));
    int i,j;
    FOR(i,0,n) FOR(j,0,m) dest[i][j]=(ll)src[i][j];
    return dest;
}

string solve(ll n,ll k,ll d1,ll d2)
{
    string no="no",yes="yes";
    VVT mat2(3,VT(3,1));
    mat2[1][2]=0;mat2[2][0]=0;
    int i,j;
    if (n%3!=0) return no;
    FOR(i,0,2) FOR(j,0,2)
    {
        VVT matb(3);
        matb[0].pb((double)k);
        matb[1].pb((double)d1);
        matb[2].pb((double)d2);
//        myprint("here",i,j);
        VVT mat=mat2;
        if (i) mat[1][0]=-1;
        else mat[1][1]=-1;
        if (j) mat[2][1]=-1;
        else mat[2][2]=-1;
//        print_mat(mat);
        vvll a=copy_mat(mat);
        vvll b=copy_mat(matb);
        if (GaussJordan(mat,matb)==0) continue;
        ll x1=matb[0][0],x2=matb[1][0],x3=matb[2][0];
//        myprint(matb[0][0],matb[1][0],matb[2][0]);
//        if (x1+x2+x3!=k) continue;
        vvll x=copy_mat(matb);
        if (!check(a,x,b)) continue;
        if (x1<0||x2<0||x3<0) continue;
//        myprint(x1,x2,x3);
        vll arr(3);
        arr[0]=x1,arr[1]=x2,arr[2]=x3;
        sort(all(arr));
        ll team2wins=arr[2]-arr[1];
        ll team3wins=arr[2]-arr[0];
        ll k2=k+team2wins+team3wins;
        if (k2>n) continue;
        if ((n-k2)%3!=0) continue;
        return yes;
    }
    return no;
//    
//    ll team2wins=d1,team3wins=d1+d2;
//    k+=team2wins+team3wins;
//    if (k>n) return no;
//    if ((n-k)%3!=0) return no;
//    return yes;
}

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    sd(T);
    int i,j,t;
    string no="no",yes="yes";
    FOR(t,0,T)
    {
        ll n,k,d1,d2;
        s(n);s(k);s(d1);s(d2);
        ps(solve(n,k,d1,d2));
    }
}