using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Net.Mime.MediaTypeNames;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;

namespace RegistrationForm_Project
{
    public partial class Form1 : Form

    {
        //public string UsernameText => textBox1.Text;
        //public string EmailText => textBox4.Text;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void label16_Click(object sender, EventArgs e)
        {

        }

        private void label12_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label23_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            LoginPage loginPage = new LoginPage(this);
            loginPage.ShowDialog();

        }

        private void button2_Click(object sender, EventArgs e)
        {
            foreach (var ctrl in this.Controls)
            {
                if(ctrl is TextBox textBox)
                {
                    textBox.Text = string.Empty;
                }
            }

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            
        }

        public void textBox1_TextChanged(object sender, EventArgs e)
        {
            TextBox textBox = (TextBox)sender;
            textBox.Text = System.Text.RegularExpressions.Regex.Replace(textBox.Text, "[^a-zA-Z]", "");
            textBox.SelectionStart = textBox.Text.Length;
            if (string.IsNullOrWhiteSpace(textBox.Text))
            {
                
                 MessageBox.Show("This Field not be Empty.");
                
            }
        }

        public void textBox4_TextChanged(object sender, EventArgs e)
        {
            TextBox textBox = (TextBox)sender;
            string emailPattern = @"^\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$";


            if (System.Text.RegularExpressions.Regex.IsMatch(textBox.Text, emailPattern))
            {
                textBox.ForeColor = Color.Black;
            }
            else
            {
                textBox.ForeColor = Color.Red;
            }
        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {
            
            
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            //TextBox textBox = (TextBox)sender;
            //string location = textBox.Text.Trim();

            //if (string.IsNullOrWhiteSpace(location))
            //{
            //    MessageBox.Show("Please enter a valid location.");
               
            //}
            
        }

        public void label1_Click(object sender, EventArgs e)
        {

        }

        public void label28_Click(object sender, EventArgs e)
        {

        }

        private void radioButton5_CheckedChanged(object sender, EventArgs e)
        {
            
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton6_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            
        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
