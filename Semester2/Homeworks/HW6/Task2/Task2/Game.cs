using System;

namespace Task2
{
    /// <summary>
    /// Class that implements the movement of the character on the map.
    /// </summary>
    public class Game
    {
        public Map GameMap { get; }
        private readonly Action<int, int> setCursor;

        /// <summary>
        /// Initializes a new instance of the <see cref="Game"/> class.
        /// </summary>
        /// <param name="filename">Name of the map file</param>
        public Game(string filename)
            : this(filename, (left, top) => Console.SetCursorPosition(left, top))
        {
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="Game"/> class.
        /// </summary>
        /// <param name="filename">Name of the map file</param>
        /// <param name="setCursor">Action that sets the position of the cursor</param>
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

        /// <summary>
        /// Moves the character to the left.
        /// </summary>
        public void OnLeft(object sender, EventArgs args) => Move(1, 0);

        /// <summary>
        /// Moves the character to the right.
        /// </summary>
        public void OnRight(object sender, EventArgs args) => Move(-1, 0);

        /// <summary>
        /// Moves the character up.
        /// </summary>
        public void Up(object sender, EventArgs args) => Move(0, 1);

        /// <summary>
        /// Moves the character down.
        /// </summary>
        public void Down(object sender, EventArgs args) => Move(0, -1);
    }
}
