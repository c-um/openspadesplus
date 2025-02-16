#include <Core/Settings.h>
#include <Plus/OpenSpadesPlus.h>

SPADES_SETTING(p_customClientMessage);

#if __linux__
	#define OS_PLATFORM_LINUX
#elif TARGET_OS_MAC
	#define OS_PLATFORM_MAC
#elif defined _WIN32 || defined _WIN64
	#define OS_PLATFORM_WINDOWS
	#include <Windows.h>
	#include <sstream>
	#include <VersionHelpers.h> // Requires Windows 10 SDK at least
#endif

#include "VersionInfo.h"

std::string VersionInfo::GetVersionInfo() {
	std::string buffer;

#if defined(OS_PLATFORM_LINUX)
	buffer = "GNU/Linux";

#elif defined(TARGET_OS_MAC)
	buffer = "MacOS";

#elif defined(OS_PLATFORM_WINDOWS)
	if (IsWindowsVistaOrGreater() && !IsWindowsVistaSP1OrGreater()) {
		buffer = "Windows Vista";
	} else if (IsWindowsVistaSP1OrGreater() && !IsWindowsVistaSP2OrGreater()){
		buffer = "Windows Vista Service Pack 1";
	} else if (IsWindowsVistaSP2OrGreater() && !IsWindows7OrGreater()) {
		buffer = "Windows Vista Service Pack 2";
	} else if (IsWindows7OrGreater() && !IsWindows7SP1OrGreater()) {
		buffer = "Windows 7";
	} else if (IsWindows7SP1OrGreater() && !IsWindows8OrGreater()) {
		buffer = "Windows 7 Service Pack 1";
	} else if (IsWindows8OrGreater() && !IsWindows8Point1OrGreater()) {
		buffer = "Windows 8";
	} else if (IsWindows8Point1OrGreater() && !IsWindows10OrGreater()) {
		buffer = "Windows 8.1"; // doesnt work winapi is shit
	} else if (IsWindows10OrGreater()) {
		buffer = "Windows 10"; // doesnt work winapi is shit
	} else {
		buffer = "Windows 11"; // doesnt work winapi is shit
	}

	if (IsWindowsServer())
		buffer += " Server";

#elif defined(__FreeBSD__)
	buffer = "FreeBSD";
#elif defined(__OpenBSD__)
	buffer = "OpenBSD";
#elif defined(__DragonFly__)
	buffer = "DragonFly BSD";
#elif defined(__NetBSD__)
	buffer = "NetBSD";
#elif defined(__sun)
	buffer = "Solaris / Illumos";
#elif defined(__HAIKU__)
	buffer = "Haiku OS";
#else
	buffer = "Probably macOS";
#endif

	buffer += " | OpenSpades+ Revision ";
	buffer += std::to_string(spades::plus::revision);

	if (p_customClientMessage != "")
	{
		std::string message = p_customClientMessage;
		
		buffer += " | ";
		buffer += message;
	}

	return std::string(buffer);
}
