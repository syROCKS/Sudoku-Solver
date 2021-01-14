#include<iostream>
using namespace std;

int sudoku[9][9];

void sudokuInput();
void sudokuOutput();
int checkColumn(int column, int number);
int checkRow(int row, int number);

int main() {
    freopen("sudokuInput.txt","r",stdin);
    freopen("sudokuOutput.txt","w",stdout);
    sudokuInput();
    sudokuOutput();
    return 0;
}

void sudokuInput() {
    for(int i=0 ; i<9 ; i++) {
        for(int j=0 ; j<9 ; j++) {
            cin>>sudoku[i][j];
        }
    }
}

void sudokuOutput() {
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

int checkColumn(int column, int number) {
    for(int row=0 ; row<9 ; row++) {
        if(sudoku[row][column]==number) {
            return 1;
        }
    }
    return 0;
}

int checkRow(int row, int number) {
    for(int column=0 ; column<9 ; column++) {
        if(sudoku[row][column]==number) {
            return 1;
        }
    }
    return 0;
}

