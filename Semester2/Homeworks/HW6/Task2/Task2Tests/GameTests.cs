using NUnit.Framework;
using System;

namespace Task2.Tests
{
    [TestFixture()]
    public class GameTests
    {
        private Game game;

        [SetUp]
        public void Initialize() => game = new Game("mapForGameTests.txt");

        [Test()]
        public void OnLeftTest()
        {
            game.OnLeft(this, EventArgs.Empty);
            Assert.AreEqual((1, 1), game.GameMap.CharacterPosition);

            game.OnLeft(this, EventArgs.Empty);
            Assert.AreEqual((1, 1), game.GameMap.CharacterPosition);
        }

        [Test()]
        public void OnRightTest()
        {
            game.OnRight(this, EventArgs.Empty);
            Assert.AreEqual((3, 1), game.GameMap.CharacterPosition);

            game.OnRight(this, EventArgs.Empty);
            Assert.AreEqual((3, 1), game.GameMap.CharacterPosition);
        }

        [Test()]
        public void UpTest()
        {
            game.Up(this, EventArgs.Empty);
            Assert.AreEqual((2, 0), game.GameMap.CharacterPosition);

            game.Up(this, EventArgs.Empty);
            Assert.AreEqual((2, 0), game.GameMap.CharacterPosition);
        }

        [Test()]
        public void DownTest()
        {
            game.Down(this, EventArgs.Empty);
            Assert.AreEqual((2, 2), game.GameMap.CharacterPosition);

            game.Down(this, EventArgs.Empty);
            Assert.AreEqual((2, 2), game.GameMap.CharacterPosition);
        }
    }
}