#include <iostream>
#include <vector>
#include <string>
using namespace std;

void TraceBack(int i, int j, vector<vector<int> > &s){
    if(i==j){cout<<"A";cout<<(i);}
    else{
        cout<<"(";
        TraceBack(i,  s[i][j], s);
        TraceBack(s[i][j]+1,j, s);
        cout<<")";
    }
}

int DP(vector<int>& p, int num){
    vector<vector<int> > m(num+1, vector<int>(num+1));
    vector<vector<int> > s(num+1, vector<int>(num+1));
    for(int r=2;r<=num;r++){
       for(int i=1;i<=num-r+1;i++){
         int j = i+r-1;
         m[i][j] = INT_MAX;
         for(int k=i;k<j;k++){
            int t = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
            if (t<m[i][j]){m[i][j] = t; s[i][j] = k;}
         }

       }
    }
    TraceBack(1, num, s);
    cout<<endl;
    return m[1][num];
}

int RecursionMM(int i, int j, vector<int>& p){

    if (i == j) return 0;
    else{
        int min_times = INT_MAX;
        for (int k=i;k<j;k++){
            int times = RecursionMM(i,k,p) + RecursionMM(k+1,j,p) + p[i]*p[k+1]*p[j+1];
            if (times<min_times) min_times = times;
        }

        return min_times;
    }
}

int LookupChain(int i, int j, vector<int>& p, vector<vector<int> >& m){

    if (m[i][j]>0) return m[i][j];
    if (i == j) return 0;
    else{
        int min_times = INT_MAX;
        for (int k=i;k<j;k++){
            int times = LookupChain(i,k,p,m) + LookupChain(k+1,j,p,m) + p[i]*p[k+1]*p[j+1];
            if (times<min_times) min_times = times;
        }
        m[i][j] = min_times;
        return min_times;
    }
}

int main()
{
    int num ;
    vector<int> p;
    p.push_back(-1);
    cout << "Input the number of matrices : " << endl;
    cin>>num;
    cout << "Input the dimensions of each matrix: " << endl;
    for(int i = 0 ; i<=num; i++){
        int a = 0;
        cin>>a;
        p.push_back(a);
    }

    //Method 1: recursion
    cout<<RecursionMM(1, num, p)<<endl;  //0.111 s

    //Method 2: dynamic programming
    cout<<DP(p, num)<<endl;  //0.128 s


    //Method 3: memorandum
    vector<vector<int> > m(num+1, vector<int>(num+1));
    cout<<LookupChain(1, num, p, m);

    return 0;
}
