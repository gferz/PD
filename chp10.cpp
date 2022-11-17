#include <iostream>
#include <map>
#include <string>

class romanType
{
    private:
        std::string roman;
    public:
        romanType(std::string); //constructor

        std::string get_roman();
        int decimal();
        void print_roman();
        void print_decimal();
};

int main(int argc, const char* argv[])
{
    std::string input;

    std::cout << "Input roman : ";
    std::cin >> input;

    romanType rom(input);

    if(rom.decimal()==-1)
    {
        std::cout << "Roman tidak valid" << std::endl;
        return 0;
    }

    input = "A";
    while(input!="R" && input!="D")
    {
        std::cout << "Ingin menampilkan roman atau decimal(R/D): ";
        std::cin >> input;

        if(input!="R" && input!="D")
        {
            std::cout << "Input tidak valid\n";
        }
    }

    if(input=="R")
    {
        rom.print_roman();
    }
    else
    {
        rom.print_decimal();
    }
    std::cout << std::endl;

    return 0;
}

romanType::romanType(std::string input)
{
    this->roman = input;
}

std::string romanType::get_roman()
{
    return this->roman;
}

int romanType::decimal()
{
    std::string str(this->roman);

    std::map<char, int> m;
    m.insert({ 'I', 1 });
    m.insert({ 'V', 5 });
    m.insert({ 'X', 10 });
    m.insert({ 'L', 50 });
    m.insert({ 'C', 100 });
    m.insert({ 'D', 500 });
    m.insert({ 'M', 1000 });
    int sum = 0;

    int count = 1; char temp;
    for (int i = 0; i < str.length(); i++)
    {
        //check pengulangan, simbol tidak boleh diulang 3x dalam aturan roman
        if(temp==str[i])
        {
            count++;
        }
        else
        {
            temp = str[i];
            count = 1;
        }

        if(count==4)
        {
            return -1;
        }
        //end check

        if(m[str[i]]==0) //jika input selain dari I,V,X,L,C,D,M maka tidak valid
        {
            return -1;
        }
        
        if(m[str[i]] < m[str[i + 1]])
        {
            sum+=m[str[i+1]]-m[str[i]];
            i++;
            continue;
        }
        sum += m[str[i]];
    }
    return sum;
}

void romanType::print_roman()
{
    std::cout << "Roman: " << this->roman;
}

void romanType::print_decimal()
{
    std::cout << "Desimal: " << this->decimal();
}