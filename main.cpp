//
//  main.cpp
//  Shifrovanie
//
//  Created by Дима Басан on 06.12.15.
//  Copyright © 2015 Дима Басан. All rights reserved.
//
#include <vector>
#include <iostream>
#include "shifrovanie.hpp"
using namespace std;



int main(int argc, const char * argv[]) {
   
    Shifrovanie a;
    a.GetAllStates();
    a.GetAllStates1();
    a.key();
    cout<<"Программа отработала успешно!"<<endl;
    return 0;
}

