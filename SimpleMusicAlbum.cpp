
#include <string>
#include <iostream>
#include "SimpleMusicAlbum.h"
using namespace std;

 MusicAlbum::MusicAlbum( const string maArtist, const string maTitle, const int maYear )

 {
    artist = maArtist;
    title = maTitle;
    year = maYear;
 }

 MusicAlbum::~MusicAlbum()
 {
    //cout<<"heh"<<endl;
 }
 MusicAlbum::MusicAlbum(const MusicAlbum &maToCopy)
 {
    artist = maToCopy.artist;
    title = maToCopy.title;
    year = maToCopy.year;
    //cout<<"copied"<<endl;
 }
 void MusicAlbum::operator=(const MusicAlbum &right)
 {
        artist = right.artist;
        title = right.title;
        year = right.year;
        //cout<<"equalized"<<endl;
 }
 void MusicAlbum::setArtist(string artistName)
 {
     artist = artistName;
 }
 void MusicAlbum::setTitle(string titleName)
 {
     title = titleName;
 }
 void MusicAlbum::setYear(int x)
 {
     year = x;
 }
 string MusicAlbum::getMusicAlbumArtist()
 {
     return artist;
 }
 string MusicAlbum::getMusicAlbumTitle()
 {
     return title;
 }
 int MusicAlbum::getMusicAlbumYear()
 {
     return year;
 }


