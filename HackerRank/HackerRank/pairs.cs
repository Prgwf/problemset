using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution
{

    static int pairs(int k, int[] arr, int n)
    {
        // Complete this function

        Dictionary<int, int> cnt = new Dictionary<int, int>();
        foreach (int x in arr)
        {
            if (cnt.ContainsKey(x))
            {
                cnt[x]++;
            }
            else
            {
                cnt.Add(x, 1);
            }
        }
        int ret = 0;
        foreach (int x in arr)
        {
            if (cnt.ContainsKey(x - k))
            {
                ret += cnt[x - k];
            }
        }
        return ret;
    }

    static void Main(String[] args)
    {
        string[] tokens_n = Console.ReadLine().Split(' ');
        int n = Convert.ToInt32(tokens_n[0]);
        int k = Convert.ToInt32(tokens_n[1]);
        string[] arr_temp = Console.ReadLine().Split(' ');
        int[] arr = Array.ConvertAll(arr_temp, Int32.Parse);
        int result = pairs(k, arr, n);
        Console.WriteLine(result);
    }
}
