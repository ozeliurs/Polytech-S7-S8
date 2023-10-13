package org.example;

import org.apache.activemq.ActiveMQConnectionFactory;

import javax.jms.*;

public class Server implements MessageListener {
    String username = "admin";
    String password = "admin";
    String broker = "tcp://localhost:61616";
    String recieveQueueName = "sendQueue";

    public void server() throws JMSException {
        ConnectionFactory factory = new ActiveMQConnectionFactory(username, password, broker);
        Connection connect = factory.createConnection(username, password);
        Session sendSession = connect.createSession(false, javax.jms.Session.AUTO_ACKNOWLEDGE);

        Queue recieveQueue = sendSession.createQueue(recieveQueueName);

        MessageConsumer consumer = sendSession.createConsumer(recieveQueue, "typeMess = 'important'");
        consumer.setMessageListener(this);
        connect.start();
    }

    public static void main(String[] args) throws JMSException {
        Server server = new Server();
        server.server();
    }

    @Override
    public void onMessage(Message message) {
        if (message instanceof MapMessage) {
            MapMessage textMessage = (MapMessage) message;
            try {
                System.out.println("Received: " + textMessage.getString("message"));
                System.out.println("Received: " + textMessage.getString("name"));
            } catch (JMSException e) {
                e.printStackTrace();
            }

        }
    }
}
