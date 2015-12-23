//
//  shifrovanie.cpp
//  Shifrovanie
//
//  Created by Дима Басан on 07.12.15.
//  Copyright © 2015 Дима Басан. All rights reserved.
//

#include "shifrovanie.hpp"
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <climits>
#include <sstream>
vector<int>array1;

vector<int> array3;
void Shifrovanie:: GetAllStates()//Линейный регистр сдвига для многочлена степени 16
{
    
    static unsigned long ShiftReg = 010;//ключ который будет сдивагаться побитово
    for (int i=0; i<32; i++)
    {
        ShiftReg = ((( (ShiftReg>>4)^(ShiftReg>>3)^ShiftReg) & 1) << 15 ) | (ShiftReg>>1);
        
        array1.insert(array1.end(), (ShiftReg & 1));
        
    }
    k=array1[11];
    cout<<endl<<k<<endl;
}

void Shifrovanie:: GetAllStates1()//Линейный регистр сдвига для многочлена степени 12
{
  
    static unsigned long ShiftReg = 1;//ключ который будет сдивагаться побитово
    for (int i=0; i<32; i++)
    {
        ShiftReg = ((( (ShiftReg>>5)^(ShiftReg>>4)^(ShiftReg>>3)^ShiftReg) & 1) << 11 ) | (ShiftReg>>1);
        
       
        array2.insert(array2.end(), (!(ShiftReg & 1)));
    }
}



int Shifrovanie::key()
{
    int countv=array2.size();
    k=array1[8];
    int *vector = new int[countv];
    for(int i=0;i<countv;i++)
    {
        vector[i]=array2[i];
    }
    for(int i=0;i<countv;i++)
    {
        swap(vector[i],vector[countv-1]);
    }
    for(int i=0;i<countv;i++)//обьеденение ЛРС
    {
        if (k==0&&vector[i]==0)
        {
            vector[i]=0;
        }
        if (k==0&&vector[i]==1)
        {
            vector[i]=1;
        }
        if (k==1&&vector[i]==0)
        {
            vector[i]=1;
        }
        if (k==1&&vector[i]==1)
        {
            vector[i]=1;
        }
    }
    ofstream fout;
    fout.open("/Users/admin/Desktop/C++/ForPidor/ForPidor/key.txt");
    for(int i=0;i<countv;i++)//запись ключа в файл
    {
        fout<<vector[i];
    }
    fout.close();
    ifstream file("/Users/admin/Desktop/C++/ForPidor/ForPidor/text.txt");
    string tmp, str;
    while(std::getline(file, tmp))//считывание текста, для шифрования
    {
        str += tmp;
        str += '\n';
    }
    using bs = bitset<sizeof(string::value_type) * CHAR_BIT>;//перевод в битовый код
    stringstream ss;
    struct bs_wrapper {
        bs_wrapper(const bs &a) : m_bs(a) { }
        operator char() const
        {
            return static_cast<char>(m_bs.to_ulong());
        }
        
        const bs &m_bs;
    };
    copy(str.begin(), str.end(), ostream_iterator<bs>(ss));
    string s;
    ss>>s;
    int kount=s.size();
    int *aaa=new int[kount];
    for(int i=0;i<kount;i++)
    {
        aaa[i]=s[i]-48;
    }
    int *vector1=new int[kount];
    int j=0;
    for(int i=0;i<kount;i++)
    {
        vector1[i]=vector[j];
        j++;
        if(j==countv)j=0;
    }
   for(int j=0;j<kount;j++)
   {
    {
        aaa[j]=aaa[j]^vector1[j];//шифрование текста
    }
   }
    string sic;
    stringstream bbb;
    for(int i=0;i<kount;i++)
    {
         sic.push_back(aaa[i]+'0');
    }
    stringstream lineStream(sic);
    ofstream fout1("/Users/admin/Desktop/C++/ForPidor/ForPidor/text.enc");
    copy(istream_iterator<bs>(lineStream), istream_iterator<bs>(), ostream_iterator<bs_wrapper>(fout1));//запись зашифрованого текста в файл
    fout1.close();
    ifstream file1("/Users/admin/Desktop/C++/ForPidor/ForPidor/text.enc");//считывание зашифрованого текста
    string tmp1, str1;
    while(std::getline(file1, tmp1))
    {
        str1 += tmp1;
        str1 += '\n';
    }
    using bs1 = bitset<sizeof(string::value_type) * CHAR_BIT>;
    stringstream ss1;
    struct bs1_wrapper {
        bs1_wrapper(const bs1 &a) : m_bs(a) { }
        operator char() const
        {
            return static_cast<char>(m_bs.to_ulong());
        }
        const bs1 &m_bs;
    };
    copy(str1.begin(), str1.end(), ostream_iterator<bs1>(ss1));
    string s1;
    ss1>>s1;
    int kount1=s1.size();
    int *aaa1=new int[kount1];
    for(int i=0;i<kount1;i++)
    {
        aaa1[i]=s1[i]-48;
    }
    for(int j=0;j<kount1;j++)
    {
        {
            aaa1[j]=aaa1[j]^vector1[j];//расшифровывание зашифрованого текста
        }
    }
    string sic1;
    stringstream bbb1;
    for(int i=0;i<kount1;i++)
    {
        sic1.push_back(aaa1[i]+'0');
    }
    stringstream lineStream1(sic1);
    ofstream fout11("/Users/admin/Desktop/C++/ForPidor/ForPidor/text1.txt");//запись расшифрованого текста
    copy(istream_iterator<bs1>(lineStream1), istream_iterator<bs1>(), ostream_iterator<bs1_wrapper>(fout11));
    fout11.close();
    file.close();
    file1.close();
    return 0;
}



