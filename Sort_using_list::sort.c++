#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  unsigned int val1;
  unsigned int val2;
  char val3;
  string val4;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename.c_str());
  if (!input) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->val1 >> pData->val2 >> pData->val3 >> pData->val4;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename.c_str());
  if (!output) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << endl;

  // Write the data
  for (list<Data *>::const_iterator ipD = l.begin(); ipD != l.end(); ipD++) {
    output << (*ipD)->val1 << " " 
	   << (*ipD)->val2 << " " 
	   << (*ipD)->val3 << " " 
	   << (*ipD)->val4 << endl;
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &, int field);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);

  cout << "Data loaded.  Executing sort..." << endl;

  int field = 0;
  cout << "Enter an integer from 1 - 4, representing field to sort: ";
  try {
    cin >> field;
    if (field < 1 || field > 4) {
      cerr << "Error: invalid field" << endl;
      exit(1);
    }
  }
  catch (...) {
    cerr << "Error: invalid field" << endl;
    exit(1);
  }
    
  clock_t t1 = clock();
  sortDataList(theList, field);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds." << endl;

  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);

  return 0;
}

// add global variables, functions, and/or
// class defintions here 

bool mylessthan1 (Data *pd1, Data *pd2) {
    if (pd1->val1 < pd2->val1) {
      return true;
    }
    else {
      return false;
    }
}

bool mylessthan2 (Data *pd1, Data *pd2) {
    if (pd1->val2 < pd2->val2) {
      return true;
    }
    else {
      return false;
    }
}  

bool mylessthan3 (Data *pd1, Data *pd2) {
    if (pd1->val3 < pd2->val3) {
      return true;
    }
    else {
      return false;
    }
}  

bool mylessthan4 (Data *pd1, Data *pd2) {
    if ((pd1->val4) < (pd2->val4)) {
      return true;
    }
    else {
      return false;
    }
}  

void sortDataList(list<Data *> &l, int field) {
  // Fill in this function
  if (field == 1) {
  l.sort(mylessthan1);
  }

  if (field == 2 ) {
  l.sort(mylessthan2);  
  }

  if (field == 3) {
  l.sort(mylessthan3);
  }

  if (field == 4) {
  l.sort(mylessthan4);  
  }
 } 


