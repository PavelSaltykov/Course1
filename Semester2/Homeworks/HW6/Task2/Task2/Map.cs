using System;
using System.Collections.Generic;
using System.IO;

namespace Task2
{
    public class Map
    {
        private readonly List<List<char>> walls;
        public const char characterSymbol = '@';
        public (int left, int top) CharacterPosition { get; private set; } = (-1, -1);

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
            using var sr = new StreamReader(filename);
            var currentLine = 0;
            walls.Add(new List<char>());

            while (!sr.EndOfStream)
            {
                var currentSymbol = sr.Read();
                if (currentSymbol == '\n')
                {
                    walls.Add(new List<char>());
                    currentLine++;
                    continue;
                }

                if (currentSymbol == characterSymbol)
                {
                    if (CharacterPosition == (-1, -1))
                    {
                        CharacterPosition = (walls[currentLine].Count, currentLine);
                    }
                    currentSymbol = ' ';
                }

                walls[currentLine].Add((char)currentSymbol);
            }
        }

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

        public bool SetCharacterPosition(int left, int top)
        {
            try
            {
                if (walls[top][left] != ' ' || CharacterPosition == (left, top))
                {
                    return false;
                }

                CharacterPosition = (left, top);
                return true;
            }
            catch (ArgumentOutOfRangeException)
            {
                return false;
            }
        }
    }
}
