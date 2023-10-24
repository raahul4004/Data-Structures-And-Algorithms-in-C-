#include <iostream>
using namespace std;

class Cylinder
{
    private:
        double base_radius = 1;
        double height = 1;
    
    public:
    //Constructors
        Cylinder() = default;
        Cylinder(double base_radius, double height)
        {
            this->base_radius = base_radius;
            this->height = height;   
        }

    //Methods
        double volume()
        {
            return base_radius * height * 3.1415926535;
        }
    
    //Getter method
        double get_base_radius()
        {
            return base_radius;
        }

        double get_height()
        {
            return height;
        }

    //Setter method
        void set_base_radius(double new_base_radius)
        {
            base_radius = new_base_radius;
        }    

        void set_height(double new_height)
        {
            height = new_height;
        }
};

int main()
{
    Cylinder cyl(2,2);
    cout<<cyl.volume()<<endl;
    cout<<cyl.get_base_radius()<<endl;
    cout<<cyl.get_height()<<endl;

    return 0;
}

