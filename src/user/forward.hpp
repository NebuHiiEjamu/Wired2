#ifndef _USER_FORWARD_H
#define _USER_FORWARD_H

#include <memory>

class Account;
class Group;
class Session;
class WiredConnection;

using AccountPtr = std::shared<Account>;
using AccountRef = std::weak_ptr<Account>;
using GroupPtr = std::shared_ptr<Group>;
using GroupRef = std::weak_ptr<Group>;
using SessionPtr = std::shared_ptr<Session>;
using SessionRef = std::weak_ptr<Session>;
using WiredConnectionPtr = std::shared_ptr<WiredConnection>;

#endif // _USER_FORWARD_H
