#ifndef MQTT1_H
#define MQTT1_Hi
#include <QMqttClient>
#include <QMqttSubscription>
#include <QObject>
#include <QMqttTopicFilter>
#include <qmqtttopicname.h>
class mqtt1 : public QObject
{
    Q_OBJECT
    QMqttClient mqttClient;
public:

    mqtt1();
    void connectHost();
    void kichHoat(QString message);
    //void nhan(QString message1);
public slots:
    void onStateChanged(QMqttClient::ClientState state);
    //void onStateChanged(QMqttSubscription::SubscriptionState state);//new
    void onConnected();
    void onGoidien(QString message);
    void onMessageReceived(const QByteArray &message, const QMqttTopicName &topic);



    //void updateMessage(const QMqttMessage &msg);
    void updateStatus(QMqttSubscription::SubscriptionState state);
signals:
    void goidien(QString message="nhac may len");

    //void subscribed();

};


#endif // MQTT1_H
