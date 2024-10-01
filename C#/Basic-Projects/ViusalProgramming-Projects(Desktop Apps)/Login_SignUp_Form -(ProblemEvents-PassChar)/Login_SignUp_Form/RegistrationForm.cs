using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;


namespace Login_SignUp_Form
{
    public partial class RegistrationForm : Form
    {
        public RegistrationForm()
        {
            InitializeComponent();
             
        }
        SqlConnection connection = new SqlConnection("Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\syedm\\OneDrive\\Documents\\SignIn_SignUp_Database.mdf;Integrated Security=True;Connect Timeout=30;");

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_Enter(object sender, EventArgs e)
        {
            if(Email.Text== "Email or Phone")
            {
                Email.Text = "";
                Email.ForeColor = Color.Black;
            }
        }

        private void textBox1_Leave(object sender, EventArgs e)
        {
            if(Email.Text=="")
            {
                Email.Text = "Email or Phone";
                Email.ForeColor = Color.Silver;
            }
        }

        private void textBox2_Enter(object sender, EventArgs e)
        {
            if(Password.Text== "Password")
            {
              
                Password.Text = "";
                Password.ForeColor = Color.Black;

            }
        }

        private void textBox2_Leave(object sender, EventArgs e)
        {
            if(Password.Text=="")
            {

                Password.Text = "Password";
                Password.ForeColor = Color.Silver;
            }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
          
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
               
        }

        private void RegistrationForm_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            RegistrationPortal registrationportal = new RegistrationPortal();
            this.Hide();
            registrationportal.Show();
        }

        private void Check_Password_CheckedChanged(object sender, EventArgs e)

        {
            if (Check_Password.Checked)
            {
                Password.UseSystemPasswordChar = false;

            }
            else
            {
                Password.UseSystemPasswordChar = true;
            }
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {

        }

        private void button_Click(object sender, EventArgs e)
        {
            if (Email.Text != "" && Password.Text != "")
            {
                string query = "SELECT COUNT(*) FROM [dbo].[Table] WHERE Email='" + Email.Text + "' AND " +
                 "Password='" + Password.Text + "'";
                connection.Open();
                SqlCommand command = new SqlCommand(query, connection);
                int v = (int)command.ExecuteScalar();
                connection.Close();
                if (v != 1)
                {
                    MessageBox.Show("Incorrect Email and Password", "Retry!💫👤👤");

                }
                else
                {
                    //MessageBox.Show("Welcome to Home Page");
                    LinkedinHomePage linkedinHomePage = new LinkedinHomePage();
                    linkedinHomePage.Show();
                    Email.Text = "";
                    Password.Text = "";
                }
            }
            else
            {
                MessageBox.Show("Fill in All Fields!");
            }

        }
    }
}
