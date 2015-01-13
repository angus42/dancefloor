using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;

namespace SequencePalletizer
{
    class Program
    {
        static void Main(string[] args)
        {
            var color_palette = new List<Color>();
            using (StreamReader file = File.OpenText(args[0]))
            using (JsonTextReader reader = new JsonTextReader(file))
            {
                dynamic root = (JObject)JToken.ReadFrom(reader);
                var name = root.name;
                Console.WriteLine(name);
                foreach (var step in root.steps)
                {
                    Console.WriteLine("{");
                    foreach (var row in step.frame)
                    {
                        Console.Write("{ ");
                        bool first = true;
                        foreach (var pixel in row)
                        {
                            if (!first)
                                Console.Write(", ");
                            else
                                first = false;
                            var v = pixel.v.ToString();
                            var c = System.Drawing.ColorTranslator.FromHtml(v);
                            var i = color_palette.IndexOf(c);
                            if (i < 0)
                            {
                                color_palette.Add(c);
                                i = color_palette.Count - 1;
                            }
                            Console.Write("0x{0:x2}", i);
                        }
                        Console.Write(" }");
                        Console.WriteLine();
                    }
                    Console.Write("}");
                    Console.WriteLine();
                }
                Console.WriteLine();
                Console.WriteLine();
            }
            foreach (var c in color_palette)
            {
                Console.WriteLine("{{ {0:x2}, {1:x2}, {2:x2} }}", c.R, c.G, c.B);
            }
            Console.ReadLine();
        }
    }
}
