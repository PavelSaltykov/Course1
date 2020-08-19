using System;
using System.Windows.Forms;
using Task1.Exceptions;

namespace Task1
{
    public partial class CalculatorForm : Form
    {
        public CalculatorForm()
        {
            InitializeComponent();
            calculator = new Calculator();
        }

        private readonly Calculator calculator;

        private const string initialEntry = "0";
        private string Entry
        {
            get => textBox.Text; 
            set => textBox.Text = value;
        }

        private bool shouldCreateNewNumber;
        private bool operationSelected;
        private bool afterEqualSign;

        private void TextBoxFocusEnter(object sender, EventArgs e) => equalSignButton.Focus();

        private void DigitButtonClick(object sender, EventArgs e)
        {
            var button = (Button)sender;
            Entry = (Entry == initialEntry || shouldCreateNewNumber) ? button.Text : Entry + button.Text;
            shouldCreateNewNumber = false;
        }

        private void ChangeSignButtonClick(object sender, EventArgs e)
        {
            if (Entry == initialEntry)
                return;

            Entry = (Entry[0] == '-') ? Entry.Remove(0, 1) : Entry.Insert(0, "-");
            
            if (afterEqualSign)
            {
                calculator.Clear();
                calculator.AddNumber(Convert.ToDouble(Entry));
            }
        }

        private void DecimalSeparatorButtonClick(object sender, EventArgs e)
        {
            if (Entry.Contains(','))
                return;

            if (shouldCreateNewNumber)
            {
                Entry = "0";
                shouldCreateNewNumber = false;
            }

            Entry = Entry.Insert(Entry.Length, ",");
        }

        private void ClearEntryButtonClick(object sender, EventArgs e) => ClearEntry();

        private void ClearButtonClick(object sender, EventArgs e)
        {
            ClearEntry();
            calculator.Clear();
            operationSelected = false;
            afterEqualSign = false;
        }

        private void ClearEntry()
        {
            Entry = initialEntry;
            shouldCreateNewNumber = false;
        }

        private void BackspaceButtonClick(object sender, EventArgs e)
        {
            if (shouldCreateNewNumber)
                return;

            var length = Entry.Length;
            var makeInitial = length == 1 || (Entry[0] == '-' && length == 2);
            Entry = makeInitial ? initialEntry : Entry.Remove(length - 1);
        }

        private void OperationButtonClick(object sender, EventArgs e)
        {
            if (afterEqualSign && !shouldCreateNewNumber)
            {
                calculator.Clear();
                operationSelected = false;
            }

            if (!shouldCreateNewNumber)
            {
                calculator.AddNumber(Convert.ToDouble(Entry));
            }

            if (operationSelected && !shouldCreateNewNumber)
            {
                PrintResult();
            }

            var sign = ((Button)sender).Text;
            var operation = sign switch
            {
                "+" => Operation.Addition,
                "-" => Operation.Subtraction,
                "×" => Operation.Multiplication,
                "÷" => Operation.Division,
                _ => throw new InvalidOperationSignException()
            };
            calculator.AddOperation(operation);
            shouldCreateNewNumber = true;
            operationSelected = true;
            afterEqualSign = false;
        }

        private void EqualSignButtonClick(object sender, EventArgs e)
        {
            if (!operationSelected)
                return;

            if (!shouldCreateNewNumber || (operationSelected && !afterEqualSign))
            {
                calculator.AddNumber(Convert.ToDouble(Entry));
            }

            if (operationSelected)
            {
                PrintResult();
            }

            afterEqualSign = true;
            shouldCreateNewNumber = true;
        }

        private void PrintResult()
        {
            try
            {
                Entry = calculator.Calculate().ToString();
            }
            catch (DivideByZeroException)
            {
                Entry = "Error";
                calculator.Clear();
                operationSelected = false;
                afterEqualSign = false;
            }
        }
    }
}
