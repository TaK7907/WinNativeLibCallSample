#pragma once

using namespace System;

class LibCore;

namespace LibCoreWrapper {
	public enum class DataTypes {
		Unsigned,
		Signed,
	};

	public enum class DataLength {
		One,
		Two,
		Four,
	};

	public value struct DataWriteReq
	{
	public:
		property int BlockNumber;
		property int Offset;
		property DataLength DataSize;
		property DataTypes DataType;
		property int Value;
	};

	public enum class DataWriteResult {
		OK,
		NG,
	};

	public value struct DataWriteAns
	{
	public:
		property DataWriteResult Result;
	};

	public ref class CoreWrapper
	{
	public:
		explicit CoreWrapper();
		~CoreWrapper();
		!CoreWrapper();
		bool Connect();
		bool Disconnect();
		bool IsConnected();

		bool RequestDataWrite(DataWriteReq req);
		void GetDataWriteAnswer(DataWriteAns% ans);

	private:
		LibCore* _core;
	};
}
