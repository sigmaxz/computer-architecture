/*
creator: Samuel Villarreal
email: csamuelvillarreal@yahoo.com

description: simulation of cache info through database for Dr. Najjar
*/

#include <iostream>
#include <stdlib.h>
#include "cachesim.h"
#include "signal.h"

using namespace std;

//This function changes the size of the memory taken by the cache class
void sconfig(int argc,char** argv, int & psize, int & ssize, int &msize){
  
  //use default if no args 
  if( argc == 1){
    return;
  }
  //naive check for argument count
  else if( argc % 2 == 0) 
  {
     cout << "anticipated argument failure terminating" << endl;
     exit(0);
  }
  else{
    //change args of corresponding values last instance in arg overwrites
    for( int i = 1; i < argc; i+=2){
        if( !strcmp(argv[i] , "-p" )){
		psize = atoi( argv[i+1]);
		cout << "p" << endl;
	}
        else if( !strcmp( argv[i] , "-s")){
		ssize = atoi(argv[i+1]);
		cout << "s" << endl;
	}
        else if( !strcmp(argv[i] , "-m")){
		msize = atoi(argv[i+1]);
		cout << "m" << endl;
	}
	else{
		cout << "not valid" << endl;
		exit(0);
	}
      }
    }
}

void sig_handler(int signum)
{
	//TODO
	printf("\tForcefully terminated data dump /*does nothing*/\n");
	exit(signum);
}

int producer(int i) //TODO  temporary data 
{
  if(i < 200)
	return ++i; //increment before returning
  return 0;
}

void emulate(Cache & pCache, Cache & sCache, Cache & mem)
{
  int entry = 0;
  int c1 = 0, c2 = 0, c3 = 0;
  //process data
  while(entry = producer(entry))
  {
    //entry in pcam increment count in pcam
    if(pCache.contains(entry)){
	c1++;
	pCache.increment(entry);
    }
    //entry in scam increment count in scam 
    else if(sCache.contains(entry)){
	c2++;
	sCache.increment(entry);
    }
    //mutually exclusive 
    //both miss insert to pcam
    else{
	c3++;
	pCache.p_insert(entry);
	//TODO
	//issue memreq?
	//return then should update pcam and move to scam?
    }
  }

  //print out stats
  cout << "\t\tpCache hits: " << c1 
       << "\n\t\tsCache hits: " << c2 
       << "\n\t\tboth miss: " << c3 << endl << endl;
  
  return; 	
}

int main(int argc, char* argv[])
{

  int psize = 256, ssize = 256, msize = 10000000;
 
  //size configure from arguemnts  
  sconfig(argc, argv, psize, ssize, msize);

  //create caches
  Cache pCache = Cache("pcache", psize);
  Cache sCache = Cache("scache", ssize);
  Cache mem = Cache("memcache", msize);

  //register signal
  signal(SIGINT, sig_handler);

  emulate(pCache, sCache, mem);
  //duplicate the emulation
  emulate(pCache, sCache, mem);

  sleep(1);
  return 0;
}
