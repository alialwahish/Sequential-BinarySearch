// Name: Ali Bayati 
// Sequential Search / Binary Search / Vectors


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>

using namespace std;

void loadWords(vector<string>&words);
int sequentialSearch( vector<string>& words, string targetWord, int& count);
void selectionSort(vector<string>& words);
int binarySearch(vector<string>& words, string targetWord, int& count);

int main()
{
	
	vector<string> words(0);
	string targetword;
	int seqsearch;

	 loadWords(words);
	 int count ;
	 cout << "Loaded " << words.size() << endl;
	 cout << "Enter Word to Look Up(Sequential) (0 to quit) :";
	 getline(cin, targetword);
		 while (targetword != "0")
	 {
		 count = words.size();
		  seqsearch = sequentialSearch(words, targetword, count);
		 cout << "Enter Word to Look Up(Sequential) (0 to quit) :";
		 getline(cin, targetword);
	 }
		 selectionSort(words);
		 cout << "Enter Word to Look Up(Binary) (0 to quit) :";
		 getline(cin, targetword);
		
		 while (targetword != "0")
		 {
			 count = words.size();
			 seqsearch = binarySearch(words, targetword, count);
			 if (seqsearch >0)
			 {
				 cout << "Found " << targetword << " at index " << seqsearch << endl;
				 cout << "I looked at " << count << " Words...\n";
				 cout << "Enter Word to Look Up(Binary) (0 to quit) :";
				 getline(cin, targetword);
			 }
			 else  
			 {
				 cout << "Word is Not Found\n";
				 cout << "I looked at " << count << " words...\n";
				 cout << "Enter Word to Look Up(Binary) (0 to quit) :";
				 getline(cin, targetword);

			 }
			
		 }
	 
	 return 0;
}
void loadWords(vector<string>& words)
{
	int i;
	
	string rr, filename = "unsortedBOG.DAT";
	ifstream infile;
	infile.open(filename);
	for (i = 0; i < 3535; i++)
	{
		infile >> rr;
		words.push_back(rr);
	}
	
	
}

int sequentialSearch(vector<string>& words, string targetWord, int& count)
{	
	int i=0 ;
	while (count > 0)
	{

		if (words[i] == targetWord)
		{
			cout << "Found " << targetWord << " at index " << i + 1 << endl;
		cout << "I looked at " << i + 1 << " Words...\n";
		break;

	}
			i++;
			count--;
				
		
	}
	
	if (count == 0)

	{
		cout << "Word is Not Found\n";
		cout << "I looked at " << words.size() << " words...\n";
	}
	return count;
}

void selectionSort(vector<string>& words)
{
	
		cout << "Sorting Array...\n";
		int i, j, lindex;
						
		vector<string>::iterator it2;
		sort(words.begin(), words.end());


}
int binarySearch(vector<string>& words, string targetWord, int& count)
{
	int lowin, higin , mid,i=0;
	lowin = 0;
	higin = words.size();
	count = 0;
	while (lowin < higin)
	{
		count++;
		mid = (higin + lowin) / 2;
		if (words[mid] == targetWord)
			return mid;
		else if (targetWord < words[mid])
			higin = mid;
		else
			lowin = mid + 1;
		
	}
	
	return -1;

		
	

}

/*Output
Loaded 3535
Enter Word to Look Up(Sequential) (0 to quit) :AGATE
Found AGATE at index 1
I looked at 1 Words...
Enter Word to Look Up(Sequential) (0 to quit) :ZOOMS
Found ZOOMS at index 2756
I looked at 2756 Words...
Enter Word to Look Up(Sequential) (0 to quit) :ASHDJGASJHDGASJHDKGASHDJK
Word is Not Found
I looked at 3535 words...
Enter Word to Look Up(Sequential) (0 to quit) :0
Sorting Array...
Enter Word to Look Up(Binary) (0 to quit) :AGATE
Found AGATE at index 39
I looked at 12 Words...
Enter Word to Look Up(Binary) (0 to quit) :ZOOMS
Found ZOOMS at index 3534
I looked at 11 Words...
Enter Word to Look Up(Binary) (0 to quit) :SHDGAHSJDGAHSDKGAHJSDGA
Word is Not Found
I looked at 12 words...
Enter Word to Look Up(Binary) (0 to quit) :0
Press any key to continue . . .*/