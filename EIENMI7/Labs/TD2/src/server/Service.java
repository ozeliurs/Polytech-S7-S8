package server;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Service extends Remote {
    public int getValue() throws RemoteException;

    public void setValue(int value) throws RemoteException;
}
