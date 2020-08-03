namespace Task2
{
    public class Program
    {
        static void Main(string[] args)
        {
            var eventLoop = new EventLoop();
            var game = new Game("map.txt");

            eventLoop.LeftHandler += game.OnLeft;
            eventLoop.RightHandler += game.OnRight;
            eventLoop.UpHandler += game.Up;
            eventLoop.DownHandler += game.Down;

            eventLoop.Run();
        }
    }
}
