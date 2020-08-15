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

        private const string initialEntry = "0";
        private string Entry
        {
            get => textBox.Text; 
            set => textBox.Text = value;
        }

        private void TextBoxFocusEnter(object sender, EventArgs e)
        {
            equalSignButton.Focus();
        }

        private void NumberButtonClick(object sender, EventArgs e)
        {
            var button = (Button)sender;
            Entry = (Entry == initialEntry) ? button.Text : Entry + button.Text;
        }

        private void ChangeSignButtonClick(object sender, EventArgs e)
        {
            if (Entry == initialEntry)
                return;

            Entry = (Entry[0] == '-') ? Entry.Remove(0, 1) : Entry.Insert(0, "-");
        }

        private void DecimalSeparatorButtonClick(object sender, EventArgs e)
        {
            if (Entry.Contains(','))
                return;

            Entry = Entry.Insert(Entry.Length, ",");
        }

        private void ClearEntryButtonClick(object sender, EventArgs e) => Entry = initialEntry;

        private void BackspaceButtonClick(object sender, EventArgs e)
        {
            var length = Entry.Length;
            var makeInitial = length == 1 || (Entry[0] == '-' && length == 2);
            Entry = makeInitial ? initialEntry : Entry.Remove(length - 1);
        }
    }
}
