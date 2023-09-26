package shared;

import java.io.Serializable;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Service extends Remote, Serializable {
    public int getI() throws RemoteException;

    public void modI(int factor) throws RemoteException;
}
