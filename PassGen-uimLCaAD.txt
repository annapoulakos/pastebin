using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace PassGen
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Shuffle()
		{
			List<string> temp = new List<string>();
			int count = all_words.Count;
			Random rnd = new Random();
			while (count > 0)
			{
				int i = rnd.Next(0, count - 1);
				temp.Add(all_words[i]);
				all_words.RemoveAt(i);
				count--;
			}
			all_words.AddRange(temp);
		}

		List<string> all_words = new List<string>();
		private void button1_Click(object sender, EventArgs e)
		{
			string password = "";

			int count = all_words.Count;
			Random rnd = new Random();
			Shuffle();
			for (int i = 0; i < 4; ++i)
			{
				int j = rnd.Next(0, count - 1);
				password += all_words[j];
			}

			textBox1.Text = password;
			textBox1.SelectAll();
			textBox1.Focus();
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			try
			{
				TextReader tr = new StreamReader("words.txt");
				string line = tr.ReadLine();
				while (line != null)
				{
					all_words.Add(line);
					line = tr.ReadLine();
				}
				tr.Close();
			}
			catch
			{
				throw new NotImplementedException();
			}
		}
	}
}

