#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<int> getMaxMatrix(vector< vector<int> >& matrix) {

    vector<int> index(4, 0);
    int gmax = INT_MIN;

    for (int i = 0; i<matrix.size(); i++){
        vector<int> b(matrix[0].size(), 0);
        for (int j = i; j<matrix.size(); j++){
                int currntMax = INT_MIN;
                int b_begin_num = 0;
                for (int k = 0; k < matrix[0].size(); k++){
                        b[k] += matrix[j][k];

                        if (currntMax>0){
                            currntMax+=b[k];
                        }
                        else{
                           currntMax = b[k];
                           b_begin_num = k;
                        }
                        if (currntMax>gmax){
                           gmax = currntMax;
                           index[0] = i;
                           index[1] = b_begin_num;
                           index[2] = j;
                           index[3] = k;

                        }
                }
        }
    }
    return index;
}


int main()
{
    int data[] = {0,-2,-7,0,9,2,-6,2,-4,1,-4,1,-1,8,0,-2};
    vector< vector<int> > matrix(4);
    for (int i = 0; i < matrix.size(); i++)
        matrix[i].resize(4);

    int d = 0;
    for(int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size();j++) {
            matrix[i][j] = data[d];
            d++;
        }
    }
    vector<int> index = getMaxMatrix(matrix);

    vector<int>::iterator v = index.begin();
    while( v != index.end()) {
      cout << "value of v = " << *v << endl;
      v++;
    }
    return 0;
}
