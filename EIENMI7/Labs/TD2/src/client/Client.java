package client;

import server.Distant;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;

public class Client {
    public static void main(String[] args) throws MalformedURLException, NotBoundException, RemoteException {

        Distant distant = (Distant) Naming.lookup("rmi://192.168.254.47:2001/a");
        distant.echo();

        
    }
}