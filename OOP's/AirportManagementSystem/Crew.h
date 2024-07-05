#ifndef CREW_H
#define CREW_H

#include <string>
#include <vector>

class Crew {
public:
    int crewID;
    std::string name;
    std::string position;
    std::string shiftTiming;

    Crew(int crewID, const std::string& name, const std::string& position, const std::string& shiftTiming);
    virtual void getDetails() const = 0;
};

class AirHostess : public Crew {
public:
    std::vector<std::string> languagesSpoken;
    int experience;

    AirHostess(int crewID, const std::string& name, const std::string& position, const std::string& shiftTiming, const std::vector<std::string>& languagesSpoken, int experience);
    void getDetails() const override;
};

class Purser : public Crew {
public:
    int seniorityLevel;
    std::vector<std::string> trainingCertifications;

    Purser(int crewID, const std::string& name, const std::string& position, const std::string& shiftTiming, int seniorityLevel, const std::vector<std::string>& trainingCertifications);
    void getDetails() const override;
};

#endif // CREW_H
