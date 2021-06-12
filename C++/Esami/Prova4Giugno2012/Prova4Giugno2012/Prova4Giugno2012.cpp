#include "MultimediaFile.h"
#include "Song.h"   
#include "Video.h"
#include "Queue.h"

using namespace std;

int main()
{
    //MultimediaFile file("C:\\Users\\Claudio", 128, "mp3");
    Song song("C:\\Users\\Claudio", 128, "mp3", "Sweet Child o' Mine", "Guns N' Roses", 5.54);
    Video video("C:\\Users\\Claudio", 128, "mp4", "Claudio", "Video test", "02/09/2020");

    //cout << song;
    //cout << video;

    Queue list;

    list.append(&song);
    list.append(&video);

    cout << list;

    return 0;
}
