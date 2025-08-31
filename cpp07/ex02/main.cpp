/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:55:35 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/31 21:35:35 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"
#include <iostream>


int main() {

	std::cout << "=== Array Template Tests ===" << std::endl;

	Array<int>* array = new Array<int>(3);
	(*array)[2] = 42;

	// Test 1: Default constructor (empty array)
	std::cout << "\n1. Default constructor test:" << std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	// Test 2: Parameterized constructor
	std::cout << "\n2. Parameterized constructor test:" << std::endl;
	Array<int> arr(5);
	std::cout << "Array size: " << arr.size() << std::endl;

	// Test 3: Element assignment and access
	std::cout << "\n3. Element assignment and access:" << std::endl;
	for (size_t i = 0; i < arr.size(); i++) {
		arr[i] = static_cast<int>(i * 10);
	}

	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}

	// Test 4: Copy constructor
	std::cout << "\n4. Copy constructor test:" << std::endl;
	Array<int> copy(arr);
	std::cout << "Copy size: " << copy.size() << std::endl;
	std::cout << "Original arr[2]: " << arr[2] << std::endl;
	std::cout << "Copy copy[2]: " << copy[2] << std::endl;

	// Modify copy to test deep copy
	copy[2] = 999;
	std::cout << "After modifying copy[2] to 999:" << std::endl;
	std::cout << "Original arr[2]: " << arr[2] << std::endl;
	std::cout << "Copy copy[2]: " << copy[2] << std::endl;

	// Test 5: Assignment operator
	std::cout << "\n5. Assignment operator test:" << std::endl;
	Array<int> assigned(3);
	for (size_t i = 0; i < assigned.size(); i++) {
		assigned[i] = static_cast<int>(i + 100);
	}
	std::cout << "Before assignment - assigned[1]: " << assigned[1] << std::endl;

	assigned = arr;
	std::cout << "After assignment - assigned[1]: " << assigned[1] << std::endl;
	std::cout << "Assigned size: " << assigned.size() << std::endl;

	// Test 6: Const array access
	std::cout << "\n6. Const array test:" << std::endl;
	const Array<int> constArr = arr;
	std::cout << "Const array size: " << constArr.size() << std::endl;
	std::cout << "Const array[1]: " << constArr[1] << std::endl;

	// Test 7: Different types
	std::cout << "\n7. String array test:" << std::endl;
	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "World";
	strArr[2] = "!";

	for (size_t i = 0; i < strArr.size(); i++) {
		std::cout << "strArr[" << i << "] = " << strArr[i] << std::endl;
	}

	// Test 8: Exception handling - out of bounds access
	std::cout << "\n8. Exception handling test:" << std::endl;
	try {
		std::cout << "Trying to access arr[100]..." << std::endl;
		std::cout << arr[100] << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to access empty[0]..." << std::endl;
		std::cout << empty[0] << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	// Test 9: Self-assignment
	std::cout << "\n9. Self-assignment test:" << std::endl;
	Array<int>& arrRef = arr;
	arr = arrRef;  // Test self-assignment through reference
	std::cout << "After self-assignment, arr[2]: " << arr[2] << std::endl;


	// Test 10: Heap allocation
	std::cout << "\n10. Heap allocation test:" << std::endl;
	Array<int>* heapArray = new Array<int>(3);
	(*heapArray)[2] = 42;

	for (size_t i = 0; i < heapArray->size(); i++) {
		std::cout << "heapArray[" << i << "] = " << (*heapArray)[i] << std::endl;
	}
	delete heapArray;

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
