#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <cstdlib>
#include "../PatternSearchingLib/PatternSearchingLib.h"
#include "../benchmark/benchmark.h"

class CustomChar{
private:
    friend std::istream &operator>>( std::istream  &input, CustomChar &Char );
    char character;
    static bool performDelay;
    void delay() const{
        if (performDelay)
            std::this_thread::sleep_for(std::chrono::milliseconds (1));
    }

public:
    CustomChar() = default;

    CustomChar(char ch) : character(ch){};

    unsigned long getChar() const
    {
        return character;
    }

    static void delayOn()
    {
        performDelay = true;
    }

    static void delayOff()
    {
        performDelay = false;
    }

    bool operator==(CustomChar const& Chr) const
    {
        delay();
        return character == Chr.character;
    }

    bool operator!=(CustomChar const& Chr) const
    {
        delay();
        return character != Chr.character;
    }

    int operator*(int const& value){
        delay();
        auto newValue = int(character)*value;
        return newValue;
    }

    int operator/(int const& value){
        delay();
        auto newValue = int(character)/value;
        return newValue;
    }

    int operator+(int const& value){
        delay();
        auto newValue = int(character)+value;
        return newValue;
    }

    int operator-(int const& value){
        delay();
        auto newValue = int(character)-value;
        return newValue;
    }

    int operator%(int const& value){
        delay();
        auto newValue = int(character)%value;
        return newValue;
    }



};
bool CustomChar::performDelay = false;

std::ostream& operator << (std::ostream& stream, CustomChar const& obj)
{
    stream << obj.getChar();
    return stream;
}
std::istream &operator>>( std::istream  &input, CustomChar &Char )
{
    char character;
    input >> character;

    Char = CustomChar(character);
    return input;
}


int main(){
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator((unsigned long)seed);

    size_t t_size = 100;
    size_t p_size = 5;


    while(t_size <= 2000) {
        CustomChar::delayOff();
        std::vector<CustomChar> text;
        std::vector<CustomChar> pattern;

        for (int i=0; i<t_size; i++){
            unsigned long n = generator();
            char x = char(65 + n%26);
            CustomChar cChar(x);
            text.push_back(cChar);
        }

        for (int i=0; i<p_size; i++){
            unsigned long n = generator();
            char x = char(65 + n%26);
            CustomChar cChar(x);
            pattern.push_back(cChar);
        }

        CustomChar::delayOn();

        Benchmark<std::chrono::nanoseconds> b;
        std::vector<int> output = NaiveSearch(pattern, text);
        std::cout<<b.elapsed()<<" ";

        Benchmark<std::chrono::nanoseconds> c;
        std::vector<int> output1 = KMPSearch(pattern, text);
        std::cout<<c.elapsed()<<" ";

        Benchmark<std::chrono::nanoseconds> a;
        std::vector<int> output2 = RKSearch(pattern, text, 13);
        std::cout<<a.elapsed()<<std::endl;

        t_size+=100;
        p_size+=5;
    }
    return 0;

}