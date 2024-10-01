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
    public partial class RegistrationPortal : Form
    {
        public RegistrationPortal()
        {
            InitializeComponent();
        }

        SqlConnection connection = new SqlConnection("Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=C:\\Users\\syedm\\OneDrive\\Documents\\SignIn_SignUp_Database.mdf;Integrated Security=True;Connect Timeout=30;");
        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void guna2Button1_Click(object sender, EventArgs e)
        {
            try
            {
                if(FirstName.Text!="" && LastName.Text!="" && DateofBirth.Text!="" && Gender.Text !="" && Address.Text!="" 
                    && Email.Text!="" && Password.Text!="" && ConfirmPassword.Text!="")
                {
                    if(Password.Text==ConfirmPassword.Text)
                    {
                        int v = check(Email.Text);
                        if(v!=1)
                        {
                            connection.Open();
                            SqlCommand command = new SqlCommand("insert into [dbo].[Table] values(@FirstName," +
                                "@LastName,@DateofBirth,@Gender,@Address,@Email,@Password)",connection);
                            command.Parameters.AddWithValue("@FirstName", FirstName.Text);
                            command.Parameters.AddWithValue("@LastName", LastName.Text);
                            command.Parameters.AddWithValue("@DateofBirth", Convert.ToDateTime(DateofBirth.Text));
                            command.Parameters.AddWithValue("@Gender", Gender.Text);
                            command.Parameters.AddWithValue("@Address", Address.Text);
                            command.Parameters.AddWithValue("@Email", Email.Text);
                            command.Parameters.AddWithValue("@Password", Password.Text);
                            command.ExecuteNonQuery();
                            connection.Close();
                            MessageBox.Show("Account Created  Successfully");
                            FirstName.Text = "";
                            LastName.Text = "";
                            DateofBirth.Text = "";
                            Gender.Text = "";
                            Address.Text = "";
                            Email.Text = "";
                            Password.Text = "";
                            ConfirmPassword.Text = "";

                        }
                        else
                        {
                            MessageBox.Show("You are Already Registered");
                        }

                    }
                    else {
                        MessageBox.Show("Password Does Not Match. Review the Password Again!🗝️🗝️🗝️🗝️");
                    }
                }
                else
                {
                    MessageBox.Show("Fill in All Fields!");
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            int check(string email)
            {
                connection.Open();
                string query = "select count(*) from [dbo].[Table] where email='" + email + "'";
                SqlCommand command = new SqlCommand(query, connection);
                int v = (int)command.ExecuteScalar();
                connection.Close();
                return v;
            }
        }

        private void RegistrationPortal_Load(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
           

        }

        private void Check_Password_CheckedChanged(object sender, EventArgs e)
        {
            if(Check_Password.Checked)
            {
                Password.UseSystemPasswordChar= false;
                ConfirmPassword.UseSystemPasswordChar = false;

            }
            else
            {
                Password.UseSystemPasswordChar= true;
                ConfirmPassword.UseSystemPasswordChar = true;
            }
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            RegistrationForm registrationForm = new RegistrationForm();
            this.Hide();
            registrationForm.ShowDialog();
        }

        private void Password_TextChanged(object sender, EventArgs e)
        {

        }
    }

}
