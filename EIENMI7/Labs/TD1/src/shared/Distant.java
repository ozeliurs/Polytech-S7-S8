package shared;

import java.io.Serializable;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Distant extends Remote, Serializable {
    public void echo() throws RemoteException, InterruptedException;

    public Resultat getResult(int value) throws RemoteException;
}
