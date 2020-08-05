using System;

namespace Task2
{
    public class Game
    {
        public Map GameMap { get; }
        private readonly Action<int, int> setCursor;

        public Game(string filename)
            : this(filename, (left, top) => Console.SetCursorPosition(left, top))
        {
        }

        public Game(string filename, Action<int, int> setCursor)
        {
            GameMap = new Map(filename);
            this.setCursor = setCursor;
            GameMap.Print();
        }

        private void Move(int stepLeft, int stepUp)
        {
            var (oldLeft, oldTop) = GameMap.CharacterPosition;

            if (!GameMap.SetCharacterPosition(oldLeft - stepLeft, oldTop - stepUp))
            {
                return;
            }

            setCursor(oldLeft, oldTop);
            Console.Write(' ');
            setCursor(GameMap.CharacterPosition.left, GameMap.CharacterPosition.top);
            Console.Write(Map.characterSymbol);
        }

        public void OnLeft(object sender, EventArgs args) => Move(1, 0);

        public void OnRight(object sender, EventArgs args) => Move(-1, 0);

        public void Up(object sender, EventArgs args) => Move(0, 1);

        public void Down(object sender, EventArgs args) => Move(0, -1);
    }
}
