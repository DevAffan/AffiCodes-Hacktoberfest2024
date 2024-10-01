using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Student_Grade_Project
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox11_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            double Database, DSA, OOP, Programming, OS, Agile, total, Perc;
            string grade;

            Database=int.Parse(txtDatabase.Text);
            DSA= int.Parse(txtDataStructure.Text);
            OOP = int.Parse(txtObjectOriented.Text);
            Programming = int.Parse(txtProgramming.Text);
            OS = int.Parse(txtOperatingSystem.Text);
            Agile = int.Parse(txtAgileMethodology.Text);


            total = Database + DSA + OOP + Programming + OS + Agile;

              txtTotal.Text = total.ToString();
            Perc = total / 6;

            txtPercentage.Text=Perc.ToString();


            if(Perc>=90)
            {
                grade = "A+";
            }
           else if (Perc >=80)
            {
                grade = "A";
            }
            else if (Perc >= 70)
            {
                grade = "B+";
            }
            else if (Perc >= 60)
            {
                grade = "B";
            }
            else if (Perc >= 50)
            {
                grade = "C";
            }
           
            else
            {
                grade = "F";
            }

            txtGrade.Text = grade;




        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
