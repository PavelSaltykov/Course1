using NUnit.Framework;
using Task2.HashFunctions;

namespace Task2.Tests
{
    [TestFixture()]
    public class HashTableTest
    {
        private readonly IHashFunction func1 = new HashFunction1();
        private HashTable hashTable;

        [SetUp()]
        public void Initialize()
        {
            hashTable = new HashTable(func1);
        }

        [Test()]
        public void AddValueTest()
        {
            hashTable.AddValue("a");
            Assert.IsTrue(hashTable.Contains("a"));
        }

        [Test()]
        public void DeleteValueTest()
        {
            hashTable.AddValue("abc");
            hashTable.DeleteValue("abc");
            Assert.IsFalse(hashTable.Contains("abc"));
        }

        [Test()]
        public void ChangeHashFunctionTest()
        {
            hashTable.AddValue("ab");
            hashTable.AddValue("12345");
            hashTable.AddValue("A1bc2");

            IHashFunction func2 = new HashFunction2();
            hashTable.ChangeHashFunction(func2);

            Assert.IsTrue(hashTable.Contains("ab"));
            Assert.IsTrue(hashTable.Contains("12345"));
            Assert.IsTrue(hashTable.Contains("A1bc2"));
        }

        [Test()]
        public void ContainsTest()
        {
            hashTable.AddValue("abc");
            Assert.IsFalse(hashTable.Contains("abcd"));
            Assert.IsTrue(hashTable.Contains("abc"));
        }

        [Test()]
        public void ResizeTest()
        {
            for (var i = 0; i < 100; ++i)
            {
                hashTable.AddValue(i.ToString());
            }

            for (var i = 0; i < 100; ++i)
            {
                Assert.IsTrue(hashTable.Contains(i.ToString()));
            }
        }

        [Test()]
        public void ClearTest()
        {
            for (var i = 0; i < 10; ++i)
            {
                hashTable.AddValue(i.ToString());
            }

            hashTable.Clear();

            for (var i = 0; i < 10; ++i)
            {
                Assert.IsFalse(hashTable.Contains(i.ToString()));
            }
        }
    }
}