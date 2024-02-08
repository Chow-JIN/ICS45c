#include <iostream>
#include "string.hpp"

using namespace std;




//constructor-----------------------------------
String::String(const char *s)
{
   buf = strdup(s);
}


//copy---------------------------------
String::String(const String &s)
{
    buf = strdup(s.buf);
}


String::String(String &&s)
{
	buf = s.buf;
	s.buf = nullptr;

}


String::String(int len)
{
	buf = new char[len + 1];
}



void String::swap(String &s)
{
	std::swap(buf, s.buf);
}




String & String::operator =(const String &s)
{
    if (this != &s) {
        delete[] buf;
    }
	if (this == &s) {
		return *this;
	}
	buf = strdup(s.buf);
    return *this;
}


String & String::operator =(String &&s)
{
	if (this != &s) {
        delete[] buf;
		buf = s.buf;
		s.buf = nullptr;
    }
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


const char & String::operator[](int index) const
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
    String result(strlen(buf));
    reverse_cpy(result.buf, buf);
    return result;
}


int String::indexOf(char c) const
{
    const char *p = strchr(buf, c);
    if (p == nullptr)
        return -1;
    return p - buf;
}


int String::indexOf(String s) const
{
    const char *p = strstr(buf, s.buf);
    if (p == nullptr)
        return -1;
    return p - buf;
}





bool String::operator==(String s) const
{
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(String s) const
{
    return strcmp(buf, s.buf) != 0;
}

bool String::operator>(String s) const
{
    return strcmp(buf, s.buf) > 0;
}

bool String::operator<(String s) const
{
    return strcmp(buf, s.buf) < 0;
}

bool String::operator<=(String s) const
{
    return strcmp(buf, s.buf) <= 0;
}

bool String::operator>=(String s) const
{
    return strcmp(buf, s.buf) >= 0;
}

String String::operator+(String s) const
{
    String result(strlen(buf) + strlen(s.buf));
    strcpy(result.buf, buf);
    strcat(result.buf, s.buf);
    return result;
}

String & String::operator+=(String s)
{
	String bbb = *this + s;
	swap(bbb);
	return *this;
}






void String::print(ostream &out) const
{
    out << buf;
}

void String::read(istream &in)
{
    char BUF[6666];
    in >> BUF;
    BUF[strlen(BUF) - 1] = '\0';
    String tra(BUF);
    swap(tra);

}

String::~String() {
	delete[] buf;
}




//~~~~~~~~~print operator~~~~~~~~~~~

ostream &operator <<(ostream &out, String s)
{
    s.print(out);
    return out;
}

istream &operator >>(istream &in, String &s)
{
    s.read(in);
    return in;
}



//~~~~~~~~~~helper method~~~~~~~~~~~~~~~

char *String::strdup(const char *s)
{
	return strcpy(new char[strlen(s) + 1], s);
}





int String::strlen(const char *s)
{
        int i;
    for (i = 0; s[i] != '\0'; ++i) {}
    return i;
}

char *String::strcpy(char *dest, const char *s)
{
        int i;
    for (i = 0; s[i] != '\0'; ++i)
        dest[i] = s[i];
    dest[i] = '\0';
    return dest;
}

char *String::strncpy(char *dest, const char *s, int n )
{
        int i = 0;
    for ( ; s[i] != '\0' && i < n; ++i)
        dest[i] = s[i];
    dest[i] = '\0';
    return dest;
}

char *String::strcat(char *dest, const char *s)
{
        int i = 0;
    int len = strlen(dest);
    for ( ; s[i] != '\0'; ++i)
        dest[len+i] = s[i];
    dest[len+i] = '\0';
    return dest;
}

char *String::strncat(char *dest, const char *s, int n)
{
    int i = 0;
    int len = strlen(dest);
	for ( ; s[i] != '\0' && i < n; ++i)
        dest[len+i] = s[i];
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

void String::reverse_cpy(char *dest, const char *s)
{
        int i = 0;
    int len = strlen(s);
    for ( ; s[i] != '\0'; ++i)
        dest[len-1-i] = s[i];
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


