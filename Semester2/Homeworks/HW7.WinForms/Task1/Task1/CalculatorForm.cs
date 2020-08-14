using System;
using System.Windows.Forms;

namespace Task1
{
    public partial class CalculatorForm : Form
    {
        public CalculatorForm()
        {
            InitializeComponent();
        }

        private void TextBoxFocusEnter(object sender, EventArgs e)
        {
            equalSignButton.Focus();
        }
    }
}
