package server;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Distant extends Remote {
    public void echo() throws RemoteException;

    public Service getService() throws RemoteException;
}
