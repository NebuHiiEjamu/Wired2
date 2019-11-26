#ifndef _USER_FORWARD_H
#define _USER_FORWARD_H

#include <memory>

class Account;
class AccountGroup;
class Session;
class WiredConnection;

using AccountGroupPtr = std::shared_ptr<AccountGroup>;
using AccountGroupRef = std::weak_ptr<AccountGroup>;
using AccountPtr = std::shared<Account>;
using AccountRef = std::weak_ptr<Account>;
using SessionPtr = std::shared_ptr<Session>;
using SessionRef = std::weak_ptr<Session>;
using WiredConnectionPtr = std::shared_ptr<WiredConnection>;

#endif // _USER_FORWARD_H
