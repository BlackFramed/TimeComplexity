/***************
Dezhi Gao
Program 1
CSCE 3110
****************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iomanip>

using namespace std;

struct Info
{
	string X, Y, OBJECTID, ID, NAME, ADDRESS,
			CITY, STATE, ZIP, ZIP4, TELEPHONE, TYPE,
			STATUS, POPULATION, COUNTY, COUNTYFIPS, COUNTRY,
			LATITUDE, LONGITUDE, NAICS_CODE, NAICS_DESC, SOURCE,
			SOURCEDATE, VAL_METHOD, VAL_DATE, WEBSITE, ST_SUBTYPE;
};

Info info;
Info* title = new Info(info);

void ReadCsv(vector<Info*>& info_vector)
{
	ifstream file;
	file.open("Child_Care_Centers.csv", ios::in);

	if (!file.is_open())
	{
		cout << "Could not open the file." << endl;

		return;
	}

	string X, Y, OBJECTID, ID, NAME, ADDRESS,
		CITY, STATE, ZIP, ZIP4, TELEPHONE, TYPE,
		STATUS, POPULATION, COUNTY, COUNTYFIPS, COUNTRY,
		LATITUDE, LONGITUDE, NAICS_CODE, NAICS_DESC, SOURCE,
		SOURCEDATE, VAL_METHOD, VAL_DATE, WEBSITE, ST_SUBTYPE;

	while (getline(file, X, ',') && getline(file, Y, ',') && getline(file, OBJECTID, ',') && getline(file, ID, ',')
			&& getline(file, NAME, ',') && getline(file, ADDRESS, ',') && getline(file, CITY, ',') && getline(file, STATE, ',')
			&& getline(file, ZIP, ',') && getline(file, ZIP4, ',') && getline(file, TELEPHONE, ',') && getline(file, TYPE, ',')
			&& getline(file, STATUS, ',') && getline(file, POPULATION, ',') && getline(file, COUNTY, ',') && getline(file, COUNTYFIPS, ',')
			&& getline(file, COUNTRY, ',') && getline(file, LATITUDE, ',') && getline(file, LONGITUDE, ',') && getline(file, NAICS_CODE, ',')
			&& getline(file, NAICS_DESC, ',') && getline(file, SOURCE, ',') && getline(file, SOURCEDATE, ',') && getline(file, VAL_METHOD, ',')
			&& getline(file, VAL_DATE, ',') && getline(file, WEBSITE, ',') && getline(file, ST_SUBTYPE, '\n'))
	{
		info.X = X;
		info.Y = Y;
		info.OBJECTID = OBJECTID;
		info.ID = ID;
		info.NAME = NAME;
		info.ADDRESS = ADDRESS;

		info.CITY = CITY;
		info.STATE = STATE;
		info.ZIP = ZIP;
		info.ZIP4 = ZIP4;
		info.TELEPHONE = TELEPHONE;
		info.TYPE = TYPE;

		info.STATUS = STATUS;
		info.POPULATION = POPULATION;
		info.COUNTY = COUNTY;
		info.COUNTYFIPS = COUNTYFIPS;
		info.COUNTRY = COUNTRY;

		info.LATITUDE = LATITUDE;
		info.LONGITUDE = LONGITUDE;
		info.NAICS_CODE = NAICS_CODE;
		info.NAICS_DESC = NAICS_DESC;
		info.SOURCE = SOURCE;

		info.SOURCEDATE = SOURCEDATE;
		info.VAL_METHOD = VAL_METHOD;
		info.VAL_DATE = VAL_DATE;
		info.WEBSITE = WEBSITE;
		info.ST_SUBTYPE = ST_SUBTYPE;

		Info* ptr = new Info(info);

		info_vector.push_back(ptr);
	}

	for (auto it = info_vector.begin(); it != info_vector.begin() + 1; ++it)
	{
		title = (*it);
		it = info_vector.erase(it);
	}

	file.close();
}

void InsertionSort(vector<Info*>& info_vector)
{

	ReadCsv(info_vector);

	if (info_vector.empty())
	{
		cout << "No Data Here." << endl;

		return;
	}

	int n = info_vector.size();

	int i, j;
	Info* key;
	for (i = 1; i < n; i++)
	{
		key = info_vector[i];
		key->NAME = info_vector[i]->NAME;

		j = i - 1;

		while (j >= 0 && info_vector[j]->NAME.length() > key->NAME.length())
		{
			info_vector[j + 1] = info_vector[j];
			j = j - 1;
		}

		info_vector[j + 1] = key;

	}

	ofstream ofile;

	ofile.open("Child_Care_Centers_Insertion.csv", ios::out);

	ofile << (title)->X << ","
		<< (title)->Y << ","
		<< (title)->OBJECTID << ","
		<< (title)->ID << ","
		<< (title)->NAME << ","
		<< (title)->ADDRESS << ","

		<< (title)->CITY << ","
		<< (title)->STATE << ","
		<< (title)->ZIP << ","
		<< (title)->ZIP4 << ","
		<< (title)->TELEPHONE << ","

		<< (title)->TYPE << ","
		<< (title)->STATUS << ","
		<< (title)->POPULATION << ","
		<< (title)->COUNTY << ","
		<< (title)->COUNTYFIPS << ","
		<< (title)->COUNTRY << ","

		<< (title)->LATITUDE << ","
		<< (title)->LONGITUDE << ","
		<< (title)->NAICS_CODE << ","
		<< (title)->NAICS_DESC << ","
		<< (title)->SOURCE << ","

		<< (title)->SOURCEDATE << ","
		<< (title)->VAL_METHOD << ","
		<< (title)->VAL_DATE << ","
		<< (title)->WEBSITE << ","
		<< (title)->ST_SUBTYPE << endl;

	for (auto it = info_vector.begin(); it != info_vector.end(); ++it)
	{
		ofile << (*it)->X << ","
			<< (*it)->Y << ","
			<< (*it)->OBJECTID << ","
			<< (*it)->ID << ","
			<< (*it)->NAME << ","
			<< (*it)->ADDRESS << ","

			<< (*it)->CITY << ","
			<< (*it)->STATE << ","
			<< (*it)->ZIP << ","
			<< (*it)->ZIP4 << ","
			<< (*it)->TELEPHONE << ","

			<< (*it)->TYPE << ","
			<< (*it)->STATUS << ","
			<< (*it)->POPULATION << ","
			<< (*it)->COUNTY << ","
			<< (*it)->COUNTYFIPS << ","
			<< (*it)->COUNTRY << ","

			<< (*it)->LATITUDE << ","
			<< (*it)->LONGITUDE << ","
			<< (*it)->NAICS_CODE << ","
			<< (*it)->NAICS_DESC << ","
			<< (*it)->SOURCE << ","

			<< (*it)->SOURCEDATE << ","
			<< (*it)->VAL_METHOD << ","
			<< (*it)->VAL_DATE << ","
			<< (*it)->WEBSITE << ","
			<< (*it)->ST_SUBTYPE << endl;
	}

	ofile.close();

	for (auto it = info_vector.begin(); it != info_vector.end(); ++it)
	{
		delete *it;
	}

	delete title;

	info_vector.clear();
}


void merge(vector<Info*>& info_vector, int start, int middle, int end)
{

	vector<Info*> leftArray(middle - start + 1);
	vector<Info*> rightArray(end - middle);

	for (unsigned int i = 0; i < leftArray.size(); ++i)
		leftArray[i] = info_vector[start + i];

	for (unsigned int i = 0; i < rightArray.size(); ++i)
		rightArray[i] = info_vector[middle + 1 + i];

	int leftIndex = 0, rightIndex = 0;

	int currentIndex = start;

	while (leftIndex < leftArray.size() && rightIndex < rightArray.size())
	{
		if (leftArray[leftIndex]->NAME.length() <= rightArray[rightIndex]->NAME.length())
		{
			info_vector[currentIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		else {
			info_vector[currentIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		currentIndex++;
	}

	while (leftIndex < leftArray.size()) info_vector[currentIndex++] = leftArray[leftIndex++];

	while (rightIndex < rightArray.size()) info_vector[currentIndex++] = rightArray[rightIndex++];
}

void mergeSort(vector<Info*>& info_vector, int start, int end)
{
	if (start < end)
	{
		int middle = (start + end) / 2;

		mergeSort(info_vector, start, middle);
		mergeSort(info_vector, middle + 1, end); 

		merge(info_vector, start, middle, end);
	}
}

void MergeSort(vector<Info*>& info_vector)
{
	ReadCsv(info_vector);

	if (info_vector.empty())
	{
		cout << "No Data Here." << endl;

		return;
	}
	
	mergeSort(info_vector, 0, static_cast<int > (info_vector.size() - 1));

	ofstream ofile;

	ofile.open("Child_Care_Centers_Merge.csv", ios::out);

	ofile << (title)->X << ","
		<< (title)->Y << ","
		<< (title)->OBJECTID << ","
		<< (title)->ID << ","
		<< (title)->NAME << ","
		<< (title)->ADDRESS << ","

		<< (title)->CITY << ","
		<< (title)->STATE << ","
		<< (title)->ZIP << ","
		<< (title)->ZIP4 << ","
		<< (title)->TELEPHONE << ","

		<< (title)->TYPE << ","
		<< (title)->STATUS << ","
		<< (title)->POPULATION << ","
		<< (title)->COUNTY << ","
		<< (title)->COUNTYFIPS << ","
		<< (title)->COUNTRY << ","

		<< (title)->LATITUDE << ","
		<< (title)->LONGITUDE << ","
		<< (title)->NAICS_CODE << ","
		<< (title)->NAICS_DESC << ","
		<< (title)->SOURCE << ","

		<< (title)->SOURCEDATE << ","
		<< (title)->VAL_METHOD << ","
		<< (title)->VAL_DATE << ","
		<< (title)->WEBSITE << ","
		<< (title)->ST_SUBTYPE << endl;

	for (auto it = info_vector.begin(); it != info_vector.end(); ++it)
	{
		ofile << (*it)->X << ","
			<< (*it)->Y << ","
			<< (*it)->OBJECTID << ","
			<< (*it)->ID << ","
			<< (*it)->NAME << ","
			<< (*it)->ADDRESS << ","

			<< (*it)->CITY << ","
			<< (*it)->STATE << ","
			<< (*it)->ZIP << ","
			<< (*it)->ZIP4 << ","
			<< (*it)->TELEPHONE << ","

			<< (*it)->TYPE << ","
			<< (*it)->STATUS << ","
			<< (*it)->POPULATION << ","
			<< (*it)->COUNTY << ","
			<< (*it)->COUNTYFIPS << ","
			<< (*it)->COUNTRY << ","

			<< (*it)->LATITUDE << ","
			<< (*it)->LONGITUDE << ","
			<< (*it)->NAICS_CODE << ","
			<< (*it)->NAICS_DESC << ","
			<< (*it)->SOURCE << ","

			<< (*it)->SOURCEDATE << ","
			<< (*it)->VAL_METHOD << ","
			<< (*it)->VAL_DATE << ","
			<< (*it)->WEBSITE << ","
			<< (*it)->ST_SUBTYPE << endl;
	}

	ofile.close();

	for (auto it = info_vector.begin(); it != info_vector.end(); ++it)
	{
		delete* it;
	}

	delete title;

	info_vector.clear();

}


int partition(vector<Info*>& info_vector, int left, int right)
{
	int pivotIndex = left + (right - left) / 2;
	int pivotValue = info_vector[pivotIndex]->NAME.length();

	int i = left, j = right;
	Info* temp;
	while (i <= j)
	{
		while (info_vector[i]->NAME.length() < pivotValue)
		{
			i++;
		}
		while (info_vector[j]->NAME.length() > pivotValue)
		{
			j--;
		}

		if (i <= j)
		{
			temp = info_vector[i];
			info_vector[i] = info_vector[j];
			info_vector[j] = temp;

			i++;
			j--;
		}
	}

	return i;

}

void quicksort(vector<Info*>& info_vector, int left, int right)
{
	if (left < right)
	{
		int pivotIndex = partition(info_vector, left, right);
		quicksort(info_vector, left, pivotIndex - 1);
		quicksort(info_vector, pivotIndex, right);
	}
}


void Quicksort(vector<Info*>& info_vector)
{
	ReadCsv(info_vector);

	if (info_vector.empty())
	{
		cout << "No Data Here." << endl;

		return;
	}

	quicksort(info_vector, 0, info_vector.size() - 1);

	ofstream ofile;

	ofile.open("Child_Care_Centers_Quick.csv", ios::out);

	ofile << (title)->X << ","
		<< (title)->Y << ","
		<< (title)->OBJECTID << ","
		<< (title)->ID << ","
		<< (title)->NAME << ","
		<< (title)->ADDRESS << ","

		<< (title)->CITY << ","
		<< (title)->STATE << ","
		<< (title)->ZIP << ","
		<< (title)->ZIP4 << ","
		<< (title)->TELEPHONE << ","

		<< (title)->TYPE << ","
		<< (title)->STATUS << ","
		<< (title)->POPULATION << ","
		<< (title)->COUNTY << ","
		<< (title)->COUNTYFIPS << ","
		<< (title)->COUNTRY << ","

		<< (title)->LATITUDE << ","
		<< (title)->LONGITUDE << ","
		<< (title)->NAICS_CODE << ","
		<< (title)->NAICS_DESC << ","
		<< (title)->SOURCE << ","

		<< (title)->SOURCEDATE << ","
		<< (title)->VAL_METHOD << ","
		<< (title)->VAL_DATE << ","
		<< (title)->WEBSITE << ","
		<< (title)->ST_SUBTYPE << endl;

	for (auto it = info_vector.begin(); it != info_vector.end(); ++it)
	{
		ofile << (*it)->X << ","
			<< (*it)->Y << ","
			<< (*it)->OBJECTID << ","
			<< (*it)->ID << ","
			<< (*it)->NAME << ","
			<< (*it)->ADDRESS << ","

			<< (*it)->CITY << ","
			<< (*it)->STATE << ","
			<< (*it)->ZIP << ","
			<< (*it)->ZIP4 << ","
			<< (*it)->TELEPHONE << ","

			<< (*it)->TYPE << ","
			<< (*it)->STATUS << ","
			<< (*it)->POPULATION << ","
			<< (*it)->COUNTY << ","
			<< (*it)->COUNTYFIPS << ","
			<< (*it)->COUNTRY << ","

			<< (*it)->LATITUDE << ","
			<< (*it)->LONGITUDE << ","
			<< (*it)->NAICS_CODE << ","
			<< (*it)->NAICS_DESC << ","
			<< (*it)->SOURCE << ","

			<< (*it)->SOURCEDATE << ","
			<< (*it)->VAL_METHOD << ","
			<< (*it)->VAL_DATE << ","
			<< (*it)->WEBSITE << ","
			<< (*it)->ST_SUBTYPE << endl;
	}

	ofile.close();

	for (auto it = info_vector.begin(); it != info_vector.end(); ++it)
	{
		delete* it;
	}

	delete title;

	info_vector.clear();

}

void HybridSort(vector<Info*>& info_vector)
{

	ReadCsv(info_vector);

	if (info_vector.empty())
	{
		cout << "No Data Here." << endl;

		return;
	}

	int n = 21;

	int i, j;
	Info* key;
	for (i = 1; i < n; i++)
	{
		key = info_vector[i];
		key->NAME = info_vector[i]->NAME;

		j = i - 1;

		while (j >= 0 && info_vector[j]->NAME.length() > key->NAME.length())
		{
			info_vector[j + 1] = info_vector[j];
			j = j - 1;
		}

		info_vector[j + 1] = key;

	}

	quicksort(info_vector, 21, info_vector.size() - 1);


	ofstream ofile;

	ofile.open("Child_Care_Centers_Hybrid.csv", ios::out);

	ofile << (title)->X << ","
		<< (title)->Y << ","
		<< (title)->OBJECTID << ","
		<< (title)->ID << ","
		<< (title)->NAME << ","
		<< (title)->ADDRESS << ","

		<< (title)->CITY << ","
		<< (title)->STATE << ","
		<< (title)->ZIP << ","
		<< (title)->ZIP4 << ","
		<< (title)->TELEPHONE << ","

		<< (title)->TYPE << ","
		<< (title)->STATUS << ","
		<< (title)->POPULATION << ","
		<< (title)->COUNTY << ","
		<< (title)->COUNTYFIPS << ","
		<< (title)->COUNTRY << ","

		<< (title)->LATITUDE << ","
		<< (title)->LONGITUDE << ","
		<< (title)->NAICS_CODE << ","
		<< (title)->NAICS_DESC << ","
		<< (title)->SOURCE << ","

		<< (title)->SOURCEDATE << ","
		<< (title)->VAL_METHOD << ","
		<< (title)->VAL_DATE << ","
		<< (title)->WEBSITE << ","
		<< (title)->ST_SUBTYPE << endl;

	for (auto it = info_vector.begin(); it != info_vector.end(); ++it)
	{
		ofile << (*it)->X << ","
			<< (*it)->Y << ","
			<< (*it)->OBJECTID << ","
			<< (*it)->ID << ","
			<< (*it)->NAME << ","
			<< (*it)->ADDRESS << ","

			<< (*it)->CITY << ","
			<< (*it)->STATE << ","
			<< (*it)->ZIP << ","
			<< (*it)->ZIP4 << ","
			<< (*it)->TELEPHONE << ","

			<< (*it)->TYPE << ","
			<< (*it)->STATUS << ","
			<< (*it)->POPULATION << ","
			<< (*it)->COUNTY << ","
			<< (*it)->COUNTYFIPS << ","
			<< (*it)->COUNTRY << ","

			<< (*it)->LATITUDE << ","
			<< (*it)->LONGITUDE << ","
			<< (*it)->NAICS_CODE << ","
			<< (*it)->NAICS_DESC << ","
			<< (*it)->SOURCE << ","

			<< (*it)->SOURCEDATE << ","
			<< (*it)->VAL_METHOD << ","
			<< (*it)->VAL_DATE << ","
			<< (*it)->WEBSITE << ","
			<< (*it)->ST_SUBTYPE << endl;
	}

	ofile.close();

	for (auto it = info_vector.begin(); it != info_vector.end(); ++it)
	{
		delete* it;
	}

	delete title;

	info_vector.clear();
}


void heapify(vector<Info*>& info_vector, int size, int i)
{
	int max = i;

	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && info_vector[left]->NAME.length() > info_vector[max]->NAME.length())
		max = left;

	if (right < size && info_vector[right]->NAME.length() > info_vector[max]->NAME.length())
		max = right;

	if (max != i)
	{
		Info* temp = info_vector[i];
		info_vector[i] = info_vector[max];
		info_vector[max] = temp;

		heapify(info_vector, size, max);
	}
}

void HeapSort(vector<Info*>& info_vector)
{
	ReadCsv(info_vector);

	if (info_vector.empty())
	{
		cout << "No Data Here." << endl;

		return;
	}


	for (int i = info_vector.size() / 2 - 1; i >= 0; i--)
	{
		heapify(info_vector, info_vector.size(), i);
	}

	for (int i = info_vector.size() - 1; i >= 0; i--)
	{
		Info* temp = info_vector[0];
		info_vector[0] = info_vector[i];
		info_vector[i] = temp;

		heapify(info_vector, i, 0);
	}

	//for (auto it = info_vector.begin(); it != info_vector.end(); ++it)
	//{
	//	cout << (*it)->NAME << endl;
	//}

	ofstream ofile;

	ofile.open("Child_Care_Centers_Heap.csv", ios::out);

	ofile << (title)->X << ","
		<< (title)->Y << ","
		<< (title)->OBJECTID << ","
		<< (title)->ID << ","
		<< (title)->NAME << ","
		<< (title)->ADDRESS << ","

		<< (title)->CITY << ","
		<< (title)->STATE << ","
		<< (title)->ZIP << ","
		<< (title)->ZIP4 << ","
		<< (title)->TELEPHONE << ","

		<< (title)->TYPE << ","
		<< (title)->STATUS << ","
		<< (title)->POPULATION << ","
		<< (title)->COUNTY << ","
		<< (title)->COUNTYFIPS << ","
		<< (title)->COUNTRY << ","

		<< (title)->LATITUDE << ","
		<< (title)->LONGITUDE << ","
		<< (title)->NAICS_CODE << ","
		<< (title)->NAICS_DESC << ","
		<< (title)->SOURCE << ","

		<< (title)->SOURCEDATE << ","
		<< (title)->VAL_METHOD << ","
		<< (title)->VAL_DATE << ","
		<< (title)->WEBSITE << ","
		<< (title)->ST_SUBTYPE << endl;

	for (auto it = info_vector.begin(); it != info_vector.end(); ++it)
	{
		ofile << (*it)->X << ","
			<< (*it)->Y << ","
			<< (*it)->OBJECTID << ","
			<< (*it)->ID << ","
			<< (*it)->NAME << ","
			<< (*it)->ADDRESS << ","

			<< (*it)->CITY << ","
			<< (*it)->STATE << ","
			<< (*it)->ZIP << ","
			<< (*it)->ZIP4 << ","
			<< (*it)->TELEPHONE << ","

			<< (*it)->TYPE << ","
			<< (*it)->STATUS << ","
			<< (*it)->POPULATION << ","
			<< (*it)->COUNTY << ","
			<< (*it)->COUNTYFIPS << ","
			<< (*it)->COUNTRY << ","

			<< (*it)->LATITUDE << ","
			<< (*it)->LONGITUDE << ","
			<< (*it)->NAICS_CODE << ","
			<< (*it)->NAICS_DESC << ","
			<< (*it)->SOURCE << ","

			<< (*it)->SOURCEDATE << ","
			<< (*it)->VAL_METHOD << ","
			<< (*it)->VAL_DATE << ","
			<< (*it)->WEBSITE << ","
			<< (*it)->ST_SUBTYPE << endl;
	}

	ofile.close();

	for (auto it = info_vector.begin(); it != info_vector.end(); ++it)
	{
		delete* it;
	}

	delete title;

	info_vector.clear();
}



void menu()
{
	cout << "Sorting Test" << endl;
	cout << "a - Insertion Sort" << endl;
	cout << "b - Merge Sort" << endl;
	cout << "c - Quick Sort" << endl;
	cout << "d - Hybrid Quick Sort and Insertion Sort " << endl;
	cout << "e - Heapsort" << endl;

	cout << "q - Quit" << endl;

	cout << "Enter: ";
}

int main()
{
	clock_t start, end;

	vector<Info*> info_vector;

	string choice;
	menu();
	getline(cin, choice);

	cout << endl;

	while (choice != "q" && choice != "Q")
	{

		if (choice == "a" || choice == "A")
		{
			start = clock();
			InsertionSort(info_vector);
			end = clock();

			double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

			cout << endl;
			cout << "Time taken by program is : " << fixed
				<< time_taken << setprecision(5);
			cout << " sec " << endl;
		}

		else if (choice == "b" || choice == "B")
		{
			start = clock();
			MergeSort(info_vector);
			end = clock();

			double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

			cout << endl;
			cout << "Time taken by program is : " << fixed
				<< time_taken << setprecision(5);
			cout << " sec " << endl;
		}

		else if (choice == "c" || choice == "C")
		{
			start = clock();
			Quicksort(info_vector);
			end = clock();

			double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

			cout << endl;
			cout << "Time taken by program is : " << fixed
				<< time_taken << setprecision(5);
			cout << " sec " << endl;
		}

		else if (choice == "d" || choice == "D")
		{
			start = clock();
			HybridSort(info_vector);
			end = clock();

			double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

			cout << endl;
			cout << "Time taken by program is : " << fixed
				<< time_taken << setprecision(5);
			cout << " sec " << endl;
		}

		else if (choice == "e" || choice == "E")
		{
			start = clock();
			HeapSort(info_vector);
			end = clock();

			double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

			cout << endl;
			cout << "Time taken by program is : " << fixed
				<< time_taken << setprecision(5);
			cout << " sec " << endl;
		}

		cin.clear();
		cout << endl;

		menu();
		getline(cin, choice);
	}

	return 0;

}