using System.Collections.Generic;
using System.Drawing;
using System.IO;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace SequencePalletizer
{
    class Program
    {
        static void Main(string[] args)
        {
            var color_palette = new List<Color>();
            string name = null;
            string headerFilePath = Path.ChangeExtension(args[0], ".h");
            if (File.Exists(headerFilePath))
                File.Delete(headerFilePath);
            using (var headerFile = File.CreateText(headerFilePath))
            {
                using (var sequenzerFile = File.OpenText(args[0]))
                using (var sequencerFileReader = new JsonTextReader(sequenzerFile))
                {
                    dynamic root = (JObject)JToken.ReadFrom(sequencerFileReader);
                    name = root.name;
                    headerFile.WriteLine("#include \"Config.h\"");
                    headerFile.WriteLine();
                    headerFile.WriteLine("const PROGMEM sequence_t {0}_sequence = {{", name);
                    bool firstStep = true;
                    foreach (var step in root.steps)
                    {
                        if (!firstStep)
                            headerFile.WriteLine(", ");
                        else
                            firstStep = false;
                        headerFile.WriteLine("{");
                        var firstRow = true;
                        foreach (var row in step.frame)
                        {
                            if (!firstRow)
                                headerFile.WriteLine(", ");
                            else
                                firstRow = false;
                            headerFile.Write("  { ");
                            var firstPixel = true;
                            foreach (var pixel in row)
                            {
                                if (!firstPixel)
                                    headerFile.Write(", ");
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
                                headerFile.Write("0x{0:x2}", i);
                            }
                            headerFile.Write(" }");
                        }
                        headerFile.Write("}");
                    }
                    headerFile.WriteLine("};");
                    headerFile.WriteLine();
                }
                headerFile.WriteLine("const PROGMEM color_palette_t {0}_palette = {{", name);
                var firstColor = true;
                foreach (var c in color_palette)
                {
                    if (!firstColor)
                        headerFile.WriteLine(", ");
                    else
                        firstColor = false;
                    headerFile.Write("  {{ 0x{0:x2}, 0x{1:x2}, 0x{2:x2} }}", c.R, c.G, c.B);
                }
                headerFile.WriteLine("};");
            }
        }
    }
}
