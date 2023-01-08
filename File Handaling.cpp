#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
 cout<< "Please Keep both files in the same folder of program"<<endl;
 cout << "Enter the name of the first file: ";
 string file1;
 cin >> file1;
 cout << "Enter the name of the second file: ";
 string file2;
 cin >> file2;
 ifstream test1(file1);
 ifstream test2(file2);
 if(!test1 || !test2) 
  {
   cout << "Error opening one of the files" << endl;
   return 1;
  }
 string word1, word2;
 int wordCount1 = 0, wordCount2 = 0;
 while(test1 >> word1)
  {
   ++wordCount1;
  }
  while(test2 >> word2)
  {
    ++wordCount2;
  }
  test1.close();
  test2.close();
  test1.open(file1);
  test2.open(file2);
  int commonWordCount = 0;
  while (test1 >> word1 && test2 >> word2)
  {
    transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
    if (word1 == word2)
	{
      ++commonWordCount;
    }
  }
  test1.close();
  test2.close();
  double similarity = static_cast<double>(commonWordCount) / wordCount1 * 100;
  cout << "Number of words in first file: " << wordCount1 << endl;
  cout << "Number of words in second file: " << wordCount2 << endl;
  cout << "Percentage similarity: " << similarity << "%" << endl;
  return0;
}

