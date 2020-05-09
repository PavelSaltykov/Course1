using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test1
{
    public partial class MyForm : Form
    {
        public MyForm()
        {
            InitializeComponent();
        }

        /// <summary>
        /// The program ends when the button is pressed.
        /// </summary>
        private void ButtonClick(object sender, EventArgs e)
        {
            Close();
        }

        /// <summary>
        /// Move button when mouse hover.
        /// </summary>
        private void ButtonMouseHover(object sender, EventArgs e)
        {
            Random r = new Random();
            button.Left = r.Next(0, ClientSize.Width - button.Width);
            button.Top = r.Next(0, ClientSize.Height - button.Height);
        }
    }
}
