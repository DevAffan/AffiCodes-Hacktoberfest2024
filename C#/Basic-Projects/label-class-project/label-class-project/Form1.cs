using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace label_class_project
{
    public partial class Details : Form
    {
        public Details()
        {
            InitializeComponent();
        }

        private void Change_Click(object sender, EventArgs e)
        {
            //Form formobj = new Form();
            //formobj.ShowDialog();
            string name = "Maaz";
            MessageBox.Show("Name: " + name);
        }

        private void label1_Click(object sender, EventArgs e)
        {
               
            
        }
    }
}
