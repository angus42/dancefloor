using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System.Text;

namespace AlphabetCompiler
{
    class Program
    {
        static void Main(string[] args)
        {
            string sourceFile = "Alphabet.dfs";
            var headerFilePath = @"..\..\..\Alphabet.h";
            if (File.Exists(headerFilePath))
                File.Delete(headerFilePath);
            using (var headerFile = File.CreateText(headerFilePath))
            {
                using (var sequencerFile = File.OpenText(sourceFile))
                using (var sequencerFileReader = new JsonTextReader(sequencerFile))
                {
                    dynamic root = (JObject)JToken.ReadFrom(sequencerFileReader);
                    headerFile.WriteLine("#include \"Config.h\"");
                    headerFile.WriteLine();
                    // FIXME: hacked in number of pixel per row (= stripes)
                    headerFile.WriteLine("const PROGMEM byte alphabet[][5] = {");
                    var firstStep = true;
                    byte asciiChar = 32 - 1;
                    foreach (var step in root.steps)
                    {
                        // a step equals a letter
                        asciiChar++;
                        if (!firstStep)
                            headerFile.WriteLine(",");
                        else
                            firstStep = false;
                        headerFile.Write("{ // ");
                        headerFile.Write(Encoding.ASCII.GetChars(new[] { asciiChar }));
                        headerFile.WriteLine();
                        var firstStripe = true;
                        int stripe = 0;
                        while (true)
                        {
                            if (!firstStripe)
                                headerFile.WriteLine(", ");
                            else
                                firstStripe = false;
                            headerFile.Write("  B");
                            // we rotate each letter 90° clockwise.
                            // this gives us vertical stripes of the letters with the LSB beeing the uppermost pixel.
                            // rows become the bits in the stripe.
                            for (int b = 7; b >= 0; b--)
                            {
                                if (step.frame.Count <= b)
                                {
                                    headerFile.Write("0");
                                }
                                else
                                {
                                    var row = step.frame[b];
                                    var pixel = row[stripe ];
                                    var v = pixel.v.ToString();
                                    var c = ColorTranslator.FromHtml(v);
                                    headerFile.Write(c.GetBrightness() < 0.5 ? "0" : "1");
                                }
                            }
                            stripe++;
                            if (step.frame[0].Count <= stripe)
                            {
                                stripe = -1;
                                break;
                            }
                        }
                        headerFile.Write("}");
                    }
                    headerFile.WriteLine("};");
                }
            }
        }
    }
}
