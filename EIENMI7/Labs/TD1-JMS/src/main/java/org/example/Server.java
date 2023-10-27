package org.example;

import org.apache.activemq.ActiveMQConnectionFactory;

import javax.jms.*;

public class Server implements MessageListener {
    String username = "admin";
    String password = "admin";
    String broker = "tcp://localhost:61616";
    String recieveQueueName = "sendQueue";
    Session session;
    int session_length = 0;

    public void server() throws JMSException {
        ConnectionFactory factory = new ActiveMQConnectionFactory(username, password, broker);
        Connection connect = factory.createConnection(username, password);
        session = connect.createSession(true, Session.CLIENT_ACKNOWLEDGE);

        Queue recieveQueue = session.createQueue(recieveQueueName);

        MessageConsumer consumer = session.createConsumer(recieveQueue);
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
                System.out.println(textMessage.getJMSRedelivered());
                if (session_length == 12) {
                    // create fake error
                    throw new JMSException("Error");
                }
                message.acknowledge();
                session_length += 1;

            } catch (JMSException e) {
                e.printStackTrace();
                session_length = -1;
            }
        }

        if (session_length == -1) {
            try {
                session.rollback();
                session_length = 0;
            } catch (JMSException e) {
                e.printStackTrace();
            }
        }

        if (session_length % 10 == 0) {
            try {
                session.commit();
            } catch (JMSException e) {
                e.printStackTrace();
            }
        }
    }
}
