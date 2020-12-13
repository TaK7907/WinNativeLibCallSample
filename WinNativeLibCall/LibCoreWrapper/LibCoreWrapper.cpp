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

/*!
 * \brief Explicit linking example
 * \return a + b + c + d
 * 
 * \remarks You may have to change the decolated function name.
 * \see "Decorated Names" in docs.microsoft.com
*/
int LibCoreWrapper::CoreWrapper::SumEx(int a, int b, int c, int d)
{
	const auto ModuleName = L"LibCore.dll";
	auto module = LoadLibrary(ModuleName);
	if (!module)
		throw gcnew DllNotFoundException(gcnew String(ModuleName));

	// You should have the decolated function name in the compiled dll file.
	const auto ProcSigSum = "?Sum@LibCore@@UAEHHHHH@Z";
	auto proc = (bool(*)(int, int, int, int))GetProcAddress(module, ProcSigSum);
	if (!proc) {
		FreeLibrary(module);
		throw gcnew MissingMethodException(gcnew String(ProcSigSum));
	}

	auto result = proc(a, b, c, d);
	FreeLibrary(module);

	return result;
}

LibCoreWrapper::CoreWrapper::CoreWrapper()
{
	_core = LibCore::GetInstance();
}
