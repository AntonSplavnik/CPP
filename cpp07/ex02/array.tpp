/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:42:54 by antonsplavn       #+#    #+#             */
/*   Updated: 2025/08/31 20:07:10 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array()
	: data(nullptr), _size(0){}

template<typename T>
Array<T>::Array (unsigned int n)
	: _size(n){
	if(n == 0)
		data = nullptr;
	else
		data = new T[n]();
}

template<typename T>
Array<T>::Array(const Array<T>& other): _size(other._size){
	if(_size == 0)
		data = nullptr;
	else{
		data = new T[_size];
		for (size_t i = 0; i < _size; i++)
			data[i] = other.data[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other){

	if(this != &other){

		delete[] data;
		_size = other._size;
		if(_size == 0)
			data = nullptr;
		else{
			data = new T[_size];
			for (size_t i = 0; i < _size; i++)
				data[i] = other.data[i];
		}
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](size_t index){
	if(index >= _size || index < 0)
		throw IndexOutOfBounds();
	else
		return data[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const{
	if(index >= _size || index < 0)
		throw IndexOutOfBounds();
	else
		return data[index];
}

template<typename T>
Array<T>::~Array(){delete[] data;}

template<typename T>
unsigned int Array<T>::size() const {return _size;}
