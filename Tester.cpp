#include <iostream>
#include <string>
#include "SimpleMusicAlbum.h"
#include "SimpleMAC.h"
using namespace::std;

void displayAllMusicAlbums(MAC mac){
     MusicAlbum *allMusicAlbums;
     int noOfMusicAlbums = mac.getMusicAlbums(allMusicAlbums);
     cout <<"No of music albums: "<< noOfMusicAlbums << endl;
     for (int i = 0; i < noOfMusicAlbums; i++){
         cout << allMusicAlbums[i].getMusicAlbumArtist() <<", "
         << allMusicAlbums[i].getMusicAlbumTitle() <<" ("
         << allMusicAlbums[i].getMusicAlbumYear() <<")"
         << endl;
     }
     if (allMusicAlbums != NULL)
         delete [] allMusicAlbums;
}
int main() {
    /*MusicAlbum ma("z", "dd",2);
    MusicAlbum mm(ma);
    MusicAlbum ma2("a","s",2);
    ma.setArtist("queen");
    ma.setTitle("best");
    ma.setYear(1981);
    MAC mc;
    mc.addMusicAlbum("GnR", "Use Your Illusion", 1985);
    mc.addMusicAlbum("GnR", "Use Your Illusion", 1985);
    mc.removeMusicAlbum("GnR", "Use Your Illusion");
    return 0;*/

    MAC m;
    m.addMusicAlbum("John Coltrane", "My Favorite Things", 1961);
    if (m.addMusicAlbum("John Coltrane", "A Love Supreme", 1965))
        cout << "Successful insertion of John Coltrane, "<< "A Love Supreme (1965)" << endl;
    else
        cout << "Unsuccessful insertion of John Coltrane, " << "A Love Supreme (1965)" << endl;
    m.addMusicAlbum("Jethro Tull", "Thick As A Brick", 1972);
    m.addMusicAlbum("Mike Oldfield", "Tubular Bells", 1973);
    m.addMusicAlbum("Pink Floyd", "The Dark Side of the Moon", 1973);
    displayAllMusicAlbums(m);

    if (m.removeMusicAlbum("John Coltrane", "Giant Steps"))
        cout << "Successful deletion of John Coltrane, "<< "Giant Steps" << endl;
    else
        cout << "Unsuccessful deletion of John Coltrane, "<< "Giant Steps" << endl;
    return 0;
}
