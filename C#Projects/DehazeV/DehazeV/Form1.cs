using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics;
using MathWorks.MATLAB.NET.Arrays;
//using DheazeFunction;//单词拼错，待修改
using DehazeFunctionV2;

namespace DehazeV
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
          //  this.WindowState = FormWindowState.Maximized;//默认打开软件直接全屏
        }
        private string pathname = string.Empty;
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void readImg_Click(object sender, EventArgs e)
        {
            OpenFileDialog file = new OpenFileDialog();
            file.InitialDirectory = ".";
            file.Filter = "所有文件(*.*)|*.*";
            file.ShowDialog();
            if (file.FileName != string.Empty)
            {
                try
                {
                    pathname = file.FileName;   //获得文件的绝对路径
                    this.inputImg.Load(pathname);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            string str1 = pathname;
            //str1 = "'" + str1 + "'";//加单引号为符合matlab输入规范
            textBox1.Text = (str1);

            outputImg.Image = DehazeV.Properties.Resources.下载;
            textBox2.Text = null;
            textBox3.Text = null;
            textBox4.Text = null;

        }

        private void startDehaze_Click(object sender, EventArgs e)
        {
            //string Atext, convCoretext;
            //convCoretext = textBox3.Text;
            //Atext = textBox4.Text;
            double Anum, convCorenum;
            Anum = 0;
            convCorenum = 0;

            DehazeFunctionV2.Class1 v2c1 = new DehazeFunctionV2.Class1();
            MWArray[] resultlist = new MWArray[2];
            resultlist = v2c1.DehazeFunctionV2(2, pathname, Anum, convCorenum);
            MWNumericArray Atmospherelight = (MWNumericArray)resultlist[0];
            MWNumericArray SSIM = (MWNumericArray)resultlist[1];
            textBox2.Text = SSIM.ToString();
            textBox4.Text = Atmospherelight.ToString();
            textBox3.Text = "15";
            string pathname2;
            pathname2 = "D:\\op\\cache\\temp.jpg";  //获得文件的绝对路径
                                                    //this.pictureBox2.Load(pathname2);//load貌似过时了？
                                                    // this.pictureBox2.Image = Image.FromFile(pathname2);
                                                    //    pictureBox2.Image.Dispose();
            FileStream pFileStream = new FileStream(pathname2, FileMode.Open, FileAccess.Read);
            outputImg.Image = Image.FromStream(pFileStream);
            pFileStream.Close();
            pFileStream.Dispose();

            //DheazeFunction.Class1 v1c1 = new DheazeFunction.Class1();
            //MWArray[] resultlist = new MWArray[2];
            //resultlist = v1c1.DheazeFunction(1, pathname);
            //MWNumericArray Atmospherelight = (MWNumericArray)resultlist[0];

            //textBox4.Text = Atmospherelight.ToString();
            //textBox3.Text = "15";
            //string pathname2;
            //pathname2 = "D:\\op\\cache\\temp.jpg";  //获得文件的绝对路径
            //                                       //this.pictureBox2.Load(pathname2);//load貌似过时了？
            //                                       // this.pictureBox2.Image = Image.FromFile(pathname2);
            //                                       //    pictureBox2.Image.Dispose();
            //FileStream pFileStream = new FileStream(pathname2, FileMode.Open, FileAccess.Read);
            //outputImg.Image = Image.FromStream(pFileStream);
            //pFileStream.Close();
            //pFileStream.Dispose();





        }

        private void button1_Click(object sender, EventArgs e)
        {
            string Atext,convCoretext;
            convCoretext = textBox3.Text;
            Atext=textBox4.Text;
            double Anum, convCorenum;
            Anum = Convert.ToDouble(Atext);
            convCorenum = Convert.ToDouble(convCoretext);

            DehazeFunctionV2.Class1 v2c1 = new DehazeFunctionV2.Class1();
            MWArray[] resultlist = new MWArray[2];
            resultlist = v2c1.DehazeFunctionV2(2, pathname,Anum,convCorenum);
            MWNumericArray Atmospherelight = (MWNumericArray)resultlist[0];
            MWNumericArray SSIM = (MWNumericArray)resultlist[1];
            textBox2.Text = SSIM.ToString();

            string pathname2;
            pathname2 = "D:\\op\\cache\\temp.jpg";  //获得文件的绝对路径
                                                    //this.pictureBox2.Load(pathname2);//load貌似过时了？
                                                    // this.pictureBox2.Image = Image.FromFile(pathname2);
                                                    //    pictureBox2.Image.Dispose();
            FileStream pFileStream = new FileStream(pathname2, FileMode.Open, FileAccess.Read);
            outputImg.Image = Image.FromStream(pFileStream);
            pFileStream.Close();
            pFileStream.Dispose();




        }
    }
}
