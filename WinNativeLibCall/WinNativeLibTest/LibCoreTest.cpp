#include "pch.h"
#include "CppUnitTest.h"
#include "../WinNativeLib/LibCore.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WinNativeLibTest
{
	TEST_CLASS(LibCoreTest)
	{
	private:
		void Suspend(int nSec)
		{
			constexpr auto interval = 10;
			const int repeat = nSec * 1000 / interval;

			for (auto i = 0; i <= repeat; ++i)
				std::this_thread::sleep_for(std::chrono::milliseconds(interval));
		}

	public:
		LibCore* sut;

		TEST_METHOD_INITIALIZE(Setup)
		{
			sut = LibCore::GetInstance();
		}

		TEST_METHOD(TestConnectDisconnect)
		{
			//未接続でDisconnect()は失敗する
			Assert::IsFalse(sut->Disconnect());

			//未接続状態でConnect()は成功する
			Assert::IsTrue(sut->Connect());

			//接続後にもう一度Connect()は失敗する
			Assert::IsFalse(sut->Connect());

			//接続中のDisconnect()は成功する
			Assert::IsTrue(sut->Disconnect());
		}

		TEST_METHOD(TestDataWrite)
		{
			//テスト用データ生成
			auto req = DataWriteRequest{ 0x100, 2, DataLength::Two, DataTypes::Unsigned, 14255 };

			Assert::IsFalse(sut->RequestDataWrite(req), L"未接続でのDataWriteRequest()は失敗する");

			sut->Connect();
			Assert::IsTrue(sut->RequestDataWrite(req), L"引数チェックしてないので接続していれば成功する");

			//1秒後に結果を確認...本番コードは正しく非同期処理しましょう
			Suspend(1);
			DataWriteAnswer ans;
			sut->GetDataWriteReult(ans);
			Assert::IsTrue(ans.result == Result::OK, L"成功を受信していれば0");

			sut->Disconnect();
		}
	};
}
