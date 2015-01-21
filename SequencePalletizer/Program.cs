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
            string name = null;
            bool xfade = false;
            int frame_count = 0;
            var color_palette = new List<Color>();
            var headerFilePath = Path.ChangeExtension(args[0], ".h");
            if (File.Exists(headerFilePath))
                File.Delete(headerFilePath);
            using (var headerFile = File.CreateText(headerFilePath))
            {
                using (var sequencerFile = File.OpenText(args[0]))
                using (var sequencerFileReader = new JsonTextReader(sequencerFile))
                {
                    dynamic root = (JObject)JToken.ReadFrom(sequencerFileReader);
                    name = root.name;
                    xfade = root.xfade ?? false;
                    headerFile.WriteLine("#include \"Config.h\"");
                    headerFile.WriteLine();
                    headerFile.WriteLine("const PROGMEM palette_sequence_t {0}_sequence = {{", name);
                    var firstStep = true;
                    foreach (var step in root.steps)
                    {
                        frame_count++;
                        if (!firstStep)
                            headerFile.WriteLine(",");
                        else
                            firstStep = false;
                        headerFile.Write("{");
                        headerFile.WriteLine();
                        var firstRow = true;
                        foreach (var row in step.frame)
                        {
                            if (!firstRow)
                                headerFile.WriteLine(", ");
                            else
                                firstRow = false;
                            headerFile.Write("  ");
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
                        }
                        headerFile.WriteLine();
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
                headerFile.WriteLine();
                headerFile.WriteLine("const palette_sequence_data_t {0}_program = {{ (byte*)&{0}_sequence, {1}, (byte*)&{0}_palette, {2} }};", name, frame_count, xfade ? "true" : "false");
            }
        }
    }
}
