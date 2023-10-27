using System;
using System.Collections.Generic;
using System.Configuration;
using System.Diagnostics;
using System.Text.Json;

namespace BasicServerHTTPlistener
{
    public class Foo
    {
        public string Bar(String name, String surname)
        {
            return "<html><body><h1>Hello " + name + " " + surname + "</h1></body></html>";
        }

        public string FooBar(String name, String surname)
        {
            // Call the executable and return the result
            ProcessStartInfo start = new ProcessStartInfo();
            start.FileName = "/Users/ozeliurs/Desktop/Polytech/EIENMI7/Labs/TD1 - CS/ExecTest/bin/Debug/ExecTest.exe"; // Specify exe name.
            start.Arguments = name + " " + surname; // Specify arguments.
            start.UseShellExecute = false;
            start.RedirectStandardOutput = true;

            // Start the process.
            using (Process process = Process.Start(start))
            {
                //
                // Read in all the text from the process with the StreamReader.
                //
                if (process != null)
                    using (System.IO.StreamReader reader = process.StandardOutput)
                    {
                        string result = reader.ReadToEnd();
                        return result;
                    }
                else
                {
                    return "Error";
                }
            }
        }

        public string BarFoo(String name, String surname)
        {
            // call python script
            ProcessStartInfo start = new ProcessStartInfo();
            start.FileName = "/opt/homebrew/bin/python3"; // Specify exe name.
            start.Arguments = "\"/Users/ozeliurs/Desktop/Polytech/EIENMI7/Labs/TD1 - CS/ExecTest/main.py\" " + name + " " + surname; // Specify arguments.
            start.UseShellExecute = false;
            start.RedirectStandardOutput = true;
            
            // Start the process.
            using (Process process = Process.Start(start))
            {
                //
                // Read in all the text from the process with the StreamReader.
                //
                if (process != null)
                    using (System.IO.StreamReader reader = process.StandardOutput)
                    {
                        string result = reader.ReadToEnd(); 
                        return result;
                    }
                else
                {
                    return "Error";
                }
            }
        }

        public string JsonBar(String name, String surname)
        {
            // create dict with the parameters
            Dictionary<string, string> parameters = new Dictionary<string, string>();
            parameters.Add("name", name);   
            parameters.Add("surname", surname);
            
            //return json of the dict;
            return JsonSerializer.Serialize(parameters);
        }
    }
}