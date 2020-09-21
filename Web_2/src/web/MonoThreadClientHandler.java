package web;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;
import java.nio.file.FileAlreadyExistsException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class MonoThreadClientHandler implements Runnable {

    private Socket _client;
    private DataInputStream _in;
    private DataOutputStream _out;

    private int _fileNameSize;
    private String _fileName;
    private long _fileSize;
    private Path _newFilePath;
    private byte[] _buffer = new byte[1024];

    public MonoThreadClientHandler(Socket socket) {
        _client = socket;
    }

    @Override
    public void run() {

        try {
            _out = new DataOutputStream(_client.getOutputStream());
            _in = new DataInputStream(_client.getInputStream());

            _fileNameSize = _in.readInt();
            _fileName = _in.readUTF();
            _fileSize = _in.readLong();

            try {
                _newFilePath = Files.createFile(Paths.get("files", _fileName));
            } catch (FileAlreadyExistsException e) {
                _out.writeBoolean(false);
            }

            _out.writeBoolean(true);

            int msg_len;

            try(OutputStream fout = Files.newOutputStream(_newFilePath)) {
                while((msg_len = _in.read(_buffer)) != -1) {
                    fout.write(_buffer, 0, msg_len);
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
