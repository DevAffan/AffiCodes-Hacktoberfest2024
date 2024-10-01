using System;
using System.Drawing;
using System.Windows.Forms;

namespace Login_SignUp_Form
{
    public partial class RegistrationForm : Form
    {
        public RegistrationForm()
        {
            InitializeComponent();
       
        }
        private void textBox1_Enter(object sender, EventArgs e)
        {
            if (Email.Text == "Email or Phone")
            {
                Email.Text = "";
                Email.ForeColor = Color.Black;
            }
        }

        private void textBox1_Leave(object sender, EventArgs e)
        {
            if (Email.Text == "")
            {
                Email.Text = "Email or Phone";
                Email.ForeColor = Color.Silver;
            }
        }

        private void textBox2_Enter(object sender, EventArgs e)
        {
            if (Password.Text == "Password")
            {
                Password.Text = "";
                Password.ForeColor = Color.Black;
            }
        }

        private void textBox2_Leave(object sender, EventArgs e)
        {
            if (Password.Text == "")
            {
                Password.Text = "Password";
                Password.ForeColor = Color.Silver;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string userEmail = Email.Text;
            string userPassword = Password.Text;

            if (string.IsNullOrWhiteSpace(Email.Text) && string.IsNullOrWhiteSpace(Password.Text))
            {
                if (userEmail != RegistrationPortal.StoredEmail && userPassword != RegistrationPortal.StoredPassword)
                {
                    MessageBox.Show("Incorrect Email or Password. Put Correct Credientials!");
                    return;
                }

                if (userEmail != RegistrationPortal.StoredEmail)
                {
                    MessageBox.Show("Incorrect Email. Please enter the correct email!");
                    return;
                }
                if (userPassword != RegistrationPortal.StoredPassword)
                {
                    MessageBox.Show("Incorrect Password. Please enter the correct password!");
                    return;
                }
                if (userEmail == RegistrationPortal.StoredEmail && userPassword == RegistrationPortal.StoredPassword)
                {
                   LinkedinHomePage linkedinHomePage = new LinkedinHomePage();
                    this.Hide();
                    linkedinHomePage.Show();
                }
               
            }
            else
            {
               MessageBox.Show("Fill in All the Fields! Fields should not be Blank");
            }
        }


        private void button2_Click(object sender, EventArgs e)
        {
            RegistrationPortal registrationPortal = new RegistrationPortal();
            this.Hide();
            registrationPortal.Show();
           
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }
    }
  
}
