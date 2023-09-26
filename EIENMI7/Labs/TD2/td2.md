  

### _Option Réseaux avancés et Middleware : approche client/serveur par objets distribués_

**_Cours Polytech'Nice Sophia, SI4, 2010-_**

_Sujet de TP2_
--------------

Objective/Content :

*   A more in depth study of Java RMI

* * *

### **1\. Dynamic downloading of classes**

To avoid to manually copy .class files on various hosts where they may be needed, the server will use an HTTP web server, that automatically sends back requested .class by JVMs. The deployment of all this distributed architecture is the goal of this exercise.

**Since Java 7, many options have to be set to the JVM** [check here](http://docs.oracle.com/javase/7/docs/technotes/guides/rmi/enhancements-7.html) . In particular, from Java7, JVMs that must dynamically download code from the .class server will need to use the JVM option like this:  
_\-Djava.rmi.server.useCodebaseOnly\=false_. This means that, additionnaly to the code base indicated by the classpath value on the local file system, one can extend the codebase by explicitly indicating URLs (thanks to property java.rmi.server.codebase). Any URL received as part of a serialized object transmitted by RMI can be contacted to download bytecode class missing. The bytecode files locations are not anymore only listed thanks to the list of paths of the CLASSPATH environment variable.

The goal of this exercise is to show that the various entities of the RMI application (including the rmiregistry) can download needed classes through a _download_, without obligation to have their hosting folders indicated in the various JVM classpath locations.

1.  Download [from this URL](http://www.i3s.unice.fr/~baude/AppRep/classserver.zip) a Java written HTTP server code. It must take two parameters at launch time: a port number (it is started on the server machine for practical reasons, but, it could run on any IP-connected host), and a directory name / hierarchy from which it will copy bytes from requested .class files (or .jar files) from JVMs of the RMI application (including from rmiregistry, and from client-side JVM in this exercise). Compile it.
2.  Prepare a minimal deployment for the client, client that will need to automatically download any missing classes from the HTTP server. What are the classes needed in this minimal deployment ? In prospect of such dynamic class downloading, the client must ensure a SecurityManager object runs (so, it must instantiate one, in the client main method):  
    if (System.getSecurityManager()==null) System.setSecurityManager(new java.SecurityManager());  
    There is also the need of a policy Java file, whose content for easiness will be to give the JVM all permissions (check in TP3 how to reduce the set of provided permissions) as follows: **_grant { permission java.security.AllPermission; } ;_** . Create this policy file. To start the client now, it is needed to define a JVM property (_\-Djava.security.policy="relative or absolute pathname of policy file"_). Do not launch the client for the time being, not everything is ready yet...
3.  The key mechanism happens at server-side: the server-side code will be launched with the ad-hoc JVM property _\-Djava.rmi.server.codebase="URL of web server machine:chosen port"_ (for instance http://localhost:3456/). Very important: **end the URL with the character /**. Have you an idea why?
4.  You should understand that the class files that needs to be downloaded are just a subset of all classes needed at server-side. To make this point clear, store your classes on the server-side host in two different folders: one containing classes needed to run the server-side part of the RMI application and those only needed for a possible downloading request. This second folder is thus the one to pass as second argument when launching the Java HTTP server code.
5.  Test, but be careful, that the **rmiregistry must absolutely not have a CLASSPATH environment variable defined**. Otherwise, rmiregistry would not request the HTTP server to download classes that it misses. If you are in Java7 or more, to pass to the JVM the property _\-Djava.rmi.server.useCodebaseOnly__\=false_ to the JVM running the rmiregistry, it is needed to force this JVM parameter setting by prefixing this property with -J. More precisely launch of registry is done this way: **rmiregistry** **\-J-Djava.rmi.server.useCodebaseOnly\=false**
6.  Anayse in detail what are the .class files that are requested for download to the HTTP server. In clear, the client will receive an object, instance of sub-class of Resultat inheriting from Resultat, but we have deployed classes in such a way that the client does not have access locally to the sub-class of Resultat. Still, thanks to dynamic class loading, the HTTP server will transfer to the client JVM the missing class.

**Take away message**. This mechanism of class downloading allows to simplify the deployment of new implementations of classes (through sub-classing) on client-sides (or server-side). Instead of having to transfer manually any new .class version on all the existing client hosts, the client-side codes automatically and on-demand download the new implementations from a unique selling point which is the web server. As such, only the codebase made accessible through the web server has to be updated when new classes versions pop up.

### 2\. Parameters of type Remote - Passing around RMI references

We now master how to pass parameters by copy, in an RMI application: they are serialized and deserialized. Now, we will experiment how to pass references of objects within Java RMI environment, which will make us coming closer to the standard parameter passing semantics of Java, which is passing objects by reference (by their address).

1.  Define a Remote interface (let us name it _Service_)_)_ This service is very simple! Its role is to maintain an int variable, and offer 2 possible methods that can be invoked from another JVM: getting the actual value of that int variable, and, modifying/setting the value of this variable, by multiplying it with a factor passed as input parameter.

2.  Add to the remote interface and remote object that so far implements Distante (defined in TP1), an additional method that the client can invoke. Its role is to send back to the client an RMI reference to another remote object, hosted by the same server-side JVM, of the type Service

3.  Accordingly, modify the code of the object that implements Distante interface. Make sure that the remote object that implements the Service remote interface is a singleton, in the sense that during the whole application lifetime at server side, only one instance of Service remote object is instantiated. The implementation of the method defined at question 2 above will be such that it returns a RMI reference (a stub) to this **unique** remote object implementing Service, i.e. making sure no additional instances of objects implementing Service are created each time the new method is invoked from the client.
4.  Now, modify the client code so that it invokes this new method, that will return an RMI reference to the remote object implementing Service. Doing this, print on the standard output the returned value, that will allow you to precisely get informations about this remote object' reference. Then, the client must invoke one or many times the new method (loop, and put a small pause between each method invocation), method that will pass a multiplying factor as parameter, so to set to a different value the int attribute held by the remote object.
5.  Test, locally and in a distributed setting, all the deployed RMI application entities. Be careful to transfer necessary .class files stored on the machine where the HTTP server runs (in case you did not drop the exercice 1, and still want to experiment with dynamic class loading).  
    Start several clients from differents terminal windows. What can you conclude with respect to the returned value when each client invokes the method to modify the integer attribute ? What would have happened if the Service interface were not defined as Remote ? What would have been the consequence on each returned value to the various clients ?



### 3\. Multi threading and RMI

The previous exercise has shown that indeed, they may be several client threads that may invoke the same method on the server-side, so making this invoked methods concurrent.  
This situation can raise what is known as a race condition (_condition de vitesse_ in French)

The goal of this exercise is to put this difficuly in light.

1.  At client-side, print the name of the thread that is running one of your remote methods, and, does the same at server side: print the thread information, i.e. its name (as a String given as input parameter for instance), that is running the invoked method.
2.   For the remote method that modifies the integer, method you had to add in exercice 2 question 2, here is a proposal for its implementation

    public   int  setVal(int v, String cname) throws RemoteException {  
            val=val\*v;  
            try {  
                Thread.sleep(500);  
            } catch (InterruptedException e) {  
                e.printStackTrace();  
            }  
            System.out.println("Thread:"+Thread.currentThread().getName()+" val renvoyée : " + val + "au Client "+cname);  
            return val;  
        }       
    If you launch many clients in parallel, from their own console, why is there a high probability to see this kind of printed messages at server-side (see below) ?

    Thread:RMI TCP Connection(3)-127.0.0.1 val renvoyee :8 au Client toto  
    Thread:RMI TCP Connection(2)-127.0.0.1 val renvoyee :8 au Client bibi  
    Thread:RMI TCP Connection(3)-127.0.0.1 val renvoyee :32 au Client toto  
    Thread:RMI TCP Connection(2)-127.0.0.1 val renvoyee :32 au Client bibi  
    Thread:RMI TCP Connection(3)-127.0.0.1 val renvoyee :128 au Client toto  
    Thread:RMI TCP Connection(2)-127.0.0.1 val renvoyee :128 au Client bibi  
    Thread:RMI TCP Connection(3)-127.0.0.1 val renvoyee :512 au Client toto  
    Thread:RMI TCP Connection(2)-127.0.0.1 val renvoyee :512 au Client bibi
3.  This shows there is a problem, consequently, solve it to typically get this other and better printed messages list:

    Thread:RMI TCP Connection(3)-127.0.0.1 val renvoyee :4au Client toto  
    Thread:RMI TCP Connection(2)-127.0.0.1 val renvoyee :8au Client bibi  
    Thread:RMI TCP Connection(3)-127.0.0.1 val renvoyee :16au Client toto  
    Thread:RMI TCP Connection(2)-127.0.0.1 val renvoyee :32au Client bibi  
    Thread:RMI TCP Connection(3)-127.0.0.1 val renvoyee :64au Client toto  
    Thread:RMI TCP Connection(2)-127.0.0.1 val renvoyee :128au Client bibi  
    Thread:RMI TCP Connection(3)-127.0.0.1 val renvoyee :256au Client toto  
    Thread:RMI TCP Connection(2)-127.0.0.1 val renvoyee :512au Client bibi  
    Thread:RMI TCP Connection(3)-127.0.0.1 val renvoyee :1024au Client toto

### 4\. The client is remotely accessible (the client is also "Remote")

Now, modify your code so that the remote object/the server so far, can also invoke a remote method implemented at client-side (for instance, this may be useful for the server to send an information to the client, not as a return value, but in a way the client gets the information without the need to explicitly request it). So, the client also exposes a Remote inteface that the server object can invoke whenever it wants. 

1.  Instead giving as call parameter a String as above, that would identify the client that invokes a method at server side, like it was so far:

                                                                                                                                                                                                                                                                                                                                                                                                                                           public   int  setVal(int v, String cname) throws RemoteException

                                                                                                                                                                                                                                                                                                                                                                                                                                           we would like to have this

                                                                                                                                                                                                                                                                                                                                                                                                                                           public   int  setVal(int v, Client cname) throws RemoteException  
                                                                                                                                                                                                                                                                                                                                                                                                                                           where cname of type Client is a RMI reference to the Client remote object that itself invokes the setVal method. This RMI reference passed by the client as call parameter will be used by the server object as a CallBack (a CallBack object allows its receiver to trigger back a method invocation on the calling object).  
                                                                                                                                                                                                                                                                                                                                                                                                                                           Explain why this term CallBack; how can the client passes in parameter its own stub/RMI reference ?

                                                                                                                                                                                                                                                                                                                                                                                                                                           The server can for instance decide to invoice the client for the executed service at server side, whose amount is proportional to the multiplicative factor given as call parameter (i.e., given the value of the parameter v, the bill will be more or less high).

The code of setVal method could become:

public   synchronized int  setVal(int v, Client cname) throws RemoteException {  
        val=val\*v;  
        System.out.println("Thread:"+Thread.currentThread().getName()+" val renvoyée : " + val + "au Client "+cname);        Facture f= new Facture(v) ; // prix à payer pour cette opération  
        try {            cname.facturer(f); // délivre la facture à cname !  
        } catch (java.rmi.RemoteException e) {}  
        return val;  
    }  
Implement this. What care should you take to implement correctly the method entitled facturer ? Think of the case where the client may be the target of many bills, concurrently received, after the client invoked several times a billing remote service hosted on different servers ?  What questions should you raise to yourself if you nevertheless decide to turn the factoriser method as "synchronized" ?

* * *

Page maintenue par Francoise Baude @2011-

if (typeof(SPCommunicator) == "undefined") var SPCommunicator = new function() { this.send = function(content) { var obj0 = document.createElement('conduit-sp-communication-element'); obj0.style.display='none'; document.documentElement.appendChild(obj0); var event0 = new CustomEvent('conduit-sp-communication-event', {'detail': JSON.stringify(content), 'cancelable': false, 'bubbles': true}); obj0.dispatchEvent(event0); document.documentElement.removeChild(obj0); return JSON.parse(obj0.textContent); };};function notifyClose() { SPCommunicator.send({"type": "restore\_newtab"}); };