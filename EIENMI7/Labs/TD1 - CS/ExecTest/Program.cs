using System;

namespace ExeTest
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length == 2)
                Console.WriteLine("<html><body><h1>Hello " + args[0] + " " + args[1] + "</h1></body></html>");
            else
                Console.WriteLine("ExeTest <string parameter>");
        }
    }
}
