package lab1;

import java.io.IOException;
import java.net.*;

public class Sender {
    private DatagramSocket socket;
    private InetAddress group;
    private byte[]buf;

    private boolean connected;

    public void multicast(String multicastMessage) throws IOException, SocketException, UnknownHostException {
        socket = new DatagramSocket();
        group = InetAddress.getByName("230.0.0.0");

        buf = multicastMessage.getBytes();

        long start = System.currentTimeMillis();
        long prevTime = System.currentTimeMillis();
        long deltaTime = 0;
        long delay = 3000;

        connected = true;

        while(connected) {

            deltaTime = System.currentTimeMillis() - prevTime;
            prevTime = System.currentTimeMillis();

            if((delay -= deltaTime) < 0) {
                delay = 3000;
                DatagramPacket packet = new DatagramPacket(buf, buf.length, group, 4446);
                socket.send(packet);
            }

        }

        socket.close();
    }

    public void disconnect () {
        connected = false;
    }
}
