#ifndef CACHESIM_H
#define CACHESIM_H

#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

class Cache{
  private:
    string name;
    int max_size;
    int oldest; //position of oldest dirty data using clock eviction
    map<int, int> hmem; // entry -> vector pos , useful for constant lookup
    vector<pair <int,bool> > Vector;// vector of counts, dirty bit

  public:
    Cache(string n, int s){
     name = n;
     max_size = s;
     oldest = 0; 
     cout << "\tcreating " << name << " size:" << max_size << endl;
    }

    ~Cache(){
	cout << "\tdestroying " << name << endl; 	
    }

    void p_insert( int entry){
       if( size() == max_size -1){
	 //TODO pcam full resolution
         cout << "full" << name << endl;
         return;
       }
       pair<int,bool> temp = make_pair(1,1);
       Vector.push_back(temp);
       hmem[entry] = Vector.size() - 1;
    }

    void s_insert(int entry){
	if(size() == max_size -1){
	  //TODO scam full resolution
	  cout << "full" << name << endl;
	  return;
	}
	pair<int,bool> temp = make_pair(1,1);
	Vector.push_back(temp);
	hmem[entry] = Vector.size() -1;
    }

    void remove( int entry){
      //TODO 
    }

    void increment(int entry){
	Vector[hmem[entry]].first++;
    }

    size_t size () { 
	return Vector.size(); }

    string get_name() {
	return name; }

    bool contains(int entry){
	return hmem.find(entry) != hmem.end(); 
    }

};

#endif
