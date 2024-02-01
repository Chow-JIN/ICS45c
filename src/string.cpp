#include <iostream>
#include "string.hpp"

using namespace std;





String::String(const char *s)
{
    strncpy(buf, s, MAXLEN-1);
}



String::String(const String &s)
{
    strcpy(buf, s.buf);
}



String & String::operator =(const String &s)
{
    strcpy(buf, s.buf);
    return *this;
}



char & String::operator [](int index)
{
    if (!in_bounds(index))
    {
        cout << "ERROR: Index Out Of Bounds" << endl;
        return buf[0];
    }else{
        return buf[index];
    }
}




int String::size() const
{
    return strlen(buf);
}

String String::reverse() const
{
    String output;
    reverse_cpy(output.buf, buf);
    return output;
}

int String::indexOf(char c) const
{
    const char *p = strchr(buf, c);
    if (p == nullptr)
        return -1;
    return p - buf;
}

int String::indexOf(const String &s) const
{
    const char *p = strstr(buf, s.buf);
    if (p == nullptr)
        return -1;
    return p - buf;
}

bool String::operator==(const String &s) const
{
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String &s) const
{
    return strcmp(buf, s.buf) != 0;
}

bool String::operator>(const String &s) const
{
    return strcmp(buf, s.buf) > 0;
}

bool String::operator<(const String &s) const
{
    return strcmp(buf, s.buf) < 0;
}

bool String::operator<=(const String &s) const
{
    return strcmp(buf, s.buf) <= 0;
}

bool String::operator>=(const String &s) const
{
    return strcmp(buf, s.buf) >= 0;
}

String String::operator+(const String &s) const
{
    String output = String(buf);
    int len = output.size();
   	// if ( (len + s.size()) > MAXLEN-1)
       // cout << "ERROR: String Capacity Exceeded." << endl; 
    strncat(output.buf, s.buf, MAXLEN-1-len);
    return output;
}

String & String::operator+=(const String &s)
{
    int len = size();
    String output = String(s.buf);
    strncat(buf, output.buf, MAXLEN-1-len);
    return *this;
}

void String::print(ostream &out) const
{
    out << buf;
}

void String::read(istream &in)
{
    in >> buf;
    buf[MAXLEN-1] = '\0';
}

String::~String() {}



ostream &operator <<(ostream &out, const String &s)
{
    s.print(out);
	return out;
}

istream &operator >>(istream &in, String &s)
{
	s.read(in);
	return in;
}



int String::strlen(const char *s)
{
	int i;
    for (i = 0; s[i] != '\0'; ++i) {}
    return i;
}

char *String::strcpy(char *dest, const char *src)
{
	int i;
    for (i = 0; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *String::strncpy(char *dest, const char *src, int n )
{
	int i = 0;
    for ( ; src[i] != '\0' && i < n; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *String::strcat(char *dest, const char *src)
{
	int i = 0;
    int len = strlen(dest);
    for ( ; src[i] != '\0'; ++i)
        dest[len+i] = src[i];
    dest[len+i] = '\0';
    return dest;
}

char *String::strncat(char *dest, const char *src, int n)
{
	int i = 0;
    int len = strlen(dest);
    for ( ; src[i] != '\0' && i < n; ++i)
        dest[len+i] = src[i];
    dest[len+i] = '\0';
    return dest;
}

int String::strcmp(const char *left, const char *right)
{
	int i = 0;
    for ( ; right[i] != '\0'; ++i)
        if (left[i] != right[i])
            break;
    return left[i] - right[i];
}

int String::strncmp(const char *left, const char *right, int n)
{
	int i = 0;
    for( ; i < n; ++i)
        if (left[i] != right[i] || (left[i] == '\0' && right[i] == '\0'))
            return left[i] - right[i];
    return 0;
}

void String::reverse_cpy(char *dest, const char *src)
{
	int i = 0;
    int len = strlen(src);
    for ( ; src[i] != '\0'; ++i)
        dest[len-1-i] = src[i];
    dest[i] = '\0';
}


const char *String::strchr(const char *str, char c)
{
	const char *i;
    for (i = str; *i != '\0'; ++i)
        if (*i == c)
            return i;
    if (c == '\0')
        return i;
    return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle)
{   
    if (strlen(needle) == 0)
        return haystack;
    int len = strlen(needle);
    for(const char *i = haystack; (i = strchr(i, needle[0])); ++i)
        if(strncmp(i, needle, len) == 0)
            return i;
    return nullptr;
}
