using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.SqlClient;
using MySql.Data.MySqlClient;
using System.Data;
using System.IO;
using System.Xml.Linq;

namespace Helivalues_ODBC_Connection_Tool
{
    class Program
    {
        static void Main(string[] args)
        {
            XDocument xdoc = XDocument.Load("sql_connections/connections.xml");
            var connections = from connection in xdoc.Element("connections").Descendants("connection")
                              select new Connection2
                              {
                                  Name = connection.Element("name").Value,
                                  Server = connection.Element("server").Value,
                                  Database = connection.Element("database").Value,
                                  Username = connection.Element("username").Value,
                                  Password = connection.Element("password").Value
                              };
            List<Connection2> myConnections = new List<Connection2>();
            foreach (var p in connections)
                myConnections.Add(p);

            MySqlConnection mysql_connection = new MySqlConnection();
            mysql_connection.ConnectionString = myConnections.Find(v => v.Name=="mysql").MySQL;
            mysql_connection.Open();
            TestMySQL(ref mysql_connection);
            mysql_connection.Close();
            Console.ReadLine();

            SqlConnectionStringBuilder sql_csb = new SqlConnectionStringBuilder();
            using (Connection2 conn = myConnections.Find(v => v.Name == "mssql"))
            {
                sql_csb.DataSource = conn.Server;
                sql_csb.InitialCatalog = conn.Database;
                //sql_csb.UserID = conn.Username;
                //sql_csb.Password = conn.Password;
            }

            SqlConnection sql_connection = new SqlConnection();
            sql_connection.ConnectionString = "Data Source=NATHAN-PC\\JIMLOCAL;Initial Catalog=HelivaluesSQL;Integrated Security=True";
            Console.WriteLine(sql_csb.ConnectionString);
            Console.ReadLine();
            
			sql_connection.Open();
            TestMSSQL(sql_connection);
            sql_connection.Close();
        }

        static void TestMySQL(ref MySqlConnection mysql_connection)
        {
            DataTable dtAll = new DataTable();
            string query = "select * from Products";
            MySqlDataAdapter adapter = new MySqlDataAdapter(query, mysql_connection);
            DataSet ds = new DataSet();
            adapter.Fill(ds);

            dtAll = ds.Tables[0];

            foreach (DataColumn dc in dtAll.Columns)
            {
                Console.WriteLine("Column name: " + dc.ColumnName);
            }
            foreach (DataRow row in dtAll.Rows)
            {
                foreach (object o in row.ItemArray)
                {
                    Console.Write("Row data: " + o.ToString() + ", ");
                }
                Console.WriteLine();
            }
        }

        static void TestMSSQL(SqlConnection mssql_connection)
        {
            DataTable dTable = new DataTable();
            string query = "select * from component";
            SqlDataAdapter adapter = new SqlDataAdapter(query, mssql_connection);
            DataSet ds = new DataSet();
            adapter.Fill(ds);

            dTable = ds.Tables[0];
            foreach (DataColumn dc in dTable.Columns)
            {
                Console.WriteLine("Column name: " + dc.ColumnName);
            }
            foreach (DataRow row in dTable.Rows)
            {
                foreach (object o in row.ItemArray)
                {
                    Console.Write("Row data: " + o.ToString() + ", ");
                }
                Console.WriteLine();
            }
        }
    }
}