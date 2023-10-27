using System.Collections.Generic;
using System.Net.Http;
using System.Text.Json;
using System.Text.Json.Serialization;
using Newtonsoft.Json;

namespace JsonClient
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            HttpClient client = new HttpClient();
            
            client.GetAsync("http://localhost:8080/JsonBar?name=maxime&surname=billy").ContinueWith(
                (requestTask) =>
                {
                    HttpResponseMessage response = requestTask.Result;
                    response.EnsureSuccessStatusCode();
                    Dictionary<string, string> answer = JsonConvert.DeserializeObject<Dictionary<string, string>>(response.Content.ReadAsStringAsync().Result);
                    foreach (KeyValuePair<string, string> entry in answer)
                    {
                        System.Console.WriteLine(entry.Key + " : " + entry.Value);
                    }
                });
        }
    }
}