#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <Windows.h>
#include <vector>

using namespace std;

void displayArray(vector<int> text1)
{
	for (int i = 0; i < text1.size(); i++)
	{
		cout << text1[i] << "";
	}
	cout << endl << endl;
}

void displayArrayTwo(vector<int> text2)
{
	for (int i = 0; i < text2.size(); i++)
	{
		cout << text2[i] << "";
	}
	cout << endl << endl;
}

void displayArraySecondText(vector<int> SecondText)
{
	for (int i = 0; i < SecondText.size(); i++)
	{
		cout << SecondText[i] << "";
	}
	cout << endl << endl;
}

void displayArraySecondTextFinal(vector<int> SecondTextFinal)
{
	for (int i = 0; i < SecondTextFinal.size(); i++)
	{
		cout << SecondTextFinal[i] << "";
	}
	cout << endl << endl;
}

//NOTE we need to use the &text1 to pass by reference so we can make changes outside the function as well
void mySwap(vector<int> &text1, int i, int j) //swapping the values between i and j
{
	int temp = text1[i];    //remeber the vector can still use the same notation to access things as an array
	text1[i] = text1[j];
	text1[j] = temp;

}

void mySwapSecondText(vector<int> &SecondTextFinal, int i, int j) //swapping the values between i and j
{
	int temp = SecondTextFinal[i];    //remeber the vector can still use the same notation to access things as an array
	SecondTextFinal[i] = SecondTextFinal[j];
	SecondTextFinal[j] = temp;

}

void bubbleSort(vector<int> &text1)
{
	bool sorted = false;
	//loop until the data is sorted in the vector
	while (!sorted)
	{
		//assume that its sorted until proven otherwise
		sorted = true;
		//loop through the vector looking for swaps that need doing
		for (int i = 0; i < text1.size() - 1; i++)
		{
			//do whatever is in the slots i and i +1
			if (text1[i] > text1[i + 1 ])
			{
				//true so swap it
				mySwap(text1, i, i + 1);
				sorted = false;
			}
		}
	}
}

void bubbleSortSecondData(vector<int>& SecondText)
{
	bool sorted = false;
	//loop until the data is sorted in the vector
	while (!sorted)
	{
		//assume that its sorted until proven otherwise
		sorted = true;
		//loop through the vector looking for swaps that need doing
		for (int i = 0; i < SecondText.size() - 1; i++)
		{
			//do whatever is in the slots i and i +1
			if (SecondText[i] > SecondText[i + 1])
			{
				//true so swap it
				mySwapSecondText(SecondText, i, i + 1);
				sorted = false;
			}
		}
	}
}

int partition(vector <int> &text2, int low, int high)
{
	//can decide pivot selection in different ways e.g median of index, high or lows etc
	//will use the value in the array at the low index position
	int pivot = text2[low];
	int i = low, j = high;
	//loop until i and j cross paths
	while (i < j)
	{
		//i is looking for value in the array which is larger than pivot value
		//moving to the right
		do {
			i++;
		} while (i < text2.size() && text2[i] <= pivot); //stop the loop as soon as value is greater than pivot value

		//j looks for value smaller than pivot value moving to the left
		do {
			j--;
		} while (j >= 0 && text2[j] > pivot);
		//IF i and j havent crossed we can assume we have found a value larger than i 
		//and a value smaller with j--- so swap them
		if (i < j)
			swap(text2[i], text2[j]);
	}

	//once done swap the pivot value with wherever j anded up.
	swap(text2[low], text2[j]);
	//return j so that new quicksorts can partition work into two loads one to the left of j and one to the right of j
	return j;
}

int partitionSecondData(vector <int>& SecondTextFinal, int low, int high)
{
	//can decide pivot selection in different ways e.g median of index, high or lows etc
	//will use the value in the array at the low index position
	int pivot = SecondTextFinal[low];
	int i = low, j = high;
	//loop until i and j cross paths
	while (i < j)
	{
		//i is looking for value in the array which is larger than pivot value
		//moving to the right
		do {
			i++;
		} while (i < SecondTextFinal.size() && SecondTextFinal[i] <= pivot); //stop the loop as soon as value is greater than pivot value

		//j looks for value smaller than pivot value moving to the left
		do {
			j--;
		} while (j >= 0 && SecondTextFinal[j] > pivot);
		//IF i and j havent crossed we can assume we have found a value larger than i 
		//and a value smaller with j--- so swap them
		if (i < j)
			swap(SecondTextFinal[i], SecondTextFinal[j]);
	}

	//once done swap the pivot value with wherever j anded up.
	swap(SecondTextFinal[low], SecondTextFinal[j]);
	//return j so that new quicksorts can partition work into two loads one to the left of j and one to the right of j
	return j;
}


void quickSort(vector <int> &text2, int low, int high)
{
	if (low < high)
	{
		int partitionIndex = partition(text2, low, high);
		quickSort(text2, low, partitionIndex); //splitting the data based on the partition index after the first run
		quickSort(text2, partitionIndex + 1, high); //as above
	}
}

void quickSortSecondData(vector <int> &SecondTextFinal, int low, int high)
{
	if (low < high)
	{
		int partitionIndex = partitionSecondData(SecondTextFinal, low, high);
		quickSortSecondData(SecondTextFinal, low, partitionIndex); //splitting the data based on the partition index after the first run
		quickSortSecondData(SecondTextFinal, partitionIndex + 1, high); //as above
	}
}


void main()
{
	
	//read from file first pass
	ifstream readFile;
	readFile.open("a2_task1_input1.txt");
	int numbersFromtext;
	readFile >> numbersFromtext;
	vector <int> text1 = {numbersFromtext};
	for (int i = 1; i <= numbersFromtext; i++)
	{
		int temp;
		readFile >> temp;
		text1.push_back(temp);

	}
	//Output sorted data from Text1 and record time taken for sort.

	
	cout << "unsorted" << endl;
	displayArray(text1);
	cout << "sorted" << endl;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	bubbleSort(text1);
	displayArray(text1);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "BubbleSort took = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

	//read from file second pass
	ifstream readFileTwo;
	readFileTwo.open("a2_task1_input1.txt");
	int numbersSecondPass;
	readFileTwo >> numbersSecondPass;
	vector <int> text2 = { numbersSecondPass };
	for (int i = 1; i <= numbersSecondPass; i++)
	{
		int temp;
		readFileTwo >> temp;
		text2.push_back(temp);
	}
	cout << "First Text file second pass, Unsorted data: " << endl;
	displayArrayTwo(text2);

	//quicksort data from the first text file, second time through using different algo.
	std::chrono::steady_clock::time_point beginSecondRun = std::chrono::steady_clock::now();
	cout << "QUICK SORTED DATA: " << endl;
	quickSort(text2, 0, 5001);
	displayArrayTwo(text2);
	std::chrono::steady_clock::time_point endSecondRun = std::chrono::steady_clock::now();
	std::cout << "QuickSort took = " << std::chrono::duration_cast<std::chrono::milliseconds>(endSecondRun - beginSecondRun).count() << "[ms]" << std::endl;
	int quickSortSpeed = std::chrono::duration_cast<std::chrono::milliseconds>(endSecondRun - beginSecondRun).count();
	int bubbleSortSpeed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

	if (quickSortSpeed > bubbleSortSpeed)
	{
		cout << "Quick Sort is Shitful at: " << quickSortSpeed << "ms" <<endl;
		cout << "Bubble Sort is faster at: " << bubbleSortSpeed << "ms" << endl;
	}
	else if (bubbleSortSpeed > quickSortSpeed)
	{
		cout << "Bubble Sort was shitfull at: " << bubbleSortSpeed << "ms" << endl;
		cout << "Quick Sort is faster at: " << quickSortSpeed << "ms" << endl;
	}

	//Complete the same operation on the second data set
	//read from file first pass
	ifstream readFileSecondDataSet;
	readFileSecondDataSet.open("a2_task1_input2.txt");
	int numbersFromSecondText;
	readFileSecondDataSet >> numbersFromSecondText;
	vector <int> SecondText = { numbersFromSecondText };
	for (int i = 1; i <= numbersFromSecondText; i++)
	{
		int temp;
		readFileSecondDataSet >> temp;
		SecondText.push_back(temp);
	}

	cout << "Second Data Set Unsorted" << endl;
	displayArraySecondText(SecondText);
	cout << "Second Data Set Bubble Sorted " << endl;
	std::chrono::steady_clock::time_point beginSecondDataSet = std::chrono::steady_clock::now();
	bubbleSortSecondData(SecondText);
	displayArraySecondText(SecondText);
	std::chrono::steady_clock::time_point endSecondDataSet = std::chrono::steady_clock::now();
	std::cout << "BubbleSort took = " << std::chrono::duration_cast<std::chrono::milliseconds>(endSecondDataSet - beginSecondDataSet).count() << "[ms]" << std::endl;


	//read from file second pass
	ifstream readFileSecondDataSetFinal;
	readFileSecondDataSetFinal.open("a2_task1_input2.txt");
	int numbersSecondPassFinal;
	readFileSecondDataSetFinal >> numbersSecondPassFinal;
	vector <int> SecondTextFinal = { numbersSecondPassFinal };
	for (int i = 1; i <= numbersSecondPassFinal; i++)
	{
		int temp;
		readFileSecondDataSetFinal >> temp;
		SecondTextFinal.push_back(temp);
	}
	cout << "Second Text file second pass, Unsorted data: " << endl;
	displayArrayTwo(SecondTextFinal);

	//quicksort data from the second text file, second time through using different algo.
	std::chrono::steady_clock::time_point beginSecondRunFinal = std::chrono::steady_clock::now();
	cout << "QUICK SORTED DATA: " << endl;
	quickSortSecondData(SecondTextFinal, 0, 5001);
	displayArraySecondTextFinal(SecondTextFinal);
	std::chrono::steady_clock::time_point endSecondRunFinal = std::chrono::steady_clock::now();
	std::cout << "Quick Sort took = " << std::chrono::duration_cast<std::chrono::milliseconds>(endSecondRunFinal - beginSecondRunFinal).count() << "[ms]" << std::endl;

	int quickSortSpeedSecondRun = std::chrono::duration_cast<std::chrono::milliseconds>(endSecondRunFinal - beginSecondRunFinal).count();
	int bubbleSortSpeedSecondRun = std::chrono::duration_cast<std::chrono::milliseconds>(endSecondDataSet - beginSecondDataSet).count();

	if (quickSortSpeedSecondRun > bubbleSortSpeedSecondRun)
	{
		cout << "Quick Sort is Shitful at: " << quickSortSpeedSecondRun << "ms" << endl;
		cout << "Bubble Sort this time is faster at: " << bubbleSortSpeedSecondRun << "ms" << endl;
	}
	else if (bubbleSortSpeedSecondRun > quickSortSpeedSecondRun)
	{
		cout << "Bubble Sort was shitfull at: " << bubbleSortSpeedSecondRun << "ms" << endl;
		cout << "Quick Sort this time is faster at: " << quickSortSpeedSecondRun << "ms" << endl;
	}

	
	system("pause");

}
