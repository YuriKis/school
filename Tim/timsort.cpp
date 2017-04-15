#include <vector>
#include <stdlib.h>/*  rand */
#include <iostream>



int min(int a, int b) {
	return (b < a) ? b : a;
}
using namespace std;
struct Range {
	int start;
	int length;
};

// minrun
int minRunLength(int n) { 
	//if (n < 64) return n; от дебилов( как я)
	int r = 0;
	while (n >= 64) {
		n >>= 1;
		r |= n & 1;
	}
	return n + r;
}

// http://cforbeginners.com/insertionsort.html
void insertion_sort(vector<int> &arr, int start, int end) {
	for (int i = start + 1; i < end; ++i)
	{
		int current = arr[i];
		int j = i - 1;
		while ((j >= start) && (current < arr[j]))
		{
			swap(arr[j], arr[j + 1]);
			--j;
		}
	}
}

void print(vector<int> arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
}

void merge(vector<int> &arr, int fStart, int fLength, int sStart, int sLength) {
	int* tmp = new int[fLength];

	memcpy(tmp, &arr[fStart], sizeof(int)*(fLength));
	int fIndex = 0;
	int sIndex = sStart;
	int i = fStart;

	while (i < sStart + sLength - 1)
	{
		if (arr[sIndex] > tmp[fIndex])
		{
			arr[i] = tmp[fIndex];
			++fIndex;
			fIndex = min(fIndex, fLength);
		}
		else if (arr[sIndex] <= tmp[fIndex])
		{
			arr[i] = arr[sIndex];
			++sIndex;
			sIndex = min(sIndex, sLength+sStart);
		}
		if (sIndex == sStart + sLength)
		{
			if (fIndex != fLength)
			{
				memcpy(&arr[i + 1], &tmp[fIndex], sizeof(int)*(fLength - fIndex));
				i = sStart + sLength;
			}
		}
		if (fIndex == fLength)
		{
			i = sStart + sLength;
		}
		++i;
	}
	delete[] tmp;
}

void sortTimsort(vector<int> &arr, int n) {

	//Minrun calc
	int minrun = minRunLength(n);

	std::vector <Range> minrunStack;

	//divide
	int currentIndex = 0;
	while (currentIndex < n - 1) {
		int currentRunIndex = currentIndex;
		int nextIndex = currentRunIndex + 1;

		if (arr[currentRunIndex] > arr[nextIndex])
		{
			swap(arr[currentRunIndex], arr[nextIndex]);
		}

		bool goNext = true;
		while (goNext)
		{
			if (arr[currentRunIndex] > arr[nextIndex])
				goNext = false;
			if (!(goNext) && (currentRunIndex - currentIndex < minrun))
				goNext = true;
			if (currentRunIndex == n - 1)
				goNext = false;
			if (goNext)
			{
				++currentRunIndex;
				++nextIndex;
			}
		}
		insertion_sort(arr, currentIndex, currentRunIndex + 1);

		Range r;
		r.start = currentIndex;
		r.length = currentRunIndex - currentIndex;

		minrunStack.push_back(r);

		currentIndex = currentRunIndex;
	}
	
	//merge
	while (minrunStack.size() > 1)
	{
		Range x = minrunStack.at(0);
		minrunStack.erase(minrunStack.begin());
		Range y = minrunStack.at(0);
		minrunStack.erase(minrunStack.begin());
		if (x.start > y.start)
		{
			swap(x.start, y.start);
			swap(x.length, y.length);
		}
		if (y.start != x.start + x.length)
		{
			minrunStack.push_back(y);
			minrunStack.push_back(x);
			continue;
		}
		merge(arr, x.start, x.length, y.start, y.length);
		x.length = x.length + y.length;
		minrunStack.push_back(x);
	}

}


#include <windows.h>
#include <stdio.h>

class Timing {
public:
	void StartTiming();
	void StopTiming();
	double GetUserSeconds() const {
		return double(m_userTime) / 10000000.0;
	}
private:
	__int64 GetUserTime() const;
	__int64 m_userTime;
};
__int64 Timing::GetUserTime() const {
	FILETIME creationTime;
	FILETIME exitTime;
	FILETIME kernelTime;
	FILETIME userTime;
	GetThreadTimes(GetCurrentThread(),
		&creationTime, &exitTime,
		&kernelTime, &userTime);
	__int64 curTime;
	curTime = userTime.dwHighDateTime;
	curTime <<= 32;
	curTime += userTime.dwLowDateTime;
	return curTime;
}
void Timing::StartTiming() {
	m_userTime = GetUserTime();
}
void Timing::StopTiming() {
	__int64 curUserTime = GetUserTime();
	m_userTime = curUserTime - m_userTime;
}

class Timing2 {
public:
	void StartTiming();
	void StopTiming();
	double GetUserSeconds() const {
		return value;
	}
private:
	DWORD_PTR oldmask;
	double value;
	LARGE_INTEGER time1;
};
void Timing2::StartTiming() {
	oldmask = SetThreadAffinityMask(::GetCurrentThread(), 1);
	QueryPerformanceCounter(&time1);
}
void Timing2::StopTiming() {
	LARGE_INTEGER performance_frequency, time2;
	QueryPerformanceFrequency(&performance_frequency);
	QueryPerformanceCounter(&time2);
	SetThreadAffinityMask(::GetCurrentThread(), oldmask);
	value = (double)(time2.QuadPart - time1.QuadPart);
	value /= performance_frequency.QuadPart;
}


//quicksort
int partition(vector<int> &arr, int start, int end) {
	int marker = start;
	for (int i = start; i <= end; i++)
	{
		if (arr[i] <= arr[end])
		{
			int temp = arr[marker]; // swap
			arr[marker] = arr[i];
			arr[i] = temp;
			marker += 1;
		}
	}
	return marker - 1;
}
void quicksort(vector<int> &arr, int start, int end) {
	//std::cout << "quicksort s= " << start << " e= " << end << " arr[] = ";
	//for (int i = 0; i<end; i++) std::cout << arr[i] << " ";
	//std::cout << "" << '\n';
	if (start >= end) return;
	int pivot = partition(arr, start, end);
	quicksort(arr, start, pivot - 1);
	quicksort(arr, pivot + 1, end);
}

#include <random>

int randomB(int n = 10) {
	/* Seed */

	//if (n > 10 && n < 0) return 1;

	std::random_device rd;

	/* Random number generator */
	std::default_random_engine generator(rd());

	long long unsigned a = 0xFFFFFFFFFF;
	switch (n) {
	case 1: a = 0xF; break;
	case 2: a = 0xFF; break;
	case 3: a = 0xFFF; break;
	case 4: a = 0xFFFF; break;
	case 5: a = 0xFFFFF; break;
	case 6: a = 0xFFFFFF; break;
	case 7: a = 0xFFFFFFF; break;
	case 8: a = 0xFFFFFFFF; break;
	case 9: a = 0xFFFFFFFFF; break;
	default:
		break;
	}




	std::uniform_int_distribution<long long unsigned> distribution(0, a);
	/* Distribution on which to apply the generator */
	

	return (int)distribution(generator);
}

#include <string> 
void sysF(string s,string f) {
	s = "echo " + s + " >> " + f;
	system(s.c_str());
}

double timeS(int n, int r=10, bool tim=true) {
	

	Timing2 t2;
	vector<int> vec(n); for (int i = 0; i < n; i++) vec[i] = randomB(r); // random vector
	t2.StartTiming();

	if(tim) sortTimsort(vec, n);
	else    quicksort(vec, 0, n - 1);
	
	t2.StopTiming();
	return t2.GetUserSeconds();
}

int main() {
	int c = 0;
	//
	double ti_t;
	double ti_q;

	int n = 0;
	for (int r = 1; r < 11; r++) {
		for (n = 100; n < 100000; n += 500) {
			for (int f = 0; f < 2; f++) {
				if(f==0) ti_t = timeS(n, r);
				else     ti_q = timeS(n, r, false);
			}
			sysF(string(to_string(r)+ "\t" + to_string(n) + "\t" + to_string(ti_t)+ "\t" + to_string(ti_q)), string("3d_ti.txt"));
		}
		
	}
	//cout << timeS(5, 1000) << "\n";
	system("pause");
	return 0;
}


/*
system("cls"); cout << 100.0 - (double)n/1000.0<<"%";// progress
sysF(string(to_string(n)+"\t"/to_string(ti)), string("ti_q.txt"));

for (n = 100; n < 100000; n += 500) {

cout << "*** t = " << ti << " s = " << sum << " c= " << c;
system("pause>>NULL");
*/