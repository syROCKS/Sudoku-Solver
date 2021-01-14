#include<iostream>
using namespace std;

int sudoku[9][9];

void sudokuInput() {
    for(int i=0 ; i<9 ; i++) {
        for(int j=0 ; j<9 ; j++) {
            cin>>sudoku[i][j];
        }
    }
}

void sudokuDisplay() {
    int k,l=1;
    for(int i=0 ; i<9 ; i++) {
        k=1;
        for(int j=0 ; j<9 ; j++) {
            cout<<sudoku[i][j]<<" ";
            if(k==3 || k==6) {
                cout<<"| ";
                k++;
            }       
            else {
                k++;
            }     
        }
        if(l==3 || l==6) {
            cout<<"\n------ ------- ------";
            l++;
        }       
        else {
            l++;
        }  
        cout<<endl;
    }
}

int main() {
    freopen("sudokuInput.txt","r",stdin);
    freopen("sudokuOutput.txt","w",stdout);
    sudokuInput();
    sudokuDisplay();
    return 0;
}