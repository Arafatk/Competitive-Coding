#include <bits/stdc++.h>
using namespace std;
#define inf                         INFINITY
/* 
   const clock_t begin_time = clock();
   // do something
   cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;

   Read from a file
   freopen("input.in","r",stdin);
   freopen("output.out","w",stdout);
*/  
void r(){};
template<typename T,typename... Args>
void r(T &a, Args&... args) {  cin>>a ; r(args...); }
void p(){cout <<"\n";};
template<typename T,typename... Args>
void p(T &a, Args&... args) {  cout << a << " "  ; p(args...); }
template<class T> T gcd(T a, T b) { return a ? gcd (b % a, a) : b; }
template<class T> T lcm(T a, T b) { return  ((a*b)/gcd (b % a, a)); }
template<class T1, class T2> T1 binpow(T1 number, T2 power) { T1 result = number; while(power) { if(power & 1) result = result*number; number = number*number;power /= 2;}return result;}
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

// Useful container manipulation / traversal macros

#define fa(i, begin, end)           for (auto i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fe(v, c)                    for(auto v :c)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          emplace_back  // this will work almost always
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((auto)(a.size()))
#define mt                          make_tuple

// comparision Guys 

#define maX(a,b)                    ( (a) > (b) ? (a) : (b))
#define abs(a)                      ( (a) > (0) ? (a) : (-a))
#define miN(a,b)                    ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)               ( (n >> b) & 1)
#define DREP(a)                     sort(all(a)); a.erase(unique(all(a)),a.end()) //deletes repeat
#define sqr(x)                      ((x) * (x))
#define sqrt(x)                     sqrt(abs(x))

// The bit standard guys

#define bit(x,i)                    (x&(1<<i))  //select the bit of position i of x
#define lowbit(x)                   ((x)&((x)^((x)-1))) //get the lowest bit of x
#define higbit(x)                   (1 << ( auto) log2(x) )

#define ft                 first
#define sd                 second
#define pq                 priority_queue
// the data types
#define ll long long
#define st string
#define ld long double

ll MOD = 1e9+7;

template< class T >
class Matrix
{
    public:
        int m,n;
        T *data;
 
        Matrix( int m, int n );
        Matrix( const Matrix< T > &matrix );
 
        const Matrix< T > &operator=( const Matrix< T > &A );
        const Matrix< T > operator*( const Matrix< T > &A );
        const Matrix< T > operator^( int P );
 
        ~Matrix();
};
 
template< class T >
Matrix< T >::Matrix( int m, int n )
{
    this->m = m;
    this->n = n;
    data = new T[m*n];
}
 
template< class T >
Matrix< T >::Matrix( const Matrix< T > &A )
{
    this->m = A.m;
    this->n = A.n;
    data = new T[m*n];
    for( int i = 0; i < m * n; i++ )
        data[i] = A.data[i];
}
 
template< class T >
Matrix< T >::~Matrix()
{
    delete [] data;
}
 
template< class T >
const Matrix< T > &Matrix< T >::operator=( const Matrix< T > &A )
{
    if( &A != this )
    {
        delete [] data;
        m = A.m;
        n = A.n;
        data = new T[m*n];
        for( int i = 0; i < m * n; i++ )
            data[i] = A.data[i];
    }
    return *this;
}
 
template< class T >
const Matrix< T > Matrix< T >::operator*( const Matrix< T > &A )
{
    Matrix C( m, A.n );
    for( int i = 0; i < m; ++i )
        for( int j = 0; j < A.n; ++j )
        {
            C.data[i*C.n+j]=0;
            for( int k = 0; k < n; ++k )
                C.data[i*C.n+j] = C.data[i*C.n+j] + data[i*n+k]*A.data[k*A.n+j];
                C.data[i*C.n+j] %= MOD;
        }
    return C;
}
 
template< class T >
const Matrix< T > Matrix< T >::operator^( int P )
{
    if( P == 1 ) return (*this);
    if( P & 1 ) return (*this) * ((*this) ^ (P-1));
    Matrix B = (*this) ^ (P/2);
    return B*B;
}
 
int main()
{
    Matrix<ll> M(2,2);
    M.data[0] = 3;M.data[1] = 1;
    M.data[2] = 1;M.data[3] = 3;
 
    ll F[2]={1,1};
    ll N;
    scanf("%lld",&N);
    if (N>0)
       printf("%lld\n", binpow(M,N-1).data[0]);
    else
       printf("%lld\n",F[N]);
}