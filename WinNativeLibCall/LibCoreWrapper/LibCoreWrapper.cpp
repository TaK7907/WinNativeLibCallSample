#include "pch.h"

#include "LibCoreWrapper.h"
#include "../WinNativeLib/LibCore.h"
#include "../WinNativeLib/LibCoreTypes.h"
#include "ConvertHelper.h"

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
	reqNative.type = ConvertHelper::ToNativeDataType(req.DataType);
	reqNative.dataSize = ConvertHelper::ToNativeDataLength(req.DataSize);
	reqNative.value = req.Value;

	return _core->RequestDataWrite(reqNative);
}

void LibCoreWrapper::CoreWrapper::GetDataWriteAnswer(DataWriteAns% ans)
{
	::DataWriteAnswer ansNative;
	_core->GetDataWriteAnswer(ansNative);

	ans.Result = ConvertHelper::FromNativeDataWriteResult(ansNative.result);
}

LibCoreWrapper::CoreWrapper::CoreWrapper()
{
	_core = LibCore::GetInstance();
}
