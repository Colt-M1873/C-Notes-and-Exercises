using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MathWorks.MATLAB.NET.Arrays;
using DiameterCalculation;
using System.IO;

namespace SandDiameterMeasuring
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private string pathname = string.Empty;     		//定义路径名变量
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }


        private void Start_Click(object sender, EventArgs e)
        {
            //pictureBox2.Image = SandDiameterMeasuring.Properties.Resources.屏幕截图_1654_;
           // pictureBox2.Image.Dispose();
           // pictureBox2.Image = null;
            textBox1.Text = ("加载图片");
            OpenFileDialog file = new OpenFileDialog();
            file.InitialDirectory = ".";
            file.Filter = "所有文件(*.*)|*.*";
            file.ShowDialog();
            if (file.FileName != string.Empty)
            {
                try
                {
                    pathname = file.FileName;   //获得文件的绝对路径
                    this.pictureBox1.Load(pathname);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            string str1 = file.FileName;
            //str1 = "'" + str1 + "'";//加单引号为符合matlab输入规范
            textBox1.Text = (str1);
            //textBox1.Text = (file.FileName);
            Class1 c1 = new Class1();
            //Object sandNumber;
            c1.linktocsharp(str1);
            //textBox2.Text = (sandNumber.ToString);
            string pathname2;
            pathname2 = "D:\\op\\tempresult.png";  //获得文件的绝对路径
            //this.pictureBox2.Load(pathname2);//load貌似过时了？
           // this.pictureBox2.Image = Image.FromFile(pathname2);
            //    pictureBox2.Image.Dispose();
            FileStream pFileStream = new FileStream(pathname2, FileMode.Open, FileAccess.Read);
            pictureBox2.Image = Image.FromStream(pFileStream);
            pFileStream.Close();
            pFileStream.Dispose();



            //if (System.IO.File.Exists(pathname2))
            //{
            //    System.IO.File.Delete(pathname2);
            //}
        }
        //下一步是尝试将matlab的粒径数组导出，使用chart控件绘图
    }
}
