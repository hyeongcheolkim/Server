#include "pch.h"
#include "UserManager.h"
#include "AccountManager.h"

void UserManager::ProcessSave()
{
	lock_guard<mutex> guard(_mutex);

	Account* account = AccountManager::instance()->GetAccount(100);
}
