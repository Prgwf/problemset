using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution
{

    static long minimumLossTLE(long[] price, int n)
    {
        // Complete this function
        long maxPrice = Math.Max(0, price[0]);
        long ret = long.MaxValue;

        SortedSet<long> st = new SortedSet<long>();
        st.Add(price[0]);
        for (int i = 1; i < n; ++i)
        {
            if (maxPrice > price[i])
            {
                int j = upper_bound(st, price[i]);
                long v = st.ElementAt(j);
                ret = Math.Min(ret, v - price[i]);
            }
            st.Add(price[i]);
            maxPrice = Math.Max(maxPrice, price[i]);
        }
        return ret;
    }
    static int lower_bound<T>(SortedSet<T> st, T value)
    {
        if (st == null)
        {
            throw new ArgumentNullException("set");
        }
        var comp = Comparer<T>.Default;
        int lb = 0, ub = st.Count - 1, ret = -1;
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (comp.Compare(st.ElementAt(mid), value) <= 0)
            {
                ret = mid;
                lb = mid + 1;
            }
            else
            {
                ub = mid - 1;
            }
        }
        return ret;
    }
    static int upper_bound<T>(SortedSet<T> st, T value)
    {
        if (st == null)
        {
            throw new ArgumentNullException("set");
        }
        var comp = Comparer<T>.Default;
        int lb = 0, ub = st.Count - 1, ret = -1;
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (comp.Compare(st.ElementAt(mid), value) > 0)
            {
                ret = mid;
                ub = mid - 1;
            }
            else
            {
                lb = mid + 1;
            }
        }
        return ret;
    }


    static void Main(String[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine());
        string[] price_temp = Console.ReadLine().Split(' ');
        long[] price = Array.ConvertAll(price_temp, Int64.Parse);
        long result = minimumLoss(price);
        Console.WriteLine(result);
    }

    static long minimumLoss(long[] price)
    {
        // Complete this function
        List<long> sortedPrice = price.ToList();
        Dictionary<long, int> idx = new Dictionary<long, int>();
        for (int i = 0; i < sortedPrice.Count; ++i)
        {
            idx.Add(sortedPrice[i], i);
        }
        sortedPrice.Sort();

        long ret = long.MaxValue;
        for (int i = 0; i + 1 < sortedPrice.Count; ++i)
        {
            long x = sortedPrice[i];
            long y = sortedPrice[i + 1];
            long sub = y - x;
            if (sub < ret && idx[y] < idx[x])
            {
                ret = sub;
            }
        }
        return ret;
    }


}
