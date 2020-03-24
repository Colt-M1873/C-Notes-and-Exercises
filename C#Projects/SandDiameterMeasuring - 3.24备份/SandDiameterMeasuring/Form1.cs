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
using linktocsharpV3;
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
            DiameterCalculation.Class1 c1 = new DiameterCalculation.Class1();
            //Object sandNumber;
            MWArray a1=c1.linktocsharp(str1);
            MWNumericArray a2 = (MWNumericArray)a1;
            textBox2.Text = a2.ToString();

            linktocsharpV3.Class1 v3c1 = new linktocsharpV3.Class1();
            //MWArray DiameterArray = v3c1.linktocsharpV3(str1);
            MWArray[] resultlist = new MWArray[2];
            resultlist = v3c1.linktocsharpV3(2,str1);//重要！！！m函数有多个返回值时在第一个参数里写入返回值个数，第二个参数才是输入m函数的第一个输入参数
            MWNumericArray DiameterArray = (MWNumericArray)resultlist[0];//返回每一粒沙子的直径数组，为n行1列的二维数组
            MWNumericArray SandNumber = (MWNumericArray)resultlist[1];//沙尘个数

            double[,] DA = new double[(int)SandNumber, 1];//matlab函数返回值为二维数组，因此需要用二维数组接收
            DA = (double[,])DiameterArray.ToArray();
            //textBox3.Text = DA[(int)a2 - 1, 0].ToString();
            //textBox3.Text = DA[(int)SandNumber - 1, 0].ToString();





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

            
            
        }
        //下一步是尝试将matlab的粒径数组导出，使用chart控件绘图
    }
}
