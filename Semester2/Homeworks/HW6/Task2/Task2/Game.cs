using System;

namespace Task2
{
    public class Game
    {
        private readonly Map map;

        public Game(string filename)
        {
            map = new Map(filename);
            map.Print();
            Console.CursorVisible = false;
        }

        private void Move(int stepLeft, int stepUp)
        {
            var (oldLeft, oldTop) = map.CharacterPosition;

            if (!map.SetCharacterPosition(oldLeft - stepLeft, oldTop - stepUp))
            {
                return;
            }

            Console.SetCursorPosition(oldLeft, oldTop);
            Console.Write(' ');
            Console.SetCursorPosition(map.CharacterPosition.left, map.CharacterPosition.top);
            Console.Write(Map.characterSymbol);
        }

        public void OnLeft(object sender, EventArgs args) => Move(1, 0);

        public void OnRight(object sender, EventArgs args) => Move(-1, 0);

        public void Up(object sender, EventArgs args) => Move(0, 1);

        public void Down(object sender, EventArgs args) => Move(0, -1);
    }
}
