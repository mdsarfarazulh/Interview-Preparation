import java.util.Scanner;

public class App{
    public static void main(String []args){
        System.out.println("THIS IS THE ENDGAME!");
        System.out.println("This is a simple implementation of famous Tic Tac Toe Game.");
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of board: ");
        int n = sc.nextInt();
//        try{
//            n = sc.nextInt();
//        }catch (Exception e){
//            e.printStackTrace();
//        }

        // Create A Board Object
        Board _board = new Board(n);

        // Player Object is created here.
        String _name = "";

        System.out.print("Enter the name of first player: ");
        try{
            _name = sc.next();
        }catch(Exception e){
            e.printStackTrace();
        }

        // Create Object Of First Player
        Player pl_1 = new Player(1, _name, 'X', 1);

        System.out.print("Enter the name of second player: ");
        try{
            _name = sc.next();
        }catch(Exception e){
            e.printStackTrace();
        }

        // Create Object Of Second Player
        Player pl_2 = new Player(2, _name, 'O', -1);

        // Game Starts Here
        System.out.println("Row & Column Number Starts From 1.");
        int _row, _col;
        _row = _col = 0;
        boolean ret = false;
        int _delta;
        while(true){
            _name = pl_1.getName();
            System.out.println(_name + "'s turn!");
            ret = false;
            while(!ret){
                try{
                    _row = sc.nextInt();
                    _col = sc.nextInt();
                }catch(Exception e){
                    e.printStackTrace();
                }
                ret = _board.setTurn(pl_1.getId(), pl_1.getMark(), pl_1.getDelta(), _row, _col);
                if(!ret){
                    System.out.println("Invalid Turn Try Again!");
                }
            }
            _delta = _board.checkGame();
            if(_delta == -1 || _delta == 1){
                System.out.println("The Game Has Ended!");
                break;
            }
            _board.showBoard();
            ret = false;
            _name = pl_2.getName();
            System.out.println(_name + "'s turn!");
            while(!ret){
                try{
                    _row = sc.nextInt();
                    _col = sc.nextInt();
                }catch(Exception e){
                    e.printStackTrace();
                }
                ret = _board.setTurn(pl_2.getId(), pl_2.getMark(), pl_2.getDelta(), _row, _col);
                if(!ret){
                    System.out.println("Invalid Turn Try Again!");
                }
            }
            _delta = _board.checkGame();
            if(_delta == -1 || _delta == 1){
                System.out.println("The Game Has Ended!");
                break;
            }
            _board.showBoard();
        }
        if(_delta == -1)
            System.out.println("Congratulations " + pl_2.getName() + " you have won the match");
        else
            System.out.println("Congratulations " + pl_1.getName() + " you have won the match");
        System.out.println("The Final Board Status Is:-");
        _board.showBoard();
    }
}