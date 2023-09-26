package shared;

import java.rmi.RemoteException;

public interface Distant {
    public Service getService() throws RemoteException;
}
