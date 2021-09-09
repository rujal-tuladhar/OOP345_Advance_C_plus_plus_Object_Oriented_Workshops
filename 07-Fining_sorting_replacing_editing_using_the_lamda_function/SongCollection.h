//Rujal Tuladhar
//id: 154594188
//email – rtuladhar@myseneca.ca
//I have done this workshop on my own by using only the material provided by my professor.


#ifndef SDDS_SONG_COLLECTION_H
#define SDDS_SONG_COLLECTION_H
#include<string>
#include<vector>
#include<list>

namespace sdds
{


	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		std::string m_year;
		int m_lenth;
	};


	class SongCollection
	{
		std::vector<Song> s;

	public:     
		//for removing the space fromt the string
		void remov(std::string& line);


		SongCollection(const std::string obj);
		void display(std::ostream& out)const;

	
		
		void sort(std::string the_value);

		bool inCollection(std::string the_artist) const;

		void cleanAlbum();


		std::list<Song> getSongsForArtist(std::string the_name) const;  
		
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);

	  
}


#endif
