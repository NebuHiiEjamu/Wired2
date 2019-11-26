#include <boost/predef.h>
#include <sqlite3.h>
#include <utility>

#if BOOST_OS_WINDOWS
	#include <windows.h>
#else
	#if !BOOST_OS_MACOS
		#include <sys/utsname.h>
	#endif
#endif

#include "server.hpp"
#include "user/wiredconnection.hpp"
#include "user/session.hpp"

std::shared_ptr<Server> Server::instance = std::make_shared<Server>();

constexpr std::string_view Server::getDefaultDatabase()
{
	return "DROP TABLE IF EXISTS `accounts`;\
		CREATE TABLE `accounts` (\
			`id` INTEGER PRIMARY KEY AUTOINCREMENT,\
			`name` TEXT NOT NULL,\
			`full_name` TEXT NOT NULL,\
			`color` INTEGER NOT NULL,\
			`comment` TEXT,\
			`last_edit_by` TEXT,\
			`file_path` TEXT,\
			`password` TEXT,\
			`created` TEXT,\
			`modified` TEXT,\
			`last_login` TEXT,\
			`access` INTEGER NOT NULL,\
			`primary_group` TEXT,\
			`secondary_groups` TEXT,\
			`recursive_file_path_depth_limit` INTEGER,\
			`dl_limit` INTEGER,\
			`ul_limit` INTEGER,\
			`dl_speed_limit` INTEGER,\
			`ul_speed_limit` INTEGER\
		);\
		\
		DROP TABLE IF EXISTS `groups`;\
		CREATE TABLE `groups` (\
			`id` INTEGER PRIMARY KEY AUTOINCREMENT,\
		);\
		\
		\
		DROP TABLE IF EXISTS `trackers`;\
		CREATE TABLE `trackers` (\
			`id` INTEGER PRIMARY KEY AUTOINCREMENT,\
			`address` TEXT NOT NULL,\
			`category` TEXT NOT NULL,\
			`port` INTEGER NOT NULL\
		);\
		\
		DROP TABLE IF EXISTS `bans`;\
		CREATE TABLE `bans` (\
			`id` INTEGER PRIMARY KEY AUTOINCREMENT,\
			`address` TEXT NOT NULL,\
			`expiration` INTEGER\
		);\
		\
		\
		INSERT INTO `accounts` (login, name, password, flags)\
			VALUES ('admin', 'Administrator', x'9E9B929691', 141836996834303),\
				('guest', 'Guest', NULL, 140738026041376);";
}

Server::Server():
	nextUserId(1)
{
}

std::string&& Server::getOSName()
{
	std::string result;
#if BOOST_OS_WINDOWS
	result = "Windows ";
	
	if (osError != 0)
	{
		switch (osVersionInfo.dwMajorVersion)
		{
			case 5:
				switch (osVersionInfo.dwMinorVersion)
				{
					case 0: result += "2000"; break;
					case 1: result += "XP"; break;
					case 2:
						if ((osVersionInfo.wProductType == VER_NT_WORKSTATION) &&
							(systemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64))
							result += "XP Professional x64 Edition";
						if (GetSystemMetrics(SM_SERVERR2) == 0)
							result += "Server 2003";
						else
							result += "Server 2003 R2";
						if (osVersionInfo.wSuiteMask & VER_SUITE_WH_SERVER)
							result += "Home Server";
						break;
					default: ;
				}
				break;
			case 6:
				switch (osVersionInfo.dwMinorVersion)
				{
					case 0:
						if (osVersionInfo.wProductType == VER_NT_WORKSTATION)
							result += "Vista";
						else
							result += "Server 2008";
						break;
					case 1:
						if (osVersionInfo.wProductType == VER_NT_WORKSTATION)
							result += "7";
						else
							result += "Server 2008 R2";
						break;
					case 2:
						if (osVersionInfo.wProductType == VER_NT_WORKSTATION)
							result += "8";
						else
							result += "Server 2012";
						break;
					case 3:
						if (osVersionInfo.wProductType == VER_NT_WORKSTATION)
							result += "8.1";
						else
							result += "Server 2012 R2";
						break;
					default: ;
				}
				break;
			case 10:
				if (osVersionInfo.wProductType == VER_NT_WORKSTATION)
					result += "10";
				else
					result += "Server 2016";
				break;
			default: ;
		}
	}
#elif BOOST_OS_MACOS
	result = "Mac OS X";
#else
	result = osInfo.sysname;
#endif
	return std::move(result)
}

std::string&& Server::getOSVersion()
{
	std::string result;
#if BOOST_OS_WINDOWS
	if (osError != 0)
		result = std::to_string(osVersionInfo.dwMajorVersion) + '.' +
			std::to_string(osVersionInfo.dwMinorVersion) + '.' +
			std::to_string(osVersionInfo.dwBuildNumber);
#elif BOOST_OS_MACOS
	result = std::to_string(osVersionMajor) + '.' + std::to_string(osVersionMinor) + '.' +
		std::string(osVersionFix);
#else
	result = osInfo.version;
#endif
	return std::move(result);
}

bool Server::createSession(uint32 id, WiredConnectionPtr connection)
{
	LockGuard lock(mutex);
	SessionPtr newSession = std::make_shared<Session>(id, connection);
	connection->setSession(newSession);
	sessionMap[id] = newSession;

	return true;
}

void Server::removeSession(uint32 id)
{
	sessionMap.erase(id);
}

uint32 Server::getNextUserId()
{
	LockGuard lock(mutex);
	return nextUserId++;
}

std::string_view Server::getName() const
{
	return name;
}

std::string_view Server::getDescription() const
{
	return description;
}

uint32 Server::getUserCount()
{
	LockGuard lock(mutex);
	return static_cast<uint32>(sessionMap.size());
}

ServerRef Server::getInstance()
{
	return instance;
}
