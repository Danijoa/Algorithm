using namespace std;

// a와 b에서(단 a>b) 
// a를 b로 나눈 나머지를 r이라고 했을때 
// GCD(a, b) = GCD(b, r)과 같고 
// "r이 0이면 그때 b가 최대공약수이다."
int GCD(int w, int h)
{
    if(h == 0)
        return w;
    else
        return GCD(h, w % h);
}

long long solution(int w, int h) 
{
    long long answer = 1;

    if( w < h)
    {
        int t = w;
        w = h;
        h = t;
    }
    
    int gcd = GCD(w, h);
    int w_gcd = w / gcd;
    int h_gcd = h / gcd;
    int square = w_gcd + h_gcd - 1;
    
    answer = (long long)w * (long long)h - square * gcd;
    //answer = (long long)w * (long long)h - (w + h - gcd);

    return answer;
} 
