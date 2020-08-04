using NUnit.Framework;

namespace Task2.Tests
{
    [TestFixture()]
    public class MapTests
    {
        private Map map;

        [Test()]
        public void MapWithoutCharacterTest()
        {
            Assert.Throws<CharacterNotFoundException>(() => map = new Map("mapWithoutCharacter.txt"));
        }

        [Test()]
        public void TwoCharactersTest()
        {
            map = new Map("mapWithTwoCharacters.txt");
            Assert.AreEqual((1, 0), map.CharacterPosition);
            Assert.IsTrue(map.SetCharacterPosition(1, 1));
        }

        [Test()]
        public void CharacterPositionTest()
        {
            map = new Map("mapForCharacterPositionTests.txt");
            Assert.AreEqual((2, 1), map.CharacterPosition);
        }

        [Test()]
        public void SetCharacterPositionTest()
        {
            map = new Map("mapForCharacterPositionTests.txt");
            Assert.AreEqual((2, 1), map.CharacterPosition);

            Assert.IsFalse(map.SetCharacterPosition(2, 1));
            Assert.IsTrue(map.SetCharacterPosition(1, 1));
            Assert.AreEqual((1, 1), map.CharacterPosition);
        }

        [Test()]
        public void SetCharacterPositionOutsideOfMapTest()
        {
            map = new Map("mapForCharacterPositionTests.txt");
            Assert.IsFalse(map.SetCharacterPosition(3, 1));
        }

        [Test()]
        public void SetNegativeCharacterPositionTest()
        {
            map = new Map("mapForCharacterPositionTests.txt");
            Assert.IsFalse(map.SetCharacterPosition(-1, -2));
        }

        [Test()]
        public void SetCharacterPositionOnWallTest()
        {
            map = new Map("mapForCharacterPositionTests.txt");
            Assert.IsFalse(map.SetCharacterPosition(2, 2));
        }
    }
}