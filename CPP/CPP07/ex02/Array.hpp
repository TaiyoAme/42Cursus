/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:55:44 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/26 17:40:51 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <exception>
#include <iostream>
template <typename T>
class Array
{

public:
	Array():size_(0), data_(nullptr)
	{
			std::cout << "Array DEFAULT constructor called" << std::endl;
	}
	Array(unsigned int n): size_(n), data_(new T[n])
	{
		for(int i = 0; i < n; i++)
			data_[i] = T();
	}
	Array(const Array&  copy):size_(copy.size_), data_(new T[copy.size_])
	{
		std::cout << "Array COPY Constructor called" << std::endl;
		for (int i = 0; i < copy.size_; i++) {
			this->data_[i] = copy.data_[i];
		}
	}
	Array &operator=(const Array& copy)
	{
		std::cout << "Array COPY assignment called" << std::endl;
		if (this != &copy)
		{
			delete[] this->data_;
			this->data_ = new T[copy.size_];
			for (int i = 0; i < copy.size_; i++) {
				this->data_[i] = copy.data_[i];
			}
			this->size_ = copy.size_;
		}
		return(*this);
	}
	~Array()
	{
		std::cout << "Array Deconstructor called" << std::endl;
		delete[] this->data_;
	}

	T	&operator[](size_t index)
	{
		if (index >= this->size_)
		{
			throw IndexOutOfBoundException();
		}
		return (this->data_[index]);
	}

	class IndexOutOfBoundException : public std::exception{
	public:
		const char * what() const noexcept override
		{
			return ("IndexOutOfBoundException\n");
		}

	private:
		
	};
	size_t size() const 
	{
		return (this->size_);
	}
private:
	size_t size_;
	T *data_;	
};
