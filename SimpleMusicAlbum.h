#ifndef __SIMPLE_MUSIC_ALBUM_H
#define __SIMPLE_MUSIC_ALBUM_H
#include <string>
using namespace std;
class MusicAlbum {
public:
     MusicAlbum( const string maArtist = "" , const string maTitle = "", const int maYear = 0 );
     ~MusicAlbum();
     MusicAlbum(const MusicAlbum &maToCopy);
     void setTitle(string titleName);
     void setArtist(string artistName);
     void setYear(int x);
     void operator=(const MusicAlbum &right);
     string getMusicAlbumArtist();
     string getMusicAlbumTitle();
     int getMusicAlbumYear();
private:
     string artist;
     string title;
     int year;
};
#endif
