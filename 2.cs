using System;
using System.Linq;

namespace _2
{
    class Program
    {
        public static void Main(string[] args)
        {
            int N = Convert.ToInt32(Console.ReadLine());
            string[] str = Console.ReadLine().Split(' ');
            long[] elements = str.Select(long.Parse).ToArray();     

            Array.Sort(elements);

            long maxComb1 = elements[0] * elements[1];
            long maxComb2 = elements[N - 1] * elements[N - 2];

            if (maxComb1 > maxComb2)
                Console.WriteLine(maxComb1);
            else
                Console.WriteLine(maxComb2);
        }
    }
}