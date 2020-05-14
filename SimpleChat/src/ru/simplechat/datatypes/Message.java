package ru.simplechat.datatypes;

public class Message {
    private String nickname;
    private String message;

    public Message(String nickname, String message) {
        this.message = message;
        this.nickname = nickname;
    }

    @Override
    public String toString() {
        return nickname + ": " + message;
    }
}
