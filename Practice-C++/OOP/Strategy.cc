/*
 * Strategy Design pattern.
 * Idea from :
 * http://www.newthinktank.com/2012/08/strategy-design-pattern-tutorial/
 */
#include <iostream>
using namespace std;

// Abstract class/ Interface
// Shows the Method
class Flys {
public:
	virtual string fly() = 0;
protected:
	Flys() {}
	virtual ~Flys() {}
};

// Concrete classes ---
// These classes implements the specific methods 
class CantFly: public Flys {
public:
	string fly() {
		return "Can't Fly!!";
	}
};
class CanFly: public Flys {
public:
	string fly() {
		return "Can Fly HIGH!!";
	}
};
// End of Concrete classes --- 


class Animal {
protected:
	Flys* flyingType;
public:
	void setFlyingType(Flys* newFlyType) {
		flyingType = newFlyType;
	}
	string tryToFly() {
		return flyingType->fly();
	}
};

class Dog : public Animal {
public:
	Dog() {
		flyingType = new CantFly();
	}
};

class Bird : public Animal{
public:
	Bird() {
		flyingType = new CanFly();
	}
};

int main () {
	Animal *corgi = new Dog() ;
	Animal *hummingBird = new Bird();
	cout << "Corgi: " << corgi->tryToFly() << endl;
	cout << "Humming Bird: " << hummingBird->tryToFly() << endl;
	
	// Now Dynamically make our corgi Fly
	corgi->setFlyingType(new CanFly());
	cout << "Corgi: " << corgi->tryToFly() << endl;
	return 0;
}


