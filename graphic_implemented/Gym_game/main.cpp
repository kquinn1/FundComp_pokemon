//Katie Quinn
//CSE 20212 
//lab 10
// Program used to detect similar documents
// may or may not use classes
//
// Program should ask the user for two file names to process. 
// these files can either be plain text or HTML 
// 	if html ignore all tags
// 		except for <ahref=" links which should be placedc in a set
// 	Use STL string processing: 
// 		ignore punctuation, formatted text
// 		convert each word to all low case
//	Compute number of unique words in each file
//	Report this number to the user
//	Display the words and their counts for the first file provided by user
//	If the files are HTML, provide a list of all unique links found in
//	<a href= tags. This can be usecd later for a web crawler to acces any pages
//	Jaccard similarity can be used in big data to detect plagiarism, similar documents etc. Compute the jaccard similarity of the two target documents:
//		the ratio of the number of items in the intersection of two sets to their union
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main(){
 // open files
  map<string, int> Data;
  int wordCount;
  set<string> mySet;
  string word; // to store words in the file
  string myFile1;
  string myFile2;

// ask the user for files
  cout << "Enter two file names: " ;
  cin >> myFile1;
  cin >> myFile2;

  ifstream dataFile1("myFile1",ifstream::in);
  ifstream dataFile2("myFile2",ifstream::in);//::in denotes input only
// exit the program if ifstream could not open file
   if(!dataFile1 || !dataFile2){
	cout << "File could not be opened!" << endl;
	return 1;
    }

// while not at the end of the file, read in the file
  while(! dataFile1.eof() ){
	dataFile1 >> word;
	for(int i = 0; i < word.size(); i++){// removes non-alpha numeric chars
	   if(!isalnum(word[i]))
		word.erase(i,1);
	   else
		word[i] = tolower(word[i]);
	}

	mySet.insert(word); //add the line to linked list
  }

// need to create a result container and use the inserter function of the STL
// which will populate the result container with the results 
// Can computer the intersection of two sets Dict and Query
//
// set_intersection(Dict.begin(),Dict.end(),Query.begin(), Query.end(),inserter(Result, Result.end());
//
// assume that any text between a < and a > can be ignored. no special text
// anything between valid HTML tags can be added to the data structure
  return 0; // the program finished successfully

}
