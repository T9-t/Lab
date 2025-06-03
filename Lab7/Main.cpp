#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;

void Yes_No();
void Common_letters();
void Repeated_words();

void vect_in(vector<int>& cop);
void vect_count(vector<int>& cop);
void vect_sum(vector<int>& cop);
void vect_sort(vector<int>& cop);
void vect_swap(vector<int>& cop);

template <typename C>//Задание 1
void Print(C& container, string delimeter) {

	int len = container.size(), count_end = 0;

	for (auto e : container) {

		cout << e;

		if (count_end != (len - 1)) {
			cout << delimeter;
		}
		count_end++;
	}
}

template <typename T>//Задание 5
void Duplicate(std::vector<T>& v) {

	auto end_it = v.end();
	vector<T> new_v;

	for (auto iter = v.begin(); iter != end_it; ++iter) {
		new_v.push_back(*iter);
	}
	for (int i = 0; i<new_v.size(); i++) {
		v.push_back(new_v[i]);
	}
}

template <typename Iter>//Задание 6
void PrintResults(Iter first, Iter last)
{
	for (Iter it = first; it != last; ++it) {
		std::cout << *it << std::endl;
	}
}

template <typename T>
void Process(const std::vector<T>& data) {
	std::vector<T> filtered;

	std::copy_if(
		data.begin(),
		data.end(),
		back_inserter(filtered),
		[](const T& x) { return x > 0; }
	);

	PrintResults(filtered.begin(), filtered.end());
}

template <typename Iter>//Задание 7
Iter Unique(Iter first, Iter last) {

	auto end = first;
	auto last_it = --last; ++last;

	sort(first, last);

	for (Iter it = first; it != last; ++it) {
		
		auto it_it = ++it; --it;

		for (Iter it_second = it_it; it_second != last; ++it_second) {
			if (count(first, it_second, *it_second) != 0 && it_second != last_it) {

				auto cop_it = *(++it_second);
				--it_second;
				auto cop_it_now = *it_second;
				
				*(++it_second) = cop_it_now;
				--it_second;
				*it_second = cop_it;
			}
		}
	}
	for (Iter it = first; it != last; ++it) {
		if (count(first, it, *it) == 0) {

			end = it;
		}
	}
	return ++end;
}

int main() {

	//********************************************************* 1,5 
	vector<int> number{ 1,5,6,11 };
	Print<vector<int>>(number, "\n");
	cout << "\n************************\n";

	Duplicate<int>(number);
	Print<vector<int>>(number, "\n");
	cout << "\n************************\n";
	//********************************************************* 2
	
	Yes_No();
	cout << "************************\n";
	//********************************************************* 3

	Common_letters();
	cout << "\n************************\n";
	//********************************************************* 4

	Repeated_words();
	cout << "\n************************\n";
	//********************************************************* 6

	vector<int> number_2{ 1,-10,5,-3,4 };
	Process<int>(number_2);
	cout << "************************\n";
	//********************************************************* 7
	
	vector<int> numbers{ 1,10,10,3,3,4,5,5,8,9,9 };
	
	cout << "Start:\n";
	Print<vector<int>>(numbers, " ");
	auto end = Unique<>(numbers.begin(),numbers.end());
	
	cout << "\nEnd:\n";
	for (auto it = numbers.begin(); it != end; ++it) {
		cout << *it << " ";
	}
	cout << "\n************************\n";
	//********************************************************* 8

	vector<int> cop_list;
	vect_in(cop_list);

	vect_count(cop_list);
	cout << "\n************************\n";
	vect_sum(cop_list);
	cout << "\n************************\n";
	vect_sort(cop_list);
	cout << "\n************************\n";
	vect_swap(cop_list);
	cout << "\n************************\n";

	return 0;
}

void Yes_No() {// Задание 2
	
	set<int> set;
	vector<string> Yes_No;
	int n;

	cout << "The number of characters you want to enter: ";
	cin >> n;
	cout << "Enter numbers:\n";

	for (int i = 0; i < n; i++) {

		int number;
		cin >> number;

		if (set.count(number) > 0) {
			Yes_No.push_back("YES");
		}
		else {
			Yes_No.push_back("NO");
		}
		set.insert(number);
	}
	for (int i = 0; i < n; i++) {

		cout << Yes_No[i] << "\n";
	}
}

void Common_letters() {//Задание 3

	set<char> letters_first, result;
	int n;string word;

	cout << "The number of word you want to enter: ";
	cin >> n;

	cout << "Enter word:\n";
	cin >> word;

	for (int j = 0; j < word.size(); j++) {

		letters_first.insert(word[j]);
	}
	for (int i = 1; i < n; i++) {

		cin >> word;

		set<char> letters_second;

		for (int j = 0; j < word.size(); j++) {

			letters_second.insert(word[j]);
		}
		set_intersection(letters_first.begin(), letters_first.end(), letters_second.begin(), letters_second.end(),inserter(result,result.begin()));
		letters_first = result;
	}
	cout << "Result (Common letters): ";
	Print<set<char>>(result, ", ");
}

void Repeated_words() {//Задание 4

	map<string, int> map; 
	vector<int> repeated; 
	int n;

	cout << "The number of word you want to enter: ";
	cin >> n;
	cout << "Enter word:\n";

	for (int i = 0; i < n; i++) {

		string word;
		
		cin >> word;

		++map[word];
		repeated.push_back(map[word]);
	}
	cout << "Result (Repeated words): ";
	Print<vector<int>>(repeated, ", ");
}

//********************************************************* 8
void vect_in(vector<int>& cop){

	ifstream vector_read("list_vec.txt");

	for (int x; vector_read >> x;) {

		cop.push_back(x);
	}
	vector_read.close();
}

void vect_count(vector<int>& cop){
	
	vector<int> pos;
	int n;

	cout << "Enter the number you are looking for: ";
	cin >> n;

	cout << "Quantity in vector: " << count(cop.begin(), cop.end(), n) << endl;

	for (int i = 0; i < cop.size(); i++) {
		if (cop[i] == n) {
			pos.push_back(i);
		}
	}
	cout << "Positions in vector: ";
	Print<vector<int>>(pos, " ");
}

void vect_sum(vector<int>& cop){

	vector<int> pos;
	int count_x = count_if(cop.begin(), cop.end(), [](int& x) {return x % 2 == 0; }), sum_all = 0 , sum_2 = 0;
	cout << "Number of even elements in a vector: " << count_x << endl;

	for (int i = 0; i < cop.size(); i++) {
		if (cop[i] %2 == 0) {
			pos.push_back(i);
			sum_2 += cop[i];
		}
	}
	cout << "Positions in vector: ";
	Print<vector<int>>(pos, " ");
	sum_all = sum_2;
	cout << "\n";

	if ((cop.size() - count_x) < count_x) {
		cout << "Sum of even elements: " << sum_2 << endl;
	}
	else {
		for (int i = 0; i < cop.size(); i++) {
			if (cop[i] % 2 != 0) {
				sum_all += cop[i];
			}
		}
		cout << "Sum of all elements: " << sum_all << endl;
	}
}

void vect_sort(vector<int>& cop){

	cout << "Start: ";
	Print<vector<int>>(cop, " ");
	sort(cop.begin(),cop.end());
	cout << "\nEnd: ";
	Print<vector<int>>(cop, " ");
}

void vect_swap(vector<int>& cop){
	
	swap(cop[0], cop[cop.size() - 1]);
	cout << "swap vector: ";
	Print<vector<int>>(cop, " ");
}