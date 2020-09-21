package web;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Server {

    private final int PORT;
    private ServerSocket _serverSocket;
    private ArrayList<MonoThreadClientHandler> _clientThreads;
    private ExecutorService _executorService = Executors.newFixedThreadPool(256);

    public Server(int port) throws IOException {
        this.PORT = port;
        _serverSocket = new ServerSocket(port);
        _clientThreads = new ArrayList<>();
    }

    public void start() {
        BufferedReader systemInReader = new BufferedReader(new InputStreamReader(System.in));

        while(!_serverSocket.isClosed()) {
            try {
                Socket client = _serverSocket.accept();
                MonoThreadClientHandler clientThread = new MonoThreadClientHandler(client);

                _clientThreads.add(clientThread);

                _executorService.execute(clientThread);

            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        _executorService.shutdown();
    }

}
