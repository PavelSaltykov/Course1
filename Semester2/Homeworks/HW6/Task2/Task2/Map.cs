using System;
using System.Collections.Generic;
using System.IO;

namespace Task2
{
    /// <summary>
    /// Game map from a file.
    /// </summary>
    public class Map
    {
        private readonly List<List<char>> walls;

        /// <summary>
        /// Current position of the character on the map.
        /// </summary>
        public (int left, int top) CharacterPosition { get; private set; } = (-1, -1);
        public const char characterSymbol = '@';

        /// <summary>
        /// Initializes a new instance of the <see cref="Map"/> class.
        /// </summary>
        /// <param name="filename">Name of the map file</param>
        /// <exception cref="CharacterNotFoundException">Thrown when the map from the file
        /// does not contain the character symbol.</exception>
        /// <exception cref="MoreThanOneCharacterException">Thrown when
        /// there is more than one character on the map.</exception>
        public Map(string filename)
        {
            walls = new List<List<char>>();

            LoadMap(filename);

            if (CharacterPosition == (-1, -1))
            {
                throw new CharacterNotFoundException();
            }
        }

        private void LoadMap(string filename)
        {
            using var streamReader = new StreamReader(filename);
            var currentLine = 0;
            walls.Add(new List<char>());

            while (!streamReader.EndOfStream)
            {
                var currentSymbol = streamReader.Read();

                if (currentSymbol == '\r')
                    continue;

                if (currentSymbol == '\n')
                {
                    walls.Add(new List<char>());
                    currentLine++;
                    continue;
                }

                if (currentSymbol == characterSymbol)
                {
                    if (CharacterPosition != (-1, -1))
                        throw new MoreThanOneCharacterException();

                    CharacterPosition = (walls[currentLine].Count, currentLine);
                    currentSymbol = ' ';
                }

                walls[currentLine].Add((char)currentSymbol);
            }
        }

        /// <summary>
        /// Prints the map with the character.
        /// </summary>
        public void Print()
        {
            walls[CharacterPosition.top][CharacterPosition.left] = '@';
            foreach (var line in walls)
            {
                foreach (var symbol in line)
                {
                    Console.Write(symbol);
                }
                Console.WriteLine();
            }
            walls[CharacterPosition.top][CharacterPosition.left] = ' ';
        }

        /// <summary>
        /// Sets the position of the character on the map.
        /// </summary>
        /// <param name="left">The column position of the character.
        /// Columns are numbered from left to right starting at 0.</param>
        /// <param name="top">The row position of the character.
        /// Rows are numbered from top to bottom starting at 0.</param>
        /// <returns>True if the position was changed; otherwise, false</returns>
        public bool SetCharacterPosition(int left, int top)
        {
            if (left < 0 || top < 0 || top >= walls.Count || left >= walls[top].Count)
            {
                return false;
            }

            if (walls[top][left] != ' ' || CharacterPosition == (left, top))
            {
                return false;
            }

            CharacterPosition = (left, top);
            return true;
        }
    }
}
