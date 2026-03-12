#ifndef MERGE_ME_HPP
#define MERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

struct RecursionLevel {
	std::vector<int> main;
	std::vector<int> pend;

	bool hasSgruggler;
	int struggler;
	int recursionDepth;

	RecursionLevel() : hasSgruggler(false), struggler(0), recursionDepth(0) {}
};


template <typename Container>
class PmergMe {

	public:
		PmergMe(Container input) : _input(input) {}
		~PmergMe() {}

		Container sort() {

			if (is_sorted(_input)) return _result;

			// recursive_sort(_input);
			std::list<RecursionLevel>::iterator it = _main_sort_list.begin();
			for (; it != _main_sort_list.end(); ++it)
			{
				std::cout << "main: ";
				for (size_t i = 0; i < it->main.size(); i++) {
					std::cout << it->main.at(i) << " ";
				}
				std::cout << std::endl;

				std::cout << "pend: ";
				for (size_t i = 0; i < it->pend.size(); i++) {
					std::cout << it->pend.at(i) << " ";
				}
				std::cout << std::endl;

				if (it->hasSgruggler) std::cout << "struggler: " << it->struggler << std::endl;

				std::cout << "depth: " << it->recursionDepth << "\n";
				std::cout << std::endl;
			}

			// insertion();

			std::vector<int> sequence = generate_cequesnce(50);

			std::cout << "final Jacob seq: ";
			for (size_t i = 0; i < sequence.size(); i++) {
				std::cout << sequence.at(i) << " ";
			}
			std::cout << "\n" << std::endl;

			fill_sequence(sequence);

			return _result;
		}

	private:
		Container _input;
		Container _result;
		std::list<RecursionLevel> _main_sort_list;
		std::vector<int> _jacobsthal;

		bool is_sorted(Container input) {
			for(size_t i = 0; i < input.size(); i++) {
				if (input.at(i) > input.at(i+1)) return false;
			}
			return true;
		}
		std::vector<int> rearrange_pend(const RecursionLevel& input) {
			// we should create new temp pend based on the positions of the main index.
			// 1. iterate over result and compare value to main values of this level,
			// if values are rqual -> copy pend element to temp,
			// if values are differ (search for the element) iterate? over origial main to find index of the element and based on that index copy pend to temp pend.

			std::vector<int> rearranged_pend;

			std::cout << "starting pend rearrangment..." << "\n" << std::endl;

			for (size_t i = 0; i < _result.size(); i++) {

				std::cout << "result: " << _result.at(i) << "\n"
						  << "main: " << input.main.at(i) << "\n"
						  << std::endl;

				if (_result.at(i) == input.main.at(i)) {
					std::cout << "found in first block: " << input.main.at(i) << " at index: " << i << "\n" << std::endl;
					rearranged_pend.push_back(input.pend.at(i));
				}
				else {
					for (size_t j = 0; j < input.main.size(); j++) {
						if(_result.at(i) == input.main.at(j)) {
							std::cout << "found in second block: " << input.main.at(j) << " at index: " << j << "\n" << std::endl;
							rearranged_pend.push_back(input.pend.at(j));
							break;
						}
						// should detect if result is missing from main.
						// else if (j == input.main.size() - 1 && _result.at(i) != input.main.at(j))
						// 	std::cout << "not found" << "\n" << std::endl;
					}
				}
			}
			return rearranged_pend;
		}
		std::vector<int> generate_cequesnce(int len) {
			// 1. generate sequence based on formula // J(n) = (2^n - (-1)^n) / 3  or iterative - J(i) = J(i-1) + 2*J(i-2)
			// 2. stop generation at len. (last operation should find most sutable nuber in a group of numbers for example: if len is 9 sequenve should be [0][1][3][5][9])
			// 2. all the missing values in cequesnce should be inserted in betveen the sequence blocks in reverce order (for example with sequence [0][1][3][5][9] it should become [0][1][3 2] [5 4] [9 8 7 6])
			std::vector<int> seq;
			if (len == 1) {
				seq.push_back(0);
				return seq;
			}
			if (len == 2) {
				seq.push_back(0);
				seq.push_back(1);
				return seq;
			}

			seq.push_back(0);

			int prev2 = 0;
			int prev1 = 1;
			int curr;
			while(true) {
				curr = prev1 + 2 * prev2;

				// std::cout << "current: " << curr << " len: " << len - 1 << std::endl;
				if (curr > len - 1) {
					seq.push_back (len - 1);

					/* int buff_curr = curr;
					while (buff_curr >= len - 1) {

						std::cout << "buff_curr: " << buff_curr << std::endl;
						if (buff_curr == len - 1)
							seq.push_back (buff_curr);
						buff_curr -= 1;
					} */

					/* int buff_curr = curr;
					for (int j = curr; j > prev1; j--) {
						std::cout << "buff_curr: " << buff_curr << std::endl;
						if (buff_curr == len - 1)
							seq.push_back (buff_curr);
						buff_curr -= 1;
					} */

					std::cout << "current seq: ";
					for (size_t k = 0; k < seq.size(); k++) {
						std::cout << seq.at(k) << " ";
					}
					std::cout << std::endl;

					break;
				}
				else {
					seq.push_back (curr);
				}

				std::cout << "current seq: ";
				for (size_t k = 0; k < seq.size(); k++) {
					std::cout << seq.at(k) << " ";
				}
				std::cout << std::endl;

				prev2 = prev1;
				prev1 = curr;
			}

			return seq;
		}

		std::vector<int> fill_sequence(std::vector<int> seq) {
			std::vector<int> filled;
			filled.push_back(0);
			filled.push_back(1);

			int block = seq.at(2);
			for (size_t i = 2; i < seq.size(); i++) {

				block = seq.at(i);

				std::cout << "bloc: " << block << std::endl;
				while (block != seq.at(i - 1)) {
					filled.push_back(block);
					block -= 1;
				}
			}

			std::cout << "filled seq: ";
			for (size_t i = 0; i < filled.size(); i++) {
				std::cout << filled.at(i) << " ";
			}
			std::cout << "\n" << std::endl;

			return filled;
		}
		/* split elements in to main (larger) and pend (smaller) recursevly - uneven goes to last positon of pend) */
		void recursive_sort(Container input, int depth = 0) {

			RecursionLevel level;
			level.recursionDepth = depth;

			size_t input_size = input.size();

			for (size_t i = 0; i + 1 < input_size; i += 2) {
				int a = input[i];
				int b = input[i + 1];

				if (a > b) std::swap(a,b);

				level.main.push_back(b);
				level.pend.push_back(a);
			}

			if (input.size() % 2 == 1) {
				level.hasSgruggler = true;
				level.struggler = input.back();
				level.pend.push_back(input.back());
			}

			_main_sort_list.push_back(level);

			/*
			std::cout << "main: ";
			for(size_t i = 0; i < level.main.size(); i++) {
				std::cout << level.main[i] << " ";
			}
			std::cout << std::endl;

			std::cout << "pend: ";
			for(size_t i = 0; i < level.pend.size(); i++) {
				std::cout << level.pend[i] << " ";
			}
			std::cout << std::endl;

			if(level.hasSgruggler) {
				std::cout << "struggler: " << level.struggler << std::endl;
				// std::cout << std::endl;
			}
			std::cout << "depth: " << level.recursionDepth << "\n" << std::endl;
			*/

			if(level.main.size() > 1) {
				recursive_sort(level.main,level.recursionDepth + 1);
			}
		}
		void insertion() {

			std::list<RecursionLevel>::reverse_iterator it = _main_sort_list.rbegin();

			_result.push_back(it->pend.at(0));
			_result.push_back(it->main.at(0));
			if (it->pend.at(1)){
				typename Container::iterator pos = std::lower_bound(_result.begin(), _result.end(), it->pend.at(1));
				_result.insert(pos, it->pend.at(1));
			}

			std::cout << "insertion depth " << it->recursionDepth << std::endl;
			std::cout << "result after first unwind: ";
			for (size_t i = 0; i < _result.size(); i++) {
				std::cout << _result.at(i)  << " ";
			}
			std::cout << "\n" << std::endl;

			++it;

			for (; it != _main_sort_list.rend(); ++it) {
				std::cout << "insertion depth " << it->recursionDepth << std::endl;
				// do these steps on each level of recursion
				// 1. rearrange pend posions based on current main positions
				// 2. generate Jacobs sequence on each recursion depth based on pend len (its our insertion order)
				// 3. use sequence to binary search for an insertion position
				// 4. move to next level of depth

				std::vector<int> rearranged_pend = rearrange_pend(*it);

				std::cout << "main: ";
				for (size_t i = 0; i < it->main.size(); i++) {
					std::cout << it->main.at(i) << " ";
				}
				std::cout << std::endl;

				std::cout << "pend: ";
				for (size_t i = 0; i < it->pend.size(); i++) {
					std::cout << it->pend.at(i) << " ";
				}
				std::cout << "\n" << std::endl;

				std::cout << "current result: ";
				for (size_t i = 0; i < _result.size(); i++) {
					std::cout << _result.at(i)  << " ";
				}
				std::cout << std::endl;

				std::cout << "new pend:       ";
				for (size_t i = 0; i < rearranged_pend.size(); i++) {
					std::cout << rearranged_pend.at(i) << " ";
				}
				std::cout << "\n" << std::endl;

				std::vector<int> sequence = generate_cequesnce(rearranged_pend.size());

				std::cout << "final Jacob seq: ";
				for (size_t i = 0; i < sequence.size(); i++) {
					std::cout << sequence.at(i) << " ";
				}
				std::cout << "\n" << std::endl;
			}
		}
};

#endif
