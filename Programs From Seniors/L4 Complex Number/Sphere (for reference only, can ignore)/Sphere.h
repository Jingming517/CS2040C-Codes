using namespace std;
const double PI = 3.14159;

class Sphere {
public:
   Sphere();
      // Default constructor: Creates a sphere and
      // initializes its radius to a default value.
      // Precondition: None.
      // Postcondition: A sphere of radius 1 created.
   Sphere(double initialRadius);
      // Constructor: Creates a sphere and initializes its radius.
      // Precondition: initialRadius is the desired radius.
      // Postcondition: A sphere of radius initialRadius created.
   void setRadius(double newRadius);
      // Sets (alters) the radius of an existing sphere.
      // Precondition: newRadius is the desired radius.
      // Postcondition: The sphere�s radius is newRadius.
   double getRadius() const;
      // Determines a sphere's radius.
      // Precondition: None.
      // Postcondition: Returns the radius.
   double getDiameter() const;
       // Determines a sphere's diameter.
       // Precondition: None.
       // Postcondition: Returns the diameter.
   double getCircumference() const;
      // Determines a sphere's circumference.
      // Precondition: PI is a named constant.
      // Postcondition: Returns the circumference.
   double getArea() const;
      // Determines a sphere's surface area.
      // Precondition: PI is a named constant.
      // Postcondition: Returns the surface area.
   double getVolume() const;
      // Determines a sphere's volume.
      // Precondition: PI is a named constant.
      // Postcondition: Returns the volume.
   void displayStatistics() const;
      // Displays statistics of a sphere.
      // Precondition: None.
      // Postcondition: Displays the radius, diameter,
      // circumference, area, and volume.

private:
   double theRadius; // the sphere�s radius
}; // end class

