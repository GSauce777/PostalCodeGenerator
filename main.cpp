#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int zip;
int preCheckDigit;
int checkDigit;
int zipCode;
int cd;

vector<string> bars = { "||:::", ":::||", "::|:|", "::||:", ":|::|", ":|:|:", ":||::", "|:::|", "|::|:", "|:|::"};

int main() {
  
  cout << "Welcome to the Postal Zip Code-Bar Code Generator!" << endl;
  cout << "Developed by Gabriel Saucedo 2023" << endl;
  cout << "Enter in Postal Zip Code: ";
  cin >> zip;
  zipCode = zip;
  
  for (preCheckDigit = 0; zip > 0; preCheckDigit += zip % 10, zip /= 10);
  if (preCheckDigit <= 10) {
    checkDigit = 10 - preCheckDigit;
  } else if (preCheckDigit > 10 && preCheckDigit <= 20) {
    checkDigit = 20 - preCheckDigit;
  } else if (preCheckDigit > 20 && preCheckDigit <= 30) {
    checkDigit = 30 - preCheckDigit;
  } else if (preCheckDigit > 30 && preCheckDigit <= 40) {
    checkDigit = 40 - preCheckDigit;
  } else if (preCheckDigit > 40 && preCheckDigit <= 50) {
    checkDigit = 50 - preCheckDigit;
  }

  vector<int> vDigits;
  while(zipCode > 0) {
    vDigits.push_back (zipCode % 10);
    zipCode /= 10;
  }
  reverse(vDigits.begin(), vDigits.end());
  cout << "Your Postal Barcode: " << endl;
  cout << "|";
  
  for (int i = 0; i < 5; i++) {
    cout << bars [vDigits[i]];
  }
  
  cout << bars [checkDigit];
  cout << "|";
  return 0;
}