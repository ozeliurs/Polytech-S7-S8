package server;

import shared.Distant;
import shared.Resultat;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class ObjetDistant extends UnicastRemoteObject implements Distant {
    public ObjetDistant(int port) throws RemoteException {
        super(port);
    }

    @Override
    public void echo() throws RemoteException, InterruptedException {
        Thread.sleep(1000);
        System.out.println("cc");
    }

    @Override
    public Resultat getResult(int value) throws RemoteException {
        System.out.println(value);
        return new Resultat(value);
    }
}
