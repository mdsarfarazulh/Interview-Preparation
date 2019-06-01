public class Player{
    private final String name;
    private final char mark;
    private final int delta;
    private final int id;

    public Player(int _id, String _name, char _mark, int _delta){
        this.name = _name;
        this.mark = _mark;
        this.delta = _delta;
        this.id = _id;
    }

    public int getId(){
        return this.id;
    }

    public int getDelta(){
        return this.delta;
    }

    public char getMark(){
        return this.mark;
    }

    public String getName(){
        return this.name;
    }

}