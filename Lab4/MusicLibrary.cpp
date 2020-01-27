/*
 * filename: MusicLibrary.h
 * Author: Ivar Juarez
 *
 * /
 */
#include "MusicLibrary.h"

MusicLibrary::MusicLibrary()
{
    mOwner = "nobody";
    mFilename = "";
}

MusicLibrary::MusicLibrary(const string& filename)
{
   mFilename = filename; 
}

// Methods
bool MusicLibrary::add(Song s)
{
    //searches for the song in the library
    for (unsigned i=0; i < mLibrary.size(); i++)
    {
        //compares the song title in the library
        //if it already exists
        if(mLibrary[i].getTitle().compare(s.getTitle()) == 0 )
        {
            return false;
        }
    }
    
    mLibrary.push_back (s);
   // cout << "Added song: " << s.getTitle() << endl;
    return true;
}
bool MusicLibrary::remove(Song s)
{
    for (unsigned int i=0; i < mLibrary.size(); i++)
    {
        if(mLibrary[i].getTitle().compare(s.getTitle()) == 0 )
        {
             mLibrary.erase(mLibrary.begin() + i);
             return true;
        }
    }
    
    return false;
}
bool MusicLibrary::remove(int index)
{
        //checks the index is within the range of the library
        if(index <= mLibrary.size() && index >=0)
        {
            //removes a song a the given index
             mLibrary.erase(mLibrary.begin() + index);
             return true;
        }
        else
	{
            return false;
	}
    
}
void MusicLibrary::print() const
{
    //prints out the list of songs in the library
    for (unsigned i=0; i < mLibrary.size(); i++)
    {
        cout << mLibrary[i] << endl;
    }
    
}
bool MusicLibrary::save() const
{
    return false;
}






















