//
//  shifrovanie.hpp
//  Shifrovanie
//
//  Created by Дима Басан on 07.12.15.
//  Copyright © 2015 Дима Басан. All rights reserved.
//

#ifndef shifrovanie_hpp
#define shifrovanie_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
class Shifrovanie
{
    int k=0;
    vector<int> array1;
    vector<int> array2;
    
public:
    void GetAllStates();

    void GetAllStates1();
    
    int key();
    
    int unkey();
};
#endif /* shifrovanie_hpp */
