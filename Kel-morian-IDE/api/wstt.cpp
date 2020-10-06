//#include "wstt.h"
//#include <QJsonDocument>
//#include <QJsonObject>
//#include <QJsonValue>


//WSTT::WSTT(QObject *parent) : QObject(parent) {
//    socket = new QWebSocket();
//}

//WSTT::~WSTT() {
//    if(socket->state() == QAbstractSocket::SocketState::ConnectedState) {
//        socket->close();
//    }
//    delete socket;
//}

//void WSTT::ConnectServer(QString id, QString apiKey, QString targetApp, CLIENT_TYPE type, QUrl hostUrl) {
//    this->id = id;
//    this->apiKey = apiKey;
//    this->type = type;
//    this->targetApp = targetApp;

//    connect(socket, &QWebSocket::connected, this, &WSTT::onConnected);
//    connect(socket, &QWebSocket::disconnected, this, &WSTT::onClosed);
//    connect(socket, &QWebSocket::textMessageReceived, this, &WSTT::onMessage);

//    socket->open(hostUrl);
//}

//bool WSTT::sendMessage(QString topic, QString message) {
//    if(topic != "Auth" && topic != "Subs") {
//        QJsonDocument json;
//        QJsonObject jsonBody;
//        jsonBody.insert("targetApp", this->targetApp);
//        jsonBody.insert("topic", topic);
//        QJsonObject messageBody;
//        messageBody.insert("message", message);
//        jsonBody.insert("message", messageBody);
//        json.setObject(jsonBody);
//        socket->sendBinaryMessage(json.toJson());
//        return true;
//    }
//    return false;
//}

//bool WSTT::sendMessage(QString topic, QJsonObject message) {
//    if(topic != "Auth" && topic != "Subs") {
//        QJsonDocument json;
//        QJsonObject jsonBody;
//        jsonBody.insert("targetApp", this->targetApp);
//        jsonBody.insert("topic", topic);
//        jsonBody.insert("message", message);
//        json.setObject(jsonBody);
//        socket->sendBinaryMessage(json.toJson());
//        return true;
//    }
//    return false;
//}

//void WSTT::subscribe(QString topic) {
//    QJsonDocument json;
//    QJsonObject jsonBody;
//    jsonBody.insert("targetApp", this->targetApp);
//    jsonBody.insert("topic", "Subs");

//    QJsonObject message;
//    message.insert("targetApp", this->targetApp);
//    message.insert("topic", topic);

//    jsonBody.insert("message", message);
//    json.setObject(jsonBody);

//    socket->sendBinaryMessage(json.toJson());
//}

//void WSTT::onConnected() {
//    QJsonDocument json;
//    QJsonObject jsonBody;

//    jsonBody.insert("topic", "Auth");

//    QJsonObject message;
//    if(this->type == CLIENT_TYPE::DEVICE){
//        message.insert("deviceID", this->id);
//    } else {
//        message.insert("appID", this->id);
//    }
//    message.insert("apiKey", this->apiKey);
//    jsonBody.insert("message", message);

//    json.setObject(jsonBody);

//    socket->sendBinaryMessage(json.toJson());
//}

//void WSTT::onClosed() {
//    if(socket->state() == QAbstractSocket::SocketState::ConnectedState) {
//        socket->close();
//    }
//}

//void WSTT::onMessage(QString message) {
//    QJsonDocument jsonMessage = QJsonDocument::fromJson(message.toUtf8());

//    if(jsonMessage.object().value("topic").toString() == "Auth") {
//        if(jsonMessage.object().value("res").toString() == "accepted") {
//            emit connectionEstablished();
//        } else {
//            emit credentialsRejected();
//        }
//    } else {
//        emit messageRecieved(message);
//        emit messageRecieved(QString::fromStdString(message.toStdString()));
//        emit messageRecieved(jsonMessage.object().value("message").toObject());
//    }
//}
