package Interface;

import javax.sound.midi.Soundbank;
import java.sql.SQLOutput;

public class Square implements Shape{

    private int size;

    Square(int size){
        System.out.println("Square Constructor");
        this.size = size;
    }

    @Override
    public int area() {
        return this.size * this.size;
    }

    @Override
    public void work() {
        Shape.help();
        System.out.println("I am working - Square");
    }
}
