class SolveSudoku{
    int n = 9;
    int[][] a = {
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
    boolean checkSafe(char[][] a, int i, int j){
        //base case
        if(i==n){
            return true;
        }
        //next position
        int nexti;
        int nextj;
        
        if(j==n-1){
            nexti = i+1;
            nextj=0;
        }else{
            nextj=j+1;
            nexti = i;
        }
        if(a[i][j]!='.'){
            return checkSafe(a,nexti,nextj);
        }else{
            safeValues = findSafeValues(a,i,j);
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
    public static void main(String[] args){

        boolean solution = checkSafe(a, 0, 0);
        sop
    }
}