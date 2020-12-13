using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace LibCoreWrapperTest
{
    [TestClass]
    public class CoreWrapperTest
    {
        [TestMethod]
        public void TestImplicitLinking()
        {
            var sut = new LibCoreWrapper.CoreWrapper();

            Assert.IsFalse(sut.IsConnected());
            Assert.IsTrue(sut.Connect());
            Assert.IsTrue(sut.IsConnected());

            var req = new LibCoreWrapper.DataWriteReq() {
                BlockNumber = 0x100,
                Offset = 3,
                DataType = LibCoreWrapper.DataTypes.Unsigned,
                DataSize = LibCoreWrapper.DataLength.Two,
                Value = 200
            };
            Assert.IsTrue(sut.RequestDataWrite(req));

            System.Threading.Tasks.Task.Delay(1000);

            var ans = new LibCoreWrapper.DataWriteAns();
            sut.GetDataWriteAnswer(ref ans);
            Assert.AreEqual(LibCoreWrapper.DataWriteResult.OK, ans.Result);

            Assert.IsTrue(sut.Disconnect());
            Assert.IsFalse(sut.IsConnected());
        }

        [TestMethod]
        public void TestExplicitLinking()
        {
            var sut = new LibCoreWrapper.CoreWrapper();
            Assert.AreEqual(4, sut.SumEx(1, 1, 1, 1));
        }
    }
}
