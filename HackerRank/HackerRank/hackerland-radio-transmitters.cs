using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution
{

    static int hackerlandRadioTransmitters(int[] x, int n, int k)
    {
        // Complete this function
        Array.Sort(x);

        int ret = 0;
        for (int i = 0, j; i < n; i = j)
        {
            ++ret;

            int pos = x[i] + k;
            j = i;
            while (j < n && x[j] <= pos)
            {
                ++j;
            }
            int rig = x[j - 1] + k;
            while (j < n && x[j] <= rig)
            {
                ++j;
            }

            i = j;
        }
        return ret;
    }

    static void Main(String[] args)
    {
        string[] tokens_n = Console.ReadLine().Split(' ');
        int n = Convert.ToInt32(tokens_n[0]);
        int k = Convert.ToInt32(tokens_n[1]);
        string[] x_temp = Console.ReadLine().Split(' ');
        int[] x = Array.ConvertAll(x_temp, Int32.Parse);
        int result = hackerlandRadioTransmitters(x, n, k);
        Console.WriteLine(result);
    }
}
