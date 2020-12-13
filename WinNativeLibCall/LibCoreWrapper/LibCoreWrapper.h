#pragma once

#include "WrapperTypes.h"

using namespace System;

class LibCore;

namespace LibCoreWrapper {
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

		int SumEx(int a, int b, int c, int d);

	private:
		LibCore* _core;
	};
}
