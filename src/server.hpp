#ifndef _SERVER_H
#define _SERVER_H

#include <bitset>
#include <boost/predef.h>
#include <map>
#include <set>

#include "net/forward.hpp"
#include "user/forward.hpp"
#include "forward.hpp"
#include "common.hpp"

using boost::asio;

#if BOOST_OS_WINDOWS
	struct OSVERSIONINFOEXA;
#elif BOOST_OS_MACOS
	using int32 = std::int32_t;
#else
	struct utsname;
#endif

struct sqlite3;

class Server final : public std::enable_shared_from_this<Server>
{
public:
#if BOOST_OS_WINDOWS
	static OSVERSIONINFOEXA osVersionInfo;
	static int osError;
#elif BOOST_OS_MACOS
	static int32 osVersionMajor;
	static int32 osVersionMinor;
	static int32 osVersionFix;
#else
	static utsname osInfo;
#endif

	static constexpr std::string_view getArchitecture();
#if BOOST_OS_WINDOWS || BOOST_OS_MACOS
	static constexpr std::string_view getOSName();
#else
	static std::string_view getOSName();
#endif
	static std::string&& getOSVersion();
	static constexpr std::string_view getDefaultDatabase();
	static ServerRef getInstance();

	~Server();
	bool createSession(uint32, WiredConnectionPtr);
	void removeSession(uint32);
	uint32 getNextUserId();
	uint32 getUserCount();
	std::string_view getDescription() const;
	std::string_view getName() const;
private:
	Server();
private:
	static std::shared_ptr<Server> instance;

	std::string name;
	std::string description;
	ByteString banner;
	std::map<uint32, SessionPtr> sessionMap;
	std::set<AccountPtr> accounts;
	std::set<GroupPtr> groups;
	sqlite3 *db;
	std::mutex mutex;
	uint32 nextUserId;
};

#endif // _SERVER_H
