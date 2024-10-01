using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Login_SignUp_Form
{
    public partial class RegistrationPortal : Form
    {
        public static string StoredEmail { get; private set; }
        public static string StoredPassword { get; private set; }

        public RegistrationPortal()
        {
            InitializeComponent();
        }
         private void button1_Click(object sender, EventArgs e)
        {
            if (FirstName.Text != "" && LastName.Text != "" && DateofBirth.Text != "" && Gender.Text != "" &&
               Address.Text != "" && Email.Text != "" && Password.Text != "" && ConfirmPassword.Text != "")
            {
                if (Password.Text == ConfirmPassword.Text)
                {
                    MessageBox.Show("Account Created Successfully");
                   StoredEmail = Email.Text;
                    StoredPassword = Password.Text;
                    ClearFields();
                }
                else
                {
                    MessageBox.Show("Password Does Not Match. Review the Password Again!🗝🗝️");
                }
            }
            else
            {
                MessageBox.Show(" Fill in All Fields! 💫🗝️👤💫");
            }
        }
        private void ClearFields()
        {
            FirstName.Text = "";
            LastName.Text = "";
            DateofBirth.Text = "";
            Gender.Text = "";
            Address.Text = "";
            Email.Text = "";
            Password.Text = "";
            ConfirmPassword.Text = "";
        }
        private void Check_Password_CheckedChanged(object sender, EventArgs e)
        {
            Password.UseSystemPasswordChar = !Check_Password.Checked;
            ConfirmPassword.UseSystemPasswordChar = !Check_Password.Checked;
        }
        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            RegistrationForm registrationForm = new RegistrationForm();
            this.Hide();
            registrationForm.ShowDialog();
        }

        private void Email_TextChanged(object sender, EventArgs e)
        {

        }

        private void Password_TextChanged(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

       
    }
}
