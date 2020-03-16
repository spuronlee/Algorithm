#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 100
int a[MAX][MAX];

void Copy(int tox, int toy, int fromx, int fromy, int r){
    for (int i=0;i<r; i++){
        for (int j =0;j<r; j++){
            a[tox+i][toy+j] = a[fromx+i][fromy+j];
        }
    }

}
void Table(int k){
    int n = 1 << k;
    for (int i=0; i<n; i++) a[i][0] = i+1;

    for (int r = 1; r<n; r<<=1){
        for(int i =0; i<n; i+= 2*r){
            Copy(i+r, r, i , 0, r);
            Copy(i, r, i+r, 0, r);
        }
    }
}

int main()
{
    int k =3;
    Table(k);
    int n = 1 << k;
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
