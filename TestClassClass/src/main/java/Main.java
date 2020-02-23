import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;

class Person {
    protected int age;
    protected int height;
}

class Dan extends Person {

    private int DansPrivateField;
    protected Person Putin;
    public int DansInt;

    Dan(int age, int height) {
        this.age = age;
        this.height = height;
    }

    public void BeDan(){
        System.out.println("Смотрите, какой крутой JetBrains, хочу там работать!");
        System.out.println("Хочу остаться в России, тут столько возможностей!");
        System.out.println("Путин - президент мира!");
        System.out.println("Моска похорошела при Собянине!");
    }
}

public class Main {

    public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException {

        Class<Dan> danClass = (Class<Dan>) Class.forName("Dan");

        Dan dan = (Dan) danClass.newInstance();

        dan.BeDan();

    }

}
