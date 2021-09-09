//Rujal Tuladhar
//id: 154594188
//email – rtuladhar@myseneca.ca
//I have done this workshop on my own by using only the material provided by my professor.



#include "SongCollection.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<algorithm>

using namespace std;
namespace sdds
{
	void SongCollection::remov(std::string& line)
	{
	
		size_t i = 0u;
		for (i = 0u; i < line.length() && line[i] == ' '; ++i);
		line = line.substr(i);
		for (i = line.length(); i > 0u && line[i - 1] == ' '; --i);
		line = line.substr(0, i);
	}

	SongCollection::SongCollection(const std::string obj)
	{
		fstream the_file(obj);
		string line;
		//creating a localobject of Song
		Song ex;

		//temp name
		string artist, title, album;

		if (!the_file)
		{
			throw "Incorect filename";
		}
		else
		{
			//reading the file and extracting the values and assigning them in the correct places
			while (!the_file.eof())
			{


				std::getline(the_file, line,'\n');

			     
				title = line.substr(0, 25);
				remov(title);

				ex.m_title = title;


				artist = line.substr(25, 25);
				remov(artist);

				ex.m_artist = artist;

				album = line.substr(50, 25);
				remov(album);

				ex.m_album = album;


				string year = line.substr(75, 5);
				remov(year);
				
				ex.m_year = year;

				string length = line.substr(80, 5);
				remov(length);
				ex.m_lenth = stoi(length);

				string price = line.substr(85, 5);
				remov(price);
				ex.m_price = stod(price);

				s.push_back(ex);

			}
		}

	}

	//using different algorithm mehods for each of the function provided 

	int the_size = 0;
	void SongCollection::display(std::ostream& out) const
	{
		//alogorithm::for_each()
		for_each(s.begin(), s.end(), [=](Song ex) {cout << ex<<endl; });
		the_size = 0;

		for_each(s.begin(), s.end(), [=](Song ex) { the_size += ex.m_lenth; });
		
		
		int min;
		int sec;
		int hrs;
		min = (the_size % 3600) / 60;
		sec = (the_size % 3600) % 60;
		hrs = (the_size / 3600);

	     
		out << setw(89) << setfill('-') << '\n' << setfill(' ');

		out << "| " << std::right << std::setw(77) << "Total Listening Time: "<<hrs<<":"<<min<<":"<<sec << right << " |"<<endl;


		

	}



	


	void SongCollection::sort(std::string the_value)
	{
		//algorithm::sort () methof
		
		if (the_value == "title")
		{
			std::sort(s.begin(), s.end(), [](Song first, Song second) {return first.m_title < second.m_title; });

		}
		else if (the_value == "album")
		{
			std::sort(s.begin(), s.end(), [](Song first, Song second) {return first.m_album < second.m_album; });

		}
		else if (the_value == "length")
		{
			std::sort(s.begin(), s.end(), [](Song first, Song second) {return first.m_lenth < second.m_lenth; });

		}

	}

	bool SongCollection::inCollection(std::string the_artist) const
	{
		//algorithm::any_of method

		return std::any_of(s.begin(), s.end(), [&the_artist](const Song& artist) {return the_artist == artist.m_artist; });
	}

	void SongCollection::cleanAlbum()
	{
		vector<Song> v1;

		//algorithm::transform
		std::transform(s.begin(), s.end(), s.begin(), [=](Song& clean_song) {if (clean_song.m_album == "[None]") clean_song.m_album = ""; { return clean_song;  } });
	}



	std::list<Song> SongCollection::getSongsForArtist(std::string the_name) const
	{
		//algorithm::copy_if method
		std::list<Song> s2;

		
		std::copy_if(s.begin(), s.end(), back_inserter(s2), [&the_name](const Song& the_artist) {return the_name == the_artist.m_artist; });


		return s2;

	}



	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		out << "| " << std::setw(20) << std::left << theSong.m_title << " | ";
		out << std::setw(15) << std::left << theSong.m_artist;
		out<< " | " << std::setw(20) << std::left << theSong.m_album;
		out << " | " << std::setw(6) << std::right << theSong.m_year;
		
		out << " | " << (theSong.m_lenth) / 60 << ":" << std::setw(2) << std::setfill('0');
		out << (theSong.m_lenth) % 60 << std::setfill(' ') << " | " << theSong.m_price;
		out	<< " |";

		return out;

	}


}
