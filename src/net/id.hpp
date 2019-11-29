#ifndef _ID_H
#define _PACKET_H

#include "../common.hpp"

enum class MsgId : uint32
{
	transaction = 1000,
	error,
	errorString,
	appName = 2000,
	appVersion,
	appBuild,
	oSName,
	oSVersion,
	architecture,
	supportsRsrc,
	serverName,
	serverDescription,
	serverStartTime,
	filesCount,
	filesSize,
	banner,
	downloads,
	uploads,
	downloadSpeed,
	uploadSpeed,
	userId = 3000,
	useridle,
	userNickname,
	userLogin,
	userPassword,
	userStatus,
	userIcon,
	userAddress,
	userHost,
	userCipherName,
	userCipherBits,
	userLoginTime,
	useridleTime,
	userDisconnectMessage,
	userDisconnectedId,
	userState,
	chatId = 4000,
	chatTopic,
	chatTopicTime,
	chatSay,
	chatMe,
	message = 5000,
	broadcast,
	board = 6000,
	newBoard,
	thread,
	boardPost,
	boardPostDate,
	boardEditDate,
	boardSubject,
	boardText,
	boardOwner,
	boardOwnerRead,
	boardOwnerWrite,
	boardGroup,
	boardGroupRead,
	boardGroupWrite,
	boardEveryoneRead,
	boardEveryoneWrite,
	boardReadable,
	boardWritable,
	ownThread,
	boardReplies,
	boardLatestReply,
	boardLatestReplyDate,
	boardOwnPost,
	filePath = 7000,
	fileType,
	fileDataSize,
	fileRsrcSize,
	directoryCount,
	fileCreationTime,
	fileEditTime,
	fileComment,
	fileRecursive,
	fileAvailable,
	fileNewPath,
	fileQuery,
	fileLink,
	fileExecutable,
	fileOwner,
	fileOwnerRead,
	fileOwnerWrite,
	fileGroup,
	fileGroupRead,
	fileGroupWrite,
	fileEveryoneRead,
	fileEveryoneWrite,
	fileLabel,
	fileVolume,
	fileReadable,
	fileWritable,
	filePreview,
	accountName = 8000,
	accountNewName,
	accountKickUsersOnDelete,
	accountFullName,
	accountComment,
	accountColor,
	accountCreationTime,
	accountEditTime,
	accountLoginTime,
	accountEditedBy,
	accountDownloads,
	accountDownloadTransferred,
	accountUploads,
	accountUploadTransferred,
	accountPassword,
	accountGroup,
	accountGroups,
	accountFiles,
	userCantSetNickname,
	accountGetUserInfo,
	accountKickUsers,
	accountBanUsers,
	accountCantBeKicked,
	accountGetUsers,
	accountKickChatUsers,
	accountSetChatTopic,
	accountCreateChats,
	accountSendMessages,
	accountBroadcast,
	accountReadBoards,
	accountAddBoards,
	accountMoveBoards,
	accountRenameBoards,
	accountDeleteBoards,
	accountGetBoardInfo,
	accountSetBoardInfo,
	accountAddThreads,
	accountMoveThreads,
	accountBoardAddPosts,
	accountEditOwnThreadsAndPosts,
	accountEditAllThreadsAndPosts,
	accountDeleteOwnThreadsAndPosts,
	accountDeleteAllThreadsAndPosts,
	accountListFiles,
	accountGetFileInfo,
	accountSearchFiles,
	accountCreateDirectories,
	accountCreateFileLinks,
	accountMoveFiles,
	accountRenameFiles,
	accountSetFileType,
	accountSetFileComment,
	accountSetFilePermissions,
	accountSetFileExecutable,
	accountSetFileLabel,
	accountDeleteFiles,
	accountAccessAllDropboxes,
	accountRecursiveFileListDepthLimit,
	accountDownloadFiles,
	accountUploadFiles,
	accountUploadDirectories,
	accountUploadAnywhere,
	accountDownloadLimit,
	accountUploadLimit,
	accountDownloadSpeedLimit,
	accountUploadSpeedLimit,
	accountEditPassword,
	accountListAccounts,
	accountReadAccounts,
	accountCreateAccounts,
	accountEditAccounts,
	accountDeleteAccounts,
	accountCreateAccountGroups,
	accountEditAccountGroups,
	accountDeleteAccountGroups,
	accountRaisePrivileges,
	accountViewLog,
	accountViewEvents,
	accountGetSettings,
	accountSetSettings,
	accountGetBans,
	accountAddBans,
	accountDeleteBans,
	accountListServers,
	accountRegisterServers,
	transferType = 9000,
	transferDataSize,
	transferRsrcSize,
	transferDataOffset,
	transferRsrcOffset,
	transferFinderInfo,
	transferQueuePosition,
	transferData,
	transferRsrc,
	transferTransferred,
	transferSpeed,
	logTime = 10000,
	logLevel,
	logMessage,
	eventFirstTime,
	eventFromTime,
	eventToTime,
	eventNumberOfDays,
	lastEventCount,
	event,
	eventTime,
	eventParameters,
	registerWithTrackers,
	trackerSettings,
	banAddress,
	banExpirationDate,
	tracker = 11000,
	trackerCategories,
	trackerCategory,
	trackerAddress,
	trackerPort,
	trackerUrl,
	trackerUsers
};

enum class Error : Byte
{
	internal = 0,
	invalidmessage,
	unrecognizedMessage,
	messageOutOfSequence,
	loginFailed,
	permissionDenied,
	notSubscribed,
	alreadySubscribed,
	chatNotFound,
	alreadyOnChat,
	notOnChat,
	notInvitedToChat,
	userNotFound,
	userCantBeKicked,
	fileNotFound,
	fileExists,
	accountNotFound,
	accountExists,
	accountInUse,
	trackerNotEnabled,
	notRegistered,
	banNotFound,
	banExists,
	boardNotFound,
	boardExists,
	threadNotFound,
	postNotFound,
	rsrcNotSupported
};

#endif // _PACKET_H