/*
    Consider a Fitness App that list and describes various exercises with details. There are 
    two types of exercises, home work-out and yoga. Each exercise has a name, id. Home work-out 
    exercise demo are given by playing a video (simply display the name of the video file being played) 
    and Yoga exercise demo is given by list of steps in the text. A user can download the app and view 
    all the exercises and their demo. Then he/she can create a playlist and include some exercises in 
    list. Write a program to display all list of exercises and playlist of the user.
*/

#include <bits/stdc++.h>
using namespace std;

class Exercise{
    public:
        string exerciseName;
        int exerciseId;
};

class Yoga : public Exercise{
    public:
        vector<string>steps;
        
        Yoga(){}

        Yoga(vector<string>steps, string exerciseName, int exerciseId){
            for(int i=0; i<steps.size(); i++){
                this->steps.push_back(steps[i]);
            }
            this->exerciseName = exerciseName;
            this->exerciseId = exerciseId;
        }

        void displaySteps() {
        cout << "Yoga Exercise--> " << exerciseName << endl;
        cout << "Steps-->" << endl;
        for (const string& step : steps) {
            cout << step << endl;
        }
    }
};

class WorkOut : public Exercise{
    public:
    string videoName;

    WorkOut(){}

    WorkOut(string videoName, string exerciseName, int exerciseId){
        this->videoName = videoName;
        this->exerciseName = exerciseName;
        this->exerciseId = exerciseId;
    }

    void displayVideoName() {
        cout << "Workout Exercise--> " << exerciseName << endl;
        cout << "Video Name--> " << videoName << endl;
    }

};

int main() {
    vector<string> yogaSteps = {"Step 1: Inhale deeply", "Step 2: Stretch your arms", "Step 3: Exhale slowly"};
    Yoga yogaExercise(yogaSteps, "Sun Salutation", 1);

    WorkOut workoutExercise("HomeWorkout1.mp4", "Pushups", 2);

    yogaExercise.displaySteps();

    workoutExercise.displayVideoName();

    return 0;
}