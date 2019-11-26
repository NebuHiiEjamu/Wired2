#include "wiredconnection.hpp"
#include "../net/hive.hpp"
#include "../net/listener.hpp"
#include "../net/packet.hpp"
#include "../server.hpp"

WiredConnection::WiredConnection(HivePtr hive, ListenerPtr listener):
	Connection(hive),
	listener(listener)
{
}

void WiredConnection::setSession(SessionRef session)
{
	this->session = session;
}

void WiredConnection::onAccept(std::string_view, uint16)
{
	WiredConnectionPtr connection(new WiredConnection(hive, listener));
	listener->accept(connection);

	Server::getInstance()->createSession(id, std::dynamic_pointer_cast<WiredConnection>
		shared_from_this()));
}

void WiredConnection::onSend(const ByteString&)
{
}

void WiredConnection::onReceive(ByteString &inString)
{
	ByteBuffer buffer(inString);
}

void WiredConnection::onError(Error)
{
}

void WiredConnection::onDisconnect()
{
}
