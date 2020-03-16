#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int,string> LCS;
#define MAX 100
int c[MAX][MAX];
int b[MAX][MAX];
string result("");

void LCS_output(int i,int j, string text){
    if(i==0 || j==0) return;
    if (b[i][j] == 1){
        string in = string(1, text[i-1]);
        result.insert(0, in);
        LCS_output(i-1,j-1,text);
    }
    else if(b[i][j] == 2){
        LCS_output(i-1,j,text);
    }else{
        LCS_output(i,j-1,text);
    }


}

LCS longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

    for (int i=0;i<=m;i++) c[i][0] = 0;
    for (int i=0;i<=n;i++) c[0][i] = 0;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if (text1[i-1]==text2[j-1]){
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 1;
            }
            else if (c[i-1][j] >= c[i][j-1]){
                 c[i][j] = c[i-1][j];
                 b[i][j] = 2;
            }else{
                 c[i][j] = c[i][j-1];
                 b[i][j] = 3;
            }
        }
    }
    LCS_output(m, n, text1);
    return {c[m][n], result};
}

int main()
{
    string text1("abcde");
    string text2("ace");
    LCS l = longestCommonSubsequence(text1, text2);
    cout<<"The longest Common Subsequence is: "<<l.second<<", its length is:"<<l.first<<"."<<endl;
    return 0;
}
