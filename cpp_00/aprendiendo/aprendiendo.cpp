#include <iostream>


class Box
{
    public:
        int height;
        void get_width(int n);
        int show_width();
        Box(void);//constructor
        
    private:
        int width;
};
//definicion del constructor
Box::Box(void)
{
    std::cout << "Object is being created \n";
}
void  Box::get_width(int n)
{
    width = n;
}
int Box::show_width()
{
    return(width);
}

int main()
{
    Box box;
    box.get_width(5);
    std::cout << "Width is : " << box.show_width() << "\n";   
}
