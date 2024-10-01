using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RegistrationForm_Project
{
    public partial class LoginPage : Form
    {
        Form1 form1Instance; 

        public LoginPage(Form1 form1)
        {
            InitializeComponent();
            form1Instance = form1;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void LoginPage_Load(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click_1(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            foreach (var ctrl in this.Controls)
            {
                if (ctrl is TextBox textBox)
                {
                    textBox.Text = string.Empty;
                }
            }
        }

        public void textBox1_TextChanged(object sender, EventArgs e)
        {
            TextBox textBox = (TextBox)sender;
            textBox.Text = System.Text.RegularExpressions.Regex.Replace(textBox.Text, "[^a-zA-Z]", "");
            textBox.SelectionStart = textBox.Text.Length;
            
        }

        public void textBox2_TextChanged(object sender, EventArgs e)
        {
            TextBox textBox = (TextBox)sender;
            
        }

        public void button1_Click(object sender, EventArgs e)
        {
            if (form1Instance.UsernameText == textBox1.Text && form1Instance.EmailText == textBox2.Text)
            {
                MainPage mainPage = new MainPage();
                mainPage.ShowDialog();
            }
            else
            {
                MessageBox.Show("Invalid username or email.ReTry");
            }
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
