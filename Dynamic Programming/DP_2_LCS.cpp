#include <iostream>
#include <string>
using namespace std;
#define NUM 51

string result("");

void TraceBack(int i, int j, int s[NUM][NUM]){


    if(i==j){
        result.insert(result.length(), "A");
        result.insert(result.length(), to_string(i));
    }
    else{
        result.insert(result.length(), "(");
        TraceBack(i, s[i][j], s);
        TraceBack(s[i][j]+1, j, s);
        result.insert(result.length(), ")");
    }
}


string MarticChain(int * p, int n)
{
    int m[NUM][NUM];
    int s[NUM][NUM];
    for(int i = 1; i <= n; i++) m[i][i] = 0;

    for(int r = 2; r <= n; r++)
    {
        for(int i = 1; i<= n-r+1; i++)
        {
            int j = i+r-1;
            m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
            s[i][j] = i;

            for (int k = i+1; k<j; k++)
            {
                int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (t < m[i][j]){m[i][j] = t; s[i][j] = k;}
            }
        }
     }
    TraceBack(1, n, s);
    return result;
}


int main()
{
    int n = 6;
    int p[n+1] = {50, 10, 40, 30, 5, 20 ,15};
    string re = MarticChain(p, n);
    cout << re << endl;
    return 0;
}
