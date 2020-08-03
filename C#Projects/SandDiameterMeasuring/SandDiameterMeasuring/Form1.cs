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
using linktocsharpV6;
using System.IO;
using System.Diagnostics;
using System.Windows.Forms.DataVisualization.Charting;

namespace SandDiameterMeasuring
{
    public partial class Form1 : Form
    {
        
        public class ChartHelper
        {
            /// <summary>
            /// Name：添加序列
            /// Author：by boxuming 2019-04-28 13:59
            /// </summary>
            /// <param name="chart">图表对象</param>
            /// <param name="seriesName">序列名称</param>
            /// <param name="chartType">图表类型</param>
            /// <param name="color">颜色</param>
            /// <param name="markColor">标记点颜色</param>
            /// <param name="showValue">是否显示数值</param>
            public static void AddSeries(Chart chart, string seriesName, SeriesChartType chartType, Color color, Color markColor, bool showValue = false)
            {
                chart.Series.Add(seriesName);
                chart.Series[seriesName].ChartType = chartType;
                chart.Series[seriesName].Color = color;
                if (showValue)
                {
                    chart.Series[seriesName].IsValueShownAsLabel = true;
                    chart.Series[seriesName].MarkerStyle = MarkerStyle.Circle;
                    chart.Series[seriesName].MarkerColor = markColor;
                    chart.Series[seriesName].LabelForeColor = markColor;
                    chart.Series[seriesName].LabelAngle = 0;
                }
            }

            /// <summary>
            /// Name：设置标题
            /// Author：by boxuming 2019-04-28 14:25
            /// </summary>
            /// <param name="chart">图表对象</param>
            /// <param name="chartName">图表名称</param>
            public static void SetTitle(Chart chart, string chartName, Font font, Docking docking, Color foreColor)
            {
                chart.Titles.Add(chartName);
                chart.Titles[0].Font = font;
                chart.Titles[0].Docking = docking;
                chart.Titles[0].ForeColor = foreColor;
            }

            /// <summary>
            /// Name：设置样式
            /// Author：by boxuming 2019-04-23 14:04
            /// </summary>
            /// <param name="chart">图表对象</param>
            /// <param name="backColor">背景颜色</param>
            /// <param name="foreColor">字体颜色</param>
            public static void SetStyle(Chart chart, Color backColor, Color foreColor)
            {
                chart.BackColor = backColor;
                chart.ChartAreas[0].BackColor = backColor;
                chart.ForeColor = Color.Red;
            }

            /// <summary>
            /// Name：设置图例
            /// Author：by boxuming 2019-04-23 14:30
            /// </summary>
            /// <param name="chart">图表对象</param>
            /// <param name="docking">停靠位置</param>
            /// <param name="align">对齐方式</param>
            /// <param name="backColor">背景颜色</param>
            /// <param name="foreColor">字体颜色</param>
            public static void SetLegend(Chart chart, Docking docking, StringAlignment align, Color backColor, Color foreColor)
            {
                chart.Legends[0].Docking = docking;
                chart.Legends[0].Alignment = align;
                chart.Legends[0].BackColor = backColor;
                chart.Legends[0].ForeColor = foreColor;
            }

            /// <summary>
            /// Name：设置XY轴
            /// Author：by boxuming 2019-04-23 14:35
            /// </summary>
            /// <param name="chart">图表对象</param>
            /// <param name="xTitle">X轴标题</param>
            /// <param name="yTitle">Y轴标题</param>
            /// <param name="align">坐标轴标题对齐方式</param>
            /// <param name="foreColor">坐标轴字体颜色</param>
            /// <param name="lineColor">坐标轴颜色</param>
            /// <param name="arrowStyle">坐标轴箭头样式</param>
            /// <param name="xInterval">X轴的间距</param>
            /// <param name="yInterval">Y轴的间距</param>
            public static void SetXY(Chart chart, string xTitle, string yTitle, StringAlignment align, Color foreColor, Color lineColor, AxisArrowStyle arrowStyle, double xInterval, double yInterval)
            {
                chart.ChartAreas[0].AxisX.Title = xTitle;
                chart.ChartAreas[0].AxisY.Title = yTitle;
                chart.ChartAreas[0].AxisX.TitleAlignment = align;
                chart.ChartAreas[0].AxisY.TitleAlignment = align;
                chart.ChartAreas[0].AxisX.TitleForeColor = foreColor;
                chart.ChartAreas[0].AxisY.TitleForeColor = foreColor;
                chart.ChartAreas[0].AxisX.LabelStyle = new LabelStyle() { ForeColor = foreColor };
                chart.ChartAreas[0].AxisY.LabelStyle = new LabelStyle() { ForeColor = foreColor };
                chart.ChartAreas[0].AxisX.LineColor = lineColor;
                chart.ChartAreas[0].AxisY.LineColor = lineColor;
                chart.ChartAreas[0].AxisX.ArrowStyle = arrowStyle;
                chart.ChartAreas[0].AxisY.ArrowStyle = arrowStyle;
                chart.ChartAreas[0].AxisX.Interval = xInterval;
                chart.ChartAreas[0].AxisY.Interval = yInterval;
            }

            /// <summary>
            /// Name：设置网格
            /// Author：by boxuming 2019-04-23 14:55
            /// </summary>
            /// <param name="chart">图表对象</param>
            /// <param name="lineColor">网格线颜色</param>
            /// <param name="xInterval">X轴网格的间距</param>
            /// <param name="yInterval">Y轴网格的间距</param>
            public static void SetMajorGrid(Chart chart, Color lineColor, double xInterval, double yInterval)
            {
                chart.ChartAreas[0].AxisX.MajorGrid.LineColor = lineColor;
                chart.ChartAreas[0].AxisY.MajorGrid.LineColor = lineColor;
                chart.ChartAreas[0].AxisX.MajorGrid.Interval = xInterval;
                chart.ChartAreas[0].AxisY.MajorGrid.Interval = yInterval;
            }
        }


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
            Stopwatch sw = new Stopwatch();
            sw.Start();
            string str1 = file.FileName;
            //str1 = "'" + str1 + "'";//加单引号为符合matlab输入规范
            textBox1.Text = (str1);
            
            linktocsharpV6.Class1 v5c1 = new linktocsharpV6.Class1();
            //MWArray DiameterArray = v3c1.linktocsharpV3(str1);
            MWArray[] resultlist = new MWArray[2];
            resultlist = v5c1.linktocsharpV6(5,str1);//重要！！！m函数有多个返回值时在第一个参数里写入返回值个数，第二个参数才是输入m函数的第一个输入参数
            MWNumericArray DiameterArray = (MWNumericArray)resultlist[0];//返回每一粒沙子的直径数组，为n行1列的二维数组
            MWNumericArray SandNumber = (MWNumericArray)resultlist[1];//沙尘个数
            MWNumericArray DiameterNumber = (MWNumericArray)resultlist[2];//返回以50um为单位的粒径累加结果数组
            MWNumericArray xlength = (MWNumericArray)resultlist[3];//返回粒径累加结果数组长度
            MWNumericArray TypeNumber = (MWNumericArray)resultlist[4];//返回三种沙粒：石砾，粗沙粒，细沙粒个数数组
            textBox2.Text = SandNumber.ToString();
            double[,] DA = new double[(int)SandNumber, 1];//matlab函数返回值为二维数组，因此需要用二维数组接收
            DA = (double[,])DiameterArray.ToArray();
            double[,] DN = new double[(int)xlength, 1];//matlab函数返回值为二维数组，因此需要用二维数组接收
            DN = (double[,])DiameterNumber.ToArray();
            double[,] TN = new double[3, 1];//matlab函数返回值为二维数组，因此需要用二维数组接收
            TN = (double[,])TypeNumber.ToArray();
            //textBox3.Text = DA[(int)a2 - 1, 0].ToString();
            //textBox3.Text = DA[(int)SandNumber - 1, 0].ToString();

            chart1.Series.Clear();
            ChartHelper.AddSeries(chart1, "由小到大每一粒沙尘的粒径", SeriesChartType.Column, Color.Transparent, Color.Red, true);
         //   ChartHelper.AddSeries(chart1, "由小到大每一粒沙尘的粒径", SeriesChartType.Spline, Color.Red, Color.Red);
         //   ChartHelper.SetTitle(chart1, "由小到大每一粒沙尘的粒径", new Font("微软雅黑", 8), Docking.Top, Color.Black);
            ChartHelper.SetStyle(chart1, Color.Transparent, Color.Black);
            ChartHelper.SetLegend(chart1, Docking.Top, StringAlignment.Center, Color.Transparent, Color.Black);
            ChartHelper.SetXY(chart1, "", "粒径(*50um)", StringAlignment.Far, Color.Black, Color.Black, AxisArrowStyle.SharpTriangle, 0, 0);
            ChartHelper.SetMajorGrid(chart1, Color.Transparent, 20, 50);
            List<int> xData = new List<int>() { };
            int i, j;
            for (i = 1; i <= (int)SandNumber; i++)
            {
                xData.Add(i);
            }
            List<double> yData = new List<double>() { };
            for (j = 0; j <= (int)SandNumber - 1; j++)
            {
                yData.Add(DA[j, 0]);
            }
            chart1.Series[0].Points.DataBindXY(xData, yData);

            chart2.Series.Clear();
            ChartHelper.AddSeries(chart2, "该粒径范围内沙尘个数", SeriesChartType.Column, Color.Lime, Color.Blue, true);
      //      ChartHelper.AddSeries(chart2, "曲线图", SeriesChartType.Spline, Color.Red, Color.Red);
      //      ChartHelper.SetTitle(chart2, "柱状图与曲线图", new Font("微软雅黑", 12), Docking.Bottom, Color.Black);
            ChartHelper.SetStyle(chart2, Color.Transparent, Color.Black);
            ChartHelper.SetLegend(chart2, Docking.Top, StringAlignment.Center, Color.Transparent, Color.Black);
            ChartHelper.SetXY(chart2, "粒径(*50um)", "个数", StringAlignment.Far, Color.Black, Color.Black, AxisArrowStyle.SharpTriangle, 4, (int)(DN[0,0]/10));
            ChartHelper.SetMajorGrid(chart2, Color.Transparent, 20, 2);
            List<int> xData2 = new List<int>() { };
            int i2, j2;
            for (i2 = 1; i2 <= (int)xlength; i2++)
            {
                xData2.Add(i2);
            }
            List<double> yData2 = new List<double>() { };
            for (j2 = 0; j2 <= (int)xlength - 1; j2++)
            {
                yData2.Add(DN[j2, 0]);
            }
            chart2.Series[0].Points.DataBindXY(xData2, yData2);

            chart3.Series.Clear();
            ChartHelper.AddSeries(chart3, "饼状图", SeriesChartType.Pie, Color.Lime, Color.Black, true);
            ChartHelper.SetStyle(chart3, Color.Transparent, Color.Black);
            ChartHelper.SetLegend(chart3, Docking.Bottom, StringAlignment.Center, Color.Transparent, Color.Black);
            List<double> y1 = new List<double>() { };
            int j3;
            for (j3= 0; j3 <= 2; j3++)
            {
                y1.Add(TN[j3, 0]);

            }
            string t1 = String.Format("石砾(>1000㎛):         {0}个", TN[0, 0]);
            string t2 = String.Format("粗沙粒(250-1000㎛):    {0}个", TN[1, 0]);
            string t3 = String.Format("细沙粒(50-250㎛):      {0}个", TN[2, 0]);
            List<string> nameX = new List<string>() { t1, t2, t3 };
            chart3.Series[0].Points.DataBindXY(nameX, y1);
            chart3.Series[0]["PieLabelStyle"] = "Outside";//将文字移到外侧 
            chart3.Series[0]["PieLineColor"] = "Black";//绘制黑色的连线。 
            chart3.Series[0].Label = "#PERCENT{P2}";

            sw.Stop();
            TimeSpan ts = sw.Elapsed;
            Console.WriteLine("DateTime costed for this function is: {0}ms", ts.TotalMilliseconds);
        }
    }
}
