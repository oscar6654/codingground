#define MAXLEN 128
#include <iostream>
//#include <string.h>
using namespace std;



class String
{
public:
	/// Both constructors should construct
	/// this String from the parameter s
	//char* x;
	int len;

	String(const char * s = "")
	{
		len = strlen(s);
		for (int i = 0; i < len; ++i)
		{
			buf[i] = s[i];
		}
	}
	String(const String & s)
	{
		len = s.len;
		for (int i = 0; i < len; ++i)
		{
			buf[i] = s.buf[i];
		}
	}
	String operator = (const String & s)
	{
	    len = s.len;
	    for (int i=0; i<len; ++i)
	    {
	        buf[i] = s.buf[i];
	    }
	    return *this;
	}
	char & operator [] (int index)
	{
	    if (index >= 0)
	    {
	        return buf[index];
	    }
	}
	
	int size();
	String reverse(); // does not modify this String
	int indexOf(const char c);
	int indexOf(const String pattern);
	bool operator == (const String s);
	bool operator != (const String s);
	bool operator > (const String s);
	bool operator < (const String s);
	bool operator <= (const String s);
	bool operator >= (const String s);
	/// concatenates this and s to return result
	String operator + (const String s);
	/// concatenates s onto end of this
	String operator += (const String s);
	void print(ostream & out)
	{
		for(int i=0; i<len; ++i)
		{
		    out << buf[i];
		}
	}
	void read(istream & in);
	//~String();
private:
	bool inBounds(int i)
	{
		return i >= 0 && i < strlen(buf);
	}// HINT: some C string primitives you should define and use
	static int strlen(const char *s)
	{
		int len = 0;
		for (int i = 0; s[i] != '\0'; ++i)
		{
			++len;
		}
		return len;
	}
	static char * strcpy(char *dest, const char *src)
	{
		int i;
		for (i = 0; src[i] != '\0'; ++i)
		{
			dest[i] = src[i];
		}
		dest[i] = '\0';
		return dest;
	}
	static char * strcat(char *dest, const char *src)
	{
		strcpy(dest + strlen(dest), src);
		return dest;
	}
	static int strcmp(const char *left, const char *right)
	{
		int i = 0;
		while (left[i] != '\0' || right[i] != '\0')
		{
			if (left[i] > right[i])
			{
				return 1;
			}
			if (left[i] < right[i])
			{
				return -1;
			}

			++i;
		}
		return 0;
	}
	static int strncmp(const char *left, const char *right, int n)
	{
	    int i = 0;
	    while(n)
	    {
	        if(left[i] < right[i])
	        {
	            return -1;
	        }
	        if(left[i] > right[i])
	        {
	            return 1;
	        }
	        --n;
	        ++i;
	    }
	    return 0;
	}
	static char * strchr(const char *str, int c);
	static char * strstr(const char *haystack, const char *needle);
	char buf[MAXLEN]; // array for the characters in this string
	// DO NOT store the ‘logical’ length of this string
	// use the null ‘\0’ terminator to mark the end
};
ostream & operator << (ostream & out, String str)
{
    str.print(out);
    return out;
}
istream & operator >> (istream & in, String & str);



int main()
{
	String a = "Hello";
	cout << a;
	cout << a[2];
}