package ru.simplechat.datatypes;

public class User {
    private String nickname;
    private boolean online = false;

    public User(String nickname) {
        this.nickname = nickname;
    }

    public boolean isOnline() {
        return online;
    }

    public String getNickname() {
        return nickname;
    }

    public void setOnline(boolean online){
        this.online = online;
    }
}
