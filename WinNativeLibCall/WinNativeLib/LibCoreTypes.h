#ifndef INCLUDE_GUARD_LIB_CORE_TYPES_H__
#define INCLUDE_GUARD_LIB_CORE_TYPES_H__

#pragma once

enum class DataLength
{
	One = 1,
	Two = 2,
	Four = 4,
};

enum class DataTypes
{
	Unsigned,
	Signed,
};

struct DataWriteRequest
{
	int blockNumber;
	int offset;
	DataLength dataSize;
	DataTypes type;
	int value;
};

enum class Result
{
	OK = 0,
	NG = 1,
};

struct DataWriteAnswer
{
	Result result;
};

#endif //INCLUDE_GUARD_LIB_CORE_TYPES_H__