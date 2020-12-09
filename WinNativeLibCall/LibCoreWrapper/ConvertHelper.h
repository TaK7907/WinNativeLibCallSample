#pragma once

#include "../WinNativeLib/LibCoreTypes.h"
#include "WrapperTypes.h"

namespace LibCoreWrapper {
	ref class ConvertHelper
	{
	public:
		static ::DataTypes ToNativeDataType(LibCoreWrapper::DataTypes type);
		static ::DataLength ToNativeDataLength(LibCoreWrapper::DataLength length);
		static LibCoreWrapper::DataWriteResult FromNativeDataWriteResult(::Result result);
	};
}
