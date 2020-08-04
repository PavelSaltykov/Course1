using System;
using System.IO;

namespace Task2
{
    public class Program
    {
        static void Main(string[] args)
        {
            try
            {
                var eventLoop = new EventLoop();
                var game = new Game("map.txt");

                eventLoop.LeftHandler += game.OnLeft;
                eventLoop.RightHandler += game.OnRight;
                eventLoop.UpHandler += game.Up;
                eventLoop.DownHandler += game.Down;

                eventLoop.Run();
            }
            catch (FileNotFoundException)
            {
                Console.WriteLine("Map file not found");
            }
        }
    }
}
