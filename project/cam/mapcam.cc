#include <iostream>
#include <map>
#include <queue>

using namespace std;

class setcam{
  private:
  map<unsigned long long, bool> cam;
  queue< map<unsigned long long, bool>::iterator> que;
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
	//cam[key] = 0;
	pair<map<unsigned long long, bool>::iterator,bool> it = cam.insert(pair<unsigned long long, bool>(key,0));
  	que.push(it.first);
  }
  void print(){
	for(map<unsigned long long, bool>::iterator it = cam.begin();it != cam.end() ; it++){
 		cout << it->first << endl;
	}
  } 
  bool in_cam(unsigned long long key){ return cam.find(key) != cam.end(); }
};


int main()
{
  setcam c;
  unsigned long long key;
  long cnt = 0;
  while(cin >> key)
  {
     //cout << ++cnt << " " << key << endl;
     c.insert(key);
  }

  c.print();
  return 0;
}
