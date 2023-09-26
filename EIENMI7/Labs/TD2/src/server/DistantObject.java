package server;

import shared.Distant;
import shared.Service;

import java.io.Serializable;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class DistantObject extends UnicastRemoteObject implements Distant {
    private Service service;

    protected DistantObject(int port) throws RemoteException {
        super(port);
    }

    public void setService(Service service) {
        this.service = service;
    }

    @Override
    public Service getService() throws RemoteException {
        return service;
    }
}
