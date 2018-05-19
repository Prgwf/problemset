#include <iostream>
#include <cstdio>

const long long MAXI = 1e9+7;

struct sec
{
	int l, r;
	long long len;
};

struct sec mix(sec a, sec b)
{
	struct sec c;

	if (a.len <= 0 || b.len <= 0)
	{
		c.l = c.r = -1;
		c.len = 0;
		return c;
	}
	else if (b.r < a.l || b.l > a.r)
	{
		c.l = c.r = -1;
		c.len = 0;
		return c;
	}
	else if (b.r <= a.r)
	{
		if (b.l < a.l)
		{
			c.l = a.l;
			c.r = b.r;
			c.len = c.r - c.l + 1;
			return c;
		}
		else return b;
	}
	else
	{
		if (b.l < a.l) return a;
		else
		{
			c.l = b.l;
			c.r = a.r;
			c.len = c.r - c.l + 1;
			return c;
		}
	}
}

int main ()
{
	int t;
	long long num;
	struct sec s1, s2, s3, s4, s12, s13, s14, s23, s24, s34, s123, s124, s134, s234, s1234;

	scanf("%d", &t);
	for(;t;t--)
	{
		scanf("%d%d%d%d%d%d%d%d", &s1.l, &s1.r, &s2.l, &s2.r, &s3.l, &s3.r, &s4.l, &s4.r);
		s1.len = s1.r - s1.l + 1;
		s2.len = s2.r - s2.l + 1;
		s3.len = s3.r - s3.l + 1;
		s4.len = s4.r - s4.l + 1;
		s12 = mix(s1, s2);
		s13 = mix(s1, s3);
		s14 = mix(s1, s4);
		s23 = mix(s2, s3);
		s24 = mix(s2, s4);
		s34 = mix(s3, s4);
		s123 = mix(s12, s13);
		s124 = mix(s12, s14);
		s134 = mix(s13, s14);
		s234 = mix(s23, s24);
		s1234 = mix(s123, s124);
		num = (s1.len * s2.len % MAXI) * (s3.len * s4.len % MAXI) % MAXI
			- s12.len * s3.len % MAXI * s4.len % MAXI - s14.len * s2.len % MAXI * s3.len % MAXI
			- s23.len * s1.len % MAXI * s4.len % MAXI - s34.len * s1.len % MAXI * s2.len % MAXI
			+ s12.len * s34.len % MAXI + s14.len * s23.len % MAXI
			+ s123.len * s4.len % MAXI + s124.len * s3.len % MAXI
			+ s134.len * s2.len % MAXI + s234.len * s1.len % MAXI
			- 3LL * s1234.len;
		num %= MAXI;
    num = (num + MAXI) % MAXI;
		printf("%lld\n", num);
	}

	return 0;
}
