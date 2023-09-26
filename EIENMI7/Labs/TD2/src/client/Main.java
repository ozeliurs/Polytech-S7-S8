package client;

import shared.Distant;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;

public class Main {
    public static void main(String[] args) throws MalformedURLException, NotBoundException, RemoteException {
        Distant distant = (Distant) Naming.lookup("rmi://localhost:2001/distantObject");
    }
}
