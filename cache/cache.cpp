#include <iostream>
#include <vector>
#include <iomanip>

#define  BLOCK_SIZE     16
const int CACHE_SIZE[]   =  { 1024, 2048, 4096, 8192, 16384 };

using namespace std;

void print_miss(double miss[])
{
	cout << setw(30) <<"LRU Replacement Policy" << endl;
	cout<<setw(7)<<"1024" <<setw(7)<< "2048" <<setw(7)<< "4096" <<setw(7)<< "8192" <<setw(8)<< "16384" << endl;
	cout << "1";
	for(int i = 0; i < 5; ++i)
	{
		cout << setprecision(4) << setw(7) << miss[i];
	}
	cout << endl;
	
	cout << "2";
	for(int i = 5; i < 10; ++i)
	{
		cout << setprecision(4) << setw(7) << miss[i];
	}
	cout << endl;
	
	cout << "4";
	for(int i = 10; i < 15; ++i)
	{
		cout << setprecision(4) << setw(7) << miss[i];
	}
	cout << endl;
	
	cout << "8";
	for(int i = 15; i < 20; ++i)
	{
		cout << setprecision(4) << setw(7) << miss[i];
	}
	cout << endl;
	
	cout << setw(30) <<"FIFO Replacement Policy" << endl;
	cout<<setw(7)<<"1024" <<setw(7)<< "2048" <<setw(7)<< "4096" <<setw(7)<< "8192" <<setw(8)<< "16384" << endl;
	cout << "1";
	for(int i = 0; i < 5; ++i)
	{
		cout << setprecision(4) << setw(7) << miss[i];
	}
	cout << endl;
	
	cout << "2";
	for(int i = 20; i < 25; ++i)
	{
		cout << setprecision(4) << setw(7) << miss[i];
	}
	cout << endl;
	
	cout << "4";
	for(int i = 25; i < 30; ++i)
	{
		cout << setprecision(4) << setw(7) << miss[i];
	}
	cout << endl;
	
	cout << "8";
	for(int i = 30; i < 35; ++i)
	{
		cout << setprecision(4) << setw(7) << miss[i];
	}
	cout << endl;
	
	
	return;
}

void calcD(vector<unsigned long long > & cache,int size, unsigned long long mask,int & miss, unsigned long long & read_line )
{
	unsigned long long tag0   = read_line >> (size + 4); // get tag
      unsigned long long index0 = read_line >> 4;
      index0 = index0 & mask;
      // check for miss
      if (cache[index0] != tag0)
      {
				cache[index0] = tag0;
				miss++;
			}
}

void calc2(vector<unsigned long long > & cache,int size, unsigned long long mask,int & miss, unsigned long long & read_line , int ways,bool LRU)
{
	unsigned long long tag   = read_line >> (size + 4); // get tag
      unsigned long long index = read_line >> 4;
      index = index & mask;
      // check for miss
      bool found = false;
      int indexfound = 0;
      for(int i = 0; i < ways ; i++)
      {
				if( cache[index * ways + i] == tag)
				{
					found = true;
					indexfound = i;
				}
			}
			if( LRU)
			{
				if( !found)
				{
					miss++;
					for( int i = ways -1 ; i > 0; i--)
					{
						cache[index * ways + i] = cache[index * ways + i -1];
					}
					cache[index* ways] = tag;
				}
				else if( indexfound != 0 && found)
				{
					for(int i = indexfound; i > 0; i--)
					{
						cache[index * ways + i ] = cache[index * ways + i -1];
					}
					cache[index* ways] = tag;
				}
				else
				{
					// do nothing
				}
		}
		else
		{
			if( !found)
				{
					miss++;
					for( int i = ways -1 ; i > 0; i--)
					{
						cache[index * ways + i] = cache[index * ways + i -1];
					}
					cache[index* ways] = tag;
				}
		}
			
			
}


int main () {
   // build cache
   int number_of_blocks[5];
   for(int i = 0; i < 5 ; i++)
   {
			number_of_blocks[i]  = CACHE_SIZE[i] / BLOCK_SIZE;
		}
   std::vector<unsigned long long> cache[35];
   //direct
   for (int i = 0; i < 35; ++i)
		{
			for(int j = 0; j < number_of_blocks[i % 5] ; j++)
			{
				cache[i].push_back(0);
			}
		}

   // read memory accesses from standard input
   unsigned long long read_line;
   int total = 0, miss[35] = {0}; // miss 5-9 are 2 way ,
   while (std::cin >> std::hex >> read_line) {
      total++;
      /////////////////////////////////direct
      //1024
      calcD(cache[0],6, 0x000000000000003F,miss[0], read_line );
			 //2048
			 calcD(cache[1],7, 0x000000000000007F,miss[1], read_line );
			 //4xxx
			 calcD(cache[2],8, 0x00000000000000FF,miss[2], read_line );
			 //8xxx
			 calcD(cache[3],9, 0x00000000000001FF,miss[3], read_line );
      //16xxx
      calcD(cache[4],10, 0x00000000000003FF,miss[4], read_line );
      ////////////////////////////////////////2way
      //1024
      calc2(cache[5],5, 0x000000000000001F,miss[5], read_line ,2 , true);
			//2k
			calc2(cache[6],6, 0x000000000000003F,miss[6], read_line ,2 , true);
			//4k
			calc2(cache[7],7, 0x000000000000007F,miss[7], read_line ,2 , true);
			//8k
			calc2(cache[8],8, 0x00000000000000FF,miss[8], read_line ,2 , true);
			//16
			calc2(cache[9],9, 0x00000000000001FF,miss[9], read_line ,2 , true);
			////////////////////////////////////////4way
			//1k
			calc2(cache[10],4, 0x000000000000000F,miss[10], read_line ,4, true );
			//2k
			calc2(cache[11],5, 0x000000000000001F,miss[11], read_line ,4, true );
			//4k
			calc2(cache[12],6, 0x000000000000003F,miss[12], read_line ,4, true );
			// 8k
			calc2(cache[13],7, 0x000000000000007F,miss[13], read_line ,4, true );
			//16k
			calc2(cache[14],8, 0x00000000000000FF,miss[14], read_line ,4, true );
			////////////////////////////////////////8way
			//1k
			calc2(cache[15],3, 0x0000000000000007,miss[15], read_line ,8, true );
			//2k
			calc2(cache[16],4, 0x000000000000000F,miss[16], read_line ,8, true );
			//4k
			calc2(cache[17],5, 0x000000000000001F,miss[17], read_line ,8, true );
			// 8k
			calc2(cache[18],6, 0x000000000000003F,miss[18], read_line ,8, true );
			//16k
			calc2(cache[19],7, 0x000000000000007F,miss[19], read_line ,8, true );
			//FIFO %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
			////////////////////////////////////////2way
      //1024
      calc2(cache[20],5, 0x000000000000001F,miss[20], read_line ,2 , false);
			//2k
			calc2(cache[21],6, 0x000000000000003F,miss[21], read_line ,2 , false);
			//4k
			calc2(cache[22],7, 0x000000000000007F,miss[22], read_line ,2 , false);
			//8k
			calc2(cache[23],8, 0x00000000000000FF,miss[23], read_line ,2 , false);
			//16
			calc2(cache[24],9, 0x00000000000001FF,miss[24], read_line ,2 , false);
			////////////////////////////////////////4way
			//1k
			calc2(cache[25],4, 0x000000000000000F,miss[25], read_line ,4, false );
			//2k
			calc2(cache[26],5, 0x000000000000001F,miss[26], read_line ,4, false );
			//4k
			calc2(cache[27],6, 0x000000000000003F,miss[27], read_line ,4, false );
			// 8k
			calc2(cache[28],7, 0x000000000000007F,miss[28], read_line ,4, false );
			//16k
			calc2(cache[29],8, 0x00000000000000FF,miss[29], read_line ,4, false );
			////////////////////////////////////////8way
			//1k
			calc2(cache[30],3, 0x0000000000000007,miss[30], read_line ,8, false );
			//2k
			calc2(cache[31],4, 0x000000000000000F,miss[31], read_line ,8, false );
			//4k
			calc2(cache[32],5, 0x000000000000001F,miss[32], read_line ,8, false );
			// 8k
			calc2(cache[33],6, 0x000000000000003F,miss[33], read_line ,8, false );
			//16k
			calc2(cache[34],7, 0x000000000000007F,miss[34], read_line ,8, false );
      
   }
   double miss_r[35] = {0.0};
   for (int i = 0; i < 35; ++i)
   {
   		miss_r[i] = ((double)miss[i] / (double)(total)) * 100.0;
   }
   print_miss(miss_r);
   
  

   return 0;
}

