// This file shows basic functions of reading in a CSV file using C++98
// Please add your name to your code! 

/* Homework Objective: fix this program to match the requirements listed: 
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category 
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.
All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std; 

int main() {

  // define variables
  string sku, brand, category, year, price; 
  vector<int>vSKU;
  vector<string>vBrand;
  vector<string>vCategory;
  vector<int>vYear;
  vector<float>vPrice;

  ifstream in_stream;
  in_stream.open("data.csv"); //opening the file.

  ofstream out_stream;
  out_stream.open("output.txt"); //opening output file

  if (!in_stream.fail()) { //if the file is open

    string line;
    getline(in_stream,line);

    while (getline(in_stream, line)) { //while the end of file is NOT reached

     // Fields: sku,brand,category,year,price

     stringstream lines(line);
     getline(lines, sku, ',');
     stringstream ssku(sku); 
     int iSKU = 0;
     ssku >> iSKU;
     vSKU.push_back(iSKU);

     getline(lines, brand, ',');
     vBrand.push_back(brand);

     getline(lines, category, ',');
     vCategory.push_back(category);

     getline(lines, year, ','); 
     stringstream syear(year);
     int iYear;
     syear >> iYear;
     vYear.push_back(iYear);

     getline(lines, price, '\n'); 
     stringstream sprice(price);
     float fPrice;
     sprice >> fPrice;
     vPrice.push_back(fPrice);
     
    }

    in_stream.close(); //closing the file cout << "Number of entries: " << i-1 << endl;

   } else {
    cout << "Unable to open file"; 
   }
 
  //output values 
  out_stream  << "SKU" << "\t" << "Brand" << "\t" << "Category" << "\t" 
<< "Year" << "\t" << "Price" << endl; 

  for (int j = 0; j < vSKU.size(); j++) {
    out_stream << vSKU[j] << "\t" << vBrand[j] << "\t" 
<< vCategory[j] << "\t" << "        " <<  vYear[j] << "\t" << vPrice[j]<< endl;
  }

  cout << endl;

}
