using System;
using System.Linq;

namespace _7
{
    class _7
    {
        public static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' '); ;
            int[] data  = str.Select(Int32.Parse).ToArray();

            int m = data[0];
            int n = data[1];
            int x1 = data[2];
            int y1 = data[3];
            int x2 = data[4];
            int y2 = data[5];

            if (Math.Abs(x1 - x2) == Math.Abs(y1 - y2))
                Console.WriteLine("NO");
            else
                Console.WriteLine("YES");
        }
    }
}