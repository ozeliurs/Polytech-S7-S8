package org.example;

import org.apache.activemq.ActiveMQConnectionFactory;

import javax.jms.*;
import java.io.IOException;

public class Client {
    public static void main(String[] args) throws JMSException, IOException {
        String username = "admin";
        String password = "admin";
        String broker = "tcp://localhost:61616";
        String sendQueueName = "sendQueue";

        ConnectionFactory factory = new ActiveMQConnectionFactory(username, password, broker);
        Connection connect = factory.createConnection(username, password);
        Session sendSession = connect.createSession(true, javax.jms.Session.AUTO_ACKNOWLEDGE);

        Queue sendQueue = sendSession.createQueue(sendQueueName);

        MessageProducer producer = sendSession.createProducer(sendQueue);

        int i = 0;

        while (true) {
            i += 1;
            MapMessage message = sendSession.createMapMessage();
            message.setString("message", "Hello World! " + i);
            message.setString("name", "John Doe");
            message.setStringProperty("typeMess", "important");
            producer.send(message);
            System.out.println("Sent: " + message);
            // wait for keypress
            System.in.read();
            if (i % 3 == 0) {
                sendSession.commit();
            }
        }
    }
}
