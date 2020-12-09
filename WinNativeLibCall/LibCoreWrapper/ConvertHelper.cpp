#include "pch.h"
#include "ConvertHelper.h"

using namespace System;

::DataTypes LibCoreWrapper::ConvertHelper::ToNativeDataType(LibCoreWrapper::DataTypes type)
{
	switch (type) {
	case LibCoreWrapper::DataTypes::Unsigned:	return ::DataTypes::Unsigned;
	case LibCoreWrapper::DataTypes::Signed:		return ::DataTypes::Signed;
	default: throw gcnew ArgumentOutOfRangeException();
	}
}

::DataLength LibCoreWrapper::ConvertHelper::ToNativeDataLength(LibCoreWrapper::DataLength length)
{
	switch (length) {
	case LibCoreWrapper::DataLength::One:	return ::DataLength::One;
	case LibCoreWrapper::DataLength::Two:	return ::DataLength::Two;
	case LibCoreWrapper::DataLength::Four:	return ::DataLength::Four;
	default: throw gcnew ArgumentOutOfRangeException();
	}
}

LibCoreWrapper::DataWriteResult LibCoreWrapper::ConvertHelper::FromNativeDataWriteResult(::Result result)
{
	switch (result) {
	case ::Result::OK:	return LibCoreWrapper::DataWriteResult::OK;
	case ::Result::NG:	return LibCoreWrapper::DataWriteResult::NG;
	default: throw gcnew NotImplementedException();
	}
}
