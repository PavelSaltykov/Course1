using System;

namespace Task2
{
    public class Game
    {
        public Map GameMap { get; }

        public Game(string filename)
        {
            GameMap = new Map(filename);
            GameMap.Print();
            Console.CursorVisible = false;
        }

        private void Move(int stepLeft, int stepUp)
        {
            var (oldLeft, oldTop) = GameMap.CharacterPosition;

            if (!GameMap.SetCharacterPosition(oldLeft - stepLeft, oldTop - stepUp))
            {
                return;
            }

            Console.SetCursorPosition(oldLeft, oldTop);
            Console.Write(' ');
            Console.SetCursorPosition(GameMap.CharacterPosition.left, GameMap.CharacterPosition.top);
            Console.Write(Map.characterSymbol);
        }

        public void OnLeft(object sender, EventArgs args) => Move(1, 0);

        public void OnRight(object sender, EventArgs args) => Move(-1, 0);

        public void Up(object sender, EventArgs args) => Move(0, 1);

        public void Down(object sender, EventArgs args) => Move(0, -1);
    }
}
