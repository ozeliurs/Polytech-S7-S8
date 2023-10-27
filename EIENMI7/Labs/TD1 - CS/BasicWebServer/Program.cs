using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Reflection;
using System.Text;
using System.Web;

namespace BasicServerHTTPlistener
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //if HttpListener is not supported by the Framework
            if (!HttpListener.IsSupported)
            {
                Console.WriteLine("A more recent Windows version is required to use the HttpListener class.");
                return;
            }


            // Create a listener.
            HttpListener listener = new HttpListener();

            // Add the prefixes.
            if (args.Length != 0)
            {
                foreach (string s in args)
                {
                    listener.Prefixes.Add(s);
                    // don't forget to authorize access to the TCP/IP addresses localhost:xxxx and localhost:yyyy 
                    // with netsh http add urlacl url=http://localhost:xxxx/ user="Tout le monde"
                    // and netsh http add urlacl url=http://localhost:yyyy/ user="Tout le monde"
                    // user="Tout le monde" is language dependent, use user=Everyone in english 
                }
            }
            else
            {
                Console.WriteLine("Syntax error: the call must contain at least one web server url as argument");
            }

            listener.Start();

            // get args 
            foreach (string s in args)
            {
                Console.WriteLine("Listening for connections on " + s);
            }

            // Trap Ctrl-C on console to exit 
            Console.CancelKeyPress += delegate
            {
                // call methods to close socket and exit
                listener.Stop();
                listener.Close();
                Environment.Exit(0);
            };

            // Instanciate a Foo object
            Foo foo = new Foo();


            while (true)
            {
                // Note: The GetContext method blocks while waiting for a request.
                HttpListenerContext context = listener.GetContext();
                HttpListenerRequest request = context.Request;

                string documentContents;
                using (Stream receiveStream = request.InputStream)
                {
                    using (StreamReader readStream = new StreamReader(receiveStream, Encoding.UTF8))
                    {
                        documentContents = readStream.ReadToEnd();
                    }
                }

                // Reflectively call the methods inside the Foo object
                // /<method_name>?<param1_name>=<param1_value>&<param2_name>=<param2_value>&...
                Type type = typeof(Foo);

                // if there is more than one path in the url, throw
                if (request.Url.LocalPath.Split('/').Length > 2)
                {
                    throw new Exception("Too many paths in the url");
                }

                MethodInfo method = type.GetMethod(request.Url.LocalPath.Substring(1));

                // if there is no method with the name in the url, throw
                if (method == null)
                {
                    throw new Exception("No method with this name");
                }

                // if there is less or more than two parameters in the url, throw
                if (request.Url.Query.Substring(1).Split('&').Length != 2)
                {
                    throw new Exception("Wrong number of parameters");
                }

                object[] parameters = new Object[2];
                parameters[0] = request.Url.Query.Substring(1).Split('&')[0].Split('=')[1];
                parameters[1] = request.Url.Query.Substring(1).Split('&')[1].Split('=')[1];
                    
                String answer = (string) method.Invoke(foo, parameters);
                
                
                // create a dictionary with the parameters and their values
                //Dictionary<string, string> parameters = new Dictionary<string, string>();
                //foreach (string param in request.Url.Query.Substring(1).Split('&'))
                //{
                //    parameters.Add(param.Split('=')[0], param.Split('=')[1]);
                //}
                
                // call the method with the parameters
                //String answer = (string) method.Invoke(foo, new object[] {parameters["name"], parameters["surname"]});
                
                Console.WriteLine(answer);

                // Obtain a response object.
                HttpListenerResponse response = context.Response;

                // Construct a response.
                byte[] buffer = System.Text.Encoding.UTF8.GetBytes(answer);

                // Get a response stream and write the response to it.
                response.ContentLength64 = buffer.Length;
                System.IO.Stream output = response.OutputStream;
                output.Write(buffer, 0, buffer.Length);

                // You must close the output stream.
                output.Close();
            }
            // Httplistener neither stop ... But Ctrl-C do that ...
            // listener.Stop();
        }
    }
}