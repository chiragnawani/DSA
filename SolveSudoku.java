class SolveSudoku{
    static char[][] a = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    static boolean isSafe(char[][] a, int i, int j, char num){
        //rowchk
        int row = i;
        int col = j;
        for(int k = 0; k<9; k++){
            if(a[row][k] == num){
                return false;
            }
        }
        //colchk
        for(int k = 0; k<9; k++){
            if(a[k][col] == num){
                return false;
            }
        }
        //cellchk
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int p = startRow; p < startRow + 3; p++) {
            for (int q = startCol; q < startCol + 3; q++) {
                if (a[p][q] == num) return false;
            }
        }
        return true;
    }
    static char[] findSafeValues(char[][] a, int i, int j){
        char[] safeValuesArray1 = new char[9];
        int count = 0;
        int k = -1;
        while(count<9){
            char num = (char)('1'+count);
            if(isSafe(a,i,j,num)){
                k++;
                safeValuesArray1[k] = num; 
            }
            count++;
        }
        if(k==-1){
            char[] emptyArray = new char[0];
            return emptyArray;
        }
        char[] safeValuesArray2 = new char[k+1];
        for(int m = 0; m<k+1; m++){
            safeValuesArray2[m] = safeValuesArray1[m];
        }
        return safeValuesArray2;
    }
    static boolean checkSafe(char[][] a, int i, int j){
        //base case
        if(i==9){
            return true;
        }
        //next position
        int nexti;
        int nextj;
        
        if(j==8){
            nexti = i+1;
            nextj=0;
        }else{
            nextj=j+1;
            nexti = i;
        }
        if(a[i][j]!='.'){
            return checkSafe(a,nexti,nextj);
        }else{
            char[] safeValues = findSafeValues(a,i,j);
            if(safeValues.length == 0){
                return false;
            }else{
                int index = 0;
                while(index<safeValues.length){
                    a[i][j] = safeValues[index];
                    if(checkSafe(a,nexti,nextj)){
                        return true;
                    }else{
                        a[i][j] = '.';
                        index++;
                    }
                }
                return false;
            }
        }
    }

    static void printSudoku(char[][] a) {

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {
                System.out.print(a[i][j] + " ");
            }

            System.out.println();
        }
    }
    
    public static void main(String[] args){
        System.out.println("Unsolved Sudoku");
        printSudoku(a);
        boolean solution = checkSafe(a, 0, 0);
        System.out.println("Solved Sudoku");
        printSudoku(a);
    }
}