#ifndef __VALUE_H__
#define __VALUE_H__

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>


class Value{
	public:
		Value(const std::string &type, const std::string &help_message) : 
			type(type), help_message(help_message){}

		~Value(){}

		void print(){
			std::cout << type << " " << help_message << std::endl;
		}

		std::string getHelpMessage(){
			return help_message;
		}

	private:
		std::string type;
		std::string help_message;
};


template<typename T>
class TypedValue : public Value{
	public:
		TypedValue(const T& default_value, const std::string &type, const std::string &help_message) : 
			Value(type, help_message), value(default_value){}

		~TypedValue() : ~Value::Value(){}

		void print(){
			Value::print();
			std::cout << value << std::endl;
		}

		void setValue(const T& value_){
			value = value_;
		}

	private:
	    T value;
};

#endif