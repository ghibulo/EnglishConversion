

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

//Dvě cvičné úlohy - permutace a english conversion
//http://www.cprogramming.com/challenge.html

using namespace std;
vector<string> v;

typedef char jmeno[20];

const jmeno jednotky[20] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
"ten", "eleven", "twelve", "thirteen", "fourteen", "fivteen", "sixteen", "seventeen",
                         "eighteen", "nineteen"};
const jmeno desitky[10] = {"", "ten ", "twenty ", "thirty ","fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninty " };
const jmeno dalsi[3] = {" hundred ", " thousand ", " million "};



int* rozdel(int co, int kde) {
    int* vysledek = (int*)malloc(sizeof(int)*2);
    string s = std::to_string(co);
    //int del = pow(10,kde);
    //double a = (double)co/del;
    string pom = s.substr(0,s.size()-kde);
    vysledek[1]=(pom=="")?0:stoi(pom);
    pom = kde?s.substr(s.size()-kde,s.size()):"0";
    vysledek[0]=stoi(pom);
    return vysledek;
}


string nazev1(int co) {
    string p="";
    int cifra, u=0;
    if (co>99) {
        cifra = (int)(co/100);
        p+=string(jednotky[cifra]);
        p+=string(" hundred ");
        co-=(cifra*100);
    }
    if (co>19) {
        cifra = (int)(co/10);
        p+=string(desitky[cifra]);
        co-=(cifra*10);
    }
    if (co>0) {
        p+=jednotky[co];
    }
    return p;
}

string nazev(int co) {

  string s = std::to_string(co);


}


void Permutace(std::string ceho, std::string scim) {
    switch (scim.size()) {
        case 0: v.push_back(ceho);break;
        case 1: v.push_back(ceho+scim);break;
        case 2:
            v.push_back(ceho+scim[1]+scim[0]);
            v.push_back(ceho+scim[0]+scim[1]);
            break;
        default:
            string s1,s2;
            for (int i=0;i<scim.size();i++) {
                s1 = ceho + scim[i];
                s2=scim; s2.erase(i,1);
                Permutace(s1,s2);
            }
    }
    return;

}

void tiskni() {
    for(int i=0;i<v.size();i++) {
        cout << i<< ". "+v[i] << endl;
    }
}


int main()
{
int c;
string v="";
cout << "zadej cislo:" << endl;
cin >> c;

//cout << nazev1(c)<< endl;


if (c<0) {
    v="minus "+v;
    c*=-1;
}

if (c>999999) {
    int* x = rozdel(c,6);
    v = v + nazev1(x[1]) + dalsi[2];
    c=x[0];delete(x);
}

if (c>999) {
    int* x = rozdel(c,3);
    v = v + nazev1(x[1]) + dalsi[1];
    c=x[0];delete(x);
}
if (c>0) {
    v=v+nazev1(c);
}
if (v=="") v=jednotky[0];




cout << v << endl;


  //std::string l;
  Permutace("", "cat");
  tiskni();

/*
  //Creates an instance of ofstream, and opens example.txt
  ofstream a_file ( "example.txt", ios::app );
  // Outputs to example.txt through a_file
  a_file<<"Thistext will now be inside of example.txt";
  // Close the file stream explicitly
  a_file.close();
  //Opens for reading the file
  ifstream b_file ( "example.txt" );
  //Reads one string from the file
  while (getline(b_file, l))
  //Should output 'this'
  cout<< l <<"\n";
  cin.get();    // wait for a keypress
  // b_file is closed implicitly here
  */
}
