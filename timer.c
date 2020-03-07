using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Timer1
{
    public partial class Form1 : Form
    {
        int count;
        int time;
        public Form1()
        {
            InitializeComponent();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            int i;
            for (i=1;i<100;i++)
            {
                comboBox1.Items.Add(i.ToString()+" 秒");//Tostring()将数字变为字符串
            
            }
            label3.Text = "";
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            count++;//记当前秒
            label3.Text = (time - count).ToString() + "秒";//显示剩余时间
            progressBar1.Value = count;     //显示剩余时间
            if (count  == time )
            {
                timer1.Stop();//时间到，计时停止
                System.Media.SystemSounds.Asterisk.Play(); //提示音
                
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string str = comboBox1.Text;//将下拉框内容添加到一个变量中
            string data = str.Substring(0, 2);//(0,2)从字符串的0位取两位
            time = Convert.ToInt16(data); //得到设定的定时值（整型）      
            progressBar1.Maximum = time; //进度条最大数值
            timer1.Start();
        }   
    }
}

