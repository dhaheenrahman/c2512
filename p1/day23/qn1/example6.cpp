/*Examples for diamond problem in inheritance:
=============================================================
Create one static object for final-derived class
and call all behaviours
and 
one dynamic object for final-derived class 
and call all behaviours

Define constructors and destructors for all the classes */

#include <iostream>

using namespace std;

class Media{
    private:
        string title;
    
    public:
        void play(){
            cout << "Media play behaviour callled" << endl;
        }

        Media(){
            cout << "Media Constructor called" << endl;
        }

        ~Media(){
            cout << "Media Destructor called" << endl;
        }
};

class Video : virtual public Media{
    private:
        string resolution;
    
    public:
        void display(){
            cout << "Video display behaviour called" << endl;
        }

        Video(){
            cout << "Video Constructor called" << endl;
        }

        ~Video(){
            cout << "Video Destructor called" << endl;
        }
};

class Audio : virtual public Media{
    private:
        string bitrate;
    
    public:
        void listen(){
            cout << "Audio listen behaviour called" << endl;
        }
        Audio(){
            cout << "Audio Constructor called" << endl;
        }

        ~Audio(){
            cout << "Audio Destructor called" << endl;
        }
};

class Movie : public Video,public Audio{
    private:
        int duration;

    public:
        void stream(){
            cout << "Movie stream behaviour called" << endl;
        }
        Movie(){
            cout << "Movie Constructor called" << endl;
        }

        ~Movie(){
            cout << "Movie Destructor called" << endl;
        }
};

int main(){
    Movie object1;                  //static object object1 for final-derived class
    object1.play();                 //object1 behaviours called
    object1.display();              
    object1.listen();
    object1.stream();
    cout << endl;
    
    Movie* object2 = new Movie;     //dynamic object object2 for final-derived class
    object2 -> play();              //object2 behaviours called
    object2 -> display();
    object2 -> listen();
    object2 -> stream();
    cout << endl;

    delete object2;                 //dynamic object object2 deleted
    object2 = nullptr;
    cout << endl;

    return 0;
}