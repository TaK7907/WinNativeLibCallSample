#include "pch.h"
#include "LibCore.h"

static LibCore* _core = nullptr;

LibCore::LibCore()
	:_isConnected(false)
{
}

LibCore::~LibCore()
{
	if (_core != nullptr)
	{
		delete _core;
		_core = nullptr;
	}
}

LibCore* LibCore::GetInstance()
{
	if (_core == nullptr)
		_core = new LibCore();

	return _core;
}

bool LibCore::Connect()
{
	if(_isConnected)
		return false;

	_isConnected = true;
	return true;
}

bool LibCore::Disconnect()
{
	if(!_isConnected)
		return false;

	_isConnected = false;
	return true;
}

bool LibCore::IsConnected()
{
	return _isConnected;
}

bool LibCore::RequestDataWrite(DataWriteRequest data)
{
	if (!_isConnected)
		return false;

	return true;
}

void LibCore::GetDataWriteReult(DataWriteAnswer& data)
{
	data.result = Result::OK;
}
