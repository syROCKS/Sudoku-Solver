#include<iostream>
using namespace std;

int sudoku[9][9];

void sudokuInput();
void sudokuOutput();
int checkColumn(int column, int number);
int checkRow(int row, int number);
int checkBox(int row, int column, int number);
int emptySlot();
int correctSlot(int row, int column , int number);

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

int checkBox(int row, int column, int number) {
    int ROW = row - row%3;
    int COLUMN = column - column%3;
    for(int i=0 ; i<3 ; i++) {
        for(int j=0 ; j<3 ; j++) {
            if(sudoku[ROW + i][COLUMN + j]==number) {
                return 1;
            }
        }
    }
    return 0;
}

int emptySlot() {
    for(int row=0 ; row<9 ; row++) {
        for(int column=0 ; column<9 ; column++) {
            if(sudoku[row][column]==0) {
                return 1;
            }
        }
    }
    return 0;
}

int correctSlot(int row, int column , int number) {
    if(checkColumn(column,number) || checkRow(row,number) || checkBox(row,column,number)) {
        return 0;
    }
    return 1;
}

