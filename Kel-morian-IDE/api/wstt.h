//#ifndef WSTT_H
//#define WSTT_H

//#include <QObject>
//#include <QWebSocket>

//enum class CLIENT_TYPE {
//    APPLICATION,
//    DEVICE
//};

//class WSTT : public QObject {
//    Q_OBJECT
//public:
//    explicit WSTT(QObject *parent = nullptr);
//    ~WSTT();

//    void ConnectServer(QString id, QString apiKey, QString targetApp, CLIENT_TYPE type = CLIENT_TYPE::DEVICE, QUrl hostUrl = QUrl("ws://ec2-52-15-169-160.us-east-2.compute.amazonaws.com:3000"));

//    bool sendMessage(QString topic, QString message);
//    bool sendMessage(QString topic, QJsonObject message);

//    void subscribe(QString topic);

//signals:
//    void messageRecieved( QJsonObject message);
//    void messageRecieved( QString message);
//    void messageRecieved( QByteArray message);

//    void connectionEstablished();
//    void credentialsRejected();
//private slots:
//    void onConnected();
//    void onClosed();
//    void onMessage( QString message );

//private:
//    QWebSocket *socket;
//    QString id;
//    QString apiKey;
//    CLIENT_TYPE type;
//    QString targetApp;
//};


//#endif // WSTT_H
