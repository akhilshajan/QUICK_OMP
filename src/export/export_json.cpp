/*
  !---------------------------------------------------------------------!
  ! Written by Madu Manathunga on 05/18/2020                            !
  !                                                                     !
  ! Copyright (C) 2020-2021 Merz lab                                    !
  ! Copyright (C) 2020-2021 Götz lab                                    !
  !                                                                     !
  ! This Source Code Form is subject to the terms of the Mozilla Public !
  ! License, v. 2.0. If a copy of the MPL was not distributed with this !
  ! file, You can obtain one at http://mozilla.org/MPL/2.0/.            !
  !_____________________________________________________________________!

  !---------------------------------------------------------------------!
  ! This source file contains functions required for exporting          !
  ! information from QUICK into json/QCSchema format.                   !
  !---------------------------------------------------------------------!
*/

#include <iostream>
#include <fstream>
#include "./include/json.hpp"
#include <vector>

using namespace std;
using namespace nlohmann; 

/*int main(void){

// create an empty structure (null)
json j;

  int n=5;
  int *myArr=new int[5];

  for(int i=0;i<n;++i) {
    myArr[i]=i*10;
    cout<< myArr[i] << endl;
  }

  vector<int> *v=new vector<int>(myArr, myArr+n);

  for(vector<int>::iterator it=v->begin();it!=v->end();++it) cout << *it << endl;

// add a number that is stored as double (note the implicit conversion of j to an object)
j["pi"] = 3.141;

// add a Boolean that is stored as bool
j["happy"] = true;

// add a string that is stored as std::string
j["name"] = "Niels";

// add another null object by passing nullptr
j["nothing"] = nullptr;

// add an object inside the object
j["answer"]["everything"] = 42;

// add an array that is stored as std::vector (using an initializer list)
j["list"] = *v;

// add another object (using an initializer list of pairs)
j["object"] = { {"currency", "USD"}, {"value", 42.99} };

// instead, you could also write (which looks very similar to the JSON above)
json j2 = {
  {"pi", 3.141},
  {"happy", true},
  {"name", "Niels"},
  {"nothing", nullptr},
  {"answer", {
    {"everything", 42}
  }},
  {"list", {1, 0, 2}},
  {"object", {
    {"currency", "USD"},
    {"value", 42.99}
  }}
};

  ofstream mystream;
  mystream.open("test.json");
  mystream << j2 << endl;
  mystream.close();
  cout << j << endl; 

  delete [] myArr;
  delete v;

  return 0;
}*/

