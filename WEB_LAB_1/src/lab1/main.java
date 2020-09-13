package lab1;

import java.io.IOException;
import java.util.Scanner;

public class main {

    public static void main(String[] args) {
        try {
        Sender sender = new Sender("hello");
        Receiver receiver = new Receiver();
        Scanner sc = new Scanner(System.in);

            while(true) {
                sender.iteration();
                receiver.iteration();
                if(System.in.available() != 0) {
                    String s = sc.nextLine();
                    if(s.equals("stop")) break;
                }
            }

            sender.close();
            receiver.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
