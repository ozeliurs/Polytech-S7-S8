package server;

import shared.Service;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

public class Main {
    public static void main(String[] args)  throws RemoteException, MalformedURLException {
        DistantObject objetDistant = new DistantObject(10001);
        ServiceObject serviceObject = new ServiceObject(10002);

        objetDistant.setService(serviceObject);

        LocateRegistry.createRegistry(2001);

        Naming.rebind("rmi://localhost:2001/distantObject", objetDistant);
        Naming.rebind("rmi://localhost:2001/serviceObject", serviceObject);
    }
}