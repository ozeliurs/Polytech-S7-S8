package client;

import shared.Resultat;
import shared.Distant;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;


public class Main {
    public static void main(String[] args) throws MalformedURLException, NotBoundException, RemoteException, InterruptedException {
        // System.setProperty()
        Distant distant = (Distant) Naming.lookup("rmi://localhost:2001/objetDistant");

        distant.echo();
        Resultat r = distant.getResult(12);
        System.out.println(r.toString());
    }
}