//Name: Rujal Tuladhar
//Id: 154594188
//email: rtuladhar@myseneca.ca
//I have done this workshop9 on my own using the notes provided by the proffesor


// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.

		//creating 4 threads
		size_t value = nbytes / 4;
	
			thread t1(std::bind(converter, text, key, value, Cryptor()));
			thread t2(std::bind(converter, text + value, key, value, Cryptor()));
			thread t3(std::bind(converter, text + value*2, key, value, Cryptor()));
			thread t4(std::bind(converter, text + value*3, key, value, Cryptor()));

			t1.join();
			t2.join();
			t3.join();  
			t4.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			 ofstream the_file (file, ios::binary | ios::out);
			if (!the_file)
			{
				throw"Error while opening !";
			}

			// TODO: write data into the binary file
			//         and close the file
			
			the_file.write(text, nbytes);
			the_file.close();

		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		 ifstream a_file(file, ios::in | ios::binary);
		if (!a_file)
		{
			throw"Error while opening the file !";
		}

		// TODO: - allocate memory here for the file content
		//since char type we add +1 during alloc
		if (text)
			delete[] text;
		a_file.seekg(0, std::ios::end);

		nbytes = (int)a_file.tellg();
		text = new char[nbytes + 1];

		// TODO: - read the content of the binary file
		a_file.seekg(0, std::ios::beg);
		a_file.read(text, nbytes);
		
		a_file.close();
	

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}