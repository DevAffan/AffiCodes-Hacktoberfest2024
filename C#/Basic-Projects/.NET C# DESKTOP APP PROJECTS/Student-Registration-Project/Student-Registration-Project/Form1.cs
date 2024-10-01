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

namespace Student_Registration_Project
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        SqlConnection conn = new SqlConnection("Data Source=BLACK_HAT\\SQLEXPRESS; Initial Catalog=ArmyPublickSchool;");
        SqlCommand cmd;
        SqlDataReader read;
        string ID;
        bool Mode = true;
        string sql;


        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
           
        }

        // If the Mode is true it means add the record and if the mode is false then  update the record
        private void txtName_TextChanged(object sender, EventArgs e)
        {
            string name = txtName.Text;
            string course = txtCourse.Text;
            string fee = txtFee.Text;

            if(Mode==true)
            {
                sql = "insert into Student(Student_Name,Course,Fee)values(@Student_Name,@Course,@Fee)";
                conn.Open();
                cmd=new SqlCommand(sql, conn);
                cmd.Parameters.AddWithValue("@Student_Name", name);
                cmd.Parameters.AddWithValue("@Course", course);
                cmd.Parameters.AddWithValue("@Fee", fee);
                MessageBox.Show("Recorded has been Added Succcessfully!");
                cmd.ExecuteNonQuery();

                txtName.Clear();
                txtCourse.Clear();
                txtFee.Clear();
                txtName.Focus();


            }
            else
            {

            }
            conn.Close();


        }
    }
}
