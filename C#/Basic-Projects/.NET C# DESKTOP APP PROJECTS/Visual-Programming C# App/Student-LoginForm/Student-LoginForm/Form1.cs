using System;
using System.Windows.Forms;
using System.Data.SqlClient;


namespace Student_LoginForm
{
    public partial class Form1 : Form
       
    {
        string sqlStr = "";
        SqlConnection Conn = new SqlConnection("Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename=\"E:\\C-Sharp-Projects\\Visual-Programming C# App\\Student-LoginForm\\Student-LoginForm\\bin\\Debug\\Student-LoginForm.mdf\";Integrated Security=True;Connect Timeout=30");
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            // SQL Statement
            sqlStr = "Select * from StudentLoginTable where LoginID='" + textBox1.Text + "' and password='" + textBox2.Text + "'";
         
            Conn.Open();
            SqlCommand cmd1= new SqlCommand(sqlStr,Conn);
            cmd1.Parameters.AddWithValue("@LoginID", textBox1.Text);
            cmd1.Parameters.AddWithValue("@password", textBox2.Text);
            SqlDataReader dr1 = cmd1.ExecuteReader();

            if (dr1.Read())
            {
                Form f2 = new Form2();
                f2.Show();
                //  MessageBox.Show("Logined Successfully");
            }
            else
            {
                MessageBox.Show("Invalid Credentials");

            }
            Conn.Close();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

      //  private void button1_Click_1(object sender, EventArgs e)
      //  {
           
          //  if ((textBox1.Text.Equals("824324")) && (textBox2.Text.Equals("824324")))
          
           // {
            //    Form f2 = new Form2();
            //    f2.Show();
                //  MessageBox.Show("Logined Successfully");
          //  }
         //   else
          //  {
          //      MessageBox.Show("Invalid Credentials");

         //   }
       // }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}