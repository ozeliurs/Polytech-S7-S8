# TD1: Approche client/serveur par objets distribués

## **1\. The remote object**

The first step consists in writing a remote interface and the object that implements it

1.  Write a remote interface named _Distante_, having a method named _echo_ without call parameters and without a return value
2.  Implement this interface in an object _ObjetDistant_ (makes echo prints a message on the standard output)
3.  Add a main method _main_ to the object, or to an other standard Java object, so to instantiate a remote object and register it in a rmiregistry (on the LMS, you can find a mini tutorial to help you)
4.  Compile all these classes and make sure the compiled files are stored in the right directory
5.  You do not need to generate a stub by hand (using rmic), because it is automatically done if the Java version, the JDK is >= JDK 1.5

## **2\. The client**

To give the client code, it is necessary to only know the remote interface defintion. So, in the client code, you must only use the type _Distante_ et never the type _ObjetDistant_

1.  Create a class named Client having a _main_ method that lookups for an RMI reference of the remote object in the rmiregistry.
2.  Write the code that will call the method exposed by the remote object
3.  Compile your class

## **3\. Local execution**

We will test this small RMI application. To simplify things, all entities will run on a single host (your local machine). Open three terminal/consoles to do the following operations, and in each shell, you must change directory so your shell is positioned in the folder that contains the .class files (be careful with the possible existence of any package your .class files belong to) or, make the tests from the IDE if you prefer after you have understood what happens:  

1.  Start an _rmiregistry_
2.  Start your remote object / server side program
3.  Start one client
4.  In which terminal/console is printed the message ? Explain

## **4\. Study of the communication**

RMI communications are qualified as being synchronous, this is what this exercise will exhibit.

1.  In the method _echo_ implemented by the remote object, add a sleep period (_Thread.sleep(...))_.
2.  At the client-side, print a message on the standard ouput just before invoking _echo_ and just after this call
3.  Execute, what do you notice ? Explain

## **5\. Simplified execution in a distributed setting**

We are going to test this small RMI application using two different hosts. We make the assumption that these machines can freely communicate (they are on the same network) and that Java installation (same JDK version preferably) is available on both machines. We will use the local machine for the client part, and another machine for the server-side (for instance your neighbour in the classroom).

1.  Transform the "localhost" value used so far with the name of the host where the rmiregistry will run, as the server-side.
2.  Then, we will separate our classes in two sets: classes useful at server-side, those only useful at client-side, meaning some .class files may be duplicated. Transfér to the remote machine the source files needed at server-side.
3.  Compile classes transferred on the server-side machine
4.  Change directory so to be able to start the rmiregistry on the server host with the right classpath. (What is a correct classpath here ?)
5.  Start the client code locally: thanks to the lookup into the registry running on the remote host, the stub object will arrive at client side, in a serialized form. It will be deserialized by applying a dynamically generated class for this stub instance, at the client-side JVM.
    
    If the IP address resolution does not work as expected (that is, the IP address indicated in the stub is localhost and not the IP where the server runs, you can solve the problem by requesting the JVM that has created the stub to run with the following JVM property \-Djava.rmi.server.hostname\=xxx.xxx.xxx.xxx
    
6.  Now, stop the server side and registry programs. On the server machine, change directory to one where there is no chance a new launched rmiregistry will have access to the .class of your RMI server-side application. Change again the directory to go back in the folder that has access to the .class of the server-side application. Start now the server-side. You will get an exception, that you now need to analyse in detail (one trace is provided below in the case you could not experiment successfully: in this example, the server implements a remote interface whose name is not Distante, but HellowWorld). Explain what this exception means, and which JVM has created this error message.
    
```
\[fbaude@bego\]~/Cours/AppRep/HelloWorld% The RMI naming service is listening at 2001  
cd bin  
\[fbaude@bego\]~/Cours/AppRep/HelloWorld/bin% java HelloWorldServer  
Creation de l'objet serveur  
Referencement dans le registry..  
On a l'acces au registry ecoutant sur 2001  
java.rmi.UnexpectedException: undeclared checked exception; nested exception is:  
**java.lang.ClassNotFoundException****: HelloWorld not found** in gnu.gcj.runtime.SystemClassLoader{urls\=\[file:./\], parent=gnu.gcj.runtime.ExtensionClassLoader{urls\=\[\], parent=null}}  
at gnu.java.rmi.registry.RegistryImpl\_Stub.rebind(libgcj.so.8rh)  
at HelloWorldServer.main(HelloWorldServer.java:23)  
Caused by: java.lang.ClassNotFoundException: HelloWorld not found in gnu.gcj.runtime.SystemClassLoader{urls\=\[file:./\], parent=gnu.gcj.runtime.ExtensionClassLoader{urls\=\[\], parent=null}}
```
    
    **Explanation**: The rmi registry complains at the (re)bind, that it does not succeed to load the .class from its classpath, this class describing the interface that extends Remote, and from which it could automatically generate the bytecode stub class
    

## **6\. Explicit generation of stub and skeleton classes (optional exercise)**

Long time ago, before Java version 2, classes corresponding to stub objects had to be created in advance, and the skeleton class was mandatory. It is instructive to provoke an explicit and manual creation of them, for pedagogical purposes.

1.  After having got documentation about the _rmic_ binary command, installed in the bin of the JDK installation, apply it to your case. What is the class name to pass to rmic ? At minimum, you must test the option v1.2, and the option v1.1 if it stills is available. This should run on the server machine, and, at least if you do not have access to two different hosts, this should run in a case where you have explicitly separated classes into a set for the server-side, and a set for the client-side.
2.  At the client-side, are these additional .class files known ? Launch the client (on the other host): explain why you obtain an exception of type ClassNotFoundException ? What class is not found ? We will study in future labs how to solve that problem, but an easy solution consists in copying manually the needed .class files to the client-side host (or, to the client-side directory). Once copied, test again (this time, everything sould work well)

**Explanation** When rmiregistry runs the binding operation, it realizes it does not possess in any path indicated in its CLASSPATH a .class file corresponding to the stub class; it learns that it should use that class from the information in the serialization stream corresponding to the stub object: in this stream, it is written that the object is instance of a specific class (the stub class). Consequently, if this .class is found in the classpath, it will be loaded by the rmiRegistry class loader; otherwise, this exception is raised.

## **7\. Parameters passing**

Methods of the Remote interface must be able to take and return some parameters...

1.  Add to the remote interface one method that takes an int as parameter, and returns an object of a class that you will define, named for instance Resultat. Do not forget to override the toString() method in this class. Complete all needed code, and use this newly added method in the client-side code.
2.  To avoid having classes missing, ensure that the directory at client-side has access to Resultat.class. Test. It may be possible that you get trace and this exception at client-side:
    
    > On va maintenant declencher l'appel de la methode distante sayResultat renvoyant un objet Resultat.**java.rmi.UnmarshalException**: error unmarshalling return; nested exception is:  
    > **java.io.InvalidClassException****: Resultat**; **Resultat****; class invalid for deserialization**  
    > at sun.rmi.server.UnicastRef.invoke(Unknown Source)  
    > at java.rmi.server.RemoteObjectInvocationHandler.invokeRemoteMethod(Unknown Source)  
    > at java.rmi.server.RemoteObjectInvocationHandler.invoke(Unknown Source)  
    > at $Proxy0.sayResultat(Unknown Source) **// sayResultat est le nom de la méthode Remote utilisé par mon HelloWorldClient**  
    > at HelloWorldClient.main(HelloWorldClient.java:36)  
    > Caused by: **java.io.InvalidClassException****: Resultat; Resultat; class invalid for deserialization**  
    > at java.io.ObjectStreamClass.checkDeserialize(Unknown Source)  
    > at java.io.ObjectInputStream.readOrdinaryObject(Unknown Source)
    
    Indeed, remember that the remote object will try to send back to the client JVM a serialized copy of the returned value, of type Resultat. For this to work, the returned object should have been serialized as a byte array, to pass on the network wire, then re-instancied in the JVM that receives this bytes stream. To do this, the class that this returned object is instance of must be tagged as Serializable. If it is not yet the case, add this marker to Resultat, recompile and test again.
    

## 8\. Serialization (reminders ?)

Java RMI intensively uses serialization. A reminder is needed! !

1.  Take again Resultat class (which is serializable). In the constructor, print a message to show the constructor has been invoked. Add an attribute of type String to describe for example the credetentials of a user wishing to pay using its bank credit card « InfoCB » (Identity of the holder, followed by numbers) declaring it as _transient_ (the effect of transient is that this attribute value will not be copyied during serialization). To convience yourself about that, launch again the RMI application and check that this attribute has only the bydefault value corresponding to its type (the value has not been serialized).
2.  Turn this attribute InfoCB as private, and add to it two methods, a getter and a setter . Put the attribute as **non** transient for the rest of this exercise.
3.  Create a sub class of Resultat. It will be _Serializable_ by inheritance. Add an attribute (int) that may correspond to the PIN code, that you will initialize in the constructor.  
4.  Also add two methods that will redefine the inherited getter and setter methots for attribute InfoCB. The idea is to simulate in this pair of methods an encryption / decryption for InfoCB : to simulate the encoding, the setter applies a transformation that turn the value of InfoCB in capital letters: it thus modify the initial value of the attribute InfoCB ; to simulate the decoding, the redefined getter method gets the value, and transform it in lowercase letters to which it concatenates the codePIN (doing this way, the client has all information that allows him to buy something).     
    Redefine toString() in the sub class (which will have also to call super.toString() of the parent class) so to well follow what are the brute (initial) values of attributes InfoCB and code PIN of an instance of the sub class of Resultat.
5.  Make sure that the implementation (but not the Remote interface implemented) of the server-side remote object returns an object that is a sub-class of Resultat and not of the class Resultat.  Just before returning back this result, so, outside of the constructor, modify the value of CodePIN. Ask yourself the following : what are the values of InfoCB and codePIN that are transmitted on the wire ?
6.  If needed, copy these modified .class on the client-side host, and launch the RMI application (do not forget to launch the rmiregistry). Thanks to the invocation of method toString(), check the received values are those you expected: those that are sent from server side. Note precisely also when the various constructors of your 2 classes are (automatically) invoked during the serialization & deserialization processes.

**Take away message** The deserialization mechanism does not use constructor(s) for classes that are _Serializable_. It only bases upon the received values from the stream, so to initialize the attributes of the object created by the deserialization process, except for the _transient_ attributes.  
The principles of polymorphism and inheritance of Java are relevant to transparently implement new behaviours (here, the main client code receives credit card information, but does not need to be aware they are encoded when it receives them, because there is a transparent decoding operation that first took place. This new behaviour that encodes / decodes is transparent to the main client code). Still, it only works if the client JVM has access to the extended classes bytecode files, so to be able to use them during the deserialization process. The next lab will address this need.