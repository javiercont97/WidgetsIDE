#include "wstt.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

WSTT::WSTT(QObject *parent) : QObject(parent) {
    socket = new QWebSocket();
}

WSTT::~WSTT() {
    if(socket->state() == QAbstractSocket::SocketState::ConnectedState) {
        socket->close();
    }
    delete socket;
}

void WSTT::publish(QString topic, QString message) {
    if(topic != "Auth" && topic != "Subs" && authenticated) {
        QJsonDocument json;
        QJsonObject jsonBody;
        jsonBody.insert("targetApp", this->appID);
        jsonBody.insert("topic", topic);
        jsonBody.insert("message", message);
        json.setObject(jsonBody);
        socket->sendBinaryMessage(json.toJson());
    }
}

void WSTT::subscribe(QString topic) {
    QJsonDocument json;
    QJsonObject jsonBody;
    jsonBody.insert("targetApp", this->appID);
    jsonBody.insert("topic", "Subs");

    QJsonObject message;
    message.insert("targetApp", this->appID);
    message.insert("topic", topic);

    jsonBody.insert("message", message);
    json.setObject(jsonBody);

    socket->sendBinaryMessage(json.toJson());
}

void WSTT::onConnected() {
    QJsonDocument json;
    QJsonObject jsonBody;

    jsonBody.insert("topic", "Auth");

    QJsonObject message;
    message.insert("appID", this->appID);
    message.insert("apiKey", this->apiKey);
    jsonBody.insert("message", message);

    json.setObject(jsonBody);

    socket->sendBinaryMessage(json.toJson());
}

void WSTT::onClosed() {
    if(socket->state() == QAbstractSocket::SocketState::ConnectedState) {
        socket->close();
    }
}

void WSTT::onMessage(QString message) {
    QJsonDocument jsonMessage = QJsonDocument::fromJson(message.toUtf8());

    if(jsonMessage.object().value("topic").toString() == "Auth") {
        if(jsonMessage.object().value("res").toString() == "accepted") {
            authenticated = true;
            emit connectionEstablished();
        } else {
            emit credentialsRejected();
        }
    } else {
        emit messageRecieved(message);
    }
}

void WSTT::connectServer() {
    connect(socket, &QWebSocket::connected, this, &WSTT::onConnected);
    connect(socket, &QWebSocket::disconnected, this, &WSTT::onClosed);
    connect(socket, &QWebSocket::textMessageReceived, this, &WSTT::onMessage);

    socket->open(this->host);
}

QString WSTT::getHost() const {
    return host;
}

void WSTT::setHost(const QString &value) {
    host = value;
}

QString WSTT::getApiKey() const {
    return apiKey;
}

void WSTT::setApiKey(const QString &value) {
    apiKey = value;
}

QString WSTT::getAppID() const {
    return appID;
}

void WSTT::setAppID(const QString &value) {
    appID = value;
}
