#ifndef CLASSESTRING_HPP_INCLUDED
#define CLASSESTRING_HPP_INCLUDED
using namespace std;

class STRING{
    private:
        char* str;
        int tamanho;
    public:
        STRING();
        STRING(const char*);
        STRING(const STRING&);
        ~STRING();

        int getTamanho();

        friend ostream& operator<<(ostream&, const STRING&);
        friend istream& operator>>(istream&, STRING&);
        STRING operator+(const STRING&);
        STRING operator+(const char*);
        STRING operator+=(const char*);
        STRING operator+=(const STRING&);
        STRING operator=(const STRING&);
        bool operator!();
        bool operator==(const STRING&);
        bool operator!=(const STRING&);
        bool operator<(const STRING&);
        bool operator>(const STRING&);
        bool operator<=(const STRING&);
        bool operator>=(const STRING&);
        char operator[](int) const;
        char& operator[](int);
        void setString(const char*);

};


#endif // CLASSESTRING_HPP_INCLUDED
