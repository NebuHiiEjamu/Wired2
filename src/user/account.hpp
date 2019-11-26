#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#include <array>
#include <bitset>
#include <filesystem>
#include <openssl/sha.h>
#include <set>

#include "forward.hpp"
#include "../common.hpp"

namespace Access
{
	enum
	{
		kickUsersOnDeletion = 0,
		cantSetNickname,
		getUserInfo,
		kickUsers,
		banUsers,
		cantBeKicked,
		getUsers,
		kickChatUsers,
		setChatTopic,
		createChats,
		sendMessages,
		broadcast,
		readBoards,
		addBoards,
		moveBoards,
		renameBoards,
		deleteBoards,
		getBoardInfo,
		setBoardInfo,
		addThreads,
		moveThreads,
		addPosts,
		editOwnThreadsAndPosts,
		editAllThreadsAndPosts,
		deleteOwnThreadsAndPosts,
		deleteAllThreadsAndPosts,
		listFiles,
		getFileInfo,
		searchFiles,
		createDirectories,
		createLinks,
		moveFiles,
		renameFiles,
		setFileType,
		setFileComment,
		setFilePermissions,
		setFileExecutable,
		setFileLabel,
		deleteFiles,
		accessAllDropboxes,
		downloadFiles,
		uploadFiles,
		uploadDirectories,
		uploadAnywhere,
		editPassword,
		listAccounts,
		readAccounts,
		createAccounts,
		deleteAccounts,
		createAccountGroups,
		editAccountGroups,
		deleteAccountGroups,
		raisePrivileges,
		viewLog,
		viewEvents,
		getSettings,
		setSettings,
		getBans,
		addBans,
		deleteBans,
		all
	};
}

enum class AccountColor : Byte
{
	black = 0,
	red,
	orange,
	green,
	blue,
	purple
};

class Account : public std::enable_shared_from_this<Account>
{
public:
private:
	AccountGroupRef primaryGroup;
	std::set<AccountGroupRef> secondaryGroups;
	std::string name;
	std::string fullName;
	std::string comment;
	std::string lastEditedBy;
	std::filesystem::path filePath;
	std::array<char, SHA_DIGEST_LENGTH * 2> password;
	std::mutex mutex;
	Timestamp created;
	Timestamp modified;
	Timestamp lastLogin;
	std::bitset<Access::all> access;
	uint32 recursiveFilePathDepthLimit;
	uint32 downloadLimit;
	uint32 uploadLimit;
	uint32 downloadSpeedLimit;
	uint32 uploadSpeedLimit;
	AccountColor color;
};

class AccountGroup : public std::enable_shared_from_this<AccountGroup>
{
public:
private:
	std::set<AccountRef> accounts;
	std::mutex mutex;
};

#endif // _ACCOUNT_H
