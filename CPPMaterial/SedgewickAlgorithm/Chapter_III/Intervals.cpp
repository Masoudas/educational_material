/** This is courtesy of yours truely!
* 
* So imagine open intervals [a,b). Define an api that has intervals in such a way that:
* 1- It has an add(a,b), adding the interval [a,b). If [a,b) is partially defined, removes pre-existing parts.
* 2- It has remove(a,b), removing the interval [a,b)
* 3- It has intersect(a,b), calculating the intersection of [a,b) with existing interval
* 4- It has union(a,b), calculating the union of [a,b) with existing interval
* 
* For now, we may assume that the intervals are integer values. We can however use templates to give a more 
* generic version.
*/
#include <vector>
#include <cmath>
#include <iostream>
#include <list>
using namespace std;

/* An interval is a continuous range such as [min, max)*/
class Interval {
public:
	const int min;
	const int max;

public:
	Interval(const int min, const int max): min(min), max(max){}
	Interval(const Interval& ref) : min(ref.min), max(ref.max) {}

	Interval* intersect(const Interval& i1) {
		if (i1.max - 1 < min) { return nullptr; }
		if (max - 1 < i1.min) { return nullptr; }

		int min_intersection = std::max(i1.min, min);
		int max_intersection = std::min(i1.max, max);

		Interval* intersection_set = new Interval {min_intersection, max_intersection};

		return intersection_set;
	}

	vector<Interval*>& get_union(const Interval& i1) {
		vector<Interval*>* union_set = new vector<Interval*>{};

	    if (i1.max - 1 < min) {
			union_set->push_back(new Interval{ i1 });
			union_set->push_back(new Interval{ *this });
		}
		else if (max - 1 < i1.min) {
			union_set->push_back(new Interval{ *this });
			union_set->push_back(new Interval{ i1 });
		}
		else {
			int min_union = std::min(i1.min, min);
			int max_union = std::max(i1.max, max);
		}

		return *union_set;	
	}

	bool operator<(const Interval& i1) {
		return this->max < i1.min - 1;
	}

	bool contains(const Interval& i1) {
		if (min <= i1.min && i1.max <= max) {
			return true;
		}

		return false;
	}

};

class Interval_Holder {
	list<Interval*> intervals{};
	Interval_Holder(int min, int max) {
		Interval* i1 = new Interval{ min, max };
		intervals.push_back(i1);
	}

	void add(int min, int max) {
		if (intervals.front()->max - 1 < min || max - 1 < intervals.front()->min) {
			intervals.push_back(new Interval{ min, max });
			return;
		} 

		Interval added{ min, max };
		bool add = false;
		for (Interval* interval : intervals)
		{
			if (max - 1 < interval->min) {
				return;
			}
			else if (interval->intersect(added)) {
				vector<Interval*> Interval_union = interval->get_union(added);
				if (add) {
					//intervals.		
				}
				
			}

		}

	}

	void remove(int min, int max) {

	}

	void get_union(int min, int max) {

	}

	void intersect(int min, int max){}
};