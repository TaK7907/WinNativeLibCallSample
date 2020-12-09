#include "pch.h"

#include "LibCoreWrapper.h"
#include "../WinNativeLib/LibCore.h"
#include "../WinNativeLib/LibCoreTypes.h"

LibCoreWrapper::CoreWrapper::~CoreWrapper()
{
}

LibCoreWrapper::CoreWrapper::!CoreWrapper()
{
}

bool LibCoreWrapper::CoreWrapper::Connect()
{
	return _core->Connect();
}

bool LibCoreWrapper::CoreWrapper::Disconnect()
{
	return _core->Disconnect();
}

bool LibCoreWrapper::CoreWrapper::IsConnected()
{
	return _core->IsConnected();
}

bool LibCoreWrapper::CoreWrapper::RequestDataWrite(DataWriteReq req)
{
	DataWriteRequest reqNative;
	reqNative.blockNumber = req.BlockNumber;
	reqNative.offset = req.Offset;
#if 0
	switch (req.DataType) {
	case LibCoreWrapper::DataTypes::Unsigned: reqNative.type = ::DataTypes::Unsigned; break;
	case LibCoreWrapper::DataTypes::Signed: reqNative.type = ::DataTypes::Signed; break;
	default: throw gcnew ArgumentOutOfRangeException(req.DataType.ToString());
	}
	switch (req.DataSize) {
	case LibCoreWrapper::DataLength::One: reqNative.dataSize = ::DataLength::One; break;
	case LibCoreWrapper::DataLength::Two: reqNative.dataSize = ::DataLength::Two; break;
	case LibCoreWrapper::DataLength::Four: reqNative.dataSize = ::DataLength::Four; break;
	default: throw gcnew ArgumentOutOfRangeException(req.DataSize.ToString());
	}
#else
	reqNative.type = (::DataTypes)req.DataType;
	reqNative.dataSize = (::DataLength)req.DataSize;
#endif
	reqNative.value = req.Value;

	return _core->RequestDataWrite(reqNative);
}

void LibCoreWrapper::CoreWrapper::GetDataWriteAnswer(DataWriteAns% ans)
{
	::DataWriteAnswer ansNative;
	_core->GetDataWriteAnswer(ansNative);

#if 0
	switch (ansNative.result) {
	case ::Result::OK: ans.Result = DataWriteResult::OK; break;
	case ::Result::NG: ans.Result = DataWriteResult::NG; break;
	default: throw gcnew NotImplementedException();
	}
#else
	ans.Result = (DataWriteResult)ansNative.result;
#endif
}

LibCoreWrapper::CoreWrapper::CoreWrapper()
{
	_core = LibCore::GetInstance();
}
