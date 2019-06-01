public class Board{
    private final int N;
    private char [][]board;
    private int []eachRowSum;
    private int []eachColSum;
    private int _major = 0;
    private int _minor = 0;

    public Board(int dims){
        this.N = dims;
        this.board = new char[this.N][this.N];
        this.eachRowSum = new int[this.N];
        this.eachColSum = new int[this.N];

        for(int i=0;i<this.N;++i){
            eachRowSum[i] = eachColSum[i] = 0;
        }

        for(int i=0;i<this.N;++i)
            for(int j=0;j<this.N;++j)
                this.board[i][j] = '-';
    }

    // To Show The Status Of The Board
    public void showBoard(){
        for(int i = 0; i<this.N; i++){
            System.out.print("|");
            for(int j=0;j<this.N;++j){
                System.out.print(this.board[i][j] + "|");
            }
            System.out.println();
        }
    }

    // To Check Whether Current Turn Is Valid Or Not
    private boolean isValid(int _row, int _col){
        if(_row>=this.N || _col>=this.N || _row<0 || _col<0 || this.board[_row][_col]!='-')
            return false;
        return true;
    }

    // Setting Turn
    public boolean setTurn(int _id, char _mark, int _delta, int _row, int _col){
        if(this.isValid(_row, _col)) {
            this.board[_row][_col] = _mark;
            eachColSum[_col] += _delta;

            // Setting Up The Diagonal Positions
            if(_row == _col)    // Major Diagonals
                _major += _delta;
            if(_row == this.N - _col - 1)   // Minor Diagonals
                _minor += _delta;
            return true;
        }
        return false;
    }

    public int checkGame(){
        for(int i=0;i<this.N;++i){
            if(this.eachColSum[i] == this.N || this.eachRowSum[i] == this.N)
                return 1;

            if(this.eachRowSum[i] == -1*this.N || this.eachColSum[i] == -1*this.N)
                return -1;
        }

        if(this._major == this.N || this._minor == this.N)
            return 1;
        if(this._major == -1*this.N || this._minor == -1*this.N)
            return -1;
        return 0;
    }


}