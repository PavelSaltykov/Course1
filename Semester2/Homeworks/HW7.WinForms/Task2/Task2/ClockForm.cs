using System;
using System.Drawing;
using System.Windows.Forms;

namespace Task2
{
    public partial class ClockForm : Form
    {
        public ClockForm()
        {
            InitializeComponent();
            Width = diameter + 23;
            Height = diameter + 57;
        }

        private const int radius = 200;
        private const int diameter = 2 * radius;

        private Graphics graphics;
        private Bitmap bitmap;

        private void ClockFormLoad(object sender, EventArgs e)
        {
            bitmap = new Bitmap(diameter + 1, diameter + 1);
            graphics = Graphics.FromImage(bitmap);

            DrawClockFace();
            pictureBox.Image = bitmap;

            TimerTick(timer, EventArgs.Empty);
        }

        private void DrawClockFace()
        {
            graphics.DrawEllipse(new Pen(Color.Black, 1), 0, 0, diameter, diameter);

            graphics.DrawString("12", new Font("Arial", 12), Brushes.Black, radius - 18, 5);
            graphics.DrawString("3", new Font("Arial", 12), Brushes.Black, diameter - 25, radius - 12);
            graphics.DrawString("6", new Font("Arial", 12), Brushes.Black, radius - 10, diameter - 30);
            graphics.DrawString("9", new Font("Arial", 12), Brushes.Black, 3, radius - 12);
        }

        private void TimerTick(object sender, EventArgs e)
        {
            Text = DateTime.Now.ToString("HH:mm:ss");

            
        }
    }
}
