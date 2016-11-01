#ifndef __CPP_OBSERVER__
#define __CPP_OBSERVER__

template <typename Event>
class AbstractObserver {
public:
	virtual void onNotified (const Event& event) = 0;
};


template <typename Event>
class ObservedSubject{
public:
	void registerObserver (AbstractObserver<Event>* ob){
		_observers.push_back (ob);
	}
	void deregisterObserver (AbstractObserver<Event>* ob){
		_observers.erase( std::remove (_observers.begin(), _observers.end(), ob), _observers.end());
		
	}
protected: 
	void notifyObservers(const Event& event){
		for (auto it = _observers.begin(); it !=_observers.end (); ++it) {
			(*it)->onNotified (event);
			
		}

	}

private:
	std::vector<AbstractObserver<Event>*>  _observers;
};

#endif //__CPP_OBSERVER__
