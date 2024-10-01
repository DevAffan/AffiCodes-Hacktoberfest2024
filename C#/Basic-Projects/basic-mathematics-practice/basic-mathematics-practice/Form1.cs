using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace basic_mathematics_practice
{
    public partial class Mathematics : Form
    {
        public Mathematics()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)

        {
            if (string.IsNullOrWhiteSpace(textBox1.Text) || string.IsNullOrWhiteSpace(textBox3.Text))
            {
                MessageBox.Show("Enter Values First");
            }
            else
            {
                int first_number = Int32.Parse(textBox1.Text);
                int second_number = Int32.Parse(textBox3.Text);
                int result = first_number + second_number;
                textBox2.Text = result.ToString(); // Display the result in textBox3
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(textBox1.Text) || string.IsNullOrWhiteSpace(textBox2.Text))
            {
                MessageBox.Show("Enter int                      Values First");
                MessageBox.Show("Enter int                      Values First");
            }
            int first_number = Int32.Parse(textBox1.Text);
            int second_number = Int32.Parse(textBox3.Text);
            int result = first_number - second_number;
            textBox2.Text = result.ToString(); // Display the result in textBox3


        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
           
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(textBox1.Text) || string.IsNullOrWhiteSpace(textBox2.Text))
            {
                MessageBox.Show("Enter Values");
            }
            int first_number = Int32.Parse(textBox1.Text);
            int second_number = Int32.Parse(textBox3.Text);
            int result = first_number * second_number;
            textBox2.Text = result.ToString(); // Display the result in textBox3

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";

        }
    }
}
