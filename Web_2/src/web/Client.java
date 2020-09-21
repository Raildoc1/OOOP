package web;

import java.io.*;
import java.net.Socket;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Client extends Socket {

    private DataOutputStream out;
    private DataInputStream in;

    private final Path filePath;
    private final long fileSize;
    private final int fileNameSize;
    private final String fileName;
    private byte[] buffer = new byte[1024];

    public Client(String host, int port, String filePath) throws IOException {
        super(host, port);

        this.filePath = Paths.get(filePath);

        if (!Files.exists(this.filePath)) {
            throw new FileNotFoundException(filePath);
        }

        this.fileName = this.filePath.getFileName().toString();
        this.fileNameSize = fileName.getBytes().length;
        this.fileSize = Files.size(this.filePath);
    }

    public void start() throws IOException {

        try(BufferedInputStream fileReader = new BufferedInputStream(Files.newInputStream(filePath));) {

            out = new DataOutputStream(this.getOutputStream());
            in = new DataInputStream(this.getInputStream());

            out.writeInt(fileNameSize);
            out.writeUTF(fileName);
            out.writeLong(fileSize);

            out.flush();

            if(in.readBoolean()) {
                int bytesRead;
                while ((bytesRead = fileReader.read(buffer)) != -1) {
                    out.write(buffer, 0, bytesRead);
                }
                out.flush();
            } else {
                System.out.println("The file has already been created!");
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void closeClient() throws IOException {
        this.close();
    }
}
