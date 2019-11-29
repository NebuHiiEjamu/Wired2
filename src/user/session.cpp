#include "session.hpp"
#include "hlconnection.hpp"

Session::Session(suint32 id, WiredConnectionPtr connection):
	connection(connection),
	id(id)
{
}

suint32 Session::getId() const
{
	return id;
}
