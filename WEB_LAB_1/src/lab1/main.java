package lab1;

import java.io.IOException;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class main {

    public static void main(String[] args) {

        ExecutorService executorService = Executors.newFixedThreadPool(1);

        Sender sender = new Sender();
        Receiver receiver = new Receiver();

        try {

            executorService.execute(receiver);
            sender.multicast("ip + port");
            executorService.shutdown();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
