#pragma once

namespace LibCoreWrapper
{
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

}
