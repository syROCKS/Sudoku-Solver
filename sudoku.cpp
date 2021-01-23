#include<iostream>
using namespace std;

int sudoku[9][9];

void sudokuInput();
void sudokuOutput();
bool checkColumn(int column, int number);
bool checkRow(int row, int number);
bool checkBox(int row, int column, int number);
int emptySlot(int &row, int &column);
bool correctSlot(int row, int column , int number);
int solveSudoku();

int main() {
    freopen("sudokuInput.txt","r",stdin);
    freopen("sudokuOutput.txt","w",stdout);
    sudokuInput();
    if(solveSudoku()) {
        sudokuOutput();
    }
    else {
        cout<<"Not Possible!";
    }
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
            if(k==3 || k==6)
                cout<<"| ";      
            k++;    
        }
        if(l==3 || l==6)
            cout<<"\n------ ------- ------";
        l++;        
        cout<<endl;
    }
}

bool checkColumn(int column, int number) {
    for(int row=0 ; row<9 ; row++) {
        if(sudoku[row][column]==number) {
            return true;
        }
    }
    return false;
}

bool checkRow(int row, int number) {
    for(int column=0 ; column<9 ; column++) {
        if(sudoku[row][column]==number) {
            return true;
        }
    }
    return false;
}

bool checkBox(int row, int column, int number) {
    int ROW = row - row%3;
    int COLUMN = column - column%3;
    for(int i=0 ; i<3 ; i++) {
        for(int j=0 ; j<3 ; j++) {
            if(sudoku[ROW + i][COLUMN + j]==number) {
                return true;
            }
        }
    }
    return false;
}

int emptySlot(int &row, int &column) {
    for(row=0 ; row<9 ; row++) {
        for(column=0 ; column<9 ; column++) {
            if(sudoku[row][column]==0) {
                return 1;
            }
        }
    }
    return 0;
}

bool correctSlot(int row, int column , int number) {
    return !(checkColumn(column,number) || checkRow(row,number) || checkBox(row,column,number));
}

int solveSudoku() {
    int row,column;
    if(!emptySlot(row,column)) {
        return 1;
    }
    for(int number=1 ; number<=9 ; number++) {
        if(correctSlot(row,column,number)) {
            sudoku[row][column]=number;
            if(solveSudoku()) {
                return 1;
            }
            sudoku[row][column]=0;
        }
    }
    return 0;
}