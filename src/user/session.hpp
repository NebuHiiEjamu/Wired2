#ifndef _SESSION_H
#define _SESSION_H

#include "forward.hpp"
#include "../net/forward.hpp"
#include "../common.hpp"

class Session : public std::enable_shared_from_this<Session>
{
public:
	Session(suint32, WiredConnectionPtr);
private:
	AccountRef account;
	WiredConnectionPtr connection;
	std::string nickname;
	std::string status;
	std::string appName;
	std::string appVersion;
	std::string appBuild;
	std::string osName;
	std::string osVersion;
	std::string architecture;
	ByteString icon;
	Timestamp loginTime;
	Timestamp idleTime;
	std::mutex mutex;
	suint32 id;
	bool idle;
	bool rsrcSupported;
};

#endif // _SESSION_H
