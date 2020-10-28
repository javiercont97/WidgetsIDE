#ifndef WSTT_H
#define WSTT_H

#include <QObject>
#include <QWebSocket>

class WSTT : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString appID READ getAppID WRITE setAppID)
    Q_PROPERTY(QString apiKey READ getApiKey WRITE setApiKey)
    Q_PROPERTY(QString host READ getHost WRITE setHost)

public:
    explicit WSTT(QObject *parent = nullptr);
    ~WSTT();

    QString getAppID() const;
    void setAppID(const QString &value);

    QString getApiKey() const;
    void setApiKey(const QString &value);

    QString getHost() const;
    void setHost(const QString &value);

public slots:
    void connectServer();
    void publish(QString topic, QString message);

    void subscribe(QString topic);


signals:
    void messageRecieved(QString message);

    void connectionEstablished();
    void credentialsRejected();
private slots:
    void onConnected();
    void onClosed();
    void onMessage(QString message);

private:

    QWebSocket *socket;
    QString appID;
    QString apiKey;
    QString host = "ws://ec2-18-224-3-207.us-east-2.compute.amazonaws.com:3000";
    bool authenticated = false;
};

#endif // WSTT_H
