package web;

import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Server {

    private final int port;
    private ServerSocket serverSocket;
    private ArrayList<MonoThreadClientHandler> clientThreads;
    private ExecutorService executorService = Executors.newFixedThreadPool(256);

    public Server(int port) throws IOException {
        this.port = port;
        ServerSocket serverSocket = new ServerSocket(port);
        clientThreads = new ArrayList<>();
    }

    public void start() {
        BufferedReader systemInReader = new BufferedReader(new InputStreamReader(System.in));

        while(!serverSocket.isClosed()) {
            try {
                Socket client = serverSocket.accept();
                MonoThreadClientHandler clientThread = new MonoThreadClientHandler(client);

                clientThreads.add(clientThread);

                executorService.execute(clientThread);

            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        executorService.shutdown();
    }

}
