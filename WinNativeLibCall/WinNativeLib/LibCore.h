#ifndef INCLUDE_GUARD_LIB_CORE_H__
#define INCLUDE_GUARD_LIB_CORE_H__

#pragma once

#include "LibCoreTypes.h"

#ifdef WIN_NATIVE_LIB_EXPORT
#define WinNativeLibApi __declspec(dllexport)
#else
#define WinNativeLibApi __declspec(dllexport)
#endif //WIN_NATIVE_LIB_EXPORT

class WinNativeLibApi LibCore
{
public:
	virtual ~LibCore();
	static LibCore* GetInstance();

	virtual bool Connect();
	virtual bool Disconnect();
	virtual bool IsConnected();

	virtual bool RequestDataWrite(const DataWriteRequest data);
	virtual void GetDataWriteAnswer(DataWriteAnswer& data);

	virtual int Sum(int a, int b, int c, int d);

protected:
	explicit LibCore();

private:
	bool _isConnected;

};

#endif //INCLUDE_GUARD_LIB_CORE_H__
