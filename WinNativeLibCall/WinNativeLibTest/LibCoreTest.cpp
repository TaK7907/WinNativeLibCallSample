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
			//���ڑ���Disconnect()�͎��s����
			Assert::IsFalse(sut->Disconnect());

			//���ڑ���Ԃ�Connect()�͐�������
			Assert::IsTrue(sut->Connect());

			//�ڑ���ɂ�����xConnect()�͎��s����
			Assert::IsFalse(sut->Connect());

			//�ڑ�����Disconnect()�͐�������
			Assert::IsTrue(sut->Disconnect());
		}

		TEST_METHOD(TestDataWrite)
		{
			//�e�X�g�p�f�[�^����
			auto req = DataWriteRequest{ 0x100, 2, DataLength::Two, DataTypes::Unsigned, 14255 };

			Assert::IsFalse(sut->RequestDataWrite(req), L"���ڑ��ł�DataWriteRequest()�͎��s����");

			sut->Connect();
			Assert::IsTrue(sut->RequestDataWrite(req), L"�����`�F�b�N���ĂȂ��̂Őڑ����Ă���ΐ�������");

			//1�b��Ɍ��ʂ��m�F...�{�ԃR�[�h�͐������񓯊��������܂��傤
			Suspend(1);
			DataWriteAnswer ans;
			sut->GetDataWriteReult(ans);
			Assert::IsTrue(ans.result == Result::OK, L"��������M���Ă����0");

			sut->Disconnect();
		}
	};
}
