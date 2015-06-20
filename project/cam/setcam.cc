#include <iostream>
#include <set>
#include <queue>

using namespace std;

class setcam{
  private:
  set<unsigned long long> cam;
  queue< set<unsigned long long>::iterator> que;
  int max;
  int pos;

  public:
  setcam(){ max = 128; 
	pos = 0;
  }
  void insert(unsigned long long key){
	if(cam.size() == max)
	{
		cam.erase(que.front());
		que.pop();
	}
	pair<set<unsigned long long>::iterator, bool> it = cam.insert(key);
	que.push(it.first);
  }
  
  bool in_cam(unsigned long long key){ return cam.find(key) != cam.end(); }
  void print(){
  	for(set<unsigned long long>::iterator it = cam.begin(); it != cam.end(); it++){
 		cout << *it << endl;
	}
  }
};


int main()
{
  setcam c;
  unsigned long long key;
  long cnt = 0;
  while(cin >> key)
  {
    // cout << ++cnt << " " << key << endl;
     c.insert(key);
  }

  c.print();
  return 0;
}
