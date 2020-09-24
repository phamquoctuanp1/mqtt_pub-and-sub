#include "mqtt1.h"

mqtt1::mqtt1()
{
  mqttClient.setHostname("10.0.50.182");//10;0;50;182
  mqttClient.setPort(1883);

  connect(&mqttClient,&QMqttClient::stateChanged,this,&mqtt1::onStateChanged);
  connect(&mqttClient,&QMqttClient::connected,this,&mqtt1::onConnected);
  connect(this,&mqtt1::goidien,this,&mqtt1::onGoidien);
  connect(&mqttClient,&QMqttClient::messageReceived,this,&mqtt1::onMessageReceived);


}


void mqtt1::connectHost()
{
    mqttClient.connectToHost();
}

void mqtt1::kichHoat(QString message)
{
    //phat tin hieu/ trigger signal
    qDebug()<<__LINE__;
    emit goidien(message);
}

void mqtt1::onStateChanged(QMqttClient::ClientState state)
{
    qDebug()<<state;
}

void mqtt1::onConnected()
{
    qDebug()<<"gui message";
    mqttClient.publish(QMqttTopicName("whtever"),"10.0.5.55");
   QMqttSubscription *m  = mqttClient.subscribe(QMqttTopicFilter("whtever"));
   connect(m,&QMqttSubscription::stateChanged,this,&mqtt1::updateStatus);
}


void mqtt1::onGoidien(QString message)
{
    qDebug()<<__LINE__;
    qDebug()<<message;
}

void mqtt1::onMessageReceived(const QByteArray &message,const QMqttTopicName &topic)
{

    qDebug()<<message;
    qDebug()<<topic;
}

void mqtt1::updateStatus(QMqttSubscription::SubscriptionState state)
{
    qDebug()<<state<<"subscribe";
}


