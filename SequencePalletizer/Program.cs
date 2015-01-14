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
            string name = null;
            using (StreamReader file = File.OpenText(args[0]))
            using (JsonTextReader reader = new JsonTextReader(file))
            {
                dynamic root = (JObject)JToken.ReadFrom(reader);
                name = root.name;
                Console.WriteLine("#include \"Config.h\"");
                Console.WriteLine();
                Console.WriteLine("const PROGMEM sequence_t {0}_sequence = {{", name);
                bool firstStep = true;
                foreach (var step in root.steps)
                {
                    if (!firstStep)
                        Console.WriteLine(", ");
                    else
                        firstStep = false;
                    Console.WriteLine("{");
                    bool firstRow = true;
                    foreach (var row in step.frame)
                    {
                        if (!firstRow)
                            Console.WriteLine(", ");
                        else
                            firstRow = false;
                        Console.Write("  { ");
                        bool firstPixel = true;
                        foreach (var pixel in row)
                        {
                            if (!firstPixel)
                                Console.Write(", ");
                            else
                                firstPixel = false;
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
                    }
                    Console.Write("}");
                }
                Console.WriteLine("};");
                Console.WriteLine();
            }
            Console.WriteLine("const PROGMEM color_palette_t {0}_palette = {{", name);
            bool firstColor = true;
            foreach (var c in color_palette)
            {
                if (!firstColor)
                    Console.WriteLine(", ");
                else
                    firstColor = false;
                Console.Write("  {{ 0x{0:x2}, 0x{1:x2}, 0x{2:x2} }}", c.R, c.G, c.B);
            }
            Console.WriteLine("};");
            Console.ReadLine();
        }
    }
}
