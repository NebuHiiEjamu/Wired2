#if BOOST_OS_WINDOWS
	#include <windows.h>
#elif BOOST_OS_MACOS
	#include <CoreServices/CoreServices.h>
#else
	#include <sys/utsname.h>
#endif

#include "server.hpp"

int main(int argc, char **argv)
{
#if BOOST_OS_WINDOWS
	Server::osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXA);
	GetNativeSystemInfo(&Server::systemInfo);
	osError = GetVersionExA(&Server::osVersionInfo)
#elif BOOST_OS_MACOS
	Gestalt(gestaltSystemVersionMajor, &Server::osVersionMajor);
	Gestalt(gestaltSystemVersionMinor, &Server::osVersionMinor);
	Gestalt(gestaltSystemVersionBugFix, &Server::osVersionFix);
#else
	uname(&Server::osInfo);
#endif

	return 0;
}
