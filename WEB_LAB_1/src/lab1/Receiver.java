package lab1;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.util.ArrayList;

public class Receiver extends Thread {
    protected MulticastSocket socket = null;
    protected byte[]buf = new byte[256];

    private ArrayList<client> clients = new ArrayList<client>();

    public void run() {
        try {
            socket = new MulticastSocket(4446);
            InetAddress group = InetAddress.getByName("230.0.0.0");
            socket.joinGroup(group);

            long prevTime = System.currentTimeMillis();
            long deltaTime = 0;
            long timer = 0;

            while (true) {
                deltaTime = System.currentTimeMillis() - prevTime;
                prevTime = System.currentTimeMillis();

                for (client c : clients) {
                    c.increment_time(deltaTime);
                    if(c.getTime_millis() > 10000) clients.remove(c);
                }

                DatagramPacket packet = new DatagramPacket(buf, buf.length);
                socket.receive(packet);
                String received = new String(packet.getData(), 0, packet.getLength());

                boolean client_found = false;

                for (client c : clients) {
                    if(c.getName().equals(packet.getSocketAddress().toString())) {
                        client_found = true;
                        c.reset_timer();
                        break;
                    }
                }

                if(!client_found) {
                    clients.add(new client(packet.getSocketAddress().toString()));
                }

                //System.out.println(packet.getSocketAddress());

                timer -= deltaTime;

                if(timer < 0){
                    timer = 3000;

                    System.out.print("\033[H\033[2J");
                    System.out.flush();

                    for (client c: clients) {
                        System.out.println(c.name);
                    }
                }

                if ("end".equals(received)) {
                break;
            }
        }
        socket.leaveGroup(group);
        socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }



    private class client {
        private String name;
        private long time_millis = 0;

        public String getName() {return name;}
        public long getTime_millis() {return time_millis;}

        public client(String name) {
            this.name = name;
        }

        public void increment_time(long delta_time_millis) {
            time_millis += delta_time_millis;
            if(time_millis < 0) time_millis = 0;
        }

        public void reset_timer() {
            time_millis = 0;
        }
    }
}
