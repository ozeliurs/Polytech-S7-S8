package server;

import shared.Distant;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

public class Main {
    public static void main(String[] args) throws RemoteException, MalformedURLException {
        ObjetDistant objetDistant = new ObjetDistant(10001);

        LocateRegistry.createRegistry(2001);

        Naming.rebind("rmi://localhost:2001/objetDistant", objetDistant);
    }
}