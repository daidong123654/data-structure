#include<iostream>
using namespace std;
class Animal
{
    public:
        void eat()
        {
            cout << "Animal eat" <<endl;
        }
    protected:
        void sleep()
        {
            cout << "Animal sleep" <<endl;
        }
        void breath()
        {
            cout << "Animal breath" <<endl;
        }
};
class fish : public Animal
{
    void test()
    {
        sleep();
        breath();
    }

};
int main()
{
    Animal an;
    fish fs;
    an.eat();
    //fs.test;
    //fs.breath();
    //an.sleep();
}
