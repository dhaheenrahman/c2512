#include <iostream>

using namespace std;

class Media{
    private:
        string title;
    
    public:
        void play(){
            cout << "Media play" << endl;
        }

        Media(){
            cout << "Media Constructor" << endl;
        }

        ~Media(){
            cout << "Media Destructor" << endl;
        }
};

class Video : virtual public Media{
    private:
        string resolution;
    
    public:
        void display(){
            cout << "Video display" << endl;
        }

        Video(){
            cout << "Video Constructor" << endl;
        }

        ~Video(){
            cout << "Video Destructor" << endl;
        }
};

class Audio : virtual public Media{
    private:
        string bitrate;
    
    public:
        void listen(){
            cout << "Audio listen" << endl;
        }
        Audio(){
            cout << "Audio Constructor" << endl;
        }

        ~Audio(){
            cout << "Audio Destructor" << endl;
        }
};

class Movie : public Video,public Audio{
    private:
        int duration;

    public:
        void stream(){
            cout << "Movie stream" << endl;
        }
        Movie(){
            cout << "Movie Constructor" << endl;
        }

        ~Movie(){
            cout << "Movie Destructor" << endl;
        }
};

int main(){
    Movie object1;

    object1.play();
    object1.display();
    object1.listen();
    object1.stream();
    
    Movie* object2 = new Movie;
    object2 -> play();
    object2 -> display();
    object2 -> listen();
    object2 -> stream();
}