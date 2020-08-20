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
        private const string errorMessage = "Error";
        private string Entry
        {
            get => textBox.Text;
            set => textBox.Text = value;
        }

        private bool isResultShown;
        private bool operationSelected;
        private bool afterEqualSign;

        private void TextBoxFocusEnter(object sender, EventArgs e) => equalSignButton.Focus();

        private void DigitButtonClick(object sender, EventArgs e)
        {
            var button = (Button)sender;
            var shouldCreateNewNumber = Entry == initialEntry || isResultShown;
            Entry = shouldCreateNewNumber ? button.Text : Entry + button.Text;
            isResultShown = false;
        }

        private void ChangeSignButtonClick(object sender, EventArgs e)
        {
            if (Entry == initialEntry || Entry == errorMessage)
                return;

            Entry = (Entry[0] == '-') ? Entry.Remove(0, 1) : Entry.Insert(0, "-");
            
            isResultShown = false;
        }

        private void DecimalSeparatorButtonClick(object sender, EventArgs e)
        {
            if (isResultShown)
            {
                Entry = initialEntry;
                isResultShown = false;
            }

            if (Entry.Contains(','))
                return;

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
            isResultShown = false;
        }

        private void BackspaceButtonClick(object sender, EventArgs e)
        {
            if (isResultShown)
                return;

            var length = Entry.Length;
            var makeInitial = length == 1 || (Entry[0] == '-' && length == 2);
            Entry = makeInitial ? initialEntry : Entry.Remove(length - 1);
        }

        private void OperationButtonClick(object sender, EventArgs e)
        {
            if (Entry == errorMessage)
                return;

            if (!isResultShown)
            {
                if (afterEqualSign)
                {
                    calculator.Clear();
                    operationSelected = false;
                }

                calculator.AddNumber(Convert.ToDouble(Entry));
                if (operationSelected)
                {
                    PrintResult();
                }
            }

            var sign = ((Button)sender).Text;
            var operation = GetOperation(sign);
            calculator.AddOperation(operation);

            isResultShown = true;
            operationSelected = true;
            afterEqualSign = false;
        }

        private Operation GetOperation(string sign) =>
            sign switch
            {
                "+" => Operation.Addition,
                "-" => Operation.Subtraction,
                "×" => Operation.Multiplication,
                "÷" => Operation.Division,
                _ => throw new InvalidOperationSignException()
            };

        private void EqualSignButtonClick(object sender, EventArgs e)
        {
            if (!isResultShown || !afterEqualSign)
            {
                calculator.AddNumber(Convert.ToDouble(Entry));
            }

            if (operationSelected)
            {
                PrintResult();
            }

            isResultShown = true;
            afterEqualSign = true;
        }

        private void PrintResult()
        {
            try
            {
                Entry = calculator.Calculate().ToString();
            }
            catch (DivideByZeroException)
            {
                Entry = errorMessage;
                calculator.Clear();
                operationSelected = false;
            }
        }
    }
}
