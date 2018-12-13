#include <string>
#include <iostream>
using namespace std;
#include "SimpleMAC.h"

MAC::MAC()
{
    musicAlbums = NULL;
    noOfMusicAlbums = 0;
    //cout<<"mikmki"<<endl;
}

MAC::~MAC()
{
    if(musicAlbums)
        delete[] musicAlbums;
}
MAC::MAC(const MAC &macToCopy)
{

    if(macToCopy.noOfMusicAlbums <= 0)
    {
        noOfMusicAlbums = 0;
        musicAlbums = NULL;
    }
    else
    {
        noOfMusicAlbums = macToCopy.noOfMusicAlbums;
        musicAlbums = new MusicAlbum[noOfMusicAlbums];
        for(int i = 0; i < noOfMusicAlbums; i++)
            musicAlbums[i] = macToCopy.musicAlbums[i];

    }
}
void MAC::operator=(const MAC &right)
{
    if(musicAlbums)
        delete[] musicAlbums;
    if(right.noOfMusicAlbums <= 0)
    {
        noOfMusicAlbums = 0;
        musicAlbums = NULL;
    }
    else
    {
        noOfMusicAlbums = right.noOfMusicAlbums;
        musicAlbums = new MusicAlbum[noOfMusicAlbums];
        for(int i = 0; i < noOfMusicAlbums; i++)
            musicAlbums[i] = right.musicAlbums[i];

    }
}
bool MAC::addMusicAlbum(const string maArtist, const string maTitle, const int maYear)
{
    bool flag = true;
    for(int i = 0; i < noOfMusicAlbums; i++)
    {
        MusicAlbum tmp(musicAlbums[i]);
        if((tmp.getMusicAlbumArtist() == maArtist) && (tmp.getMusicAlbumTitle() == maTitle) && (tmp.getMusicAlbumYear()== maYear))
            flag = false;
    }
    if(flag)
    {
        MusicAlbum* tmp = musicAlbums;
        musicAlbums = new MusicAlbum[noOfMusicAlbums+1];
        for(int i = 0; i < noOfMusicAlbums; i++)
        {
            musicAlbums[i] = tmp[i];
        }
        musicAlbums[noOfMusicAlbums].setArtist(maArtist);
        musicAlbums[noOfMusicAlbums].setTitle(maTitle);
        musicAlbums[noOfMusicAlbums].setYear(maYear);
        noOfMusicAlbums++;
        //cout<<"eklendi"<<endl;
        delete[] tmp;
    }

    return flag;
}
bool MAC::removeMusicAlbum(const string maArtist, const string maTitle)
{
    bool flag = false;
    int index;
    for(int i = 0; i < noOfMusicAlbums; i++)
    {
        if(musicAlbums[i].getMusicAlbumArtist()== maArtist && musicAlbums[i].getMusicAlbumTitle()==maTitle)
        {
            index = i;
            flag = true;
        }
    }
    if(flag)
    {
        MusicAlbum* temp = musicAlbums;
        musicAlbums = new MusicAlbum[noOfMusicAlbums-1];
        for(int i = 0; i < index; i++)
            musicAlbums[i] = temp[i];
        for(int i = index+1; i < noOfMusicAlbums; i++)
            musicAlbums[i-1] = temp[i];
        delete[] temp;
        noOfMusicAlbums--;
    }
    return flag;

}
int MAC::getMusicAlbums(MusicAlbum *&allMusicAlbums)
{
    if(allMusicAlbums)
        delete[] allMusicAlbums;

    if(noOfMusicAlbums > 0)
    {
       allMusicAlbums = new MusicAlbum[noOfMusicAlbums];
        for(int i = 0; i < noOfMusicAlbums; i++)
        {
            allMusicAlbums[i] = musicAlbums[i];
        }
    }
    else
        allMusicAlbums = NULL;

    return noOfMusicAlbums;
}
