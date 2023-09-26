package server;

import shared.Service;

import java.io.Serializable;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class ServiceObject extends UnicastRemoteObject implements Service, Serializable {
    private int i;

    protected ServiceObject(int port) throws RemoteException {
        super(port);
    }

    @Override
    public int getI() throws RemoteException {
        return i;
    }

    @Override
    public void modI(int factor) throws RemoteException {
        i *= factor;
    }
}
