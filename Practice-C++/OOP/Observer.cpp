/**
 * Observer Design Pattern.
 * Idea from:  https://www.youtube.com/watch?v=wiQdrH2YpT4&list=PLF206E906175C7E07&index=4
 * 	       http://www.newthinktank.com/2012/08/observer-design-pattern-tutorial/
 */

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// Subscriber Interface 
class Observer {
public:
	virtual void update (double ibmPrice, double aaplPrice,
			double googPrice) = 0;
protected:
	Observer() {}
	virtual ~Observer() {}
};

// Publisher Interface
class Subject {
public:
	virtual void registerObserver(Observer *o) = 0;
	virtual void unregisterObserver(Observer *o) = 0;
	virtual void notifyObserver() = 0;
protected:
	Subject() {}
	virtual ~Subject() {}
};


// Subscriber Class 
class StockObserver : public Observer {
private:
	double ibmPrice;
	double aaplPrice;
	double googPrice;
	static unsigned int observerIDTracker;
	int observerID;

	Subject *stockGrabber;
public:
	StockObserver(Subject *stockGrabber) {
		this->stockGrabber = stockGrabber;
		this->observerID = ++observerIDTracker;
		cout << "New Observer: " << this->observerID << endl;
		stockGrabber->registerObserver(this);
	}
	
	void update (double ibmPrice, double aaplPrice,
			double googPrice) {
		this->ibmPrice = ibmPrice;
		this->aaplPrice = aaplPrice;
		this->googPrice = googPrice;
		printThePrices();
	}

	void printThePrices() {
		cout << "-- Update Report --" << endl;
		cout << "Observer ID: " << this->observerID << endl;
		cout << "ibmPrice: " << this->ibmPrice << endl; 
		cout << "aaplPrice: " << this->aaplPrice << endl; 
		cout << "googPrice: " << this->googPrice << endl;
		cout << "--------------" << endl;
	}

};
// Initialize the static variable to use as a counter. 
unsigned int StockObserver::observerIDTracker = 0;

// Publisher Class
class StockGrabber: public Subject {
private:
	set <Observer*> observers;
	double ibmPrice;
	double aaplPrice;
	double googPrice;
public:
	StockGrabber () {
		this->ibmPrice = 0;
		this->aaplPrice = 0;
		this->googPrice = 0;
	}
	
	void registerObserver(Observer *newObserver) {
		observers.insert(newObserver);
		cout << "Observer Registered Successfully!" << endl;
	}

	void unregisterObserver(Observer *deleteObserver) {
		set <Observer*>:: iterator it = observers.find(deleteObserver);
		if (it != observers.end()) {
			observers.erase(it);
		}
		cout << "Observer Unregistered Successfully!" << endl;
	}

	void notifyObserver() {
		for (auto ob : observers) {
			ob->update(ibmPrice, aaplPrice, googPrice);
		}
		cout << "All Observers Notified Successfully!" << endl;
	}

	void setIBMPrice(double ibmPrice) {
		this->ibmPrice = ibmPrice;
		notifyObserver();
	}
	void setAAPLPrice(double aaplPrice) {
		this->aaplPrice = aaplPrice;
		notifyObserver();
	}
	void setGOOGPrice(double googPrice) {
		this->googPrice = googPrice;
		notifyObserver();
	}
};

int main () {
	StockGrabber stockGrabber;// = new StockGrabber ();

	StockObserver *observer1 = new StockObserver(&stockGrabber);
	
	stockGrabber.setIBMPrice(197.00);
	stockGrabber.setAAPLPrice(677.60);
	stockGrabber.setGOOGPrice(676.40);

	StockObserver *observer2 = new StockObserver(&stockGrabber);
	
	stockGrabber.setIBMPrice(197.00);
	stockGrabber.setAAPLPrice(677.60);
	stockGrabber.setGOOGPrice(676.40);
	
	stockGrabber.unregisterObserver(observer2);

	stockGrabber.setIBMPrice(197.00);
	stockGrabber.setAAPLPrice(677.60);
	stockGrabber.setGOOGPrice(676.40);
	


	return 0;
}
